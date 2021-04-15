#include "mlx.h"
#include <stdio.h>
#include "get.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             main(int argc,char **argv)
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     temp;
    s_map   map;

    temp = open(argv[1]);
    get_next_line(temp, char **line);
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, map.res[0], map.res[1], "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	int c = 0x000000FF;
	for (int i = 0;i < 255;i++)
{
	for (int j = 0;j < 600;j++)
	{
		if(j >= 200){c = i * 0x00000100 + 0x000000FF;}
		if(j >= 400){c = i * 0x00000001 + 0x0000FF00;}
		if(j <= 200){c = 0x00000001 + i + 0x00FF0000;}
		my_mlx_pixel_put(&img, i, j, c);
	}
}
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 250, 250);
    mlx_loop(mlx);
}