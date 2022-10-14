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
	glColor3f(0.0, 0.0, 0.0);

	glLoadIdentity();

	glTranslatef(0.0, 0.0, -15.0);

    //Cylinder Body
	glPushMatrix();
	glScalef(1.0, 2.3, 1.0);
    glTranslatef(0, 1.5, 0);
    glRotatef(90, 1, 0, 0);
    glColor3f(1, 0, 0);
	glutWireCylinder(2, 4, 20, 5); // Cylinder Body.
    glPopMatrix();
	/*glPushMatrix();
	glScalef(1.0, 1.2, 1.0);
    glTranslatef(0, 1.1, 0);
    glRotatef(90, 1, 0, 0);
    glColor3f(1, 0, 1);
	glutWireCylinder(2.05, 4, 20, 5); // Cylinder Body Sticker.
    glPopMatrix();
    glPushMatrix();
    glScalef(1.0, -0.5, 1.0);
    glTranslatef(0, 4.5, 0);
    glRotatef(90, 1, 0, 0);
    glColor3f(0.5, 0.5, 0.5);
	glutWireCylinder(2.06, 4, 20, 5); // Cylinder Body Sticker 2.
	*/ glPopMatrix();

    //Sphere & Cylinder Body Head
    glPushMatrix();
    glTranslatef(0, 3.2, 0);
	glScalef(1.0, -0.6, 1.0);
    glRotatef(90, 1, 0, 0);
    glColor3f(1, 0, 0);
	glutWireSphere(2, 25, 10); // Sphere Body Head
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 4.5, 0);
	glScalef(1.0, -0.7, 1.0);
    glRotatef(90, 1, 0, 0);
    glColor3f(1, 0, 0);
	glutWireCylinder(0.5, 1, 10, 3); // Cylinder Body Head
    glPopMatrix();
	
    //Box Top Head 1
    glPushMatrix();
    glTranslatef(1.5, 6, 0);
    glRotatef(15, 0, 0, 1);
	glScalef(5.0, -0.2, 1.0);
    glColor3f(0, 0, 0);
	glutWireCube(1); //Box Top Head 1
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4.1, 6.5, 0);
    glRotatef(15, 0, 0, -1);
	glScalef(1.5, -0.2, 1.0);
    glColor3f(0, 0, 0);
	glutWireCube(1); //Box Top Head 1.2
    glPopMatrix();

    //Box Top Head 2
    glPushMatrix();
    glTranslatef(1.5, 5, 0);
    glRotatef(10, 0, 0, -1);
	glScalef(2.5, -0.2, 1.0);
    glColor3f(0, 0, 0);
	glutWireCube(1); //Box Top Head 2
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3, 4.6, 0);
    glRotatef(32, 0, 0, -1);
	glScalef(1.5, -0.2, 1.0);
    glColor3f(0, 0, 0);
	glutWireCube(1); //Box Top Head 2.2
    glPopMatrix();

	//Cylinder Hose
	glPushMatrix();
    glTranslatef(-1.5, 5.2, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
    glColor3f(0.5, 0.5, 0.5);
	glutWireCylinder(0.7, 1, 10, 3); // Cylinder Ring 1
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-1.5, 5.2, 0);
	glScalef(-0.8, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
    glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 1
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-3.0, 4.9, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glRotatef(45, 0, 1, 0);
    glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 2
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-3.4, 4.4, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glRotatef(20, 0, 1, 0);
    glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 3
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-3.4, 3.8, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 4
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-3.4, 3.2, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 5
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-3.4, 2.6, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 6
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-3.1, 2.2, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glRotatef(-20, 0, 1, 0);
	glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 7
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-2.9, 1.6, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glRotatef(-5, 0, 1, 0);
	glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 8
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-2.9, 1.1, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 9
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-2.9, 0.55, 0);
	glScalef(1.0, -0.5, 1.0);
    glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 10
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-2.9, 0.5, 0);
	glScalef(1.0, 4.0, 1.0);
    glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 0);
	glutWireCylinder(0.45, 1, 10, 3); // Cylinder Hose 11
    glPopMatrix();
	glPushMatrix();
    glTranslatef(-2.9, -5.2, 0);
	glScalef(1.0, 1.0, 1.0);
    glRotatef(90, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glColor3f(0, 0, 0);
	glutWireCone(1.0, 2, 10, 3); // Cone Tip
    glPopMatrix();

	glPushMatrix();
    glTranslatef(-2.9, -3.0, 0);
	glScalef(1.0, 1.0, 1.0);
    glRotatef(90, 1, 0, 0);
	glColor3f(0.5, 0.5, 0.5);
	glutWireCylinder(0.55, 1, 10, 3); // Cylinder Ring 2
    glPopMatrix();
	
    /*
	glTranslatef(0.0, 7.0, 0.0);
	glutWireSphere(2.0, 10, 8); // Spherical head.
    */

	glFlush();
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
	glutCreateWindow("APAR(AlatPemadamApiRingan).cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
