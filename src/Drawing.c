#include "fdf.h"

void drawLine(fdf_t *fdf, point_t start, point_t end)
{
    getParameters(fdf, start, end);
    if (fdf->delta.x > fdf->delta.y)
        drawLowPoint(fdf, start, end);
    else
        drawHighPoint(fdf, start, end);
}

void drawMap(fdf_t *fdf)
{
	for (int y = 0; y < fdf->map.height; ++y)
	{
		for (int x = 0; x < fdf->map.width; ++x)
		{
			if (x < fdf->map.width - 1)
				drawLine(fdf, fdf->map.matrix[y][x], fdf->map.matrix[y][x + 1]);
			if (y < fdf->map.height - 1)
				drawLine(fdf, fdf->map.matrix[y][x], fdf->map.matrix[y + 1][x]);
		}
	}
}

void drawHighPoint(fdf_t *fdf, point_t start, point_t end)
{
    for(int posY = 0; posY <= fdf->delta.y; ++posY)
    {
        if (inRange(fdf->current.y, 0, SCREENHEIGHT) && inRange(fdf->current.x, 0, SCREENWIDTH))
            putPixel(&fdf->mlx.image, fdf->current.x, fdf->current.y, get_color(fdf, start, end));
        if (fdf->error > 0)
        {
            fdf->current.x += fdf->sign.x;
            fdf->error += 2 * (fdf->delta.x - fdf->delta.y); 
        }
        else
            fdf->error += 2 * fdf->delta.x;
        fdf->current.y += fdf->sign.y;
    }
}

void drawLowPoint(fdf_t *fdf, point_t start, point_t end)
{
    for(int posX = 0; posX <= fdf->delta.x; ++posX)
    {
        if (inRange(fdf->current.y, 0, SCREENHEIGHT) && inRange(fdf->current.x, 0, SCREENWIDTH))
            putPixel(&fdf->mlx.image, fdf->current.x, fdf->current.y, get_color(fdf, start, end));
        if (fdf->error > 0)
        {
            fdf->current.y += fdf->sign.y;
            fdf->error += 2 * (fdf->delta.y - fdf->delta.x); 
        }
        else
            fdf->error += 2 * fdf->delta.y;
        fdf->current.x += fdf->sign.x;
    }
}

void drawControls(fdf_t *fdf)
{
    for(int y = CONTROLPOSY; y < SCREENHEIGHT; ++y)
        for(int x = CONTROLPOSX; x < SCREENWIDTH; ++x)
            putPixel(&fdf->mlx.image, x, y, CONTROLCOLOR);
    mlx_put_image_to_window(fdf->mlx.ptr, fdf->mlx.window, fdf->mlx.image.ptr, 0, 0);
}

void drawButton(fdf_t *fdf)
{ 
    for(int y = 0; y < BTNSIZE; ++y)
        for(int x = 0; x < BTNSIZE; ++x)
            putPixel(&fdf->mlx.button, x, y, BTNDEFAULTCOLOR);
    for(int y = 0; y < BTNSIZE; ++y)
        putPixel(&fdf->mlx.button, BTNSIZE / 2, y, BTNCOLOR);
    for(int x = 0; x < BTNSIZE; ++x)
        putPixel(&fdf->mlx.button, x, BTNSIZE / 2, BTNCOLOR);
    mlx_put_image_to_window(fdf->mlx.ptr, fdf->mlx.window, fdf->mlx.button.ptr, BTNPOSX, BTNPOSY);
}