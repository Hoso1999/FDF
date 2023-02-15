#include "fdf.h"

#include <stdio.h>
int			create_file(char *name, int i, int j, fdf_t *fdf)
{
	char	*filename;
	int		path;
	int		fd;
    char    *fdf_file;

	path = 0;
    j = ft_strlen(IMG_PATH);
    fdf_file = ft_strrchr(name, '/');
    if (!fdf_file)
        fdf_file = name;
    else
       ++fdf_file;
	filename = (char *)malloc(ft_strlen(fdf_file) + j + 1);
    if (!filename)
        error(ERR_MALLOC, MALLOC_ERROR, fdf);
    ft_strcpy(filename, IMG_PATH);
	ft_strcat(filename, "/");
	++j;
	while (fdf_file[i] && fdf_file[i] != '.')
		filename[j++] = fdf_file[i++];
	filename[j] = '\0';
	ft_strcat(filename, ".bmp");
	if (!((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
													S_IRUSR | S_IWUSR)) > 0))
		error(ERR_IO, FILE_ERROR, fdf);
	free(filename);
	return (fd);
}

void		create_header(fdf_t* fdf, bmphead_t *header, dibhead_t *dib)
{
	header->type[0] = 0x42;
	header->type[1] = 0x4D;
	header->size = (SCREENWIDTH * SCREENHEIGHT * 4) + 54;
	header->reserved = 0x00000000;
	header->offset = 0x36;
	dib->size = 40;
	dib->width = SCREENWIDTH;
	dib->height = -SCREENHEIGHT;
	dib->colplanes = 1;
	dib->bits_per_pixel = 32;
	dib->compression = 0;
	dib->img_size = (SCREENWIDTH * SCREENHEIGHT * 4);
	dib->x_ppm = 2835;
	dib->y_ppm = 2835;
	dib->color_number = 0;
	dib->important_color = 0;
}

void		write_header(int fd, bmphead_t header, dibhead_t dib)
{
	write(fd, &header.type, 2);
	write(fd, &header.size, 4);
	write(fd, &header.reserved, 4);
	write(fd, &header.offset, 4);
	write(fd, &dib.size, 4);
	write(fd, &dib.width, 4);
	write(fd, &dib.height, 4);
	write(fd, &dib.colplanes, 2);
	write(fd, &dib.bits_per_pixel, 2);
	write(fd, &dib.compression, 4);
	write(fd, &dib.img_size, 4);
	write(fd, &dib.x_ppm, 4);
	write(fd, &dib.y_ppm, 4);
	write(fd, &dib.color_number, 4);
	write(fd, &dib.important_color, 4);
}

void		write_file(int fd, fdf_t *fdf)
{
	char	*pixel_array;
	int		image_size;
	int		i;
	int		j;

	pixel_array = (char *)malloc(fdf->mlx.image.size_line * SCREENHEIGHT);
    if (!pixel_array)
        error(ERR_MALLOC, MALLOC_ERROR, fdf);
	image_size = SCREENWIDTH * SCREENHEIGHT;
	i = 0;
	j = 0;
	while (i < image_size)
	{
		pixel_array[j++] = fdf->mlx.image.px[i] & 255;
		pixel_array[j++] = (fdf->mlx.image.px[i] & 255 << 8) >> 8;
		pixel_array[j++] = (fdf->mlx.image.px[i] & 255 << 16) >> 16;
		pixel_array[j++] = 0;
		i++;
	}
	write(fd, pixel_array, fdf->mlx.image.size_line * SCREENHEIGHT);
	free(pixel_array);
}

void		do_the_bmp_thing(fdf_t  *fdf, char* name)
{
	bmphead_t	header;
	dibhead_t	dib;
	int			fd;
	int			i;
	int			j;

	i = 0;
	j = 0;
	fd = create_file(name, i, j, fdf);
	create_header(fdf, &header, &dib);
	write_header(fd, header, dib);
	write_file(fd, fdf);
	close(fd);
}
