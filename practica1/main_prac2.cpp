//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	García Rosales Luis Enrique				******//
//*************											******//
//************************************************************//
#include "Main.h"
#include <math.h>

#define PI 3.14159265

void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aquí codigo a dibujar
	
	//G
	glColor3f(0.34, 0.32, 1.0);

	glBegin(GL_LINE_LOOP);
	glVertex3f(-3.0, 3.0, -1.0);
	glVertex3f(-3.0, -3.0, -1.0);
	glVertex3f(3.0, -3.0, -1.0);
	glVertex3f(3.0, 0.0, -1.0);
	glVertex3f(0.0, 0.0, -1.0);
	glVertex3f(0.0, -1.0, -1.0);
	glVertex3f(2.0, -1.0, -1.0);
	glVertex3f(2.0, -2.0, -1.0);
	glVertex3f(-2.0, -2.0, -1.0);
	glVertex3f(-2.0, 2.0, -1.0);
	glVertex3f(3.0, 2.0, -1.0);
	glVertex3f(3.0, 3.0, -1.0);
	glEnd();

	//E
	glColor3f(0.2, 0.9, 0.9);

	glBegin(GL_POLYGON);
	glVertex3f(-4.0, 3.0, -1.0);
	glVertex3f(-4.0, 2.0, -1.0);
	glVertex3f(-9.0, 2.0, -1.0);
	glVertex3f(-10.0, 3.0, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-10.0, 3.0, -1.0);
	glVertex3f(-9.0, 2.0, -1.0);
	glVertex3f(-9.0, -2.0, -1.0);
	glVertex3f(-10.0, -3.0, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-9.0, 0.5, -1.0);
	glVertex3f(-9.0, -0.5, -1.0);
	glVertex3f(-4.0, -0.5, -1.0);
	glVertex3f(-4.0, 0.5, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.0, -3.0, -1.0);
	glVertex3f(-10.0, -3.0, -1.0);
	glVertex3f(-9.0, -2.0, -1.0);
	glVertex3f(-4.0, -2.0, -1.0);
	glEnd();

	//L
	glColor3f(0.54, 0.12, 0.12);

	glBegin(GL_LINE_LOOP);
	glVertex3f(-16.0, 3.0, -1.0);
	glVertex3f(-17.0, 3.0, -1.0);
	glVertex3f(-17.0, -3.0, -1.0);
	glVertex3f(-11.0, -3.0, -1.0);
	glVertex3f(-11.0, -2.0, -1.0);
	glVertex3f(-16.0, -2.0, -1.0);
	glEnd();
	
	//R
	glColor3f(1.0, 0.23, 0.65);

	glBegin(GL_POLYGON);
	glVertex3f(10.0, 3.0, -1.0);
	glVertex3f(4.0, 3.0, -1.0);
	glVertex3f(5.0, 2.0, -1.0);
	glVertex3f(9.0, 2.0, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(10.0, 3.0, -1.0);
	glVertex3f(9.0, 2.0, -1.0);
	glVertex3f(9.0, 1.0, -1.0);
	glVertex3f(10.0, 0.0, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(9.0, 1.0, -1.0);
	glVertex3f(5.0, 1.0, -1.0);
	glVertex3f(5.0, 0.0, -1.0);
	glVertex3f(10.0, 0.0, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.0, 3.0, -1.0);
	glVertex3f(4.0, -3.0, -1.0);
	glVertex3f(5.0, -3.0, -1.0);
	glVertex3f(5.0, 2.0, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6.5, 0.0, -1.0);
	glVertex3f(5.0, 0.0, -1.0);
	glVertex3f(8.5, -3.0, -1.0);
	glVertex3f(10.0, -3.0, -1.0);
	glEnd();

	//Estrella

	glColor3f(0.85, 0.65, 0.12);

	glBegin(GL_POLYGON);
	glVertex3f(cos(54*PI/180)+14.0, sin(54 * PI / 180), -1.0);
	glVertex3f(cos(126 * PI / 180)+14.0, sin(126 * PI / 180), -1.0);
	glVertex3f(cos(198 * PI / 180)+14.0, sin(198 * PI / 180), -1.0);
	glVertex3f(cos(270 * PI / 180)+14.0, sin(270 * PI / 180), -1.0);
	glVertex3f(cos(342 * PI / 180)+14, sin(342 * PI / 180), -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(cos(54 * PI / 180) + 14.0, sin(54 * PI / 180), -1.0);
	glVertex3f(cos(126 * PI / 180) + 14.0, sin(126 * PI / 180), -1.0);
	glVertex3f(3 * cos(90 * PI / 180) + 14.0, 3 * sin(90 * PI / 180), -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(cos(198 * PI / 180) + 14.0, sin(198 * PI / 180), -1.0);
	glVertex3f(cos(126 * PI / 180) + 14.0, sin(126 * PI / 180), -1.0);
	glVertex3f(3 * cos(162 * PI / 180) + 14.0, 3 * sin(162 * PI / 180), -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(cos(198 * PI / 180) + 14.0, sin(198 * PI / 180), -1.0);
	glVertex3f(cos(270 * PI / 180) + 14.0, sin(270 * PI / 180), -1.0);
	glVertex3f(3 * cos(234 * PI / 180) + 14.0, 3 * sin(234 * PI / 180), -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(cos(270 * PI / 180) + 14.0, sin(270 * PI / 180), -1.0);
	glVertex3f(cos(342 * PI / 180) + 14.0, sin(342 * PI / 180), -1.0);
	glVertex3f(3 * cos(306 * PI / 180) + 14.0, 3 * sin(306 * PI / 180), -1.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(cos(54 * PI / 180) + 14.0, sin(54 * PI / 180), -1.0);
	glVertex3f(cos(342 * PI / 180) + 14.0, sin(342 * PI / 180), -1.0);
	glVertex3f(3 * cos(18 * PI / 180) + 14.0, 3 * sin(18 * PI / 180), -1.0);
	glEnd();



	glFlush();

	
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-18,18,-18,18,0.1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

