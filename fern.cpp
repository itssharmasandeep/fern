#include <string.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<bits/stdc++.h>
/* GLUT callback Handlers */

using namespace std;

void resize(int width, int height)
{
    if(width<=height)
        glViewport(0,(GLsizei) (height-width)/2,(GLsizei) width,(GLsizei) width);

    else
        glViewport((GLsizei) (width-height)/2,0,(GLsizei) height,(GLsizei) height);
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.5,2.75,10.5,0, -1.0, 1.0); // adjusted for suitable viewport

}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);        // clear display screen
    // declaration of variables
    int i;
    int numberOfPoints = 200000;
    double randomNumber,x,x0,y,y0;

    // initialization
    x0 = 0.0;
    y0 = 0.0;

    // Creating all points and plotting them
    for ( i = 0; i < numberOfPoints; i++ )
    {
        randomNumber = rand()%100; // getting random value from 0 to 99

        if ( randomNumber < 85 )
        {
            x =   0.85 * x0 + 0.04 * y0 + 0.0;
            y = - 0.04 * x0 + 0.85 * y0 + 1.6;
        }
        else if ( randomNumber < 92 )
        {
            x =   0.20 * x0 - 0.26 * y0 + 0.0;
            y =   0.23 * x0 + 0.22 * y0+ 1.6;
        }
        else if ( randomNumber < 99 )
        {
            x = - 0.15 * x0 + 0.28 * y0 + 0.0;
            y =   0.26 * x0 + 0.24 * y0 + 0.44;
        }
        else
        {
            x =   0.00 * x0 + 0.00 * y0 + 0.0;
            y =   0.00 * x0 + 0.16 * y0 + 0.0;
        }

        x0 = x;
        y0 = y;

        // plotting the point
        /**
        * using current x and y values it will make the graphics downwards as y = 0 at the top of the windows
        and increases as we go down. So I am using one logic to make it look like upwards
        * remove next line to see fern pointing downwards
        */
        y = y > 10.0 ? y - 5.0 : 10.0 - y;
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();
    }
    
    glFlush ();                           // clear buffer
}


void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :                       // esc key to exit
    case 'q':
        exit(0);
        break;
    }

    glutPostRedisplay();
}


/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (250, 250);                //window screen
    glutInitWindowPosition (100, 100);            //window position
    glutCreateWindow ("Program1");                //program title
    glClearColor ( 1.0, 1.0, 1.0, 1.0 ); // setting background color to white
    glColor3f ( 0.133, 0.545, 0.133 ); // setting graphics color to green
    init();
    glutDisplayFunc(display);                     //callback function for display
    glutReshapeFunc(resize);                      //callback for reshape
    glutKeyboardFunc(key);                        //callback function for keyboard
    glutMainLoop();                               //loop

    return EXIT_SUCCESS;
}
