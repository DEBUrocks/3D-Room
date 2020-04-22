@mainpage Results, Issues and Analysis
>Made By:

1. Debmeet Banerjee     2018A7PS0385H
2. Anirudh Sood         2018A7PS0673H
3. Sri Chand Gamguri    2017A7PS0272H

---
>Procedure:

To make this Project, I used the freeGLUT library: http://freeglut.sourceforge.net/, which I also used in Assignment 1. I worked on the Ubuntu terminal and used the gedit text editor. The scene consists of two rooms and some 3D objects placed in them. Some of the 3D objects are made using Blender and the rest are made using predefined functions for cube, torus, teapot etc. The objects have been transformed(scaled, translated, rotated) so that the overall scene looks good and sensible.

---

>Issues Faced While Doing the Assignment

1. Working with 3D was not easy in the beginning
    
    The 3D objects appeared in random places, their size was sometimes way too big and sometimes it was so small that it was not even visible and I thought that the code was not working. To make things right, I had to use transformations in a hit and trial manner in order to place the objects and make their size correct.
2. Confusion between Various Libraries Available

    There were many libraries like GLUT, GLEW, GLFW3, SDL2 which work with OpenGL and achieve similar effects(with some unique features as well)
3. Lighting was also confusing

    When I enabled lighting, my scene looked horrible, some objects were not visible at all, some were grayscaled, some were perfect. The scene was not looking realistic. I later understood about the ambient and diffuse settings and about vertex normals.
    But since my scene failed to look good with lighting, I removed it.

4. Understanding Blender tools

    As I was using Blender for the first time, I had no idea how to use it.
    I used the following Youtube tutorials to understand and make my 3D Objects.
    https://www.youtube.com/watch?v=D6sW1Cezi5o
    
    https://www.youtube.com/watch?v=mbs0nMeMvXw

    https://www.youtube.com/watch?v=sT984LP_kz4

    https://www.youtube.com/watch?v=y93V2nIDdaE

5. Using Vectors

    I was not comfortable in using vectors in C++. I learnt but I had used vectors in Java and found them to be similar.
    I took help from: https://docs.oracle.com/cd/E17802_01/j2se/javase/technologies/desktop/java3d/forDevelopers/j3dapi/javax/vecmath/Vector3f.html while making my Vector3f class in C++.

6. Camera
    
    Setting up the camera was easy but what was it capturing was difficult in the beginnig. I had confusions regarding the eye and centre vector, but eventually it was sorted out. Camera movement and rotation was easy. 

7. Push/Pop Matrix

    Understanding the function of Push and Pop Matrix commands was tricky. How the whole scene changes if we use it or do not use it was really interesting.

8. Importing Blender .obj Files

    This was by far the most difficult thing to do. Majority of my assingment time was spent on this. I had absolutely no idea about how to proceed in this situation. I made 4-5 attempts, some gave segmentation faults, some were running but not producing any output and the others did not even compile. Someone  suggested the use ASSIMP library but I did not have enough time to go ahead with that. 
    In the end, I made my own .obj parser using hints from some online tutorials and came up with an inefficient but working code. My program, takes a .obj file as input and outputs the vertices in groups of 3 which can be rendered using GL_TRIANGLES mode. This resulted in around 25,000 lines of code. It is not efficient, but it works perfectly and was mh last resort.

---

>Other Places from where I took Help:

1. https://nehe.gamedev.net/
2. http://www.opengl-tutorial.org/
3. https://learnopengl.com/

---

>Compiling and Running

First of all you need to install GLUT: In the linux terminal run the following command:

    sudo apt-get install freeglut3-dev

Compiling the Project is very easy. Go to the Directory where the main.cpp file is located. Open a Terminal in there. Enter the following command-
    
    g++ main.cpp objects.cpp blenderObjects.cpp -lglut -lGL -lGLU
After this , a file called a.out will appear in the same directory.
Now run the project using:

    ./a.out

After this, a Window will open in which the project will run. The scene will open in Front View. You can Interact with the scene using the keyboard. The terminal will look like this:

![https://github.com/DEBUrocks/3D-Scene/blob/master/Terminal.png](https://github.com/DEBUrocks/3D-Scene/blob/master/Terminal.png "Terminal")

You can use the above mentioned keys to get the desired effect.

Front View:

![https://github.com/DEBUrocks/3D-Scene/blob/master/FV.png](https://github.com/DEBUrocks/3D-Scene/blob/master/FV.png "Front View")

Top View:

![https://github.com/DEBUrocks/3D-Scene/blob/master/TV.png](https://github.com/DEBUrocks/3D-Scene/blob/master/TV.png "Top View")

Left View: 

![ https://github.com/DEBUrocks/3D-Scene/blob/master/LV.png ](https://github.com/DEBUrocks/3D-Scene/blob/master/LV.png "Left View")

Right View:

![https://github.com/DEBUrocks/3D-Scene/blob/master/RV.png](https://github.com/DEBUrocks/3D-Scene/blob/master/RV.png "Right View")

Zoomed In View:

![https://github.com/DEBUrocks/3D-Scene/blob/master/Zoomed.png](https://github.com/DEBUrocks/3D-Scene/blob/master/Zoomed.png "Zoomed View")

At an angle View:

![https://github.com/DEBUrocks/3D-Scene/blob/master/Angle.png](https://github.com/DEBUrocks/3D-Scene/blob/master/Angle.png "Angled View")

---

Overall it was a good learning experience

Hope you Like our Project!!



