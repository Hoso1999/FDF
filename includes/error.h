#ifndef ERROR_H
#define ERROR_H

//Error codes
#define ERR_IO 5
#define ERR_INVALID_ARGS 22
#define ERR_MALLOC 14
#define ERR_PARSING -1
#define ERR_MLX 10

#define USAGE_ERROR "Usage: ./fdf <filepath> <zoom> <Zmod>"
#define FILE_ERROR "Could not open file"
#define GETLINE_ERROR "Could not read line"
#define MALLOC_ERROR "Could not allocate memory"
#define PARSING_ERROR "Invalid Map"
#define EXTENSION_ERROR "File extension must be <.fdf>"
#define ARGUMENT_ERROR "Argument must be number"
#define MLXWINDOW_ERROR "Could not create window"
#define MLXIMAGE_ERROR "Could not create window"
#define MLX_ERROR "Could not initalize minilibx"

//Error Handle
void error(int errnum, char *message);

#endif