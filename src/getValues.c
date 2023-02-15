#include "fdf.h"

void	getHeight(int fd, fdf_t *fdf)
{
	int		ret;
	char	*line;

	ret = 0;
	line = NULL;
	while ((ret = ft_getline(fd, &line)) > 0)
	{
		++fdf->map.height;
		free(line);
	}
	free(line);
	if (ret < 0)
		error(ERR_IO, GETLINE_ERROR, fdf);
}

int getWidth(fdf_t *fdf, char **lineValues, int lineIndex)
{
    int index;

    index = -1;
    while (lineValues[++index]);
    if (index == -1 || (lineIndex > 0 && index != fdf->map.width))
        error(ERR_PARSING, PARSING_ERROR, fdf);
    if (index > fdf->map.width)
        fdf->map.width = index;
    return index; 
}

void fillMap(fdf_t *fdf, char **lineValues, int lineIndex)
{
    int     width;
    char    *color;
    int     index;
    point_t p;

    index = 0;
    width = getWidth(fdf, lineValues, lineIndex);
    if (!(fdf->map.matrix[lineIndex] = (point_t *)malloc(sizeof(point_t) * (width + 1))))
        error(ERR_MALLOC, MALLOC_ERROR, fdf);
    while(lineValues[index])
    {
        p.pos.x = index;
        p.pos.y = lineIndex;
        if (!ft_atoi_error(lineValues[index]))
            error(ERR_PARSING, PARSING_ERROR, fdf);
        p.pos.z = ft_atoi(lineValues[index]);
        color = ft_strchr(lineValues[index], ',');
        p.color = (color) ? hexToInt(color + 1) : DEFAULT_COLOR;
        fdf->map.matrix[lineIndex][index] = p;
        ++index;
        free(lineValues[index]);
    }
    free(lineValues);
}
