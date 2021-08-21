#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.0);//dark-green
    glVertex2f(-0.50,0.0);
    glVertex2f(0.50,0.0);
    glVertex2f(0.50,0.30);
    glVertex2f(-0.80,0.30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);//white
    glVertex2f(-0.50,0.0);
    glVertex2f(0.50,0.0);
    glVertex2f(0.50,-0.30);
    glVertex2f(-0.50,-0.30);
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
    glVertex2f(-0.50,-0.30);
    glVertex2f(0.50,-0.30);
    glVertex2f(0.50,-0.60);
    glVertex2f(-0.80,-0.60);
    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
}

main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(500,200);
    glutInitWindowSize(900,700);

    glutCreateWindow("Flag");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();

    glutMainLoop();
}

