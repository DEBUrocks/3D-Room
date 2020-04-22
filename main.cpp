#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "camera.h"
#include "objects.h"
///Window close if ESC pressed
#define GLUT_KEY_ESCAPE 27
///Clears Linux Terminal
#define clear() printf("\033[H\033[J")
using namespace std;
///This is the main Display Function
///It sets up the Camera
///It Clears Color and Depth buffer bits
///Draws Room 1 and 2 by calling respective functions
void Display()
{
	clear();
	cout << "Press I to Zoom-in ; O to Zoom-out\n";
	cout << "Press D to Pan-left; A to Pan-right\n";
	cout << "Press W to Elevate ; S to Descend\n\n";
	cout << "Press L-arrow  and   R-arrow  to Rotate about X \n";
	cout << "Press Up-arrow and Down-arrow to Rotate about Y \n\n";
	cout << "Press F for Front view\n";
	cout << "Press T for Top   view\n";
	cout << "Press R for Right view\n";
	cout << "Press L for Left  view\n";
	setupCamera();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	///The glPushMatrix() and glPopMartix() Help us keep individual objects independent of each other.
	///If some transformations are enclosed within a Push and a Pop matrix, then it only affects
	///the function called between them. Basically the OpenGL works as a State Machine and the Pop
	///helps it go back to the original state as it was, hence the transformations after Push will
	///not affect any other object draw called later
	glPushMatrix();
	drawFirstRoom();
	glPopMatrix();
	glPushMatrix();
	drawSecondRoom();
	glPopMatrix();
	glFlush();
}
///This Function uses the W,A,S,D,I,O,L,R,T,F,ESC keys
///and performs some action on the Scene like Zoom/Pan
void onKeyPress(unsigned char key, int x, int y)
{
	float d = 0.1;
	switch (key)
	{
	case 'w':
		camera.moveY(d);
		break;
	case 's':
		camera.moveY(-d);
		break;
	case 'a':
		camera.moveX(d);
		break;
	case 'd':
		camera.moveX(-d);
		break;
	case 'i': //zoom in
		camera.moveZ(d);
		break;
	case 'o': //zoom out
		camera.moveZ(-d);
		break;
	case 'r':
		setRightView();
		break;
	case 'l':
		setLeftView();
		break;
	case 't':
		setTopView();
		break;
	case 'f':
		setFrontView();
		break;
	case GLUT_KEY_ESCAPE:
		exit(EXIT_SUCCESS);
	}
	glutPostRedisplay();
}
///This Function uses the Arrow keys to Rotate Scene
///about X or Y axis
void onSpecialKey(int key, int x, int y)
{
	float a = 3.0;
	switch (key)
	{
	case GLUT_KEY_UP:
		camera.rotateX(a);
		break;
	case GLUT_KEY_DOWN:
		camera.rotateX(-a);
		break;
	case GLUT_KEY_LEFT:
		camera.rotateY(a);
		break;
	case GLUT_KEY_RIGHT:
		camera.rotateY(-a);
		break;
	}
	///glutMainLoop() will execute repeatedly
	glutPostRedisplay();
}
///The Main Function
int main(int argc, char **argv)
{
	///Initializing FreeGlut
	glutInit(&argc, argv);
	///Setting window size
	glutInitWindowSize(1280, 720);
	///Scene will start with front view
	setFrontView();
	///Creating&naming the window
	glutCreateWindow("Graphics Assignment 2");
	///This Will Draw the 2 rooms
	glutDisplayFunc(Display);
	///W,A,S,D,I,O meanings
	glutKeyboardFunc(onKeyPress);
	///Arrow Key Meanings
	glutSpecialFunc(onSpecialKey);
	///Mode=RGB,Single&Depth Bufer
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	///Background Color
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	///Enables Depth Test
	glEnable(GL_DEPTH_TEST);
	///The Main Loop
	glutMainLoop();
	return 0;
}

