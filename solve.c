/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnila <mnila@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:33:16 by mnila             #+#    #+#             */
/*   Updated: 2019/12/24 20:31:52 by mnila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	can_place_piece(t_board *board, int piece, int place)
{
	int x;
	int y;
	int	mask;

	mask = 0x8000;
	x = place % board->size;
	y = place / board->size;
	while (mask)
	{
		if (piece & mask)
			if (x >= board->size || y >= board->size || board->state[y][x] != 0)
				return (0);
		x++;
		mask = mask >> 1;
		if (mask == 0x800 || mask == 0x80 || mask == 0x8)
		{
			x = place % board->size;
			y++;
		}
		if (mask == 0)
			return (1);
	}
	return (0);
}

static int	place_piece(t_board *board, int piece, int place)
{
	int x;
	int y;
	int	mask;

	mask = 0x8000;
	x = place % board->size;
	y = place / board->size;
	if (can_place_piece(board, piece, place))
	{
		while (mask)
		{
			if (piece & mask && y < board->size)
				board->state[y][x] = board->letter;
			x++;
			mask = mask >> 1;
			if (mask == 0x800 || mask == 0x80 || mask == 0x8)
			{
				x = place % board->size;
				y++;
			}
		}
		board->letter++;
	}
	return (0);
}

static int	remove_piece(t_board *board, int piece, int place)
{
	int x;
	int y;
	int	mask;

	mask = 0x8000;
	x = place % board->size;
	y = place / board->size;
	while (mask)
	{
		if (piece & mask && y < board->size)
			board->state[y][x] = 0;
		x++;
		mask = mask >> 1;
		if (mask == 0x800 || mask == 0x80 || mask == 0x8)
		{
			x = place % board->size;
			y++;
		}
	}
	board->letter--;
	return (0);
}

static int	solve_map(t_board *board, int *tets, int elem, int place)
{
	int x;
	int y;

	x = place % board->size;
	y = place / board->size;
	if (elem == 0)
		return (1);
	while (place < board->size * board->size)
	{
		if (can_place_piece(board, *tets, place))
		{
			place_piece(board, *tets, place);
			if (solve_map(board, tets + 1, elem - 1, 0))
				return (1);
			remove_piece(board, *tets, place);
		}
		place++;
	}
	return (0);
}

t_board		*solve(int *tets, int elems)
{
	int		size;
	t_board *board;

	board = create_board(board_size(elems));
	while (!solve_map(board, tets, elems, 0))
	{
		size = board->size;
		destroy_board(board);
		board = create_board(size + 1);
	}
	return (board);
}
