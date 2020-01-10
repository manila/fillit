/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:55:58 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/24 20:27:29 by mnila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	tet_check(int tet)
{
	if (tet == I_PIECE || tet == IH_PIECE || tet == O_PIECE ||
		tet == L_PIECE || tet == LR_PIECE || tet == LD_PIECE ||
		tet == LL_PIECE || tet == J_PIECE || tet == JR_PIECE ||
		tet == JD_PIECE || tet == JL_PIECE || tet == T_PIECE ||
		tet == TR_PIECE || tet == TD_PIECE || tet == TL_PIECE ||
		tet == S_PIECE || tet == SR_PIECE || tet == Z_PIECE ||
		tet == ZR_PIECE)
		return (tet);
	return (0);
}

static int	topleft(int tet)
{
	int i;
	int	mask;

	mask = 0xFFFF;
	i = 0;
	while (tet <= IH_PIECE && tet > 0)
	{
		if (tet_check(tet))
			return (tet);
		tet = (tet << 1);
	}
	return (0);
}

int			pullout(int *tets, char *buf)
{
	int		i;
	int		mask;
	char	*ptr;

	i = 0;
	mask = 0x8000;
	ptr = buf;
	while (*buf)
	{
		if ((buf != ptr && (int)(buf - ptr) % 21 == 0) || *(buf + 1) == '\0')
		{
			if ((tets[i] = topleft(tets[i])) == 0)
				return (0);
			mask = 0x8000;
			i++;
		}
		if (*buf == '#')
			tets[i] = tets[i] | mask;
		if (*buf == '.' || *buf == '#')
			mask = mask >> 1;
		buf++;
	}
	return (i);
}

int			check_file(char *buf)
{
	int i;
	int nt;
	int nh;

	nt = 0;
	while (*buf)
	{
		i = 1;
		nh = 0;
		while (*buf && i <= 21)
		{
			if (*buf == '#')
				nh++;
			if ((i != 21 && i % 5 && *buf != '.' && *buf != '#') ||
			(!(i % 5) && (*buf != '\n')) || ((i == 21) && (*buf != '\n')))
				return (0);
			buf++;
			i++;
		}
		nt++;
		if ((!*buf && i < 20) || nh != 4 || nt > 26)
			return (0);
	}
	return (1);
}

char		*read_file(char *filename)
{
	char	buffer[BUFF_SIZE + 1];
	int		bytes_read;
	int		fd;

	fd = open(filename, O_RDONLY);
	if ((bytes_read = read(fd, &buffer, BUFF_SIZE)) > 0)
	{
		close(fd);
		buffer[bytes_read] = '\0';
		if (buffer[bytes_read - 2] == '\n' || bytes_read < 20)
			return (NULL);
		return (ft_strdup(buffer));
	}
	close(fd);
	return (NULL);
}
