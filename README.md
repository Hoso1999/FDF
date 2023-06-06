# FDF
This project is about creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges).
Project Overview:
The aim of this project is to develop a simple 3D wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges) that allows users to interact with the model through various features such as zoom, move, rotate, change projection, and apply a linear gradient to lines. The wireframe model will be represented in a single projection, and each point will be assigned a specific color. Additionally, the project will incorporate mouse and keyboard controls to enhance user experience and navigation.

Project Features:

1. 3D Wireframe Model Representation: Implement a basic wireframe model using lines and points to represent a 3D object. The model will be displayed in a single projection (e.g., orthographic, perspective).
2. Zoom: Allow users to zoom in and out of the wireframe model to examine it more closely or view it from a wider perspective. Implement controls to adjust the zoom level accordingly.
3. Move: Enable users to move the wireframe model within the viewing window. Users should be able to translate the model along the X, Y, and Z axes to change its position within the viewport.
4. Rotate: Implement rotation functionality to enable users to spin the wireframe model around different axes. Users should be able to rotate the model horizontally and vertically to view it from different angles.
5. Change Projection: Provide users with the ability to switch between different projections to observe the wireframe model from various perspectives. Offer options such as orthographic, perspective, isometric, etc., and implement controls for seamless projection switching.
6. Linear Gradient for Lines: Enhance the wireframe model's aesthetics by incorporating a linear gradient for the lines. This feature will apply a gradual color transition along the length of each line, giving the model a visually appealing appearance.
7. Mouse and Keyboard Controls: Implement intuitive mouse and keyboard controls to facilitate user interaction. Users should be able to navigate the wireframe model using mouse movements and employ keyboard shortcuts for various features, such as zoom, rotate, and projection change.
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



