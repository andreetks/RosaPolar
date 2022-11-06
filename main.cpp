
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

GLdouble angulo=0;
GLint modelo=1;
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2 ;
GLfloat a=1.0,b=0.0,c=0.0;


void rosa_polar(int N, int M){

float ang,radio,a,x,y;
a=1;
glBegin(GL_LINE_STRIP);
for(ang=0.0;ang<8*M_PI;ang+=2*M_PI/180){
    radio = a * cos(N*ang/M);
    x = radio * cos(ang);
    y = radio * sin(ang);
    glVertex3f(x,y,0);
}
glEnd();
}

void rosa_cubica(){


   glutWireCube(2);

   glPushMatrix();
   glTranslatef(0.0,0.0,1.0);
   rosa_polar(1,3);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.0,0.0,-1.0);
   rosa_polar(1,3);
   glPopMatrix();

   glPushMatrix();
   glRotatef(90,1.0,0.0,0.0);
   glTranslatef(0.0,0.0,-1.0);
   rosa_polar(1,3);
   glPopMatrix();

   glPushMatrix();
   glRotatef(90,1.0,0.0,0.0);
   glTranslatef(0.0,0.0,1.0);
   rosa_polar(1,3);
   glPopMatrix();

   glPushMatrix();
   glRotatef(90,0.0,1.0,0.0);
   glTranslatef(0.0,0.0,-1.0);
   rosa_polar(1,3);
   glPopMatrix();

   glPushMatrix();
   glRotatef(90,0.0,1.0,0.0);
   glTranslatef(0.0,0.0,1.0);
   rosa_polar(1,3);
   glPopMatrix();



}

void iniciar(void)
{
 glClearColor (1.0, 1.0, 1.0, 0.0);
 glColor3f (1.0, 0.0, 0.0);
 glLineWidth(2.0);
 glShadeModel (GL_FLAT);
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glLoadIdentity();
 gluLookAt(0,0.0,5,0,0.0,4,0,1,0);
 glRotatef(theta[0],1.0,0.0,0.0);
 glRotatef(theta[1],0.0,1.0,0.0);
 glRotatef(theta[2],0.0,0.0,1.0);
 switch(modelo){
 case 1: glutWireCube(2); break;
 case 2: rosa_cubica();break;


 }
 glFlush();
 glutSwapBuffers();
}
void CubeSpin()
{
 theta[axis] += 0.5;
 if(theta[axis]>360) theta[axis] -= 360.0;
 display();
}
void myReshape(int w, int h)
{
 glViewport (0, 0, (GLsizei) w, (GLsizei) h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity ();
 gluPerspective(60.0, (GLfloat) w/(GLfloat) h,0.1, 30.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}



void menu_rotaciones(int opcion)
{
switch(opcion){
case 1: axis = 0; break;
case 2: axis = 1; break;
case 3: axis = 2; break;
case 4 : exit(0); break;
}
}

void menu_rosas(int opcion)
{
switch(opcion){
case 1: modelo = 2; break;
case 2: modelo = 1 ; break;
}
}

void menu_tipo_rosas(int opcion)
{
switch(opcion){
case 1: cout<<"opcion1"<<endl; break;
case 2: cout<<"opcion2"<<endl; break;
case 3: cout<<"opcion3"<<endl; break;
case 4: cout<<"opcion4"<<endl; break;
}
}

void menu_color(int opcion)
{
switch(opcion){
case 1: glColor3f (1.0, 0.0, 0.0); break;
case 2: glColor3f (0.0, 1.0, 0.0); break;
case 3: glColor3f (0.0, 0.0, 1.0); break;

}
}

void menu_grosor(int opcion){
switch (opcion){
case 1: cout<<"1"<<endl; break;
case 2: cout<<"2"<<endl; break;
case 3: cout<<"3"<<endl; break;
}
}

void menu_patron(int opcion){
switch (opcion){
case 1: cout<<"1"<<endl; break;
case 2: cout<<"2"<<endl; break;
}
}

void menu_modelos_alambricos(int opcion)
{
switch(opcion){
case 1: modelo=4; break;
case 3 : exit(0); break;
}
}
void menu_glut(int opcion)
{
switch(opcion){
case 1: modelo=1; break;
case 2: modelo=2; break;
case 3: modelo=3; break;
}
}


void menu_principal(int opcion)
{
 switch(opcion){
//case 1: int i=0;break;
case 4: exit( -1 );
}
}
int main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(500,500);
 glutCreateWindow("dasdasda");
 int submenu_rotaciones=glutCreateMenu(menu_rotaciones);
 glutAddMenuEntry("Eje X",1);
 glutAddMenuEntry("Eje Y",2);
 glutAddMenuEntry("Eje Z",3);
 int submenu_rosas=glutCreateMenu(menu_rosas);
 glutAddMenuEntry("Activado",1);
 glutAddMenuEntry("Desactivado",2);
 int submenu_tipo_rosas=glutCreateMenu(menu_tipo_rosas);
 glutAddMenuEntry("M=3 , N=7",1);
 glutAddMenuEntry("M=1 , N=5",2);
 glutAddMenuEntry("M=7 , N=9",3);
 glutAddMenuEntry("M=2 , N=8",4);
 int submenu_color=glutCreateMenu(menu_color);
 glutAddMenuEntry("Rojo",1);
 glutAddMenuEntry("Verde",2);
 glutAddMenuEntry("Azul",3);
 int submenu_grosor=glutCreateMenu(menu_grosor);
 glutAddMenuEntry("1",1);
 glutAddMenuEntry("2",2);
 glutAddMenuEntry("3",3);
 int submenu_patron=glutCreateMenu(menu_patron);
 glutAddMenuEntry("Opcion 1",1);
 glutAddMenuEntry("Opcion 2",2);


 int menu=glutCreateMenu(menu_principal);
 glutAddSubMenu("Rotaciones",submenu_rotaciones);
 glutAddSubMenu("Grafico de rosas",submenu_rosas);
 glutAddSubMenu("Tipo de rosas",submenu_tipo_rosas);
 glutAddSubMenu("Color",submenu_color);
 glutAddSubMenu("Grosor",submenu_grosor);
 glutAddSubMenu("Patron de Trazado",submenu_patron);
 glutAddMenuEntry("Esc",4);
 // usaremos el boton derecho del mouse
 glutAttachMenu(GLUT_RIGHT_BUTTON);
 iniciar();
 glutReshapeFunc(myReshape);
 glutDisplayFunc(display);
 glutIdleFunc(CubeSpin);
 glEnable(GL_DEPTH_TEST);
 glutMainLoop();

 return 0;
}
