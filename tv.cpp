#define _USE_MATH_DEFINES 

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 

static int isAnimate = 0; // Animated?
static int animationPeriod = 50; // Time interval between frames.
static float angle = 0.0; // Angle of rotation.

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	
	

	glLoadIdentity();

	// TV.
	glPushMatrix();
	glTranslatef(0.0, 1.0, -10.0);
	glRotatef(0, 0, 0, 0);
	glScalef(2.0, 1.0, 0.1);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutWireCube(4.0); // Literally the TV.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0, -1.1, -10.0);
	glRotatef(90, 1, 0, 0);
	glScalef(1.0, 1.0, 0.2);
	// glColor3f(0.5, 0.5, 0.5);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutWireCylinder(2, 1, 20, 4); // TV Ring Suspension.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-1.2, 1.8, -9.5);
	glRotatef(0, 0, 0, 0);
	glScalef(0.7, 0.4, 0.2);
	glColor3f(1.0, 0.0, 1.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutWireSphere(1, 10, 10); // Literally kerusakan TV-nya.
	glPopMatrix();

	// Meja.
	glPushMatrix();
	glTranslatef(0.0, -1.6, -10.0);
	glRotatef(0, 0, 0, 0);
	glScalef(2.2, 0.1, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutWireCube(4.0); // Board of the Table.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3, -2.8, -6.0);
	glRotatef(0, 0, 0, 0);
	glScalef(0.3, 3.0, 0.3);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutWireCube(1.0); // Leg Front Right.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3, -2.8, -6.0);
	glRotatef(0, 0, 0, 0);
	glScalef(0.3, 3.0, 0.3);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutWireCube(1.0); // Leg Front Left.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-3.65, -3, -11.0);
	glRotatef(0, 0, 0, 0);
	glScalef(0.3, 3.0, 0.3);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutWireCube(1.0); // Leg Back Right.
	glPopMatrix();
	glPushMatrix();
	glTranslatef(3.65, -3, -11.0);
	glRotatef(0, 0, 0, 0);
	glScalef(0.3, 3.0, 0.3);
	glRotatef(angle, 0.0, 1.0, 0.0);
	glutWireCube(1.0); // Leg Back Left.
	glPopMatrix();
	glutSwapBuffers();
	// glFlush();
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Routine to increase the rotation angle.
void increaseAngle(void)
{
	angle += 5.0;
	if (angle > 360.0) angle -= 360.0;
}

// Routine to animate with a recursive call made after animationPeriod msecs.
void animate(int value)
{
	if (isAnimate)
	{
		increaseAngle();

		glutPostRedisplay();
		glutTimerFunc(animationPeriod, animate, 1);
	}
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case ' ':
		if (isAnimate) isAnimate = 0;
		else
		{
			isAnimate = 1;
			animate(1);
		}
		break;
	default:
		break;
	}
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN) animationPeriod += 5;
	if (key == GLUT_KEY_UP)
		if (animationPeriod > 5) animationPeriod -= 5;
	glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	std::cout << "Interaction:" << std::endl;
	std::cout << "Press space to toggle between animation on and off." << std::endl
		<< "Press the up/down arrow keys to speed up/slow down animation." << std::endl;
}

// Main routine.
int main(int argc, char **argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("TV Muter.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
