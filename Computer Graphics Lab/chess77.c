#include<stdio.h>
 #include<stdio.h>
#include<GL/glut.h>
#include<math.h>
int count=0;
float mat[10][3]={{350,350,1},{350,470,1},{380,350,1},{380,470,1},{410,350,1},{410,470,1},{440,350,1},{440,470,1},{470,350,1},{470,470,1}};
float mat1[10][3]={{350,350,1},{470,350,1},{350,380,1},{470,380,1},{350,410,1},{470,410,1},{350,440,1},{470,440,1},{350,470,1},{470,470,1} };

float trans[3][3],res[10][3];
float x;

typedef struct pixel
{
GLubyte red,green,blue;
}pixel;
pixel c, boundary,f;

void Init()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1,1,1,0);
  //glColor3f(1,1,0);
  glClear(GL_COLOR_BUFFER_BIT );
  glColor3ub(0,0,0);
 gluOrtho2D(0 ,800 ,0 ,800);
 
}
void mult(float mat[10][3],float trans[3][3],float res[10][3])
{
 int i,j,k;
 for(i=0;i<10;i++)
 {
  for(j=0;j<3;j++)
  {
   res[i][j]=0;
   for(k=0;k<3;k++)
   {
    res[i][j]+=mat[i][k]*trans[k][j];
   }
  }
 }
}

 
void dda(int X1,int Y1,int X2,int Y2)
{
  float x,y,dx,dy,length;
	int i;
	
	dx=abs(X2-X1);
	dy=abs(Y2-Y1);
	if(dx>=dy)
		length=dx;
	else
		length=dy;
	dx=(X2-X1)/length;
	dy=(Y2-Y1)/length;
	x=X1; 
	y=Y1;
	i=1;
	while(i<=length)
	{
	
		glBegin (GL_POINTS);  
               glVertex2i (x, y);  
               glEnd ();  
                glFlush (); 
		x=x+dx;
		y=y+dy;
		i=i+1;
	}
}

void initmat()
{
 
 trans[0][0]=cos(x);
 trans[0][1]=sin(x);
 trans[1][0]=-sin(x);
 trans[1][1]=cos(x);

 trans[2][1]=trans[2][0]=trans[0][2]=trans[1][2]=0;
 
 trans[2][2]=1;
 
}

void drawcb(float mat[10][3])
{
int i;

 
  for(i=0;i<10;i=i+2)
  {
  	dda(mat[i][0],mat[i][1],mat[i+1][0],mat[i+1][1]);
 
  }
 
 
}

void boundary_fill(int x,int y,pixel b,pixel f)
{
	glReadPixels(x,y,1,1,GL_RGB,GL_UNSIGNED_BYTE,&c);
	if(c.red!=b.red && c.green!=b.green && c.blue!=b.blue && c.red!=f.red && c.green!=f.green && c.blue!=f.blue)
	{
		glColor3ub(f.red,f.green,f.blue);
		glBegin(GL_POINTS);
  		glVertex2i(x,y);
  		glEnd();
		boundary_fill(x+1,y,b,f);
		boundary_fill(x-1,y,b,f);
		boundary_fill(x,y+1,b,f);
		boundary_fill(x,y-1,b,f);
		
 		glFlush();
	}
}

void mouse(int btn,int state,int x,int y)
{
  int ymax=glutGet(GLUT_WINDOW_HEIGHT);

  if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
  {
 	boundary_fill(x,ymax-y,boundary,f);
  }
}

void draw()
{
	initmat();
        drawcb(mat);
        drawcb(mat1);
	mult(mat,trans,res);
        drawcb(res);
        mult(mat1,trans,res);
	drawcb(res);
}
int main(int argc,char ** argv)
{
  int p;
   
  f.red = 0.0;
  f.green = 0.0;
  f.blue = 0.0;

  boundary.red = 100;
  boundary.green = 100;
  boundary.blue = 100;

  printf("ENTER THE ANGLE FOR ROTATION : ");
  scanf("%d",&p);
 
  x=(p*3.14)/180;

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(800,800);
  glutCreateWindow("chess board");
  Init();

  glutDisplayFunc(draw);	
  glutMouseFunc(mouse);												
  glutMainLoop();
  return 0;
}

