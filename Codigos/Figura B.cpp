#include <windows.h>
#include <iostream>
#include <GL/glut.h>

int figuraActual = 1;  
int numberOfFigures = 4;


void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void initial_Figure() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5); // Establece el sistema de coordenadas

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f); // Gris
    //Dibujar la cuadricula
    for (int y = -5; y <= 5; y++) {
        glVertex2f(-5.0f, y);
        glVertex2f(5.0f, y);
    }

    for (int x = -5; x <= 5; x++) {
        glVertex2f(x, -5.0f);
        glVertex2f(x, 5.0f);
    }

    

    //Dibujar la figura inicial
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco
    // A - B
    glVertex2f(-2.0f, -2.0f); 
    glVertex2f(-2.0f, 0.0f);

    // B - C
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(0.0f, 2.0f);

    // C - D
    glVertex2f(0.0f, 2.0f);
    glVertex2f(2.0f, 0.0f);

    // D - E
    glVertex2f(2.0f, 0.0f);
    glVertex2f(2.0f, -2.0f);
    

    // Conecta E con A
    glVertex2f(2.0f, -2.0f);
    glVertex2f(-2.0f, -2.0f);
    glEnd();

    //Dibujar punto central de la cuadricula
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glFlush();
}

void rotation_Figure() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5); // Establece el sistema de coordenadas

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f); // Gris
    //Dibujar la cuadricula
    for (int y = -5; y <= 5; y++) {
        glVertex2f(-5.0f, y);
        glVertex2f(5.0f, y);
    }

    for (int x = -5; x <= 5; x++) {
        glVertex2f(x, -5.0f);
        glVertex2f(x, 5.0f);
    }



    //Dibujar la figura inicial
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco
    // A - B
    glVertex2f(2.0f, -2.0f);
    glVertex2f(0.0f, -2.0f);

    // B - C
    glVertex2f(0.0f, -2.0f);
    glVertex2f(-2.0f, 0.0f);

    // C - D
    glVertex2f(-2.0f, 0.0f);
    glVertex2f(0.0f, 2.0f);

    // D - E
    glVertex2f(0.0f, 2.0f);
    glVertex2f(2.0f, 2.0f);


    // Conecta E con A
    glVertex2f(2.0f, 2.0f);
    glVertex2f(2.0f, -2.0f);
    glEnd();

    //Dibujar punto central de la cuadricula
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glFlush();
}

void traslation_Figure() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5); // Establece el sistema de coordenadas

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f); // Gris
    //Dibujar la cuadricula
    for (int y = -5; y <= 5; y++) {
        glVertex2f(-5.0f, y);
        glVertex2f(5.0f, y);
    }

    for (int x = -5; x <= 5; x++) {
        glVertex2f(x, -5.0f);
        glVertex2f(x, 5.0f);
    }



    //Dibujar la figura inicial
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco
    // A - B
    glVertex2f(4.0f, 0.0f);
    glVertex2f(2.0f, 0.0f);

    // B - C
    glVertex2f(2.0f, 0.0f);
    glVertex2f(0.0f, 2.0f);

    // C - D
    glVertex2f(0.0f, 2.0f);
    glVertex2f(2.0f, 4.0f);

    // D - E
    glVertex2f(2.0f, 4.0f);
    glVertex2f(4.0f, 4.0f);


    // Conecta E con A
    glVertex2f(4.0f, 4.0f);
    glVertex2f(4.0f, 0.0f);
    glEnd();

    //Dibujar punto central de la cuadricula
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glFlush();
}

void scaling_Figure() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5, 5, -5, 5); // Establece el sistema de coordenadas

    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f); // Gris
    //Dibujar la cuadricula
    for (int y = -5; y <= 5; y++) {
        glVertex2f(-5.0f, y);
        glVertex2f(5.0f, y);
    }

    for (int x = -5; x <= 5; x++) {
        glVertex2f(x, -5.0f);
        glVertex2f(x, 5.0f);
    }



    //Dibujar la figura inicial
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco
    // A - B
    glVertex2f(2.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);

    // B - C
    glVertex2f(1.0f, 0.0f);
    glVertex2f(0.0f, 2.0f);

    // C - D
    glVertex2f(0.0f, 2.0f);
    glVertex2f(1.0f, 4.0f);

    // D - E
    glVertex2f(1.0f, 4.0f);
    glVertex2f(2.0f, 4.0f);


    // Conecta E con A
    glVertex2f(2.0f, 4.0f);
    glVertex2f(2.0f, 0.0f);
    glEnd();

    //Dibujar punto central de la cuadricula
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();

    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Dibuja la figura actual
    if (figuraActual == 1) {
        initial_Figure();
    }
    else if (figuraActual == 2) {
        rotation_Figure();
    }
    else if (figuraActual == 3) {
        traslation_Figure();
    }
    else if (figuraActual == 4) {
        scaling_Figure();
    }

    glFlush();
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        // Cambia a la siguiente figura al hacer clic
        figuraActual++;
        if (figuraActual > numberOfFigures) {
            figuraActual = 1; // Vuelve a la primera figura si ya mostraste todas
        }
        glutPostRedisplay(); // Solicita redibujar
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Dibujar Figura");
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);
    initGL();
    
    // Registra la funci�n mouseClick para manejar los clics del mouse
    glutMouseFunc(mouseClick);

    glutMainLoop();
    return 0;
}
