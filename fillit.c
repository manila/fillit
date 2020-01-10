/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:56:25 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/24 21:00:59 by mnila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		fillit(char *filename)
{
	int		i;
	int		elems;
	int		tets[MAX_TETS];
	char	*file;
	t_board	*board;

	i = 0;
	while (i < MAX_TETS)
		tets[i++] = 0;
	if ((file = read_file(filename)))
	{
		if ((check_file(file)))
		{
			if ((elems = pullout(tets, file)))
			{
				board = solve(tets, elems);
				print_board(board);
				destroy_board(board);
				return (1);
			}
		}
	}
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	else if (argc == 2)
	{
		if (fillit(argv[1]))
			return (0);
	}
	ft_putendl("error");
	return (1);
}
