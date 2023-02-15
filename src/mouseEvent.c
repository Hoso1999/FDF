#include "fdf.h"

void changeButtonColor(fdf_t *fdf)
{
    for(int y = 0; y < BTNSIZE; ++y)
        for(int x = 0; x < BTNSIZE; ++x)
            putPixel(&fdf->mlx.button, x, y, BTNCOLOR);
    for(int y = 0; y < BTNSIZE; ++y)
        putPixel(&fdf->mlx.button, BTNSIZE / 2, y, BTNDEFAULTCOLOR);
    for(int x = 0; x < BTNSIZE; ++x)
        putPixel(&fdf->mlx.button, x, BTNSIZE / 2, BTNDEFAULTCOLOR);
    mlx_put_image_to_window(fdf->mlx.ptr, fdf->mlx.window, fdf->mlx.button.ptr, BTNPOSX, BTNPOSY);
}
static void	changeZoom(int button, fdf_t *fdf)
{
	if (button == KEY_SCROLL_UP)
		fdf->camera.zoom -= 1;
	if (button == KEY_SCROLL_DOWN)
		fdf->camera.zoom += 1;
}
static void	mouseChangeZmod(int button, fdf_t *fdf)
{
	if (button == KEY_SCROLL_UP)
		fdf->camera.zMod -= 1;
	if (button == KEY_SCROLL_DOWN)
		fdf->camera.zMod += 1;
}

int mouseDown(int button, int x, int y, fdf_t *fdf)
{
    if (button == KEY_LEFT_CLICK && inRange(y, BTNPOSY, BTNPOSY + BTNSIZE) && inRange(x, BTNPOSX, BTNPOSX + BTNSIZE))
    {
            ++fdf->projection;
            if (fdf->projection == NONE)
                fdf->projection = ISO;
            changeButtonColor(fdf);
            return (0);
    }
    if (y < 0)
        return (0);
    if (button == KEY_SCROLL_DOWN || button == KEY_SCROLL_UP)
    {
        if (fdf->mlx.mouse.keys.right)
            mouseChangeZmod(button, fdf);
        else
            changeZoom(button, fdf);   
    }
    if (button == KEY_RIGHT_CLICK)
    {
        fdf->camera.move.x = x;
        fdf->camera.move.y = y;
    }
    if (button == KEY_LEFT_CLICK)
        fdf->mlx.mouse.keys.left = 1;
    if (button == KEY_RIGHT_CLICK)
        fdf->mlx.mouse.keys.right = 1;
    if (button == KEY_SCROLL_CLICK)
        fdf->mlx.mouse.keys.scroll = 1;
    return (0);
}

int mouseUp(int button, int x, int y, fdf_t *fdf)
{
    (void)x;
    (void)y;
    if (y < 0)
        return (0);
    if (button == KEY_LEFT_CLICK)
        fdf->mlx.mouse.keys.left = 0;
    if (button == KEY_RIGHT_CLICK)
        fdf->mlx.mouse.keys.right = 0;
    if (button == KEY_SCROLL_CLICK)
        fdf->mlx.mouse.keys.scroll = 0;
    return (0);
}

int mouseMove(int x,int y,fdf_t *fdf)
{
    fdf->mlx.mouse.lastX = fdf->mlx.mouse.x;
    fdf->mlx.mouse.lastY = fdf->mlx.mouse.y;
    fdf->mlx.mouse.x = x;
    fdf->mlx.mouse.y = y;
    if (fdf->mlx.mouse.keys.left)
	{
		fdf->camera.move.y = fdf->mlx.mouse.lastY;
		fdf->camera.move.x = fdf->mlx.mouse.lastX;
	}
    return (0);
}