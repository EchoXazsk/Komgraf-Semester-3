/////////////////////////////////          
// box.cpp
//
// This program draws a wire box.
//
// Sumanta Guha.
/////////////////////////////////

#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h> 

static float X = 0.0;
static float Y = 0.0;
static float Z = -15.0;

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
///kaki kanan
    glPushMatrix();
    glColor3f(0.1f, 0.0f, 0.0f);
    glTranslatef(0.0, 0.0, -15.0);
    glTranslatef(3.0, 6.0, 0.0);
    glRotatef(60.0, 15.0, 1.0, 0.0);
    glScalef(1.0, 1.0, 1.0);
    //glRotatef(45.0, 1.0, -3.0, 1.0);
    glutSolidCylinder(0.7, 10.0, 10.0, 2.0);
    glPopMatrix();
//kaki Kiri
    glPushMatrix();
    glColor3f(0.1f, 0.0f, 0.0f);
    glTranslatef(0.0, 0.0, -15.0);
    glTranslatef(-3.0, 6.0, 0.0);
    glRotatef(60.0, 15.0, -1.0, 0.0);
    glScalef(1.0, 1.0, 1.0);
	glutSolidCylinder(0.7, 10.0, 10.0, 2.0);
	glPopMatrix();
//kaki Tengah
    glPushMatrix();
    glColor3f(0.1f, 0.0f, 0.0f);
    glTranslatef(0.0, 0.0, -15.0);
    glTranslatef(0.0, 6.0, 0.0);
    glRotatef(60, 1.0, 0.0, 0.0);
	glRotatef(-45, 0.0, 0.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCylinder(0.7, 10.0, 10.0, 2.0);
    glPopMatrix();
//Dudukan
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 1.0f);
    glTranslatef(0.0, 0.0, -15.0);
    glTranslatef(0.0, 8.0, 0.0);
    glRotatef(95, 1.0, 0.0, 0.0);
	//glRotatef(-45, 0.0, 0.0, 1.0);
    glScalef(1.0, 1.0, 1.0);
    glutSolidCylinder(4, 1, 10.0, 2.0);
    glPopMatrix();
  	glutSwapBuffers();
}

// Initialization routine.
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
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'a':
		X+=0.5;
		glutPostRedisplay();
		break;
	case 'd':
		X -= 0.5;
		glutPostRedisplay();
		break;
	case 's':
		Y -= 0.5;
		glutPostRedisplay();
		break;
	case 'w':
		Y += 0.5;
		glutPostRedisplay();
		break;
	case 'q':
		Z -= 0.5;
		glutPostRedisplay();
		break;
	case 'e':
		Z += 0.5;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Kursi.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
