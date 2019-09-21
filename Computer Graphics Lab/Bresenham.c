#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int xx1,xx2,yy1,yy2;
int r;
void putpixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
void drawline(int X1,int Y1, int X2,int Y2)	
{
	float x,y,dx,dy,length,xinc,yinc;
	int i;
	
	dx=abs(X2-X1);
	dy=abs(Y2-Y1);
	if(dx>=dy)
		length=dx;
	else
		length=dy;
	xinc=(X2-X1)/length;
	yinc=(Y2-Y1)/length;
	x=X1;
	y=Y1;
	i=0;
	do
	{
	
                 glBegin(GL_POINTS);
	         glVertex2i(x,y);
                 glEnd();
                glFlush();
                 x=x+xinc;
		y=y+yinc;
		i=i+1;
	}while(i<=length);
	glFlush();

}

void drawtri()
{
	drawline(0,r,-sqrt(3)*r/2,-r/2);
	drawline(-sqrt(3)*r/2,-r/2,sqrt(3)*r/2,-r/2);
	drawline(sqrt(3)*r/2,-r/2,0,r);
}

void drawcircle(int r)
{
	float x=0,y=r;
	int d=3-2*r;
	do
	{
		putpixel(x,y);
                putpixel(y,x);
                putpixel(x,-y);
                putpixel(y,-x);
                putpixel(-x,-y);
                putpixel(-y,-x);
                putpixel(-x,y);
                putpixel(-y,x);
                if(d<0)
                {
                	x=x+1;
                	d=d+4*x+6;
                }
                else
                {
                	x=x+1;
                	y=y-1;
                	d=d+4*(x-y)+10;
                }
	}while(x<=y);
}

void display()
{
	
	glColor3f(1.0,0.0,0.0);
	drawcircle(r);
	glColor3f(0.0,1.0,0.0);
	drawtri();
	glColor3f(0.0,0.0,1.0);
	drawcircle(r/2);

}

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(-640.0,640.0,-480.0,480.0);
        glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc,char** argv)
{
	
    	printf("\n Enter radius : ");
        scanf("%d",&r);
    
            
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("DDA Line");
        
	init();
	glutDisplayFunc(display);
	glFlush();
	glutMainLoop();

	return 0;
	
}
