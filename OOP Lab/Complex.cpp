#include <iostream>
using namespace std;

class Complex
{
    float real,imag;
    public:
            Complex()
            {
                real=0;
                imag=0;
            }
            Complex(float r,float i)
            {
                real=r;
                imag=i;
            }
            void accept()
            {
                    cout<<"\nEnter real and imaginary part : ";
                    cin>>real>>imag;
            }
            void display()
            {
                cout<<"\nThe complex number is "<<real<<"+"<<imag<<"i"<<endl;
            }
            friend Complex operator+(Complex c1,Complex c2);
            friend Complex operator-(Complex c1,Complex c2);
            Complex operator*(Complex c2);
            Complex operator/(Complex c2);
};
Complex operator+(Complex c1, Complex c2)
{
    Complex c3;
    c3.real=c1.real+c2.real;
    c3.imag=c1.imag+c2.imag;
    return c3;
}
Complex operator-(Complex c1,Complex c2)
{
    Complex c3;
    c3.real=c1.real-c2.real;
    c3.imag=c1.imag-c2.imag;
    return c3;
}
Complex Complex::operator*(Complex c2)
{
    Complex c3;
    c3.real=(real*c2.real)-(imag*c2.imag);
    c3.imag=(real*c2.imag)-(imag*c2.real);
    return c3;
}
Complex Complex::operator/(Complex c2)
{
    Complex c3;
    c3.real=((real*c2.real)+(imag*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));
    c3.imag=(-(real*c2.imag)+(imag*c2.real))/((c2.real*c2.real)+(c2.imag*c2.imag));
    return c3;
}
int main()
{
    int ch;
    char ans;
    Complex c1,c2,c3;
    cout<<"\nFor Complex number 1 : \n";
    c1.accept();
    cout<<"\nFor Complex number 2 : \n";
    c2.accept();
    c1.display();
    c2.display();
    do
    {
        cout<<"\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: c3=c1+c2;
                    c3.display();
                    break;
            case 2: c3=c1-c2;
                    c3.display();
                    break;
            case 3: c3=c1*c2;
                    c3.display();
                    break;
            case 4: c3=c1/c2;
                    c3.display();
                    break;
            default:cout<<"\nWrong choice\n";
        }
        cout<<"\nMore? (Y/N)\n";
        cin>>ans;
    }while(ans=='Y'||ans=='y');
    return 0;
}
