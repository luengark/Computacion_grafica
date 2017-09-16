//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************García	Rosales Luis Enrique			******//
//*************											******//
//************************************************************//

/*Teclas del brazo:
Hombro : R/r
Codo : F/f
Mano : V/v
Falange proximal del pulgar : T/t
Falange distal del pulgar : G/g
Falange proximal del índice : Y/y
Falange media del índice : H/h
Falange distal del índice : N/n
Falange proximal del medio : U/u
Falange media del medio : J/j
Falange distal del medio : M/m
Falange proximal del anular : I/i
Falange media del anular : K/k
Falange distal del anular : O/o
Falange proximal del meñique : Z/z
Falange media del meñique : X/x 
Falange distal del meñique : C/c
*/
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro = 90.0;
float angCodo = 0.0f;
float angMano = 0.0f;
float angPulgar1 = 0.0;
float angPulgar2 = 0.0f;
float angIndice1 = 0.0f;
float angIndice2 = 0.0f;
float angIndice3 = 0.0f;
float angMedio1 = 0.0f;
float angMedio2 = 0.0f;
float angMedio3 = 0.0f;
float angAnular1 = 0.0f;
float angAnular2 = 0.0f;
float angAnular3 = 0.0f;
float angMenique1 = 0.0f;
float angMenique2 = 0.0f;
float angMenique3 = 0.0f;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
		//Poner Código Aquí.
	
	glPushMatrix();
		glScalef(3.0, 3.0, 1.0);
		glColor3f(1.0, 0.0, 0.0);
		prisma();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 1.75, 0.0);
		glScalef(0.5, 0.5, 1.0);
		glColor3f(0.0, 1.0, 0.0);
		prisma();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 2.5, 0.0);
		glColor3f(0.0, 0.0, 1.0);
		prisma();
	glPopMatrix();

	/*glPushMatrix();
		glTranslatef(3.0, 1.0, 0.0);
		glScalef(3.0, 1.0, 1.0);
		glColor3f(0.34, 0.65, 0.0);
		prisma();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(5.5, 1.0, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 1.0, 0.34);
		prisma();
	glPopMatrix();*/

	glPushMatrix();
		glTranslatef(2.0, 1.0, 0.0);
		glRotatef(angHombro, 0.0, 0.0, 1.0);
		glScalef(2.0f, 2.0f, 1.0f);
		//hombro
		glPushMatrix();
			glScalef(0.5f, 0.5f, 1.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			prisma();
		glPopMatrix();
		//bíceps
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glScalef(0.5, 1.0, 1.0);
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		//codo
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angCodo, 1.0, 0.0, 0.0);
		glPushMatrix();
			glScalef(0.5, 0.5, 1.0);
			glColor3f(0.0, 0.0, 1.0);
			prisma();
		glPopMatrix();
		//antebrazo
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
		glPopMatrix();
		//mano
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angMano, 1.0, 0.0, 0.0);
		glPushMatrix();
			glColor3f(0.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		//pulgar
		glPushMatrix();
			glTranslatef(0.25, 0.0, 0.0);
			glRotatef(angPulgar1, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.2f, 0.1f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.2, 0.1, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();
		//índice
		glPushMatrix();
			glTranslatef(0.20, -0.25, 0.0);
			glRotatef(angIndice1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.2f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angIndice2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angIndice3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.2f, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//medio
		glPushMatrix();
			glTranslatef(0.075, -0.25, 0.0);
			glRotatef(angMedio1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.3f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.15, 0.0);
			glRotatef(angMedio2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.1, 0.3, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.15, 0.0);
			glRotatef(angMedio3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.3f, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//Anular
		glPushMatrix();
			glTranslatef(-0.05, -0.25, 0.0);
			glRotatef(angAnular1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.2f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angAnular2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angAnular3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.2f, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//Meñique
		glPushMatrix();
			glTranslatef(-0.175, -0.25, 0.0);
			glRotatef(angMenique1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.1f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angMenique2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.1, 0.1, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angMenique3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.1f, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-3.0, 1.0, 0.0);
		glScalef(3.0, 1.0, 1.0);
		glColor3f(0.0, 0.5, 0.0);
		prisma();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-5.5, 1.0, 0.0);
		glScalef(2.0, 2.0, 1.0);
		glColor3f(1.0, 0.0, 1.0);
		prisma();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.75, -5.0, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(0.0, 0.65, 0.09);
		prisma();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.75, -10.0, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(1.0, 0.98, 0.54);
		prisma();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.75, -5.0, 0.0);
		glScalef(1.0, 7.0, 1.0);
		glColor3f(0.5, 0.5, 0.5);
		prisma();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(1.75, -10.0, 0.0);
		glScalef(3.0, 3.0, 1.0);
		glColor3f(0.0, 0.54, 0.23);
		prisma();
	glPopMatrix();

	/*
	//Brazo detallado
	glPushMatrix();
		//hombro
		glRotatef(angHombro, 0.0, 0.0, 1.0);
		glPushMatrix();
			glScalef(0.5f, 0.5f, 1.0f);
			glColor3f(0.0f, 1.0f, 0.0f);
			prisma();
		glPopMatrix();
		//bíceps
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glScalef(0.5, 1.0, 1.0);
			glColor3f(1.0, 0.0, 0.0);
			prisma();
		glPopMatrix();
		//codo
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angCodo, 0.0, 0.0, 1.0);
		glPushMatrix();
			glScalef(0.5, 0.5, 1.0);
			glColor3f(0.0, 0.0, 1.0);
			prisma();
		glPopMatrix();
		//antebrazo
		glTranslatef(0.0, -0.75, 0.0);
		glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glScalef(0.5, 1.0, 1.0);
			prisma();
		glPopMatrix();
		//mano
		glTranslatef(0.0, -0.75, 0.0);
		glRotatef(angMano, 1.0, 0.0, 0.0);
		glPushMatrix();
			glColor3f(0.0, 1.0, 1.0);
			glScalef(0.5, 0.5, 1.0);
			prisma();
		glPopMatrix();
		//pulgar
		glPushMatrix();
			glTranslatef(0.25, 0.0, 0.0);
			glRotatef(angPulgar1, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.2f, 0.1f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.1, 0.0, 0.0);
			glRotatef(angPulgar2, 0.0, 0.0, 1.0);
			glTranslatef(0.1, 0.0, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.2, 0.1, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();
		//índice
		glPushMatrix();
			glTranslatef(0.20, -0.25, 0.0);
			glRotatef(angIndice1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.2f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angIndice2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angIndice3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.2f, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//medio
		glPushMatrix();
			glTranslatef(0.075, -0.25, 0.0);
			glRotatef(angMedio1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.3f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.15, 0.0);
			glRotatef(angMedio2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.1, 0.3, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.15, 0.0);
			glRotatef(angMedio3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.15, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.3f, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//Anular
		glPushMatrix();
			glTranslatef(-0.05, -0.25, 0.0);
			glRotatef(angAnular1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.2f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angAnular2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.1, 0.2, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.1, 0.0);
			glRotatef(angAnular3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.1, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.2f, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();

		//Meñique
		glPushMatrix();
			glTranslatef(-0.175, -0.25, 0.0);
			glRotatef(angMenique1, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.1f, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angMenique2, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);
			glPushMatrix();
				glColor3f(0.3, 0.6, 1.0);
				glScalef(0.1, 0.1, 1.0);
				prisma();
			glPopMatrix();
			glTranslatef(0.0, -0.05, 0.0);
			glRotatef(angMenique3, 1.0, 0.0, 0.0);
			glTranslatef(0.0, -0.05, 0.0);

			glPushMatrix();
				glColor3f(0.3, 0.5, 0.0);
				glScalef(0.1f, 0.1f, 1.0);
				prisma();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
	*/	
  											
	glutSwapBuffers ( );
  // Swap The Buffers
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

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		//Manipulación de brazo
		case 'r':
			if (angHombro < 180.0)
			angHombro += 0.5f;
			break;
		case 'R':
			if (angHombro > 0.0)
			angHombro -= 0.5f;
			break;
		case 'f':
			if (angCodo < 0.0)
			angCodo += 0.5f;
			break;
		case 'F':
			if (angCodo > -160.0)
			angCodo -= 0.5f;
			break;
		case 'v':
			if (angMano < 70.0)
			angMano += 0.5f;
			break;
		case 'V':
			if (angMano > -70.0)
			angMano -= 0.5f;
			break;
		case 't':
			if (angPulgar1 < 0.0)
			angPulgar1 += 0.5f;
			break;
		case 'T':
			if (angPulgar1 > -80.0)
			angPulgar1 -= 0.5f;
			break;
		case 'g':
			if (angPulgar2 < 0.0)
			angPulgar2 += 0.5f;
			break;
		case 'G':
			if (angPulgar2 > -90.0)
			angPulgar2 -= 0.5f;
			break;
		case 'y':
			if (angIndice1 < 0.0)
			angIndice1 += 0.5f;
			break;
		case 'Y':
			if (angIndice1 > -70.0)
			angIndice1 -= 0.5f;
			break;
		case 'h':
			if (angIndice2 < 0.0)
			angIndice2 += 0.5f;
			break;
		case 'H':
			if (angIndice2 > -70.0)
			angIndice2 -= 0.5f;
			break;
		case 'n':
			if (angIndice3 < 0.0)
			angIndice3 += 0.5f;
			break;
		case 'N':
			if (angIndice3 > -60.0)
			angIndice3 -= 0.5f;
			break;
		case 'u':
			if (angMedio1 < 0.0)
			angMedio1 += 0.5f;
			break;
		case 'U':
			if (angMedio1 > -70.0)
			angMedio1 -= 0.5f;
			break;
		case 'j':
			if (angMedio2 < 0.0)
			angMedio2 += 0.5f;
			break;
		case 'J':
			if (angMedio2 > -70.0)
			angMedio2 -= 0.5f;
			break;
		case 'm':
			if (angMedio3 < 0.0)
			angMedio3 += 0.5f;
			break;
		case 'M':
			if (angMedio3 > -60.0)
			angMedio3 -= 0.5f;
			break;
		case 'i':
			if (angAnular1 < 0.0)
			angAnular1 += 0.5f;
			break;
		case 'I':
			if (angAnular1 > -70.0)
			angAnular1 -= 0.5f;
			break;
		case 'k':
			if (angAnular2 < 0.0)
			angAnular2 += 0.5f;
			break;
		case 'K':
			if (angAnular2 > -70.0)
			angAnular2 -= 0.5f;
			break;
		case 'o':
			if (angAnular3 < 0.0)
			angAnular3 += 0.5f;
			break;
		case 'O':
			if (angAnular3 > -60.0)
			angAnular3 -= 0.5f;
			break;
		case 'z':
			if (angMenique1 < 0.0)
			angMenique1 += 0.5f;
			break;
		case 'Z':
			if (angMenique1 > -70.0)
			angMenique1 -= 0.5f;
			break;
		case 'x':
			if (angMenique2 < 0.0)
			angMenique2 += 0.5f;
			break;
		case 'X':
			if (angMenique2 > -70.0)
			angMenique2 -= 0.5f;
			break;
		case 'c':
			if (angMenique3 < 0.0)
			angMenique3 += 0.5f;
			break;
		case 'C':
			if (angMenique3 > -60.0)
			angMenique3 -= 0.5f;
			break;
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}