#include <iostream>
#include<string.h>
using namespace std;

class Book
{
    char *title,*author,*publisher;
    int price, stock;
    static int validT,T;
    public:
        Book()
        {
            title=new char[20];
            author=new char[20];
            publisher=new char[20];
            price=0;
            stock=0;
        }
        void add();
        void update();
        int search(char[]);
        void purchase(int N);
        void display();
        friend void displayALL(Book B[],int num);
    static void transaction()
    {
        cout<<"\nValid Transactions = "<<validT;
        cout<<"\nInvalid Transactions = "<<(T-validT);
    }
};
int Book::validT=0;
int Book::T=0;
void Book::add()
{
    cout<<"\nEnter book name: ";cin>>title;
    cout<<"\nEnter author name: ";cin>>author;
    cout<<"\nEnter publisher name: ";cin>>publisher;
    cout<<"\nEnter book price: ";cin>>price;
    cout<<"\nEnter stock: ";cin>>stock;
}
int Book::search(char N[])
{
    if(strcasecmp(title,N)==0)
        return 1;
    return 0;
}
void Book::display()
{
    cout<<"\nBook details are : ";
    cout<<"\nName : "<<title;
    cout<<"\nAuthor : "<<author;
    cout<<"\nPublisher : "<<publisher;
    cout<<"\nPrice : "<<price;
    cout<<"\nStock : "<<stock;
}
void Book::update()
{
    int ch;
    cout<<"\nUpdate 1.Stock 2.Price";
    cin>>ch;
    if(ch==1)
    {
        cout<<"\nEnter new stock";
        cin>>ch;
        stock+=ch;
    }
    else
    {
        cout<<"\nEnter new price";
        cin>>price;
    }
}
void Book::purchase(int N)
{
    if(N<=stock)
    {
        cout<<"\nTotal price of books = "<<N*price;
        stock=stock-N;
        validT++;
        T++;
    }
    else
    {
        cout<<"\nTransaction failed. Book out of stock";
        T++;
    }
}
void displayALL(Book B[20], int num)
{
    int i=0;
    cout<<"\nNo.\tBook Name \t Author \t Publisher \t Price \t Stock";
    for(i=0;i<num;i++)
    {
            cout<<"\n"<<(i+1)<<"\t"<<B[i].title<<" \t "<<B[i].author<<" \t "<<B[i].publisher<<" \t"<<B[i].price<<" \t"<<B[i].stock;
    }
}
int main()
{
    int ch,num,N,i;
    Book B[25];
    char name[25],ans;
    cout<<"\nEnter no. of books";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        B[i].add();
    }
    do
    {
        cout<<"\n1.Add new book\n2.Update\n3.Search a book\n4.Purchase a book\n5.Number of successful and unsuccessful transactions\n6.Display all books\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: B[num++].add();
                    break;
            case 2: cout<<"\nEnter book name : ";
                    cin>>name;
                    for(i=0;i<num;i++)
                    {
                        if(B[i].search(name))
                        {
                            B[i].display();
                            B[i].update();
                            break;
                        }
                    }
                    if(i==num)
                        cout<<"\nBook not present";
                    break;
            case 3: cout<<"\nEnter book name";
                    cin>>name;
                    for(i=0;i<num;i++)
                    {
                        if(B[i].search(name))
                        {
                            B[i].display();
                            break;
                        }
                    }
                    if(i==num)
                        cout<<"\nBook not present";
                    break;
            case 4: cout<<"\nEnter the name of the book to be purchased";
                    cin>>name;
                    cout<<"\nEnter number of books to be purchased";
                    cin>>N;
                    for(i=0;i<num;i++)
                    {
                        if(B[i].search(name))
                        {
                            B[i].display();
                            B[i].purchase(N);
                            break;
                        }
                    }
                    if(i==num)
                        cout<<"\nBook not present";
                    break;
            case 5: Book::transaction();
                    break;
            case 6: displayALL(B,num);
                    break;
            default:cout<<"\nWrong choice";
        }
        cout<<"\nMore? (Y/N)";
        cin>>ans;
    }while(ans=='Y'||ans=='y');
    return 0;
}
