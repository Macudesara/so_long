#include "so_long.h"
#include <stdio.h>

void    ft_load_images(t_data *data)
{
    int w;
    int h;

    w = 40;
    h = 40;
    data->img_fondo = mlx_xpm_file_to_image(data->mlx_cont, "images/fondo.xpm", &w, &h);
    data->img_1 = mlx_xpm_file_to_image(data->mlx_cont, "images/pared.xpm", &w, &h);
    data->img_p = mlx_xpm_file_to_image(data->mlx_cont, "images/personaje.xpm", &w, &h);
    data->img_c = mlx_xpm_file_to_image(data->mlx_cont, "images/coleccionable.xpm", &w, &h);
    data->img_e = mlx_xpm_file_to_image(data->mlx_cont, "images/exit.xpm", &w, &h);
}
//agregar imagen de fondo en los if
void    ft_put_img_in_map(t_data *data, int w, int h)
{
    if (data->map[data->y][data->x] == '1')
        mlx_put_image_to_window(data->mlx_cont, data->mlx_wind, data->img_1, w, h);
    else if (data->map[data->y][data->x] == 'o')
        mlx_put_image_to_window(data->mlx_cont, data->mlx_wind, data->img_fondo, w, h);
    else if (data->map[data->y][data->x] == 'p')
        mlx_put_image_to_window(data->mlx_cont, data->mlx_wind, data->img_p, w, h);
    else if (data->map[data->y][data->x] == 'c')
        mlx_put_image_to_window(data->mlx_cont, data->mlx_wind, data->img_c, w, h);
    else if (data->map[data->y][data->x] == 'E')
        mlx_put_image_to_window(data->mlx_cont, data->mlx_wind, data->img_e, w, h);
}

void	ft_make_map(t_data *data)
{
    int width;
    int height;

    data->y = 0;
    data->x = 0;
    width = 0;
    height = 0;
    while (data->y < data->row)
    {
        printf("data->row = %d\n", data->row);
        data->x = 0;
        width = 0;
        while (data->x < data->col)
        {
            printf("data->col = %d\n", data->col);
            if (data->map[data->y][data->x] == '0')
                data->map[data->y][data->x] = 'o';
            ft_put_img_in_map(data, width, height);
            data->x++;
            width += 40;
        }
        data->y++;
        height += 40;
    }
}