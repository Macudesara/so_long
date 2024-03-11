/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:12:37 by mde-sara          #+#    #+#             */
/*   Updated: 2024/02/09 11:12:39 by mde-sara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf/ft_printf.h"
#include "get_next_line/get_next_line.h"
#include "mlx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_data
{
	int		col;
	int		row;
	int		x;
	int		y;
	int		coins;
	int		collected_coins;
	int		pos_x;
	int		pos_y;
	int		coins_flood;
	int		flood_fill_check;
    char    **map;
	int		line_posi;
	int		i_posi;
	void	*mlx_cont;
	void	*mlx_wind;
	void	*img_1;
	void	*img_c;
	void	*img_p;
	void	*img_e;
	void	*img_fondo;
	int		movements;
}				t_data;

void	*ft_memset(void *str, int c, size_t n);
int     ft_error(t_data *data, char *message);
void    ft_read_map(char **argv, t_data *data);
void    ft_get_size_map(int fd, t_data *data);
void    ft_memory_map(t_data *data, int fd);
void    ft_check_errors(t_data *data);
int 	ft_check_epc01(t_data *data);
int		ft_get_p_position(t_data *data);
int		ft_check_wall_top_bottom(t_data *data);
int		ft_check_wall_first_last(t_data *data);
int		ft_count_coins_c(t_data *data);
int     ft_flood_fill(t_data *data);
void    ft_fill(t_data *data, int pos_x, int pos_y);
void	ft_load_images(t_data *data);
void	ft_make_map(t_data *data);
void    ft_put_img_in_map(t_data *data, int w, int h);
void	ft_instructions(void);
int 	key_hook(int keycode, t_data *data);
void	ft_endgame(void);
int		ft_esc(t_data *data);
int		ft_up(t_data *data);
int		ft_down(t_data *data);
int		ft_right(t_data *data);
int		ft_left(t_data *data);