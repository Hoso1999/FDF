#include "fdf.h"

double degreeToRad(int degree)
{
    return ((degree * M_PI) / 180);
}

void getParameters(fdf_t *fdf, point_t start, point_t end)
{
    fdf->delta.x = ft_abs(end.current.x - start.current.x);
    fdf->delta.y = ft_abs(end.current.y - start.current.y);
    fdf->sign.x = (end.current.x >= start.current.x) ? 1 : -1;
    fdf->sign.y = (end.current.y >= start.current.y) ? 1 : -1;
    fdf->current.x = start.current.x;
    fdf->current.y = start.current.y;
    fdf->error = (fdf->delta.x > fdf->delta.y) ? 2 * fdf->delta.y - fdf->delta.x : 2 * fdf->delta.x - fdf->delta.y;
}

void changeToIsometric(fdf_t *fdf, point_t *p)
{
    position_t previus;
    double rad;

    rad = degreeToRad(30);
    previus.x = p->rotate.x;
    previus.y = p->rotate.y;
    p->current.x = fdf->camera.move.x + (previus.x - previus.y) * cos(rad);
    p->current.y = fdf->camera.move.y - p->rotate.z + (previus.x + previus.y) * sin(rad);
}

void changeToDiametric(fdf_t *fdf, point_t *p)
{
    position_t previus;
    double rad;

    rad = degreeToRad(15);
    previus.x = p->rotate.x;
    previus.y = p->rotate.y;
    p->current.x = fdf->camera.move.x + (previus.x - previus.y) * cos(rad);
    p->current.y = fdf->camera.move.y - p->rotate.z + (previus.x + previus.y) * sin(rad);
}

void changeToConic(fdf_t *fdf, point_t *p)
{
    position_t previus;

    previus.x = p->rotate.x;
    previus.y = p->rotate.y;
    p->current.x = fdf->camera.move.x + previus.x;
    p->current.y = fdf->camera.move.y + previus.y;
}

void changeTo2D(fdf_t *fdf, point_t *p)
{
    position_t previus;

    previus.x = p->rotate.x;
    previus.y = p->rotate.y;
    previus.z = 0;
    p->current.x = fdf->camera.move.x + previus.x;
    p->current.y = fdf->camera.move.y + previus.y;
}

void changeProjection(fdf_t *fdf)
{
    for(int y = 0; y < fdf->map.height; ++y)
    {
        for(int x = 0; x < fdf->map.width; ++x)
        {
            if (fdf->projection == ISO)
                changeToIsometric(fdf, &fdf->map.matrix[y][x]);
            else if (fdf->projection == CONIC)
                changeToConic(fdf, &fdf->map.matrix[y][x]);
            else if (fdf->projection == TWOD)
                changeTo2D(fdf, &fdf->map.matrix[y][x]);
            else
                changeToDiametric(fdf, &fdf->map.matrix[y][x]);
        }
        
    }
    
}