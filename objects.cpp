#include <GL/gl.h>
#include <GL/glut.h>
#include "objects.h"
#include "blenderObjects.h"
//drawing a wall with given thickness
void drawWall(double thickness)
{
	glPushMatrix();
	glTranslated(0.5, thickness / 2, 0.5);
	glScaled(1.0, thickness, 1.0);
	glColor3f(1, 1, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}
//drawing 1 leg of the table with given thickness and lengh
void drawTableLeg(double thick, double len)
{
	glPushMatrix();
	glTranslated(0, len / 2, 0);
	glScaled(thick, len, thick);
	glutSolidCube(1.0);
	glPopMatrix();
}
//drawing table top and 4 legs using appropriate passed parameters
void drawTable(double topWid, double topThick, double legThick, double legLen)
{
	glPushMatrix();
	glTranslated(0, legLen, 0);
	glScaled(topWid, topThick, topWid);
	glColor3f(1, 0, 0);
	glutSolidCube(1.0);
	glPopMatrix();
	double dist = 0.95 * topWid / 2.0 - legThick / 2.0;
	glPushMatrix();
	glTranslated(dist, 0, dist);
	drawTableLeg(legThick, legLen);
	glTranslated(0, 0, -2 * dist);
	drawTableLeg(legThick, legLen);
	glTranslated(-2 * dist, 0, 2 * dist);
	drawTableLeg(legThick, legLen);
	glTranslated(0, 0, -2 * dist);
	drawTableLeg(legThick, legLen);
	glPopMatrix();
}
//drawing the chair back, seat and legs
void drawChair()
{
	glPushMatrix();
	// chair back start
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslated(-0.25, 1.03, -0.1);
	glScaled(0.8, 1.1, 0.08);
	glutSolidCube(1);
	glPopMatrix();
	// chair back end
	// chair seat start
	glPushMatrix();
	glTranslated(-0.25, 0.5, 0.25);
	glScaled(0.8, 0.08, 0.8);
	glutSolidCube(1);
	glPopMatrix();
	// chair seat end
	// chair legs start
	glPushMatrix();
	glScaled(0.1, 1, 0.1);
	glPushMatrix();
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-5, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-5, 0, 5);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, 5);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	// chair legs end
	glPopMatrix();
}
//drawing the lamp
void drawLamp()
{
	glPushMatrix();
	// lamp body start
	glPushMatrix();
	glColor3f(0.6, 0.3, 0.1);
	glScaled(0.35, 20, 0.35);
	glutSolidCube(1);
	glPopMatrix();
	// lamp body end
	// lamp base start
	glPushMatrix();
	glColor3f(0, 0.3, 0.5);
	glTranslated(0, -10, 0);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.9, 1, 20, 20);
	glPopMatrix();
	// lamp base end
	// lamp top start
	glPushMatrix();
	glColor3f(0, 0.8, 0.5);
	glTranslated(0, 12, 0);
	glRotated(90, 1, 0, 0);
	gluCylinder(gluNewQuadric(), 1, 2, 5, 20, 20);
	glPopMatrix();
	// lamp top end
	glPopMatrix();
}
//drawing the entire first room by calling appropriate draw calls
void drawFirstRoom()
{
	glPushMatrix();
	glTranslated(0, 0, 0);
	// chair start
	glPushMatrix();
	glTranslated(0.25, 0.13, 0.7);
	glScaled(0.15, 0.15, 0.15);
	glRotated(45, 0, 1, 0);
	drawChair();
	glPopMatrix();
	// chair end
	// lamp start
	glPushMatrix();
	glTranslated(0.75, 0.35, 0.1);
	glScaled(0.05, 0.03, 0.05);
	drawLamp();
	glPopMatrix();
	// lamp end
	// clock start
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(0.4, 0.55, 0);
	glScaled(0.15, 0.15, 0.15);
	//    clock hand start
	glPushMatrix();
	glTranslated(0.5, 0.1, 0);
	glScaled(1, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	//    clock hand end
	glutSolidTorus(0.1, 1, 25, 25);
	glPopMatrix();
	// clock end
	// teapot start
	glPushMatrix();
	glScaled(0.8, 0.8, 0.8);
	glTranslated(0.4, 0, 0.4);
	glPushMatrix();
	glTranslated(0.5, 0.38, 0.3);
	glRotated(15, 0, 1, 0);
	glScaled(1, 1.3, 1);
	glColor3f(0.7, 0.7, 0.7);
	glutSolidTeapot(0.08);
	glPopMatrix();
	// teapot end
	glPushMatrix();
	glTranslated(0.4, 0.0, 0.4);
	glColor3f(1, 1, 0.7);
	drawTable(0.6, 0.02, 0.02, 0.3);//Drawing the Table
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	// walls start
	drawWall(0.02);
	glPushMatrix();
	glRotated(90, 0, 0, 1.0);
	drawWall(0.02);
	glPopMatrix();
	glPushMatrix();
	glRotated(-90, 1.0, 0.0, 0.0);
	drawWall(0.02);
	glPopMatrix();
	drawGlass();//Drawing the Blender Object
	drawBottle();//Drawing the Blender Object
	// walls end
}
//drawing the closet
void drawCloset()
{
	glPushMatrix();
	// blue line start
	glPushMatrix();
	glColor3f(0.5, 1, 0.8);
	glTranslated(0, 0.7, 0.5);
	glScaled(1, 0.1, 0.05);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5, 1, 0.8);
	glTranslated(0, 0.9, 0.5);
	glScaled(1, 0.1, 0.05);
	glutSolidCube(1);
	glPopMatrix();
	// blue line end
	glScaled(1, 3, 1);
	glColor3f(0.6, 0.4, 0);
	glutSolidCube(1);
	glPopMatrix();
}
//drawing the bed
void drawBed()
{
	glPushMatrix();
	// bed support start
	glPushMatrix();
	glColor3f(0.2, 0.1, 0.1);
	glScaled(1, 1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	// bed support end
	// matress start
	glPushMatrix();
	glTranslated(0, -0.25, 2);
	glPushMatrix();
	glColor3f(0.9, 0, 1);
	glScaled(1, 0.5, 4);
	glutSolidCube(1);
	glPopMatrix();
	// mattress end
	glPopMatrix();
	glPopMatrix();
}
// drawing the bed side table
void drawCounter()
{
	glPushMatrix();
	// table top start
	glPushMatrix();
	glColor3f(0.6, 1, 0.7);
	glTranslated(0, 0.5, 0);
	glScaled(1.2, 0.1, 1.2);
	glutSolidCube(1);
	glPopMatrix();
	// table top end
	// table middle start
	glPushMatrix();
	glColor3f(0.8, 0.4, 0);
	glutSolidCube(1);
	glPopMatrix();
	// table middle end
	// table legs start
	glPushMatrix();
	glColor3f(0.8, 0.4, 0);
	glTranslated(0.3, -0.5, -0.3);
	glScaled(0.2, 1, 0.2);
	glPushMatrix();
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-3, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-3, 0, 3);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0, 3);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	// table legs end
	glPopMatrix();
}
// drawing the second room by calling other draw functions
void drawSecondRoom()
{
	glPushMatrix();
	glTranslated(0, 0, 0);
	// bed side table start
	glPushMatrix();
	glTranslated(-0.15, 0.17, 0.8);
	glScaled(0.15, 0.15, 0.15);
	drawCounter();
	glPopMatrix();
	// bed side table end
	// bed start
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	glScaled(0.25, 0.25, 0.15);
	glTranslated(2, 0.6, 0.3);
	drawBed();
	glPopMatrix();
	// bed end
	// closet start
	glPushMatrix();
	glTranslated(-0.3, 0.3, 0.1);
	glScaled(0.2, 0.2, 0.2);
	drawCloset();
	glPopMatrix();
	// closet  end
	glPopMatrix();
	glPushMatrix();
	// back wall start
	glPushMatrix();
	glRotated(-90, 1.0, 0.0, 0.0);
	glRotated(-90, 0.0, 1.0, 0.0);
	drawWall(0.02);
	glPopMatrix();
	// back wall end
	// floor start
	glPushMatrix();
	glTranslated(-1.0, 0.0, 0.0);
	drawWall(0.02);
	glPopMatrix();
	//floor end
	glPopMatrix();
	drawPot();//Drawing the Blender Object
	drawFlower();//Drawing the Blender Object
}

