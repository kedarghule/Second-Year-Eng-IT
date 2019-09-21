
#include<iostream>
using namespace std;

template<class T>
class matrix
{
   T m[10][10];
   int row,col;
   public:
             matrix(int a ,int b)
             {
                    row=a;col=b;
             }
             void accept();
             void display();
             matrix addition(matrix);
             matrix sub(matrix);
             matrix trans();
             matrix mul(matrix);
};

template<class T>void matrix<T>::accept()
{
       for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)
                cin>>m[i][j];
}
template<class T>void matrix<T>::display()
{
       for(int i=0;i<row;i++)
       {     cout<<"\n";
             for(int j=0;j<col;j++)
                cout<<"\t"<<m[i][j];
       }
}
template<class T>matrix<T> matrix<T>::addition(matrix<T> B)
{
       matrix<T> C(row,col);
       for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)
                 C.m[i][j]=m[i][j]+B.m[i][j];
       return C;
}
template<class T>matrix<T> matrix<T>::sub(matrix<T> B)
{
       matrix<T> C(row,col);
       for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)
                C.m[i][j]=m[i][j]-B.m[i][j];
       return C;
}
template<class T>matrix<T> matrix<T>::trans()
{
       matrix<T> C(col,row);
       for(int i=0;i<col;i++)
          for(int j=0;j<row;j++)
                C.m[i][j]=m[j][i];
       return C;
}
template<class T>matrix<T> matrix<T>::mul(matrix<T> B)
{
       matrix<T> C(row,col);
       for(int i=0;i<row;i++)
       {
          for(int j=0;j<col;j++)
          {
                C.m[i][j]=0;
          for(int k=0;k<row;k++)
             {
                   C.m[i][j]=C.m[i][j]+(m[i][k]*B.m[k][j]);
             }
          }
       }
       return C;
}
int main()
{
      int r,c,ch;
      char choice;
      do
      {
          cout<<"\nEnter\n1.To Enter Integer Matrix\n2.To Enter Floating point Matrix\n3.Exit\n";
          cin>>ch;
          switch(ch)
          {
              case 1:
                  {   cout<<"\nEnter row and column size: ";
                      cin>>r>>c;
                      matrix<int> A(r,c),B(r,c),C(r,c),D(c,r);
                      cout<<"\nEnter matrix 1 Elements\n";
                      A.accept();
                      cout<<"\nEnter matrix 2 Elements\n";
                      B.accept();
                      cout<<"\nMatrix 1 is: \n";
                         A.display();
                      cout<<"\nMatrix 2 is: \n";
                         B.display();
                      C=A.addition(B);
                      cout<<"\nMatrix Addition is: \n";
                      C.display();
                         C=A.sub(B);
                      cout<<"\nMatrix subtraction is: \n";
                      C.display();
                         D=A.trans();
                      cout<<"\nTranspose Matrix is: \n";
                      D.display();
                         C=A.mul(B);
                      cout<<"\nMatrix multiplication is: \n";
                      C.display();
                      break;
                  }
              case 2:
                   {
                      cout<<"\nEnter row and column size: ";
                      cin>>r>>c;
                      matrix<float> P(r,c),Q(r,c),R(r,c);
                      cout<<"\nEnter matrix 1 Elements\n";
                      P.accept();
                      cout<<"\nEnter matrix 2 Elements\n";
                      Q.accept();
                      cout<<"\nMatrix 1 is: \n";
                         P.display();
                      cout<<"\nMatrix 2 is: \n";
                         Q.display();
                      R=P.addition(Q);
                      cout<<"\nMatrix Addition is: \n";
                      R.display();
                      R=P.sub(Q);
                      cout<<"\nMatrix subtraction is: \n";
                      R.display();
                      R=P.trans();
                      cout<<"\nTranspose Matrix is: \n";
                      R.display();
                      R=P.mul(Q);
                      cout<<"\nMatrix multiplication is: \n";
                      R.display();
                      break;
                   }
              case 3: break;
              default: cout<<"Wrong Choice"<<endl;
          }
        cout<<"\nMore Data?(Y/N)\n";
        cin>>choice;
      }while(choice=='Y'|| choice=='y');
}

