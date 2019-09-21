/** Create a base class shape with 2 double type values and member functions to input the data and compute area for calculating area of figure. Derive 2 classes Triangle and Rectangle and make computeArea() as a virtual function and redfine this function in the derive class to suit their requirements. WAP that accepts the dimensions and displays area. **/
#include<iostream>
using namespace std;
class Shape
{
	protected:
			double a,b;
	public:
		  virtual void accept()
		  {
		  	cout<<"\nEnter the values of a and b\n";
		  	cin>>a>>b;
		  }
		  virtual void area()=0;
};
class Triangle:public Shape
{
	public:
		   void area()
		   {
		   	double ans;
		   	ans=0.5*a*b;
		   	cout<<"\nArea of triangle is = "<<ans;
		   }
};
class Rectangle:public Shape
{
	public:
		    void area()
		    {
		    	double ans;
		    	ans=a*b;
		    	cout<<"\nArea of rectangle is = "<<ans;
		    }
};
		   
int main()
{
	Shape *ptr;
	Triangle T; Rectangle R;
	int ch;
	do
	{
		cout<<"\nCompute area of\n1. Triangle\n2. Rectangle\n3. Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				     ptr=&T;
				     ptr->accept();
				     ptr->area();
				     break;
		 	case 2:
		 		     ptr=&R;
				     ptr->accept();
				     ptr->area();
				     break;
			case 3:
				     break;
			default: cout<<"\nWrong Choice!\n";
		}
	}while(ch!=3);
	return 0;
}		   
		   
		   
		   
