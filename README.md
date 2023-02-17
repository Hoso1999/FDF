# FDF
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
# Usage
```bash
    git clone https://github.com/Hoso1999/FDF.git && cd FDF && cmake . && make
```
You can specify build directory
```bash
    git clone https://github.com/Hoso1999/FDF.git && cd FDF && mkdir BUILD_DIR && cmake -B BUILD_DIR . && make -C BUILD_DIR
```
## Run
```bash
    BUILD_DIR/build/bin/fdf <map.fdf> [zoom] [z-mod] [--save]
```
You can save image using --save option<br />
Images will be save in resources/images folder
The coordinates of the landscape are stored in a .fdf file passed as a parameter to
your program
Here is an example
```bash
$>cat 42.fdf
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
$>
```
You can specify colors as example below
```bash
$>cat resources/maps/42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0 0  0  0  0  0
0  0 10,0xff 10,0xff  0  0 10,0xff 10,0xff  0  0  0 10,0xff 10,0xff 10,0xff 10,0xff 10,0xff  0  0  0
0  0 10,0xff 10,0xff  0  0 10,0xff 10,0xff  0  0  0  0  0  0  0 10,0xff 10,0xff  0  0
0  0 10,0xff 10,0xff  0  0 10,0xff 10,0xff  0  0  0  0  0  0  0 10,0xff 10,0xff  0  0
0  0 10,0xff 10,0xff 10,0xff 10,0xff 10,0xff 10,0xff  0  0  0  0 10,0xff 10,0xff 10,0xff 10,0xff  0  0  0
0  0  0 10,0xff 10,0xff 10,0xff 10,0xff 10,0xff  0  0  0 10,0xff 10,0xff  0  0  0  0  0  0
0  0  0  0  0  0 10,0xff 10,0xff  0  0  0 10,0xff 10,0xff  0  0  0  0  0  0
0  0  0  0  0  0 10,0xff 10,0xff  0  0  0 10,0xff 10,0xff 10,0xff 10,0xff 10,0xff 10,0xff  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
$>
```
Each number represents a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.
Should render a landscape similar to:

![42](https://user-images.githubusercontent.com/45395182/219730692-7f38b3ea-3c9d-4ce7-baf6-bb65d2bb65e4.jpeg)
Application has control instruction panel

![image](https://user-images.githubusercontent.com/45395182/219734968-08c300a3-c9ba-4972-8397-8d8ec519deca.png)

You can find example .fdf files in resources/maps folder



