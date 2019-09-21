#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class EMP_CLASS
{
 typedef struct EMPLOYEE
 {
 char name[10];
 int emp_id;
 int salary;
 int link;
 int loc;
 }Rec;
 Rec Records;
 public:
  int size;
  int Chain_tab[10][10];
  EMP_CLASS();
  void Insert();
  void init();
  void Display();
  void Search();
  void set_chain();
  friend int Hash(int);
  void modify();
};
EMP_CLASS::EMP_CLASS()
  {
   strcpy(Records.name,"");
   Records.emp_id=-1;
   Records.salary=-1;
   Records.link=-1;
  }
void EMP_CLASS::init()
{
 fstream seqfile;
 seqfile.open("EMP.DAT",ios::out|ios::binary);
 cout<<"\n Enter the Hash table size ";
 cin>>size;
 for(int i=0;i<size;i++)
 {
  strcpy(Records.name,"");
Records.emp_id=-1;
  Records.salary=-1;
  Records.link=-1;
  Records.loc=i;
 seqfile.write((char*)&Records,sizeof(Records));
  for(int i=0;i<size;i++)
  for(int j=0;j<size;j++)
  Chain_tab[i][j]=-1;
 }
 cout<<"\n\n Hash table is initialised...";
 cout<<"\n Now, insert the records in the hash table";
 seqfile.close();
}
int Hash(int num)
{
 int key;
 key=num%10;
 return key;
}
void EMP_CLASS::set_chain()
{
 fstream seqfile;
 int i,j,h,offset;
 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
 for(i=0;i<size;i++)
 {
  h=i;
  for(j=0;j<size;j++)
  {
   if(Chain_tab[i][j]==1)
   {
    offset=h*sizeof(Records);
    seqfile.seekg(offset);
    seqfile.read((char*)&Records,sizeof(Records));
    seqfile.seekp(offset);
    if(Records.link==-1 && Hash(Records.emp_id)==i)
        Records.link=j;
    seqfile.write((char*)&Records,sizeof(Records));
    h=j;
   }
  }
 }
 seqfile.close();
}
void EMP_CLASS::Insert()
{
 int i,h;
char ch='y';
 char new_name[10];
 int new_emp_id;
 int new_salary;
 fstream seqfile;
 init();//initialising the hash table
 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
 do
 {
  cout<<"\n Enter Name: ";
  cin>>new_name;
  cout<<"\n Enter Emp_ID: ";
  cin>>new_emp_id;
  cout<<"\n Enter Salary: ";
  cin>>new_salary;
  h=Hash(new_emp_id);
  int offset;
  offset=h*sizeof(Records);

  //seeking for reading record
seqfile.seekg(offset);
  seqfile.read((char*)&Records,sizeof(Records));
  //seeking for writing record
  seqfile.seekp(offset);
  if(Records.emp_id==-1)
  {
    strcpy(Records.name,new_name);
    Records.emp_id=new_emp_id;
    Records.salary=new_salary;
    Records.link=-1;
    Records.loc=h;//h is used for marking the loc.
    seqfile.write((char*)&Records,sizeof(Records))<<flush;
   //thus rec. is inserted at the hashed position in file
  }
  else//collision occurs
  {
  int flag=0;
  int prev_link=Records.loc;
  do      //handling collision
  {
   h++;//searching down for empty loc.in the file
   if(h>size+1)
   {
   cout<<"\n The hash table is Full, Can't insert record!!!";
   return;
}
   offset=h*sizeof(Records);
   seqfile.seekg(offset);
   seqfile.read((char*)&Records,sizeof(Records));
   if(Records.emp_id==-1) //finding empty loc. using linear probing
   {
    seqfile.seekp(offset);//seeking the empty slot in the file
    strcpy(Records.name,new_name);//for placing the record
    Records.emp_id=new_emp_id;
    Records.salary=new_salary;
    Records.link=-1;
    Records.loc=h;//setting the location for colliding record
    seqfile.write((char*)&Records,sizeof(Records))<<flush; 
//collinding record is placed in the file at proper pos.
  //chain table is maintained for keeping track of all the colliding entries.
    Chain_tab[prev_link][h]=1;
    flag=1;//indicates colliding record is inserted
   }//end of if
  }while(flag==0);//collision handled
  }//end of else
  cout<<"\nDo you want to add more records?";
  cin>>ch;
  set_chain();//setting the chain to handle collision
 }while(ch=='y');
 seqfile.close();
}
void EMP_CLASS::Display()
{
 fstream seqfile;
 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
 seqfile.seekg(0,ios::beg);
 cout<<"\n The Contents of file are ..."<<endl;
 cout<<"\nLoc.      Name         Emp_ID      Salary        Link    ";
 while(seqfile.read((char *)&Records,sizeof(Records)))
 {

   if(strcmp(Records.name,"")!=0)//not displaying empty slots
   {
   cout<<"\n--------------------------------------------------------\n";
 cout<<Records.loc<<"     "<<Records.name<<flush<<"    "<<Records.emp_id;
 cout<<"      "<<Records.salary<<"       "<<Records.link;

         }
 }
seqfile.close();
}
void EMP_CLASS::Search()
{
 fstream seqfile;
 int key,h,offset,flag=0;
 cout<<"\n Enter the Emp_ID for searching the record ";
 cin>>key;
 seqfile.open("EMP.DAT",ios::in|ios::binary);
 h=Hash(key);//obtaining the location of rec.using hash function
 while(seqfile.eof()==0)
 {       //h is a hash key
  offset=h*sizeof(Records);
  //using h for getting actual position in the file
  //hence offset is calculated
  seqfile.seekg(offset,ios::beg);//seeking rec.of that offset
  seqfile.read((char *)&Records,sizeof(Records));//reading that rec.
  if(key==Records.emp_id)//checking if it is required rec.
  {
   cout<<"\n The Record is present in the file and it is...";
   cout<<"\n Name: "<<Records.name;
   cout<<"\n Emp_ID: "<<Records.emp_id;
   cout<<"\n Salary: "<<Records.salary;
   flag=1;//means desired reocrd is obtained
   return;
  }
  else//following link for colliding record
  {
   h=Records.link;//moving along the chain
  }
 }//endof while
  if(flag==0)
  cout<<"\n The Record is not present in the file";
  seqfile.close();
}
void EMP_CLASS::modify()
{
 fstream seqfile;
 char na[10];
 int key,h,offset,flag=0,sa;
 cout<<"\n Enter the Emp_ID for modifying the record: ";
 cin>>key;
 seqfile.open("EMP.DAT",ios::in|ios::binary | ios::out);
 h=Hash(key);//obtaining the location of rec.using hash function
 while(seqfile.eof()==0)
 {       //h is a hash key
  offset=h*sizeof(Records);
  //using h for getting actual position in the file
  //hence offset is calculated
  seqfile.seekg(offset);//seeking rec.of that offset
  seqfile.read((char *)&Records,sizeof(Records));//reading that rec.
  if(key==Records.emp_id)//checking if it is required rec.
  {
   cout<<"\n The Record is present in the file and it is...";
   cout<<"Enter the name: ";
   cin>>na;
   cout<<"Enter the salary: ";
   cin>>sa;
    strcpy(Records.name,na);
    Records.salary=sa;
    Records.emp_id=key;
    Records.link=Records.link;
    Records.loc=Records.loc;
   seqfile.seekp(offset);
   seqfile.write((char*)&Records,sizeof(Records))<<flush;
   flag=1;//means desired reocrd is obtained
   return;
  }
  else//following link for colliding record
  {
   h=Records.link;//moving along the chain
  }
 }//endof while
  if(flag==0)
  cout<<"\n The Record is not present in the file";
  seqfile.close();
}
int main()
{
 EMP_CLASS List;
 char ans='y';
 int choice,key;
 do
 {
  cout<<"\n             Main Menu             "<<endl;
  cout<<"\n 1.Insert";
  cout<<"\n 2.Display";
  cout<<"\n 3.Search";
  cout<<"\n 4.modify";
  cout<<"\n 5.Exit";
  cout<<"\n Enter your choice: ";
  cin>>choice;
  switch(choice)
  {
  case 1:List.Insert();
      break;
  case 2:List.Display();
      break;
  case 3:List.Search();
      break;
  case 4:List.modify();
	 break;
  case 5:exit(0);
  }
 
 }while(1);
return 0;
}
















