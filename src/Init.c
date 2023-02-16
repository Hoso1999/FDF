#include "fdf.h"

void initCamera(camera_t *cam)
{
    cam->zoom = 25;
    cam->zMod = 10;
    cam->rotAngle.x = 30;
    cam->rotAngle.y = 0;
    cam->rotAngle.z = 0;
    cam->move.x = SCREENWIDTH / 2;
    cam->move.y = SCREENHEIGHT / 2;
}

void initKeys(activeKeys_t *keys)
{
    keys->rotate = (keyPosition_t){0, 0, 0, 0, 0, 0};
    keys->move = (keyPosition_t){0, 0, 0, 0, 0, 0};
    keys->zMod = (pos_t){0,0};
}

void initFdf(fdf_t *fdf)
{
    fdf->map.matrix = NULL;
    fdf->is_save = 0;
    fdf->save_loc = 0;
    fdf->map.height = 0;
    fdf->map.width = 0;
    fdf->delta = (position_t){0, 0, 0};
    fdf->sign = (position_t){0, 0, 0};
    fdf->current = (position_t){0, 0, 0};
    fdf->error = 0;
    fdf->projection = ISO;
}

void initMlx(fdf_t  *fdf)
{
    fdf->mlx.ptr = 0;
    fdf->mlx.window = 0;
    fdf->mlx.button.ptr = 0;
    fdf->mlx.image.ptr = 0;
    if (!(fdf->mlx.ptr = mlx_init()))
        error(ERR_MLX, MLX_ERROR, fdf);
    if (!(fdf->mlx.window = mlx_new_window(fdf->mlx.ptr, SCREENWIDTH, SCREENHEIGHT, "FDF Landscape")))
        error(ERR_MLX, MLXWINDOW_ERROR, fdf);
    if (!(fdf->mlx.button.ptr = mlx_new_image(fdf->mlx.ptr, BTNSIZE, BTNSIZE)))
        error(ERR_MLX, MLXIMAGE_ERROR, fdf);
    fdf->mlx.button.px = (int*)mlx_get_data_addr(fdf->mlx.button.ptr, &fdf->mlx.button.bits_per_pixel, &fdf->mlx.button.size_line, &fdf->mlx.button.endian);
    if (!(fdf->mlx.image.ptr = mlx_new_image(fdf->mlx.ptr, SCREENWIDTH, SCREENHEIGHT)))
        error(ERR_MLX, MLXIMAGE_ERROR, fdf);
    fdf->mlx.image.px = (int*)mlx_get_data_addr(fdf->mlx.image.ptr, &fdf->mlx.image.bits_per_pixel, &fdf->mlx.image.size_line, &fdf->mlx.image.endian);
}
