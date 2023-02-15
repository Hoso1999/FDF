#include "fdf.h"

void changeRotationAngle(fdf_t *fdf)
{
    if (fdf->keys.rotate.posX && !fdf->keys.rotate.negX)
        fdf->camera.rotAngle.x += 5;
    if (!fdf->keys.rotate.posX && fdf->keys.rotate.negX)
        fdf->camera.rotAngle.x -= 5;
    if (fdf->keys.rotate.posY && !fdf->keys.rotate.negY)
        fdf->camera.rotAngle.y += 5;
    if (!fdf->keys.rotate.posY && fdf->keys.rotate.negY)
        fdf->camera.rotAngle.y -= 5;
    if (fdf->keys.rotate.posZ && !fdf->keys.rotate.negZ)
        fdf->camera.rotAngle.z += 5;
    if (!fdf->keys.rotate.posZ && fdf->keys.rotate.negZ)
        fdf->camera.rotAngle.z -= 5;
        
}
void changeMovePosition(fdf_t *fdf)
{
    if (fdf->keys.move.posX && !fdf->keys.move.negX)
        fdf->camera.move.x += 5;
    if (!fdf->keys.move.posX && fdf->keys.move.negX)
        fdf->camera.move.x -= 5;
    if (fdf->keys.move.posY && !fdf->keys.move.negY)
        fdf->camera.move.y -= 5;
    if (!fdf->keys.move.posY && fdf->keys.move.negY)
        fdf->camera.move.y += 5;
    if ((fdf->keys.move.posZ && !fdf->keys.move.negZ) || (fdf->mlx.mouse.keys.scrollDown && !fdf->mlx.mouse.keys.scrollDown))
        fdf->camera.zoom += 1;
    if ((!fdf->keys.move.posZ && fdf->keys.move.negZ) || (!fdf->mlx.mouse.keys.scrollDown && fdf->mlx.mouse.keys.scrollDown))
        fdf->camera.zoom -= 1;
}

void changeZmod(fdf_t *fdf)
{
    if (!fdf->keys.zMod.posSide && fdf->keys.zMod.negSide)
        fdf->camera.zMod += 1;
    if (fdf->keys.zMod.posSide && !fdf->keys.zMod.negSide)
        fdf->camera.zMod -= 1;
}

void clearWindow(fdf_t *fdf)
{
    for(int y = 0; y < SCREENHEIGHT; ++y)
        for(int x = 0; x < SCREENWIDTH; ++x)
            putPixel(&fdf->mlx.image, x, y, rgb(0,0,0));
}

int draw(fdf_t *fdf)
{
    clearWindow(fdf);
    changeZmod(fdf);
    changeRotationAngle(fdf);
    changeMovePosition(fdf);
    fdf->camera.zoom = (fdf->camera.zoom < 1) ? 1 : fdf->camera.zoom;
    fdf->camera.zMod = (fdf->camera.zMod < MINZMOD) ? MINZMOD : fdf->camera.zMod;
    fdf->camera.zMod = (fdf->camera.zMod > MAXZMOD) ? MAXZMOD : fdf->camera.zMod;
    changeRotation(fdf);
    changeProjection(fdf);
    drawMap(fdf);
    drawControls(fdf);
    drawButton(fdf);
    UI(fdf);
    mlx_do_sync(fdf->mlx.ptr);
	if (fdf->is_save)
    {
		do_the_bmp_thing(fdf, fdf->save_loc);
        printf("Image saved in \"%s\" location\n", IMG_PATH);
        exit(0);
    }
    return (1);
}

int main(int argc, char **argv)
{
    fdf_t fdf;

    initFdf(&fdf);
    readFromFile(&fdf, argc, argv);
    initMlx(&fdf);
    if (fdf.is_save)
        fdf.save_loc = argv[1];
    graphicEvents(&fdf);
}
