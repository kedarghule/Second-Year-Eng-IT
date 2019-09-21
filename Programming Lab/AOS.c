#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

typedef struct
{
    int eid;
    char Name[30];
    int salary;
}employee;
int icount=0;
void initialize(employee emp[MAX])
{
    int i;
    for(i=0;i<MAX;i++)
        emp[i].eid=0;
}
void InsertRecord(employee emp[MAX],int recno)
{
    int id,j,flag=0,pos;
    for(j=0;j<recno;j++)
    {
        printf("\nEnter an employee ID : ");
        scanf("%d",&id);
        flag=SearchRecord(emp,id);
        if(flag!=-1)
        {
            printf("\nRecord exists\n");
            j--;
            flag=0;
        }
        else
        {
            pos=findfree(emp);
            if(pos==-1)
            {
                printf("\nEmpty slot is not present.\n");
                return;
            }
            emp[pos].eid=id;
            printf("\nEnter your name : ");
            scanf("%s",emp[pos].Name);
            printf("\nEnter your Salary : ");
            scanf("%d",&emp[pos].salary);
            printf("\nRecord entered successfully\n");
            icount++;
        }
    }
}
int findfree(employee emp[MAX])
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(emp[i].eid==0)
            return i;
    }
    return -1;
}
int SearchRecord(employee emp[MAX],int id)
{
    int i;
    for(i=0;i<icount;i++)
    {
        if(id==emp[i].eid)
            return i;
    }
    return -1;
}
void DisplayRecord(employee emp[MAX])
{
    int i;
    printf("\nID\t\tName\t\tSalary");
    for(i=0;i<icount;i++)
    {
        if(emp[i].eid!=0)
        {
            printf("\n%d\t%s\t  %d",emp[i].eid,emp[i].Name,emp[i].salary);
        }
    }
}
void ModifyRecord(employee emp[MAX])
{
    int id,i,flag=0;
    printf("\nEnter employee ID: ");
    scanf("%d",&id);
    flag=SearchRecord(emp,id);
    if(flag!=-1)
    {
        printf("\nEnter your name : ");
        scanf("%s",emp[flag].Name);
        printf("\nEnter your Salary : ");
        scanf("%d",&emp[flag].salary);
        printf("\nRecord modified successfully\n");
    }
    else
        printf("\nRecord does not exist\n");
}
void DelRecord(employee emp[MAX])
{
    int id,flag=0;
    printf("\nEnter employee ID : ");
    scanf("%d",&id);
    flag=SearchRecord(emp,id);
    if(flag!=-1)
    {
        emp[flag].eid=0;
        printf("\nRecord Deleted\n");
    }
    else
        printf("\nRecord Not Found\n");
}
void Delete(employee emp[MAX])
{
    int i,id,flag=0;
    printf("\nEnter employee ID : ");
    scanf("%d",&id);
    for(i=flag+1;i<MAX;i++)
    {
        emp[i-1].eid=emp[i].eid;
        strcpy(emp[i-1].Name,emp[i].Name);
        emp[i-1].salary=emp[i].salary;
    }
    printf("\nRecord deleted successfully\n");
}
int main(void)
{
    int ch,recno,id,flag;
    employee emp[MAX];
    initialize(emp);
    while(1)
    {
        printf("\n1.Insert a Record\n2.Display Records\n3.Search Record\n4.Modify Record\n5.Delete a Record logically\n6.Delete a Record\n7.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nHow many records do you want to enter?\n");
                    scanf("%d",&recno);
                    InsertRecord(emp,recno);
                    break;
            case 2: DisplayRecord(emp);
                    break;
            case 3: printf("\nEnter employee ID : ");
                    scanf("%d",&id);
                    flag=SearchRecord(emp,id);
                    if(flag!=-1)
                    {
                        printf("\nRecord exists");
                        printf("\nID\tName\tSalary");
                        printf("\n%d\t%s\t  %d",emp[flag].eid,emp[flag].Name,emp[flag].salary);
                    }
                    else
                        printf("\nRecord does not exist\n");
                    break;
            case 4: ModifyRecord(emp);
                    break;
            case 5: DelRecord(emp);
                    break;
            case 6: Delete(emp);
                    break;
            case 7: exit(1);
                    break;
            default:printf("\nWrong choice\n");
        }
    }
}
