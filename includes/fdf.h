#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include "keys.h"
#include "libft.h"
#include "error.h"
#include <stdio.h>
#include <math.h>

//Screen Sizes
#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

//Control Parameters
#define inRange(x, min, max)(x >= min && x <= max)
#define TEXTCOLOR rgb(255, 255, 255)
#define BGCOLOR rgb	(25,24,24)
#define CONTROLCOLOR rgb(24, 21, 21)
#define CONTROLWIDTH SCREENWIDTH / 4
#define CONTROLHEIGHT SCREENHEIGHT / 4 - 200
#define CONTROLPOSX SCREENWIDTH - CONTROLWIDTH
#define CONTROLPOSY SCREENHEIGHT - CONTROLHEIGHT
#define MINZOOM 10
#define MINZMOD 1
#define MAXZMOD 20
#define DEFAULT_COLOR rgb(108, 196, 71)
#define BTNCOLOR rgb(0, 0, 0)
#define BTNDEFAULTCOLOR rgb(255, 255, 255)
#define BTNPOSX CONTROLPOSX + CONTROLWIDTH / 2
#define BTNPOSY SCREENHEIGHT - 50
#define BTNSIZE 25

typedef enum projection
{
    ISO,
    DIAMETRIC,
    CONIC,
    TWOD,
    NONE
} projection_t;

//Int Position
typedef struct position
{
    int x;
    int y;
    int z;
} position_t;

//Coordinate
typedef struct coord
{
    double x;
    double y;
    double z;
} coord_t;

//Minilibx Image
typedef struct image
{
    void    *ptr;
    void    *px;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
} image_t;

//Mouse Keys
typedef struct mouseActiveKeys
{
    int left;
    int right;
    int scroll;
    int scrollDown;
    int scrollUp;
} mouseActiveKeys_t;

//Mouse Event
typedef struct mouse
{
    int x;
    int y;
    int lastX;
    int lastY;
    int isPressed;
    int button;
    mouseActiveKeys_t keys;
} mouse_t;

//Minilibx
typedef struct minilibx
{
    void    *ptr;
    void    *window;
    mouse_t mouse;
    image_t button;
    image_t image;
    int     uiCount;
} minilibx_t;

//Camera
typedef struct camera
{
    double      zoom;
    double      zMod;
    coord_t     rotAngle;
    position_t  move;
} camera_t;

//Points
typedef struct point
{
    position_t  pos;
    coord_t     rotate;
    position_t  current;
    int color;
} point_t;

//Deep Map
typedef struct map
{
    point_t **matrix;
    int width;
    int height;
} map_t;


typedef struct pos
{
    int posSide;
    int negSide;
} pos_t;


typedef struct keyPosition
{
    int posX;
    int negX;
    int posY;
    int negY;
    int posZ;
    int negZ;
} keyPosition_t;


//Current Active Keys
typedef struct activekeys
{
    keyPosition_t   rotate;
    keyPosition_t   move;
    pos_t           zMod;        
} activeKeys_t;

//Main Structure
typedef struct fdf
{
    activeKeys_t    keys;
    minilibx_t      mlx;
    map_t           map;
    camera_t        camera;
    position_t      delta;
    position_t      sign;
    position_t      current;
    projection_t    projection;
    int             error;
} fdf_t;


//Read from File and Parsing
void    readFromFile(fdf_t *fdf, int argc, char **argv);
void    fillMap(fdf_t *fdf, char **lineValues, int lineIndex);
void	getHeight(int fd, fdf_t *fdf);
int     getWidth(fdf_t *fdf, char **lineValues, int lineIndex);

//Rotation
void	rotateX(point_t *p, double ang);
void	rotateY(point_t *p, double ang);
void	rotateZ(point_t *p, double ang);
void    changeRotation(fdf_t *fdf);

//Calculation and Projecting
double  degreeToRad(int degree);
void    getParameters(fdf_t *fdf, point_t start, point_t end);
void    changeToIsometric(fdf_t *fdf, point_t *p);
void    changeToDiametric(fdf_t *fdf, point_t *p);
void    changeToConic(fdf_t *fdf, point_t *p);
void    changeProjection(fdf_t *fdf);

//Drawing
void    drawLine(fdf_t *fdf, point_t start, point_t end);
void    drawMap(fdf_t *fdf);
void    drawHighPoint(fdf_t *fdf, point_t start, point_t end);
void    drawLowPoint(fdf_t *fdf, point_t start, point_t end);
int     draw(fdf_t *fdf);
void    UI(fdf_t *fdf);
void    putPixel(image_t *img, int x, int y, int color);
void    drawControls(fdf_t *fdf);
void    drawButton(fdf_t *fdf);


//Helpers
void    mapFree(map_t *map);
int     rgb(int r, int g, int b);
int     isNumberString(char *str);
int     hexToInt(char *hex);
int		get_color(fdf_t *fdf, point_t start, point_t end);


//Mouse Events
int     mouseDown(int button, int x, int y, fdf_t *fdf);
int     mouseUp(int button, int x, int y, fdf_t *fdf);
int     mouseMove(int x,int y,fdf_t *fdf);

//Keyboard Events
int     keyRelease(int key, fdf_t *fdf);
int     keyPress(int key, fdf_t *fdf);
void    releaseMoveKeys(int key, fdf_t *fdf);
void    pressMoveKeys(int key, fdf_t *fdf);
void    releaseRotationKeys(int key, fdf_t *fdf);
void    pressRotationKeys(int key, fdf_t *fdf);
void    changeZmod(fdf_t *fdf);

//initalization
void    initCamera(camera_t *cam);
void    initFdf(fdf_t *fdf);

//Minilibx Events
int     closeWindow(fdf_t *fdf);
int     keyPress(int key, fdf_t *fdf);
void    graphicEvents(fdf_t *fdf);

#endif