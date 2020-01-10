/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnila <mnila@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:38:15 by mnila             #+#    #+#             */
/*   Updated: 2019/12/24 20:00:26 by mnila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				board_size(int elems)
{
	int	size;

	size = 2;
	while (size * size < (elems * 4))
		size++;
	return (size);
}

static int		**grid_make(int size)
{
	int **grid;
	int n;
	int a;

	n = 0;
	grid = (int**)malloc(sizeof(int*) * size);
	if (grid == NULL)
		return (NULL);
	while (n < size)
	{
		a = 0;
		grid[n] = (int*)malloc(sizeof(int) * (size + 0));
		if (grid[n] == NULL)
			return (NULL);
		while (a < size)
		{
			grid[n][a] = 0;
			a++;
		}
		n++;
	}
	return (grid);
}

void			print_board(t_board *board)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < board->size)
	{
		while (x < board->size)
		{
			if (board->state[y][x] != 27 && board->state[y][x] != 0)
				ft_putchar(board->state[y][x]);
			else
				ft_putchar('.');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

t_board			*create_board(int size)
{
	t_board *board;

	board = (t_board *)malloc(sizeof(t_board));
	if (board == NULL)
		return (NULL);
	board->state = grid_make(size);
	if (board->state == NULL)
		return (NULL);
	board->letter = 'A';
	board->size = size;
	board->next = NULL;
	return (board);
}

void			destroy_board(t_board *board)
{
	int i;

	i = 0;
	if (board != NULL)
	{
		while (i < board->size)
		{
			free(board->state[i]);
			i++;
		}
		free(board->state);
		free(board);
		board = NULL;
	}
}
