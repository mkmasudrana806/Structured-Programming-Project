#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void addStudentDetails();
void printDB();
void countStudents();
void findStudent();
void updateStudent();

void decorationhomeWindow();
void decorationOthersWindow();
void decoration_on_list_all_students();
void decoration_on_searching_record();

typedef struct student
{
    int id;
    char name[30];
    char dpt[10];
    char section[10];
    float cgpa;
    char phone_no[15];

} student;


int main()
{
    int choice;
    do
    {
        decorationhomeWindow();
        printf("1. Add Student\n");
        printf("2. List of All Students\n");
        printf("3. Number of Records\n");
        printf("4. Search Student Record\n");
        printf("5. Modify Record\n");
        printf("0. Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addStudentDetails();
            break;
        case 2:
            printDB();
            break;

        case 3:
            countStudents();
            break;
        case 4:
            findStudent();
            break;
        case 5:
            updateStudent();
            break;

        }
    }
    while(choice!=0);
    return 0;
}




void addStudentDetails()
{
    system("cls");
    FILE *fp;
    student *s;
    int num,i;
    decorationOthersWindow();
    printf("\nHow Many Student Want to Add?");
    scanf("%d",&num);
    s = (student*)calloc(num,sizeof(student));
    fp=fopen("studentInfo.txt","a");
    for(i=0; i<num; i++)
    {
        printf("Enter ID: ");
        scanf("%d",&s[i]);
        printf("Enter Name: ");
        fflush(stdin);
        scanf("%[^\n]s",&s[i].name);
        fflush(stdin);
        printf("Enter Department: ");
        gets(s[i].dpt);
        printf("Enter Section: ");
        gets(s[i].section);

        printf("Enter CGPA: ");
        scanf("%f",&s[i]);
        fflush(stdin);
        printf("Enter Phone Number: ");
        gets(s[i].phone_no);
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
    system("cls");
}



void printDB()
{
    student s1;
    FILE *fp;
    fp=fopen("studentInfo.txt","r");
    decoration_on_list_all_students();
    while(fread(&s1,sizeof(student),1,fp))
    {
        printf("\n %-13d%-22s%-12s%-10s%-10f%-10s\n",s1.id,s1.name,s1.dpt,s1.section,s1.cgpa,s1.phone_no);
    }
    fclose(fp);
}



void countStudents()
{
    system("cls");
    student s1;
    FILE *fp;
    fp=fopen("studentInfo.txt","r");
    fseek(fp,0,SEEK_END);
    int num = ftell(fp)/sizeof(student);
    printf("\nNumber of Records = %d\n",num);
    fclose(fp);
}


void findStudent()
{

    student s1;
    FILE *fp;
    fp=fopen("studentInfo.txt","r");
    int ID,found=0;
    printf("Enter ID to search: ");
    scanf("%d",&ID);
    system("cls");
    decoration_on_searching_record();
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.id==ID)
        {
            found=1;
            printf(" %-13d%-22s%-12s%-10s%-10f%-10s\n",s1.id,s1.name,s1.dpt,s1.section,s1.cgpa,s1.phone_no);
        }
    }
    if(!found)
    {
        printf("\n Record Not found!\n");
    }
    fclose(fp);
}




void updateStudent()
{
    system("cls");
    student s1;
    FILE *fp,*fp1;
    fp=fopen("studentInfo.txt","r");
    fp1=fopen("temp.txt","w");
    int ID,found=0;
    printf("Enter ID to search\n");
    scanf("%d",&ID);
    while(fread(&s1,sizeof(student),1,fp))
    {
        if(s1.id==ID)
        {
            found=1;
            printf("enter new name: ");
            fflush(stdin);
            scanf("%[^\n]s",&s1.name);
            fflush(stdin);
            printf("Enter Depertment: ");
            gets(s1.dpt);
            printf("Enter Section: ");
            gets(s1.section);
            fflush(stdin);
            printf("Enter CGPA: ");
            scanf("%f",&s1.cgpa);

            printf("Enter Phone Number: ");
            gets(s1.phone_no);

        }
        fwrite(&s1,sizeof(student),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found)
    {
        fp1 = fopen("temp.txt","r");
        fp = fopen("studentInfo.txt","w");

        while(fread(&s1,sizeof(student),1,fp1))
        {
            fwrite(&s1,sizeof(student),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        printf("Record is not found!\n");
    }
    system("cls");
    printf("\n Record is Modified Successfully.\n");
    fclose(fp);
}






void decorationOthersWindow()
{
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############   Welcome to Student Record Management System     ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
}


void decoration_on_list_all_students()
{
    printf("\n******************** LIST OF ALL STUDENTS RECORD ********************\n");
    printf("\n   ID\t\tName   \t\tDepartment    Section\t  Phone No.\n");
    printf("---------------------------------------------------------------------");
}


void decoration_on_searching_record()
{
    printf("\n******************** LIST OF ALL STUDENTS RECORD ********************\n");
    printf("\n   ID\t\tName   \t\tDepartment    Section\t  Phone No.\n");
    printf("---------------------------------------------------------------------\n");
}



void decorationhomeWindow()
{
    printf("\n");
    printf("\n\t\t\t  **-**-**-**-**-**-** -**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               STUDENT RECORD              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
}

