# include "fractol.h"
/* 
*INIT
*~mlx
*~listening events
*~hooks data
*/
static void malloc_error(void)
{
    perror("Problems with malloc");
    exit(EXIT_FAILURE);
}

void data_init(t_fractal *fractal)
{
        fractal->escape_value = 4;
        fractal->iterations_definitions = 42;
}
void fractal_init(t_fractal *fractal) 
{
    //    MLX: stuff
    fractal->mlx_connection = mlx_init();
    if (NULL == fractal->mlx_connection)
        malloc_error();
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
                                        WIDTH, 
                                        HEIGHT, 
                                        fractal->name );
    if (NULL == fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,WIDTH,HEIGHT );
    if (NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
                                                &fractal->img.bpp,
                                                &fractal->img.line_len,
                                                &fractal->img.endian);
}

