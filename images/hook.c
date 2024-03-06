#include "so_long.h"

int key_hook(int keycode, t_data *data)
{
	if (keycode == 53) // Código de tecla 'Esc'
	{
		printf("Saliendo...\n");
		return (1);
	}
	else if (keycode == 49) // Código de tecla 'Espacio'
		printf("Has presionado la tecla de espacio.\n");
	else if (keycode == 36) // Código de tecla 'Enter'
		printf("Has presionado la tecla de enter.\n");
	else
		printf("Has presionado una tecla con código: %d\n", keycode);
	return (0);
}