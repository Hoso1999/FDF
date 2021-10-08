#include "fdf.h"

//rgb to int
int rgb(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

static double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(fdf_t *fdf, point_t start, point_t end)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (start.color == end.color)
		return (end.color);
	percentage = (fdf->delta.x > fdf->delta.y) ? percent(start.current.x, end.current.x, fdf->current.x) : percent(start.current.y, end.current.y, fdf->current.y);
	r = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	g = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	b = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}


int hexToInt(char *hex)
{
    char c;
    int result;
    int byte;

    while ((c = *hex))
    {
        ++hex;
        byte = (c & 0xF) + (c >> 6) | ((c >> 3) & 0x8);
        result = (result << 4) | byte;
    }
    return result;
}

int isNumberString(char *str)
{
    if (*str == '+' || *str == '-')
        ++str;
    while(*str)
    {
        if (!ft_isdigit(*str))
            return (0);
       ++str;
    }
    return (1);
}
void error(int errnum, char *message)
{
    ft_putendl_fd(message, 2);
    exit(errnum);
}

void putPixel(image_t *img, int x, int y, int color)
{
    char	*dst;

	dst = img->px + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void mapFree(map_t *map)
{
    int index;

    index = 0;
    while(map->matrix[index])
    {
       free(map->matrix[index]);
       ++index;
    }
    free(map->matrix);
    map->matrix = NULL;
}