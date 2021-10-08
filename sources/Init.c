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
    if (!(fdf->mlx.ptr = mlx_init()))
        error(ERR_MLX, MLX_ERROR);
    if (!(fdf->mlx.window = mlx_new_window(fdf->mlx.ptr, SCREENWIDTH, SCREENHEIGHT, "FDF Landscape")))
        error(ERR_MLX, MLXWINDOW_ERROR);
    if (!(fdf->mlx.button.ptr = mlx_new_image(fdf->mlx.ptr, BTNSIZE, BTNSIZE)))
        error(ERR_MLX, MLXIMAGE_ERROR);
    fdf->mlx.button.px = mlx_get_data_addr(fdf->mlx.button.ptr, &fdf->mlx.button.bits_per_pixel, &fdf->mlx.button.size_line, &fdf->mlx.button.endian);
    if (!(fdf->mlx.image.ptr = mlx_new_image(fdf->mlx.ptr, SCREENWIDTH + 1, SCREENHEIGHT + 1)))
        error(ERR_MLX, MLXIMAGE_ERROR);
    fdf->mlx.image.px = mlx_get_data_addr(fdf->mlx.image.ptr, &fdf->mlx.image.bits_per_pixel, &fdf->mlx.image.size_line, &fdf->mlx.image.endian);
    fdf->map.matrix = NULL;
    fdf->map.height = 0;
    fdf->map.width = 0;
    fdf->delta = (position_t){0, 0, 0};
    fdf->sign = (position_t){0, 0, 0};
    fdf->current = (position_t){0, 0, 0};
    fdf->error = 0;
    // fdf->mlx.mouse.x = 0;
    // fdf->mlx.mouse.y = 0;
    fdf->projection = ISO;
    initCamera(&fdf->camera);
    initKeys(&fdf->keys);
}
