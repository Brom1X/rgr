#include "GL/freeglut.h"
#include <cmath>
#include <ctime>

clock_t curTime, startTime;


void renderScene(void);
void animateScene(int value);

struct Object
{
    float x = 0;
    float y = 0;
};

Object yoda, spaceship, mando;

void Yoda(Object yoda);
void Background();
void Spaceship(Object spaceship);
void Powerpoint();
void Mandalorian(Object mando);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutTimerFunc(1000 / 60, animateScene, 1);
    startTime = clock();
    glutMainLoop();
    return 0;
}


void renderScene(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    Background();

    Powerpoint();

    curTime = clock() - startTime;

    if (curTime > 1000 && curTime < 3800) {

        yoda.x += 0.006;
    }

    glPushMatrix();
    glScalef(0.5, 0.5, 0.5);
    Yoda(yoda);
    glPopMatrix();

    if (curTime > 4800 && curTime < 7800) {

        spaceship.y += 0.0015;
    }

    if (curTime > 8800 && curTime < 11800) {

        spaceship.x -= 0.03;
    }

    Spaceship(spaceship);

    if (curTime > 11800 && curTime < 15130) {

        mando.y -= 0.01;
    }

    glPushMatrix();
    glTranslatef(0, 2, 0);
    Mandalorian(mando);
    glPopMatrix();


    glutSwapBuffers();

}
void animateScene(int value) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, animateScene, 1);
}


void Yoda(Object yoda) {

    glTranslatef(yoda.x, yoda.y, 0);

    glBegin(GL_TRIANGLES);

    //body
    glColor3f(0.3, 0.1, 0.1);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.6, -0.3);
    // l uxo
    glColor3f(0.25, 0.6, 0.25);
    glVertex2f(0.1, 0.5);
    glVertex2f(0.2, 0.3);
    glVertex2f(0.3, 0.4);
    //r uxo
    glColor3f(0.25, 0.6, 0.25);
    glVertex2f(0.5, 0.4);
    glVertex2f(0.6, 0.3);
    glVertex2f(0.7, 0.5);
    //golova
    glColor3f(0.25, 0.6, 0.25);
    glVertex2f(0.1, 0.2);
    glVertex2f(0.4, 0.5);
    glVertex2f(0.7, 0.2);
    //r leg
    glColor3f(0.25, 0.6, 0.25);
    glVertex2f(0.8, -0.4);
    glVertex2f(0.6, -0.3);
    glVertex2f(0.6, -0.4);
    //l leg
    glColor3f(0.25, 0.6, 0.25);
    glVertex2f(0.0, -0.4);
    glVertex2f(0.2, -0.3);
    glVertex2f(0.2, -0.4);

    glEnd();


    glBegin(GL_QUADS);

    //l eye 
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(0.31, 0.36);
    glVertex2f(0.35, 0.36);
    glVertex2f(0.35, 0.4);
    glVertex2f(0.31, 0.4);
    //r eye 
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(0.42, 0.36);
    glVertex2f(0.46, 0.36);
    glVertex2f(0.46, 0.4);
    glVertex2f(0.42, 0.4);

    glEnd();

    glTranslatef(-yoda.x, -yoda.y, 0);

}
void Background() {

    glBegin(GL_QUADS);

    //Ground
    glColor3f(0.15, 0.15, 0.2);
    glVertex2f(-15, -0.2);
    glVertex2f(15, -0.2);
    glVertex2f(15, -5);
    glVertex2f(-15, -5);

    //Sky
    glColor3f(0.2, 0.2, 0.3);
    glVertex2f(-15, 5);
    glVertex2f(15, 5);
    glVertex2f(15, -0.2);
    glVertex2f(-15, -0.2);

    glEnd();

}
void Spaceship(Object spaceship) {

    glTranslatef(spaceship.x, spaceship.y, 0);

    glBegin(GL_TRIANGLES);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.8, 0);
    glVertex2f(-0.6, 0.2);
    glVertex2f(-0.6, -0.2);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.2, 0.2);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.2, -0.2);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.57, 0.1);
    glVertex2f(-0.23, 0.1);
    glVertex2f(-0.23, -0.1);
    glVertex2f(-0.57, -0.1);

    glEnd();

    glTranslatef(-spaceship.x, -spaceship.y, 0);

}
void Powerpoint() {

    glBegin(GL_QUADS);

    glColor3f(0.1, 0.6, 0.7);
    glVertex2f(0.7, 0.0);
    glVertex2f(0.75, 0.0);
    glVertex2f(0.75, -0.05);
    glVertex2f(0.7, -0.05);

    glEnd();

}
void Mandalorian(Object mando) {

    glTranslatef(mando.x, mando.y, 0);

    glBegin(GL_QUADS);

    //body
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.3, -0.2);
    glVertex2f(-0.5, -0.2);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.5, 0.0);
    glVertex2f(-0.3, 0.0);
    glVertex2f(-0.3, -0.02);
    glVertex2f(-0.5, -0.02);

    //legs
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.405, 0.0);
    glVertex2f(-0.395, 0.0);
    glVertex2f(-0.395, -0.2);
    glVertex2f(-0.405, -0.2);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.5, -0.18);
    glVertex2f(-0.3, -0.18);
    glVertex2f(-0.3, -0.2);
    glVertex2f(-0.5, -0.2);

    //arms

    //1
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-0.6, 0.2);
    glVertex2f(-0.5, 0.2);
    glVertex2f(-0.5, 0.0);
    glVertex2f(-0.6, 0.0);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.6, 0.02);
    glVertex2f(-0.5, 0.02);
    glVertex2f(-0.5, 0.0);
    glVertex2f(-0.6, 0.0);

    //2
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.2, 0.2);
    glVertex2f(-0.2, 0.0);
    glVertex2f(-0.3, 0.0);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.3, 0.02);
    glVertex2f(-0.2, 0.02);
    glVertex2f(-0.2, 0.0);
    glVertex2f(-0.3, 0.0);

    //head
    glColor3f(0.2, 0.2, 0.2);
    glVertex2f(-0.5, 0.36);
    glVertex2f(-0.3, 0.36);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.5, 0.2);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.415, 0.34);
    glVertex2f(-0.385, 0.34);
    glVertex2f(-0.385, 0.2);
    glVertex2f(-0.415, 0.2);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.47, 0.34);
    glVertex2f(-0.33, 0.34);
    glVertex2f(-0.33, 0.31);
    glVertex2f(-0.47, 0.31);

    //visor
    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.515, 0.46);
    glVertex2f(-0.5, 0.46);
    glVertex2f(-0.5, 0.33);
    glVertex2f(-0.515, 0.33);

    glColor3f(0.1, 0.1, 0.1);
    glVertex2f(-0.5, 0.46);
    glVertex2f(-0.48, 0.46);
    glVertex2f(-0.48, 0.44);
    glVertex2f(-0.5, 0.44);

    glEnd();

    glTranslatef(-mando.x, -mando.y, 0);

}