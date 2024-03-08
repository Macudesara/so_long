#include "so_long.h"

int key_hook(int keycode, t_data *data)
{
	int	movements;
	int	temp;

	movements = 0;
	temp = movements;
	if (keycode == 53)
	{
		ft_esc(data);
		ft_printf("0 movements\n");
    	ft_printf("You have pressed the ESC key\n");
    	ft_printf("The game is over\n");
	}
	else if (keycode == 126 || keycode == 13)
	{
		if (ft_up(data) == 0)
			movements++;
	}
	else if (keycode == 125 || keycode == 1)
	{
		if (ft_down(data) == 0)
			movements++;
	}
	else if (keycode == 124 || keycode == 2)
	{
		if (ft_right(data) == 0)
			movements++;
	}
	else if (keycode == 123 || keycode == 0)
	{
		if (ft_left(data) == 0)
			movements++;
	}
	ft_make_map(data); //esta ft es necesaria para ver el mov del personaje en pantalla
	//ft_printf("%d\n", movements);

	return (0);
}

// int	mov_p(t_data *data)
// {

// 	return (0);
// }