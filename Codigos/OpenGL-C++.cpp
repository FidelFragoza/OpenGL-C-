/*#include <GL/freeglut.h>

void init(void)
{

    glClearColor(1.0, 1.0, 1.0, 0.0); // set window color to white
    glMatrixMode(GL_PROJECTION); // Set projection parameters
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);

}

void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.4, 0.2);
    glBegin(GL_LINES);
    glVertex2i(180, 15);
    glVertex2i(10, 145);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100); // Set top
    glutInitWindowSize(400, 300),
        glutCreateWindow("An Example OpenGL Program");

    init(); // Execute initialization procedure
    glutDisplayFunc(lineSegment); // Send graphics to display window
    glutMainLoop(); // Display everything and wait

}
*/