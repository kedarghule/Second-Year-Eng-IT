#include<GL/glut.h>
float rt = 0.0;
void init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-50.0,50.0,-50.0,50.0,-50.0,50.0);
	glMatrixMode(GL_MODELVIEW);
}

/*float ballx = 0.0f;
float bally = -5.0f;
float ballz = 0.0f;
*/
void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0,rt,0.0);
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,1.0,1.0);
	glVertex3f(5.0,13.0,0.0);
	glVertex3f(10.0,8.0,0.0);
	glVertex3f(10.0,0.0,0.0);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(0.0,8.0,0.0);
	//glColor3f(0.0,1.0,0.0);
	glVertex3f(5.0,13.0,0.0);
	//glColor3f(0.0,0.0,1.0);
	//glVertex3f(-10.0,0.0,0.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex3f(10.0,0.0,0.0);
	glVertex3f(12.0,-4.0,0.0);
	glVertex3f(-2.0,-4.0,0.0);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(10.0,0.0,0.0);
	glEnd();
	
/*	glColor3f(1.0,1.0,0.0);
	glTranslatef(ballx,bally,ballz);
	glutSolidSphere(3.0,20,20);
	glTranslatef(ballx,bally+15.0,ballz);
	glutSolidSphere(3.0,20,20);
*/	
	rt+=0.5f;
	if(rt>50) rt=-40.0f;
	
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Flying Rocket");
	glutDisplayFunc(Draw);
	glutIdleFunc(Draw);
	
	init();
	
	glutMainLoop();
	return 0;
	}
