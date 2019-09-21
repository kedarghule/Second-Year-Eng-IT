#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

int ax,ay,len1,len2,ang,sx,sy,tx,ty;
float a[4][3],b[3][3],c[4][3];

void display(float a[4][3])
{
	int i;
	glColor3f(1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0;i<4;i++)
	{
		glBegin(GL_LINES);
			glVertex2i(a[i][0],a[i][1]);
    			glVertex2i(a[(i+1)%4][0],a[(i+1)%4][1]);
		glEnd();
		glFlush();
	}
}
void rotate(float b[3][3],int ang)
{
	int i,j,s1;
	float rad=ang*3.14/180;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
	}
	b[0][0]=b[1][1]=cos(rad);
	b[0][1]=sin(rad);
        b[1][0]=-sin(rad);
}
void multiply(float a[4][3],float b[3][3],float c[4][3])
{
	int i,j,k;
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
		{
			c[i][j]=0;
			for(k=0;k<3;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
}
void scale(float b[3][3],int sx,int sy)
{
    	int i,j,s1;
     	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
	}
	b[0][0]=sx;
	b[1][1]=sy;	
}
void translate(float b[3][3],int tx,int ty)
{
    	int i,j,s1;
     	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
	}
	b[2][0]=tx;
	b[2][1]=ty;	
}
void shear(float b[3][3],int sx,int sy)
{
   	int i,j,s1;
    	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
	}
	b[0][1]=sy;
	b[1][0]=sx;
}
void reflect(float b[3][3])
{
   	int i,j,s1;
    	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
	}
	b[0][0]=-1;
	b[1][1]=-1;
}
void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	gluOrtho2D(0,640,0,480);
	glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc,char** argv)
{
	int bx,by,cx,cy,dx,dy,ch;
	printf("\n Enter Vertex of rhombus : ");
	scanf("%d%d",&ax,&ay);
	printf("\n Enter length of diagonal 1 : ");
	scanf("%d",&len1);
	printf("\n Enter length of diagonal 2 : ");
	scanf("%d",&len2);
	bx=ax+len1/2;
	by=ay-len2/2;
	cx=ax+len1;
	cy=ay;
	dx=ax+len1/2;
	dy=ay+len2/2;
	
	a[0][0]=ax; a[0][1]=ay; a[0][2]=1;
        a[1][0]=bx; a[1][1]=by; a[1][2]=1;
        a[2][0]=cx; a[2][1]=cy; a[2][2]=1; 
	a[3][0]=dx; a[3][1]=dy; a[3][2]=1; 
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("2D TRANSFORMATIONS");

	init();
	display(a);
	
	while(1)
	{
		printf("\n1.Rotation\n2.Scaling\n3.Translation\n4.Shearing\n5.Reflection about origin\n6.Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\n Enter angle of rotation: ");
				scanf("%d",&ang);
         			rotate(b,ang);
				multiply(a,b,c);
				display(c);
              			break;
			case 2: printf("\n Enter scaling ratio: ");
				scanf("%d%d",&sx,&sy);
				scale(b,sx,sy);
				multiply(a,b,c);
				display(c);
				break;
			case 3:	printf("\n Enter translation ratio: ");
				scanf("%d%d",&tx,&ty);
				translate(b,tx,ty);
				multiply(a,b,c);
        			display(c);
				break;
	    		case 4: printf("\n Enter shear ratio: ");
				scanf("%d%d",&sx,&sy);
				shear(b,sx,sy);
				multiply(a,b,c);
        			display(c);
				break;
			case 5: reflect(b);
				multiply(a,b,c);
				display(c);
				break;
			case 6: exit(0);
		}
	}
	glFlush();
	glutMainLoop();
	return 0;
}
