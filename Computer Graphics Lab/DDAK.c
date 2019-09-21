#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
int xx1,xx2,yy1,yy2;

void DDALine(int X1, int Y1,int X2,int Y2)
{
	float x,y,dx,dy,xinc,yinc,len;
	dx=abs(X2-X1);
	dy=abs(Y2-Y1);
	if(dx>=dy)
		len=dx;
	else
		len=dy;
	xinc=(X2-X1)/len;
	yinc=(Y2-Y1)/len;
	x=X1;
	y=Y1;
	int i;i=0;
	do
	{
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();
		x=x+xinc;
		y=y+yinc;
		i=i+1;
	}while(i<=len);
	glFlush();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
		DDALine(xx1,yy1,xx1,yy2);
		DDALine(xx1,yy2,xx2,yy2);
		DDALine(xx2,yy2,xx2,yy1);
		DDALine(xx2,yy1,xx1,yy1);
	glColor3f(0.0,1.0,0.0);
		DDALine(xx1,(yy1+yy2)/2,(xx1+xx2)/2,yy2);
		DDALine((xx1+xx2)/2,yy2,xx2,(yy1+yy2)/2);
		DDALine(xx2,(yy1+yy2)/2,(xx1+xx2)/2,yy1);
		DDALine((xx1+xx2)/2,yy1,xx1,(yy1+yy2)/2);
	glColor3f(0.0,0.0,1.0);
        	DDALine((xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2);
       	 	DDALine((xx2+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2,(xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2);
        	DDALine((xx2+(xx1+xx2)/2)/2,(yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2);
        	DDALine((xx1+(xx1+xx2)/2)/2, (yy1+(yy1+yy2)/2)/2,(xx1+(xx1+xx2)/2)/2,(yy2+(yy1+yy2)/2)/2);    
}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(0.0,640.0,0.0,480.0);
	glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char** argv)
{
	printf("\nEnter vertex 1 : ");
	scanf("%d%d",&xx1,&yy1);
	printf("\nEnter vertex 2 : ");
	scanf("%d%d",&xx2,&yy2);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DDA Line using Keyboard");
	init();
	glutDisplayFunc(display);
	glFlush();
	glutMainLoop();
	return 0;
}
