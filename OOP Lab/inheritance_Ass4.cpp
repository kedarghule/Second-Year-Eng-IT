#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class b1
{
	protected :
		char name[20];
		char dob[15];
		char bgroup[4];
	public :
		b1()
		{	name[0]=dob[0]=bgroup[0]='\0';
		}
		void accept()
		{	cout<<"\nEnter Name : ";
			cin>>name;
			cout<<"Enter Date of Birth (dd/mm/yy) : ";
			cin>>dob;
			cout<<"Enter Blood Group : ";
			cin>>bgroup;
		}
		void display()
		{
			cout<<"\nName : "<<name;
			cout<<"\nDate of Birth (dd/mm/yy) : "<<dob;
			cout<<"\nBlood Group : "<<bgroup;
		}
};
class b2
{
	protected :
		float height,weight;
	public:
		b2()
		{
			height=weight=0;
		}
		void accept()
		{
			cout<<"Enter height : ";
			cin>>height;
			cout<<"Enter weight : ";
			cin>>weight;
		}
		void display()
		{
			cout<<"\nHeight : "<<height;
			cout<<"\nWeight : "<<weight;
		}
};
class b3
{
	protected :
		long int policy_no;
		char address[20];
	public :
		b3()
		{
			policy_no=0;
			address[0]='\0';
		}
		void accept()
		{
			cout<<"Enter insurance policy number : ";
			cin>>policy_no;
			cout<<"Enter address : ";
			cin>>address;
		}
		void display()
		{
			cout<<"\nInsurance policy number : "<<policy_no;
			cout<<"\nAddress : "<<address;
		}
};
class d : public b1,public b2,public b3
{
	private :
		long int driving_lic;
		long int ph_no;
	public :
		void accept();
		void display();
		void display_all();
		int search(char []);
		void modify();
};
void d::accept()
{
	b1::accept();
	b2::accept();
	b3::accept();
	cout<<"Enter driving licence number : ";
	cin>>driving_lic;
	cout<<"Enter telephone number : ";
	cin>>ph_no;
}
void d::display()
{
	b1::display();
	b2::display();
	b3::display();
	cout<<"\nDriving licence number : "<<driving_lic;
	cout<<"\nTelephone number : "<<ph_no;
}
void d::display_all()
{
	cout<<endl<<setw(10)<<name<<" "<<setw(10)<<dob<<" ";
	cout<<setw(10)<<bgroup<<setw(10)<<height<<setw(10)<<weight;
	cout<<setw(11)<<policy_no<<setw(11)<<address;
	cout<<setw(11)<<driving_lic<<setw(11)<<ph_no;
}
int d::search(char nm[])
{
	if(strcasecmp(name,nm)==0)
		return 1;
	return 0;
}
void d::modify()
{
	b1::accept();
	b2::accept();
	b3::accept();
	cout<<"Enter driving licence number : ";
	cin>>driving_lic;
	cout<<"Enter telephone number : ";
	cin>>ph_no;
}
int main()
{
	int choice,n,i,j;
	char name[10];
	d D[10];
	cout<<"Create a Database : ";
	do
	{
		cout<<"\n1.Build master table\n2.Display\n3.Insert new entry\n4.Delete entry\n5.Edit entry\n6.Search entry\n7.Exit\nEnter option : ";
		cin>>choice;
		switch(choice)
		{
			case 1 :
				cout<<"\nEnter number of entries to be created : ";
				cin>>n;
				for(i=0;i<n;i++)
					D[i].accept();
				break;
			case 2 :
				cout<<endl<<setw(10)<<"Name"<<" "<<setw(10)<<"DOB"<<" ";
				cout<<setw(10)<<"BGroup"<<setw(10)<<"Height"<<setw(10)<<"Weight";
				cout<<setw(11)<<"Policy no."<<setw(11)<<"Address ";
				cout<<setw(11)<<"Driving licence"<<setw(11)<<"Telephone";
				for(i=0;i<n;i++)
					D[i].display_all();
				break;
			case 3 :
				D[n++].accept();
				break;
			case 4 :
				cout<<"\nEnter name : ";
				cin>>name;
				for(i=0;i<n;i++)
				{
					if(D[i].search(name)==1)
					{
						cout<<"Deleted entry is : ";
						D[i].display();
						for(j=i;j<n;j++)
							D[j]=D[j+1];
						n--;
						break;
					}
				}
				if(i==n+1)
					cout<<"\nEntry not found.";
				break;
			case 5 :
				cout<<"\nEnter name : ";
				cin>>name;
				for(i=0;i<n;i++)
				{
					if(D[i].search(name)==1)
					{
						cout<<"Original entry is : ";
						D[i].display();
						cout<<"Enter modified data : ";
						D[i].modify();
						cout<<"Modified entry is : ";
						D[i].display();
						break;
					}
				}
				if(i==n+1)
					cout<<"\nEntry not found.";
				break;
			case 6 : 
				cout<<"\nEnter name : ";
				cin>>name;
				for(i=0;i<n;i++)
				{
					if(D[i].search(name)==1)
					{
						cout<<"Entry is : ";
						D[i].display();
						break;
					}
				}
				if(i==n+1)
					cout<<"\nEntry not found.";
				break;							}
	}while(choice!=7);
}
