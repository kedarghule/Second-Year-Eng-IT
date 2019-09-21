#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int id,salary;
	char name[25],dept[25];
}emp;

void main()
{
	FILE *fp,*ft;
	int ch,id,found;
	char another;
	long int recsize;
	emp e;
	fp=fopen("emp.txt","rb+");
	if(fp==NULL)
	{
		fp=fopen("emp.txt","wb+");
		if(fp==NULL)
		{
			printf("File cannot be created.");
			exit(1);
		}
	}
	recsize=sizeof(emp);
	while(1)
	{
		printf("\n1.Add record\n2.Display records\n3.Modify record\n4.Delete record\n5.Exit\nEnter option : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				fseek(fp,0,SEEK_END);
				another='Y';
				while(another=='Y')
				{
					printf("Enter ID,name,department,salary : ");
					scanf("%d %s %s %d",&e.id,e.name,e.dept,&e.salary);
					fwrite(&e,recsize,1,fp);
					fflush(stdin);
					printf("Do you want to add another record?(Y/N)");
					scanf(" %c",&another);
				}
				break;
			case 2 :
				rewind(fp);
				printf("\nID\tName\tDepartment\tSalary\n");
				while(fread(&e,recsize,1,fp)==1)
					printf("%d\t%s\t%s\t\t%d\n",e.id,e.name,e.dept,e.salary);
				break;
			case 3 :
				another='Y';
				found=0;
				while(another=='Y')
				{
					printf("Enter ID of employee to modify : ");
					scanf("%d",&id);
					rewind(fp);
					while(fread(&e,recsize,1,fp)==1)
					{
						if(id==e.id)
						{
							printf("Enter name,department,salary : ");
							scanf("%s%s%d",e.name,e.dept,&e.salary);
							fseek(fp,-recsize,SEEK_CUR);
							fwrite(&e,recsize,1,fp);
							found=1;
							break;
						}
					}
					if(found==0)
						printf("Record not present");
					printf("Modify another?(Y/N) : ");
					scanf(" %c",&another);
					fflush(stdin);
				}
				break;
			case 4 :
				another='Y';
				found=0;
				while(another=='Y')
				{
					printf("Enter ID of employee to delete : ");
					scanf("%d",&id);
					rewind(fp);
					ft=fopen("temp.txt","wb");
					while(fread(&e,recsize,1,fp)==1)
					{
						if(id!=e.id)
							fwrite(&e,recsize,1,ft);
						else
							found=1;
					}
					if(found==0)
						printf("Record not present.");
					fclose(fp);
					fclose(ft);
					remove("emp.txt");
					rename("temp.txt","emp.txt");
					fp=fopen("emp.txt","rb+");
					printf("Delete another record?(Y/N) : ");
					scanf(" %c",&another);
					fflush(stdin);
				}
				break;
			case 5 :
				fclose(fp);
				exit(0);
		}
	}
}
