#include <windows.h>
#include <math.h>
#include <GL/glut.h>

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15, 15, -15, 15);  // Establece el sistema de coordenadas

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f); // Gris
    for (int y = -15; y <= 15; y++) {
        glVertex2f(-15.0f, y);
        glVertex2f(15.0f, y);
    }

    for (int x = -15; x <= 15; x++) {
        glVertex2f(x, -15.0f);
        glVertex2f(x, 15.0f);
    }

    // Remarcar la cuadrícula (-10,0 / 10,0) en rojo
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex2f(-15.0f, 0.0f);
    glVertex2f(15.0f, 0.0f);

    // Remarcar la cuadrícula (0, -10 / 0, 10) en rojo
    glVertex2f(0.0f, -15.0f);
    glVertex2f(0.0f, 15.0f);
    glEnd();


    /*
    //Dibuja la recta que pasa por los puntos (10,1) y (2,6) - GLUT
    glColor3f(1.0f, 1.0f, 1.0f); // Blanco
    glBegin(GL_LINES);
    glVertex2f(10, 1);
    glVertex2f(2, 6);
    */

    
    
    //Dibuja la recta que pasa por los puntos(10, 1) y(2, 6)  - ALGORITMO DDA
    glColor3f(1.0f, 1.0f, 1.0f); // Blanco
    glBegin(GL_LINES); // Inicia el dibujo de líneas
    int x1 = 10;
    int y1 = 1;
    int x2 = 2;
    int y2 = 6;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = dx > dy ? dx : dy;
    float xIncrement = (float)(x2 - x1) / steps;
    float yIncrement = (float)(y2 - y1) / steps;
    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        glVertex2f(x, y); // Agrega un punto a la línea
        x += xIncrement;
        y += yIncrement;
    }
    glEnd(); 
    
    
    /*
    // Dibuja la circunferencia con centro en el origen y radio 12 - METODO DE PUNTOS DISCRETOS
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159265358979323846 / 180;
        float x = 12.0f * cos(angle);
        float y = 12.0f * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    */

    /*
    //Mejora al de puntos discretos
    // Dibuja la circunferencia con centro en el origen y radio 12 - ALGORITMO DE BRESENHAM
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glBegin(GL_LINES);

    int radio = 12;
    int numSegmentos = 100;  // Mayor resolución
    float incrementoAngular = 360.0f / numSegmentos;

    for (int i = 0; i < numSegmentos; i++) {
        float angulo1 = i * incrementoAngular;
        float angulo2 = (i + 1) * incrementoAngular;
        float x1 = radio * cos(angulo1 * 3.14159265358979323846 / 180);
        float y1 = radio * sin(angulo1 * 3.14159265358979323846 / 180);
        float x2 = radio * cos(angulo2 * 3.14159265358979323846 / 180);
        float y2 = radio * sin(angulo2 * 3.14159265358979323846 / 180);

        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }

    glEnd();
    */


    // Dibuja la circunferencia con centro en el origen y radio 12 - ALGORITMO DE BRESENHAM
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glBegin(GL_LINES);

    int radio = 12;
    int posX = 0, posY = radio;
    int p = 3 - 2 * radio;
    while (posX <= posY) {
        // Octante 1
        glVertex2f(posX, posY);
        // Octante 2
        glVertex2f(posY, posX);
        // Octante 3
        glVertex2f(-posY, posX);
        // Octante 4
        glVertex2f(-posX, posY);
        // Octante 5
        glVertex2f(-posX, -posY);
        // Octante 6
        glVertex2f(-posY, -posX);
        // Octante 7
        glVertex2f(posY, -posX);
        // Octante 8
        glVertex2f(posX, -posY);

        if (p < 0) {
            p = p + 4 * posX + 6;
        }
        else {
            p = p + 4 * (posX - posY) + 10;
            posY--;
        }
        posX++;
    }

    glEnd();

    


    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Recta en Cuadrícula y Circunferencia");
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
