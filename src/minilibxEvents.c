#include "fdf.h"

int closeWindow(fdf_t *fdf)
{
    mapFree(&fdf->map);
    if (fdf->mlx.ptr && fdf->mlx.window)
    {
        if (fdf->mlx.image.ptr)
            mlx_destroy_image(fdf->mlx.ptr, fdf->mlx.image.ptr);
        if (fdf->mlx.button.ptr)
            mlx_destroy_image(fdf->mlx.ptr, fdf->mlx.button.ptr);
        mlx_destroy_window(fdf->mlx.ptr, fdf->mlx.window);
    }
    exit(0);
    return (0);
}

void graphicEvents(fdf_t *fdf)
{
    mlx_hook(fdf->mlx.window, 17, 0, closeWindow, fdf);
    mlx_hook(fdf->mlx.window, 2, 1L << 0, keyPress, fdf);
    mlx_hook(fdf->mlx.window, 3, 1L << 1, keyRelease, fdf);
    mlx_hook(fdf->mlx.window, 4, 1L << 2, mouseDown, fdf);
    mlx_hook(fdf->mlx.window, 5, 1L << 3, mouseUp, fdf);
    mlx_hook(fdf->mlx.window, 6, 1L << 6, mouseMove, fdf);
    mlx_loop_hook(fdf->mlx.ptr, draw, fdf);
    mlx_loop(fdf->mlx.ptr);
}

void UI(fdf_t *fdf)
{
    int y;

    y = CONTROLPOSY + 10;
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 150, y += 30, rgb(169, 169, 169), "Controls Instruction");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "W A S D for move");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Z and C for zoom");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "R and F for Z mod");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Up and Down for X axis rotate");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Left and Right for Y axis rotate");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Q and E for Z axis rotate");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Press G for reset");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Mouse scroll for zoom");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Mouse Right click for move to position");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Mouse drag and Drop for move");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Mouse Left Click hold and Scroll for Z mod");
    mlx_string_put(fdf->mlx.ptr, fdf->mlx.window, CONTROLPOSX + 15, y += 30, TEXTCOLOR, "Click Button for change Projection");
}
