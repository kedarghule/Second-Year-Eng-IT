#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <stdio.h>
int first=0;
double x,y,xx1, yy1, xx2, yy2;
void plot(double xx1, double yy1, double xx2, double yy2)
{
	double dx = abs(xx2-xx1);
	double dy = abs(yy2-yy1);
	double len = (dy>=dx) ? dy : dx;
	double xinc = (xx2-xx1)/len;
	double yinc = (yy2-yy1)/len;
	 x=xx1;
	 y=yy1;
	int i=0;
	do
	{
  		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
        	glFlush();
		x=x+xinc;
		y=y+yinc;
		i++;
	} while(i<=len);
}
void display()
{
    glColor3f(1.0,0.0,1.0); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
	//plot(xx1, yy1, xx2, yy2);
glColor3f(0.0,1.0,0.0);	
	plot(xx1, yy1, xx1, yy2);
	plot(xx1, yy2, xx2, yy2);
	plot(xx2, yy2, xx2, yy1);
	plot(xx2, yy1, xx1, yy1);
glColor3f(0.0,0.0,1.0);	
	plot(xx1, (yy1+yy2)/2, (xx1+xx2)/2, yy2);
	plot((xx1+xx2)/2, yy2, xx2, (yy1+yy2)/2);
	plot(xx2, (yy1+yy2)/2, (xx1+xx2)/2, yy1);
	plot((xx1+xx2)/2, yy1, xx1, (yy1+yy2)/2);
glColor3f(1.0,0.0,0.0);
	plot((3*xx1+xx2)/4, (3*yy1+yy2)/4,(xx1+3*xx2)/4, (3*yy1+yy2)/4); 
	plot((3*xx1+xx2)/4, (3*yy1+yy2)/4,(3*xx1+xx2)/4, (yy1+3*yy2)/4); 
	plot((3*xx1+xx2)/4, (yy1+3*yy2)/4,(xx1+3*xx2)/4, (yy1+3*yy2)/4);
	plot((xx1+3*xx2)/4, (yy1+3*yy2)/4,(xx1+3*xx2)/4, (3*yy1+yy2)/4);
glFlush();
}

void mouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		switch(first)
		{
			case 0:
				xx1=x;
				yy1=768-y;
				first=1;
				break;
			case 1:
				xx2=x;
				yy2=768-y;
				display();
				first=0;
				break;		
		}	
	}
	glFlush();
}
 void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    gluOrtho2D(0.0,1366.0,0.0,768.0);
      glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char** argv)    
{
    glutInit(&argc, argv); 
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);                   
           
    glutInitWindowSize(1366,768);	
    glutInitWindowPosition(0,0);
    glutCreateWindow("dda with mouse "); 
    init();  
    glutMouseFunc(mouse); 
    glFlush();
    glutMainLoop();           
    return 0;
}
