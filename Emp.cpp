#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct employee
{
	char name[20], dept[20];
	int id;
	float salary;
};
void totalsal(struct employee*i, char dn[], int m);
int main()
{
	int m, i;
	struct employee*emp;
	char dname[20], choice;
	printf("Enter no of employee:");
	scanf("%d", &m);
	emp=(struct employee*)malloc(m*sizeof(struct employee));
	for(i=0; i<m; ++i)
	{
		printf("Enter details of employee %d\n", i+1);
		printf("Name");
		scanf("%s", (emp+i)-> name);
		printf("id");
		scanf("%d", (emp+i)->id);
		printf("Department");
		scanf("%s", (emp+i)-> dept);
		printf("Salary");
		scanf("%f", (emp+i)-> salary);
	}
	printf("%-15s%-25s%-15s%-15s\n", "id","Employye_name","Department","Salary");
	for(i=0; i<m; i++)
{   printf("%-15s%-25s%-15s%-15s\n",(emp+i)->id,(emp+i)->name,(emp+i)->dept,(emp+i)->salary);
 
}
do{printf("\n Enter department for which total salary has to be calculated");
scanf("%s", dname);
totalsal(emp, dname,m);
printf("\n DO you want to continue");
scanf("%c", &choice);

}
while(choice=='y'||choice=='y');
}
void totalsal(struct employee*i, char dn[], int m)
{
	float totalsal=0;
	int e, flag=0;
	for(e=0; e<m; ++e)
	if(strcmp((e+i)->dept,dn)==0)
	{
		flag=1;
		totalsal+=(e+i)->salary;
	}
	if(flag==0)
	 printf("\n No such Department\n");
	 else
	 printf("\n Total Salary of employees in department %s is %f, dn, totalsal");
	 
}
