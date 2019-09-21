#include <iostream>

using namespace std;
class exceptions
{
    double a,b;
    public:
            void accept()
            {
                cout<<"\nEnter 2 numbers \n";
                cin>>a>>b;
            }
            float divide()
            {
                try
                {
                    if(b==0)
                        throw (b);
                    cout<<"\nDivision is = "<<a/b<<endl;
                }
                catch(float p)
                {
                    cout<<"\nDivide by zero exception\n";
                }
            }
};
int main()
{
    exceptions E;
    E.accept();
    E.divide();
};
