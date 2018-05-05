#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600
#define MAX 1000

int FPS = 200;
int direction = 0; // 0 means right and 1 means left
int index = 0, cloudIndex = 0, cloud1 = 200, cloud2 = 600, cloud3 = 900;

void shipTimer(int) {

    glutPostRedisplay();
    glutTimerFunc(MAX/FPS, shipTimer, 0);
    
    // For ship
    if(direction == 0) { // right

        index ++;
        
        if(index > WINDOW_WIDTH) {
            index = - 400;
        }
    
    } else if(direction == 1) {
        
        index --;
        
        if(index < -400) {
            index = WINDOW_WIDTH;
        }
    }
    
    // For Cloud
    if(direction == 0) { // left 

        cloud1 -= 2;
        cloud2 -= 2;
        cloud3 -= 2;
        
        if(cloud1 < -120) {
        
            cloud1 = WINDOW_WIDTH + 120;
            
        }else if(cloud2 < -120) {
        
            cloud2 = WINDOW_WIDTH + 120;
            
        }else if(cloud3 < -120) {
        
            cloud3 = WINDOW_WIDTH + 120;
        }
    
    } else if(direction == 1) { // right
        
        cloud1 += 2;
        cloud2 += 2;
        cloud3 += 2;
        
        if(cloud1 > WINDOW_WIDTH + 120) {
        
            cloud1 = -120;
            
        }else if(cloud2 > WINDOW_WIDTH + 120) {
        
            cloud2 = -120;
            
        }else if(cloud3 > WINDOW_WIDTH + 120) {
        
            cloud3 = -120;
        }
        
    }
}

void drawCloud(int centerX, int centerY, int rX, int rY) {

    float x1, y1;
    
    glBegin(GL_TRIANGLE_FAN);
    for (float ang=1.0f; ang<=360.0f; ang+=1)
    {
        x1 = centerX + sin(ang) * rX;
        y1 = centerY + cos(ang) * rY;
        glVertex2f(x1, y1);
    }
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Draw water
    glColor3d(0, 1, 1);
    glBegin(GL_POLYGON);
        glVertex2d(0, 0);
        glVertex2d(0, 150);
        glVertex2d(WINDOW_WIDTH, 150);
        glVertex2d(WINDOW_WIDTH, 0);
    glEnd();
    
    // Draw ship
    glColor3d(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2d(120 + index, 100);
        glVertex2d(0 + index, 180);
        glVertex2d(420 + index, 180);
        glVertex2d(300 + index, 100);
    glEnd();
    
    glColor3d(0.63, 0.63, 0.63);
    glBegin(GL_POLYGON);
        glVertex2d(70 + index, 180);
        glVertex2d(70 + index, 200);
        glVertex2d(350 + index, 200);
        glVertex2d(350 + index, 180);
    glEnd();
    
    glColor3d(0.38, 0.39, 1);
    glBegin(GL_POLYGON);
        glVertex2d(90 + index, 200);
        glVertex2d(90 + index, 260);
        glVertex2d(330 + index, 260);
        glVertex2d(330 + index, 200);
    glEnd();
    
    // Ship window
    glColor3d(0.87, 0.99, 1);
    glBegin(GL_POLYGON);
        glVertex2d(100 + index, 210);
        glVertex2d(100 + index, 250);
        glVertex2d(150 + index, 250);
        glVertex2d(150 + index, 210);
    glEnd();
    
    glColor3d(0.87, 0.87, 1);
    glBegin(GL_POLYGON);
        glVertex2d(170 + index, 260);
        glVertex2d(170 + index, 280);
        glVertex2d(200 + index, 280);
        glVertex2d(200 + index, 260);
    glEnd();
    
    glBegin(GL_POLYGON);
        glVertex2d(220 + index, 260);
        glVertex2d(220 + index, 290);
        glVertex2d(250 + index, 290);
        glVertex2d(250 + index, 260);
    glEnd();
    
    glBegin(GL_POLYGON);
        glVertex2d(270 + index, 260);
        glVertex2d(270 + index, 300);
        glVertex2d(300 + index, 300);
        glVertex2d(300 + index, 260);
    glEnd();
    
    // Draw Cloud
    drawCloud(cloud1, 530, 100, 50); // CenterX, CenterY, radiusX, radiusY
    drawCloud(cloud1 + 100, 550, 80, 50);
    drawCloud(cloud1 + 30, 480, 80, 50);

    drawCloud(cloud2, 500, 150, 50);
    drawCloud(cloud2 - 100, 550, 80, 60);
    drawCloud(cloud2 + 30, 530, 80, 60);
    
    drawCloud(cloud3, 530, 100, 60);
    drawCloud(cloud3 + 100, 500, 100, 60);

    glutSwapBuffers();
}

void catchKey(int key, int x, int y) {

    switch(key) {
        
        case GLUT_KEY_LEFT: 
            direction = 1;
            break;
            
        case GLUT_KEY_RIGHT:
            direction = 0;
            break;
            
        case GLUT_KEY_UP:
        
            if(FPS < MAX) {
                FPS += 50;
            }
            break;
            
        case GLUT_KEY_DOWN:
        
            if(FPS > 100) {
                FPS -= 50;
            }
            break;
    }
    
    glutPostRedisplay();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Cruising Ship");

    glutDisplayFunc(display);
    
    glutTimerFunc(0, shipTimer, 0);
    glutSpecialFunc(catchKey);

    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    glClearColor(1,1,1,1);
    
    glutMainLoop();

    return EXIT_SUCCESS;
}
