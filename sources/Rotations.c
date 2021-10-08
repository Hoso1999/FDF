#include "fdf.h"

void	rotateX(point_t *p, double ang)
{
	int	y;

	y = p->rotate.y;
	p->rotate.y = y * cos(ang) + p->rotate.z * sin(ang);
	p->rotate.z = -y * sin(ang) + p->rotate.z * cos(ang);
}

void	rotateY(point_t *p, double ang)
{
	int	x;

	x = p->rotate.x;
	p->rotate.x = x * cos(ang) + p->rotate.z * sin(ang);
	p->rotate.z = -x * sin(ang) + p->rotate.z * cos(ang);
}

void	rotateZ(point_t *p, double ang)
{
	int	x;
	int	y;

	x = p->rotate.x;
	y = p->rotate.y;
	p->rotate.x = x * cos(ang) - y * sin(ang);
	p->rotate.y = x * sin(ang) + y * cos(ang);
}

void changeRotation(fdf_t *fdf)
{
    for(int y = 0; y < fdf->map.height; ++y)
    {
        for(int x = 0; x < fdf->map.width; ++x)
        {
            fdf->map.matrix[y][x].rotate.x = fdf->map.matrix[y][x].pos.x;
            fdf->map.matrix[y][x].rotate.y = fdf->map.matrix[y][x].pos.y;
            fdf->map.matrix[y][x].rotate.z = (fdf->projection == TWOD) ? 0 : fdf->map.matrix[y][x].pos.z;
            fdf->map.matrix[y][x].rotate.x *= fdf->camera.zoom;
            fdf->map.matrix[y][x].rotate.y *= fdf->camera.zoom;
            fdf->map.matrix[y][x].rotate.z *= fdf->camera.zoom / fdf->camera.zMod;
            fdf->map.matrix[y][x].rotate.x -= (fdf->map.width * fdf->camera.zoom) / 2;
            fdf->map.matrix[y][x].rotate.y -= (fdf->map.height * fdf->camera.zoom) / 2;
            rotateX(&fdf->map.matrix[y][x], degreeToRad(fdf->camera.rotAngle.x));
            rotateY(&fdf->map.matrix[y][x], degreeToRad(fdf->camera.rotAngle.y));
            rotateZ(&fdf->map.matrix[y][x], degreeToRad(fdf->camera.rotAngle.z));
        }
    }
}
