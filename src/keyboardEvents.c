#include "fdf.h"

int keyRelease(int key, fdf_t *fdf)
{
    if (key == KEY_ESC)
        closeWindow(fdf);
     #if MACOS
        if ((key >= KEY_ARROW_LEFT && key <= KEY_ARROW_UP) || key == KEY_Q || key == KEY_E)
    #elif LINUX
        if((key >= KEY_ARROW_LEFT && key <= KEY_ARROW_DOWN) || key == KEY_Q || key == KEY_E)
    #endif
        releaseRotationKeys(key, fdf);
     #if MACOS
        if ((key >= KEY_A && key <= KEY_D) || key == KEY_W || key == KEY_Z || key == KEY_C)
    #elif LINUX
        if (key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_W || key == KEY_Z || key == KEY_C)
    #endif
        releaseMoveKeys(key, fdf);
    if (key == KEY_LCTRL || key == KEY_RCTRL)
        fdf->keys.option = 0;
    if (key == KEY_R)
        fdf->keys.zMod.posSide = 0;
    if (key == KEY_F)
        fdf->keys.zMod.negSide = 0;
    return (1);
}

int keyPress(int key, fdf_t *fdf)
{
    if (key == KEY_ESC)
        closeWindow(fdf);
    #if MACOS
        if ((key >= KEY_ARROW_LEFT && key <= KEY_ARROW_UP) || key == KEY_Q || key == KEY_E)
    #elif LINUX
        if((key >= KEY_ARROW_LEFT && key <= KEY_ARROW_DOWN) || key == KEY_Q || key == KEY_E)
    #endif
        pressRotationKeys(key, fdf);
     #if MACOS
        if ((key >= KEY_A && key <= KEY_D) || key == KEY_W || key == KEY_Z || key == KEY_C)
    #elif LINUX
        if (key == KEY_A || key == KEY_S || key == KEY_D || key == KEY_W || key == KEY_Z || key == KEY_C)
    #endif
        pressMoveKeys(key, fdf);
    if (key == KEY_LCTRL || key == KEY_RCTRL)
        fdf->keys.option = 1;
     if (key == KEY_G)
        initCamera(&fdf->camera);
    if (key == KEY_R)
        fdf->keys.zMod.posSide = 1;
    if (key == KEY_F)
        fdf->keys.zMod.negSide = 1;
    if (key == KEY_1)
        fdf->projection = ISO;
    if (key == KEY_2)
        fdf->projection = TWOD;
    if (key == KEY_3)
        fdf->projection = DIAMETRIC;
    if (key == KEY_4)
        fdf->projection = CONIC;
    return (1);
}

void releaseMoveKeys(int key, fdf_t *fdf)
{
    if (key == KEY_W)
        fdf->keys.move.posY = 0;
    else if(key == KEY_S)
        fdf->keys.move.negY = 0;
    else if(key == KEY_A)
        fdf->keys.move.negX = 0;
    else if(key == KEY_D)
        fdf->keys.move.posX = 0;
    else if(key == KEY_Z)
        fdf->keys.move.negZ = 0;
    else if(key == KEY_C)
        fdf->keys.move.posZ = 0; 
}

void pressMoveKeys(int key, fdf_t *fdf)
{
    if (key == KEY_W)
        fdf->keys.move.posY = 1;
    else if(key == KEY_S)
        fdf->keys.move.negY = 1;
    else if(key == KEY_A)
        fdf->keys.move.negX = 1;
    else if(key == KEY_D)
        fdf->keys.move.posX = 1;
    else if(key == KEY_Z)
        fdf->keys.move.negZ = 1;
    else if(key == KEY_C)
        fdf->keys.move.posZ = 1;  
}

void releaseRotationKeys(int key, fdf_t *fdf)
{
    if (key == KEY_ARROW_UP)
        fdf->keys.rotate.negX = 0;
    else if (key == KEY_ARROW_DOWN)
        fdf->keys.rotate.posX = 0;
    else if (key == KEY_ARROW_LEFT)
        fdf->keys.rotate.negY = 0;
    else if (key == KEY_ARROW_RIGHT)
        fdf->keys.rotate.posY = 0;
    else if (key == KEY_Q)
        fdf->keys.rotate.negZ = 0;
    else if (key == KEY_E)
        fdf->keys.rotate.posZ = 0;
}

void pressRotationKeys(int key, fdf_t *fdf)
{
    if (key == KEY_ARROW_UP)
        fdf->keys.rotate.negX = 1;
    else if (key == KEY_ARROW_DOWN)
        fdf->keys.rotate.posX = 1;
    else if (key == KEY_ARROW_LEFT)
        fdf->keys.rotate.negY = 1;
    else if (key == KEY_ARROW_RIGHT)
        fdf->keys.rotate.posY = 1;
    else if (key == KEY_Q)
        fdf->keys.rotate.negZ = 1;
    else if (key == KEY_E)
        fdf->keys.rotate.posZ = 1;
}