# FDF
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
# Usage
```bash
    git clone https://github.com/Hoso1999/FDF.git && cd FDF && cmake .
```
You can specify build directory
```bash
    git clone https://github.com/Hoso1999/FDF.git && cd FDF && mkdir BUILD_DIR && cmake -B BUILD_DIR .
```
Build project
```bash
    make
```
## Run
```bash
    BUILD_DIR/build/fdf <map.fdf> [zoom] [z-mod] [--save]
```
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
