#ifndef BMP_WRITER_H
#define BMP_WRITER_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "error.h"


typedef struct				bmp_header
{
	char					type[2];
	unsigned int			size;
	unsigned int			reserved;
	unsigned int			offset;
}							bmphead_t;

typedef struct				dib_header
{
	unsigned int			size;
	int						width;
	int						height;
	unsigned short			colplanes;
	unsigned short			bits_per_pixel;
	unsigned int			compression;
	unsigned int			img_size;
	int						x_ppm;
	int						y_ppm;
	unsigned int			color_number;
	unsigned int			important_color;
}							dibhead_t;


int			create_file(char *name, int i, int j, fdf_t* fdf);

void		create_header(fdf_t* fdf, bmphead_t *header, dibhead_t *dib);

void		write_header(int fd, bmphead_t header, dibhead_t dib);

void		write_file(int fd, fdf_t* fdf);

void		do_the_bmp_thing(fdf_t* fdf, char *name);

#endif
