#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// here all the userdefined functions
void create();
void add();
void display_all_records();
void num_of_rocords();
void search();
void update();
void delete_record();
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
    char phone_no[15];

} student;


int main()
{
    int choice;
    do
    {
        decorationhomeWindow();
        printf("\n1. Create\n");
        printf("2. Add Student\n");
        printf("3. List of All Students\n");
        printf("4. Number of Records\n");
        printf("5. Search Student Record\n");
        printf("6. Modify Record\n");
        printf("7. Delete Record\n");
        printf("0. Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            create();
            break;
        case 2:
            add();
            break;
        case 3:
            display_all_records();
            break;

        case 4:
            num_of_rocords();
            break;
        case 5:
            search();
            break;
        case 6:
            update();
            break;

        case 7:
            delete_record();
            break;
        }
    }
    while(choice!=0);
    return 0;
}


// below all use-defined function written
void create()
{
    system("cls");
    FILE *fp;
    student *s;
    int num,i;
    decorationOthersWindow();
    printf("\nHow many student want to Create?: ");
    scanf("%d",&num);
    s = (student*)calloc(num,sizeof(student));
    fp=fopen("studentInfo.txt","w");
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
        printf("Enter Phone Number: ");
        gets(s[i].phone_no);
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
    system("cls");
}





// copy from create.
void add()
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
        printf("Enter Phone Number: ");
        gets(s[i].phone_no);
        fwrite(&s[i],sizeof(student),1,fp);
    }
    fclose(fp);
    system("cls");
}





void display_all_records()
{

    student s1;
    FILE *fp;
    fp=fopen("studentInfo.txt","r");
    decoration_on_list_all_students();
    while(fread(&s1,sizeof(student),1,fp))
    {
        printf("\n %-13d%-22s%-12s%-10s%-10s\n",s1.id,s1.name,s1.dpt,s1.section,s1.phone_no);
    }
    fclose(fp);
}






void num_of_rocords()
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


// copy from display
void search()
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
            printf(" %-13d%-22s%-12s%-10s%-10s\n",s1.id,s1.name,s1.dpt,s1.section,s1.phone_no);
        }
    }
    if(!found)
    {
        printf("\n Record Not found!\n");
    }
    fclose(fp);
}







// copy search
void update()
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





// copy from update
void delete_record()
{
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
        }
        else
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
    fclose(fp);
    system("cls");
    printf(" Record is Deleted successfully\n");

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
    printf("\n******************** LIST OF ALL STUDENTS RECORDS ********************\n");
    printf("\n   ID\t\tName   \t\tDepartment    Section\t  Phone No.\n");
    printf("-----------------------------------------------------------------------");
}


void decoration_on_searching_record()
{
    printf("\n******************* LIST OF SEARCHING STUDENTS RECORD *******************\n");
    printf("\n   ID\t\tName   \t\tDepartment    Section\t  Phone No.\n");
    printf("-----------------------------------------------------------------------\n");
}



void decorationhomeWindow()
{
    printf("\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               STUDENT RECORD              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
}


