/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:56:16 by kmaneera          #+#    #+#             */
/*   Updated: 2019/12/24 20:01:55 by mnila            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <libft.h>

# define MAX_TETS 26
# define BUFF_SIZE 546
# define I_PIECE 0x8888
# define IH_PIECE 0xF000
# define O_PIECE 0xCC00
# define L_PIECE 0x88C0
# define LR_PIECE 0xE800
# define LD_PIECE 0xC440
# define LL_PIECE 0x2E00
# define J_PIECE 0x44C0
# define JR_PIECE 0x8E00
# define JD_PIECE 0xC880
# define JL_PIECE 0xE200
# define T_PIECE 0x4E00
# define TR_PIECE 0x8C80
# define TD_PIECE 0xE400
# define TL_PIECE 0x4C40
# define S_PIECE 0x6C00
# define SR_PIECE 0x8C40
# define Z_PIECE 0xC600
# define ZR_PIECE 0x4C80

typedef struct		s_board
{
	int				**state;
	int				size;
	char			letter;
	struct s_board	*next;
}					t_board;

int					board_size(int elems);
int					check_file(char *buf);
int					pullout(int *tets, char *buf);
char				*read_file(char *filename);
t_board				*solve(int *tets, int elem);
t_board				*create_board(int size);
void				print_board(t_board *board);
void				destroy_board(t_board *board);

#endif
