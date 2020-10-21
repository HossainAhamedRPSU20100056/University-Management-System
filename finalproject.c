#include <stdio.h>
#include <string.h>
#include <conio.h>
FILE *sms;
FILE *s_result;
FILE *total_result;
FILE *att_info;
struct teacher
{
    char ID[15];
    char name[20];
    char address[30];
    char qua[25];
    int n;
    char code[10][10];
    long unsigned int phn_num;
};
struct teacher per ;
struct student
{
    char ID[15];
    char name[18];
    char address[30];
    char parents[20];
    long unsigned int phn_num;
    char dept[15];
    int sem;
    int batch;
};
struct student stud;
struct result
{
   char ID[15];
   int sem;
   char university_batch[15];
   int n;
   char code[8][8];
   int credit[8];
   float result[8];
};
struct result res;
struct final_result
{
    char ID[15];
    int sem;
    float results;
};
struct final_result semresult;
struct savedPassword
{
    char ID[15];
    char password[10];
};
struct savedPassword pass;
struct att_stud
{
    char ID[15];
    int date;
    int month;
    int year;
    char code[15];
    char att_story[5];
};
struct att_stud att_data;
struct money_reciept
{
    char ID[15];
    int sem;
    float total;
    float first_pay;
    char first_pay_data[10];
    float second_pay;
    char second_pay_data[10];
};
struct money_reciept reciept ;

 void front()
{
    system("cls");
    system("color 07");
    printf("          _____________________________________________\n");
    printf("         |      Ranada Prasad Shaha University         |\n");
    printf("         |               Estd-2014                     |\n");
    printf("         |---------------------------------------------|\n");
    printf("         |          'Management System'                |\n");
    printf("         |_____________________________________________|\n\n");
    return ;
}
 void mainwindow()
{
    system("cls");
    front();
    int panelChoice;
    printf("\n              MAIN WINDOW\n\n");
    printf("         1. Admin\n");
    printf("         2. Course Teacher\n");
    printf("         3. Student\n");
    printf("         4. Exit\n");
    printf("\n");
    printf("Enter your choice : ");
    correction:
    scanf("%d",&panelChoice);
    switch(panelChoice)
    {
    case 1:
        {
        system("cls");
        front();
        printf("\n\n\t\tADMIN LOGIN : \n");
        login("abc%123!");
        admin_window();
        break;
        }
    case 2:
        {
        teacher_passField();
        break;
        }
    case 3:
        {
        student_passField();
        break;

        }
    case 4:
        {
        system("cls");
        front();
        printf("\n\n\n\t\tThanks for being part of \n\t\t\tRPSU FAMILY\n\n\n\n");
        exit(0);
        break;
        }
    default:
        {
        printf("\a\nEnter correct option : ");
        goto correction;
        break;
        }
    }
    return;
}
void admin_window()
{
    int choose,a;
    admin_Dash:
    system("cls");
    front();
    printf("\n\n  ADMIN DASHBOARD\n\n");
    printf("\n1. Add student                 8. Generate result");
    printf("\n2. Edit student                9. Search result");
    printf("\n3. Add teachers               10.Payment data entry");
    printf("\n4. Search student             11.Search attendence");
    printf("\n5. Search all student         12.Teacher passwords");
    printf("\n6. Search teacher             13.Student password");
    printf("\n7. Delete previous sem data   14.Return to Main Window");
    printf("\n\nEnter your choice : ");
    correction:
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        {
            add1:
            add_student();
            printf("\n\nPress 0 to ADD NEW \nOr 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add1;
               else goto admin_Dash;
            break;
        }
    case 2:
        {
            int x;
            add2:
            system("cls");
            front();
            printf("\n\n     1. Modify student  ");
            printf("\n     2. Add new semester info");
            printf("\n     3. Go back");
            printf("\n\n     Enter your choice : ");
            scanf("%d",&x);
            if(x ==2)
             {
                 addagain:
                 new_sem();
                 printf("\n\nPress 0 for another student \nOr 1 for ADMIN DASHBOARD ");
                 scanf("%d",&a);
                 if(a==0) goto addagain;
                 else goto admin_Dash;
                break;
             }
            else if(x ==1)
                {
                 edit_student();
                 printf("\n\nPress 0 to go EDIT STUDENT \nOr 1 for ADMIN DASHBOARD ");
                 scanf("%d",&a);
                 if(a==0) goto add2;
                 else goto admin_Dash;
                 break;
                }
            else{
                goto admin_Dash;
                break;
            }
        }
    case 3:
        {
            int x;
            add3:
            system("cls");
            front();
            printf("\n\n     1. Add new teacher");
            printf("\n     2. Modify teachers subject");
            printf("\n     3. Go back");
            printf("\n\n     Enter your choice : ");
            scanf("%d",&x);
            if(x ==2)
             {
            edit_teacher();
            printf("\n\nPress 0 to go EDIT ANOTHER TEACHER \nOr 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add3;
              else goto add3;
            break;
             }
            else if(x ==1 )
                {
                 add_teacher();
            printf("\n\nPress 0 to ADD TEACHER \nOr 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add3;
              else goto add3;
            break;
            }
            else{
                goto admin_Dash;
                break;
            }
        }
    case 4:
        {
            add4:
            search_student("0");
            printf("\n\nPress 0 to SEARCH AGAIN \nOr 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add4;
              else goto admin_Dash;
            break;
        }
    case 5:
        {
            add5:
            all_student();
            printf("\n\nPress 0 to SEARCH AGAIN \nOr 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add5;
              else goto admin_Dash;
            break;

        }
    case 6:
        {
            add7:
            all_teacher();
            search_teacher("0");
           printf("\n\nPress 0 to SEARCH AGAIN \nOr 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add7;
              else goto admin_Dash;
            break;
        }

    case 7:
         {
            del_data();
            printf("\n\n\t\tSUCCESSFULLY DELETED");
            printf("\n\nPress 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto admin_Dash;
              else goto admin_Dash;
            break;
        }
        case 8:
            {
                front();
                generate_result();
                 printf("\n\nPress 1 for ADMIN DASHBOARD ");
                 scanf("%d",&a);
            if(a==0) goto admin_Dash;
              else goto admin_Dash;
            break;
            }

    case 9:
        {
            int x;
            add9:
            system("cls");
            front();
            printf("\n\n     1. Search this semester result");
            printf("\n     2. Results of any semester of a student");
            printf("\n     3. Go back");
            printf("\n\n     Enter your choice : ");
            scanf("%d",&x);
            if(x ==1)
             {
                search_result("0");
              printf("\n\nPress 0 for search again \nor 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add9;
              else goto admin_Dash;
            break;
             }
            else if(x ==2 )
                {
                 search_all_sem_result("0");
            printf("\n\nPress 0 for search again \nor 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add9;
              else goto admin_Dash;
            break;
            }
            else goto admin_Dash;
        }
    case 10:
       {
            add10:
            payment();
            printf("\n\nPress 0 to ADD NEW \nOr 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add10;
               else goto admin_Dash;
            break;
        }
    case 11:
         {
            search_attendence("0");
            goto admin_Dash;
            break;
        }
        case 12:
         {
            all_teacher_pass();
            printf("\n\nPress 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==1) goto admin_Dash;
              else goto admin_Dash;
            break;
         }
        case 13:
         {
            all_student_pass();
            printf("\n\nPress 1 for ADMIN DASHBOARD ");
            scanf("%d",&a);
            if(a==1) goto admin_Dash;
              else goto admin_Dash;
            break;
        }
    case 14:
        {
            mainwindow();
        break;
        }

    default:
        {
           printf("\a\nEnter correct option : ");
           goto correction;
           break;
        }

    }

    return;
}
void teacher_window(char ID[15])
{

    int choose,a;
    teacher_Dash:
    system("cls");
    front();
    printf("\n\n  TEACHERS DASHBOARD\n\n");
    printf("\n1. Your profile");
    printf("\n2. Search student");
    printf("\n3. All student");
    printf("\n4. Add result");
    printf("\n5. Search result");
    printf("\n6. Add attendence");
    printf("\n7. Search attendence");
    printf("\n8. Change Password");
    printf("\n9. Return to Main Window");

    printf("\n\nEnter your choice : ");
    correction:
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
     {
        search_teacher(ID);
        printf("\n\nPress 0 for TEACHER DASHBOARD ");
        scanf("%d",&a);
        if(a==0)
            goto teacher_Dash;
        else
            goto teacher_Dash;
    break;
     }
    case 2:
        {
           add1:
           search_student("0");
           printf("\n\nPress 0 to SEARCH AGAIN \nOr 1 for TEACHER DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add1;
               else goto teacher_Dash;
            break;
        }
   case 3:
        {
            add2:
            all_student();
            printf("\n\nPress 0 to SEARCH AGAIN \nOr 1 for TEACHER DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add2;
              else goto teacher_Dash;
            break;

        }
    case 4:
       {
           add_result(ID);
            break;
        }
    case 5:
        {
             int x;
           add3:
            system("cls");
            front();
            printf("\n\n     1. Search this semester result");
            printf("\n     2. Results of any semester of a student");
            printf("\n     3. Go back");
            printf("\n\n     Enter your choice : ");
            scanf("%d",&x);
            if(x ==1)
             {
                search_result("0");
              printf("\n\nPress 0 for search again \nor 1 for TEACHER DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add3;
              else goto teacher_Dash;
            break;
             }
            else if(x ==2 )
                {
                 search_all_sem_result("0");
            printf("\n\nPress 0 for search again \nor 1 for TEACHER DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto add3;
              else goto teacher_Dash;
            break;
            }
            else goto teacher_Dash;
        }
    case 6:
        {
            add4:
            add_attendence(ID);
           printf("\n\nPress 1 for TEACHER DASHBOARD ");
            scanf("%d",&a);
            if(a == 1)
                goto teacher_Dash;
               else goto teacher_Dash;
            break;
        }
    case 7:
        {

            search_attendence(ID);
             goto teacher_Dash;
            break;
        }
    case 8:
        {
            int x=1;
         changepass(ID,x);
         goto teacher_Dash;
         break;
        }

    case 9:
        mainwindow();
        break;
    default:
        {
            printf("\a\nEnter correct option : ");
            goto correction;
        }

    }

    return;

}
void student_window(char studentID[15])
{
    int a;
    student_Dash:

    system("cls");
    front();
    int choose;
    printf("\n\n STUDENTS DASHBOARD\n\n");
    printf("\n1. Profile");
    printf("\n2. Money Reciept");
    printf("\n3. Result");
    printf("\n4. Change Password");
    printf("\n5. Return to Main Window");
    printf("\n\nEnter your choice : ");
    correction:
    scanf("%d",&choose);
    switch(choose)
    {
 case 1:
     {
        search_student(studentID);
        printf("\n\nPress 0 for STUDENT DASHBOARD ");
        scanf("%d",&a);
        if(a==0)
            goto student_Dash;
        else
          goto  student_Dash;
    break;
     }
 case 2:
      {
        system("cls");
        front();
        printf("\n\t\tMONEY RECIEPT\n");
        payment_data(studentID);
        printf("\n\nPress 0 for STUDENT DASHBOARD ");
        scanf("%d",&a);
        if(a==0)
            goto student_Dash;
        else
           goto student_Dash;
    break;
     }
 case 3:
     {
             int x;
            system("cls");
            front();
            printf("\n\n     1. Search this semester result");
            printf("\n     2. Results of any semester ");
            printf("\n     3. Go back");
            printf("\n\n     Enter your choice : ");
            fflush(stdin);
            scanf("%d",&x);
            if(x ==1)
             {
                search_result(studentID);
              printf("\n\nPress 0 for DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto student_Dash;
              else goto student_Dash;
            break;
             }
            else if(x ==2 )
                {
                 search_all_sem_result(studentID);
            printf("\n\nPress 0 for DASHBOARD ");
            scanf("%d",&a);
            if(a==0) goto student_Dash;
              else goto student_Dash;
            break;
            }
            else goto student_Dash;
     }
 case 4:
     {
         int x =2;
         changepass(studentID,x);
         goto student_Dash;
         break;
     }

 case 5:
    {
        mainwindow();
        break;
    }
 default:
     {
         printf("\a\nEnter correct option : ");
         goto correction;
         break;
     }
    }
    return;
}
float get_sub_result(float mark)
{
    correction_mark:
     if (mark >= 80 && mark <= 100){
             return 4.00;
        }
        else if (mark >= 70 && mark < 80){
            return 3.75;
        }
        else if (mark >= 60 && mark < 70){
            return 3.5;
        }

        else if(mark >= 50 && mark < 60){
            return 3.00;
        }
        else if(mark >= 40 && mark < 50){
            return 2.50;
        }
        else if(mark >= 0 && mark < 40){
            return 0.00;
        }
        else
        {
            printf("\nEnter correct mark : ");
            fflush(stdin);
            scanf("%f",&mark);
            goto  correction_mark;
        }
        return;
}
void add_result(char ID[15])
{
    char studentID[15];
    int batch;
    char code[15];
    int i,x,k,b,total_credit =0;
    float mark,y,sum,fail =0;
    int choose;

    search_again2:
    system("cls");
    front();
    sms = fopen("teacher_record.txt","rb");
    while(fread(&per, sizeof(per),1,sms) == 1)
        {
           if(strcmp(ID,per.ID) == 0)
         {
           int k,x;
            x = per.n;
            printf("\n\nYour courses are   : ");
            for(k =0;k<x;k++)
              {
                printf("\n%d - %s",k+1,per.code[k]);
               }
            break;
      }
    }
    fclose(sms);
    printf("\nEnter your choice : ");
    fflush(stdin);
    scanf("%d",&choose);
    switch (choose)
       {
        case 1:
           {
                strcpy(code,per.code[0]);
                break;
           }
        case 2:
           {
                strcpy(code,per.code[1]);
                break;
           }
        case 3:
           {
               strcpy(code,per.code[2]);
                break;
           }
        case 4:
           {
               strcpy(code,per.code[3]);
                break;
           }
        case 5:
           {
                strcpy(code,per.code[4]);
                break;
           }
        case 6:
           {
                strcpy(code,per.code[5]);
                break;
           }
        case 7:
           {
                strcpy(code,per.code[6]);
                break;
           }
        case 8:
           {
                strcpy(code,per.code[7]);
                break;
           }
            case 9:
           {
                strcpy(code,per.code[8]);
                break;
           }
            case 10:
           {
                strcpy(code,per.code[9]);
                break;
           }
           default :
            {
                teacher_window(ID);
                break;
            }
       }
    system("cls");
    front();
    again:

    printf("\nStudents in this course are : \n");
    s_result = fopen("student_result.txt","rb");
    // ID list for that batch
       while (fread(&res,sizeof(res),1,s_result)==1)
          {
              int j;
              j=res.n;
              for(i=0;i<=j;i++)
                      {
                          if(strcmp(res.code[i],code) ==0 )
                          {
                            printf("\n\nID : %s",res.ID);
                            x=1;
                          }
                      }
          }
    fclose(s_result);
    if(x != 1)
        {
            int q=1;
            printf("\n\aINVALID INFORMATION");
            printf("\n    NOT FOUND !!!");
            printf("\npress 1 for correction or \n0 for DASHBOARD");
            scanf("%d",&q);
            if(q ==1 )
                 goto search_again2;
            else
            {
              teacher_window(ID);
            }
        }
    printf("\nENTER STUDENT ID      : ");
    fflush(stdin);
    gets(studentID);
    system("cls");
    front();
    int value;
    int z=0;
    s_result= fopen("student_result.txt","rb");
    while(fread(&res,sizeof(res),1,s_result)==1)
    {
         if(strcmp(res.ID,studentID) ==0)
               {
                   value = res.n;
                    for(i=0;i<value;i++)
                      {
                          if(strcmp(res.code[i],code) ==0)
                          {
                              z=1;
                               break;
                          }
               }
          }
    }
    fclose(s_result);
    if(z!=1)
    {
     printf("\nnot found");
     return teacher_window(ID);
    }
    printf("\nEnter marks    :");
    fflush(stdin);
    scanf("%f",&mark);
    y = get_sub_result(mark);
    s_result= fopen("student_result.txt","rb+");
    while(fread(&res,sizeof(res),1,s_result)==1)
    {
         if(strcmp(res.ID,studentID) ==0)
               {
                   res.result[i] = y;
              fseek(s_result,-sizeof(res), SEEK_CUR);
              fwrite(&res,sizeof(res),1,s_result);
              b=1;
            break;
               }
    }

     fclose(s_result);
    if(b!=1)
        {
        printf("\n\n\t\aERROR IN FINDING !!!\n");
        goto again;
        }
    if(b ==1)
        {
            int t;
            printf("\nPress 0 for add another result\n1 for DASHBOARD ");
            scanf("%d",&t);
            if(t==0)
                goto again;
            else teacher_window(ID);
        }
    return;
}
void generate_result()
{
    char uni_batch[15];
    char uni_batch2[15];
    int sem;
    int x,b,total_credit;
    int value,sem_no;
    float sum;
    system("cls");
    front();
    correction:
    printf("\n\t     Enter current university session : ");
    fflush(stdin);
    gets(uni_batch);
    strcpy(uni_batch2, strupr(uni_batch));
    system("cls");
    s_result = fopen("student_result.txt","rb");
    while(fread(&res,sizeof(res),1,s_result)==1)
    {
         total_result = fopen("final_result.txt","ab+");
        if(strcmp(uni_batch2,res.university_batch)==0)
        {

             total_result = fopen("final_result.txt","ab+");
            sum =0;
            total_credit=0;
            sem_no = res.sem;
            fflush(stdin);
            value =res.n;
            for(x=0;x<value;x++)
            {
                sum += (res.credit[x] * res.result[x]);
                total_credit+=res.credit[x];
            }
             float final_result = sum/total_credit;
             fflush(stdin);
             strcpy(semresult.ID,res.ID);
             fflush(stdin);
             semresult.sem= sem_no;
             fflush(stdin);
             semresult.results = final_result;
              fwrite(&semresult,sizeof(semresult),1,total_result);
             fclose(total_result);
             b=1;
        }
    }
    fclose(s_result);
    if(b!=1)
    {
        system("cls");
        front();
          printf("\n\n\n\n\t\t\aERROR !!!");
    }

    if(b ==1)
    {
        system("cls");
        front();
        printf("\n\n\n\n\t\tSUCCESSFULLY ADDED");
    }
    return;
}
void changepass(char givenID[15],int x)
{
    char mainID[15],prevPass[10];
    int b=0;
    int z=1;

    FILE *sms;
    system("cls");
    front();
    correction:
    if(x == 2)
    {
        strcpy(mainID,givenID);
        printf("Enter previous password ");
        fflush(stdin);
        gets(prevPass);
        sms = fopen("student_pass.txt","rb+");
    }
    else if(x==1)
    {
    fflush(stdin);
    strcpy(mainID,givenID);
    printf("\n\tPrevious password ");
    gets(prevPass);
    sms = fopen("teacher_pass.txt","rb+");
    }
    while(fread(&pass,sizeof(pass),1,sms)==1)
    {
        if(strcmp(mainID,pass.ID)==0 && strcmp(prevPass,pass.password)==0)
       {
            fflush(stdin);
            strcpy(pass.ID,mainID);
            printf("\n\t\t'REMEMBER THE PASSWORD FOR FUTURE LOGIN'\n");
            printf("\n\nType Your Password ");
            gets(pass.password);
            fseek(sms,-sizeof(pass), SEEK_CUR);
            fwrite(&pass,sizeof(pass),1,sms);
            b=1;
            break;
        }
    }
    fclose(sms);
    if(b!=1)
        {
            z++;
            if(z>3)
             {
                printf("\nDidn't match for three times\nGoing to Main window");
                for(int i=0;i<5;i++)
                   {
                     delay(100000000);

                      printf(". ");
                   }
              for(int i=0;i<5;i++)
                   {
                      delay(100000000);

                       printf(". ");
                    }
              mainwindow();
            }
        printf("\n\n\t\aINCORRECT !!!\n");
        goto correction;

    }
    return;

}
void search_teacher(char ID[15])
{
    char givenID[15];
    int b=0;
    if(strcmp(ID,"0") == 1)
    {
        strcpy(givenID,ID);
        system("cls");
        front();
        printf("\n  YOUR INFORMATION\n\n");
    }
    else
    {
    printf("\n\nEnter teacher ID to see detail info : ");
    fflush(stdin);
    gets(givenID);
    system("cls");
    front();
    printf("\n  TEACHER INFORMATION\n\n");
    }
    sms = fopen("teacher_record.txt","rb");
    while(fread(&per, sizeof(per),1,sms) == 1)
        {
    if(strcmp(givenID,per.ID) == 0)
          {
            b = 1;
            break;
          }
        }
    if(b==1)
      {
        printf("\nID            : %s",per.ID);
        printf("\nName          : %s",per.name);
        printf("\nAddress       : %s",per.address);
        printf("\nQualifiaction : %s",per.qua);
        printf("\nPhone Number  : 0%ld",per.phn_num);
        int k,x;
        x = per.n;
        printf("\nCourses are   : ");
        for(k =0;k<x;k++)
            {
                printf("%s ",per.code[k]);
           }
      }
    else
      {
        printf("\n\n\t\aERROR IN FINDING !!!\n");
      }
      fclose(sms);
    return;
}
void search_all_sem_result(char givenID[15])
{
    char mainID[15];
    int b=0;
    if(strcmp(givenID,"0") == 1)
    {
        strcpy(mainID,givenID);
        system("cls");
        front();
        printf("\n  YOUR INFORMATION\n\n");
    }
    else
    {
    system("cls");
    printf("\n\t\tENTER ID              :");
    fflush(stdin);
    gets(mainID);
    system("cls");
    front();
    printf("\n  STUDENT'S RESULT INFORMATION\n\n");
    }
    int x =0;
         total_result = fopen("final_result.txt","rb");
                     while(fread(&semresult, sizeof(semresult),1,total_result) == 1)
                     {
                           if(strcmp(mainID,semresult.ID) == 0)
                           {
                               printf("\n\ semester %d result : %.2f",semresult.sem,semresult.results);
                           }
                           x =1;
                     }
                     fclose(total_result);
                     if(x != 1)
                        printf("\nNot found !!!!");
    return;
}
void search_result(char givenID[15])
{

    char mainID[15];
    int b=0;
    if(strcmp(givenID,"0") == 1)
    {
        strcpy(mainID,givenID);
        system("cls");
        front();
        printf("\n  YOUR INFORMATION\n\n");
    }
    else
    {
    system("cls");
    printf("\n\t\tENTER ID              :");
    fflush(stdin);
    gets(mainID);
    system("cls");
    front();
    printf("\n  STUDENT'S RESULT INFORMATION\n\n");
    }
    int k,x,sem;
    s_result = fopen("student_result.txt","rb");
    while(fread(&res, sizeof(res),1,s_result) == 1)
        {
           if(strcmp(mainID,res.ID) == 0)
              {

                     printf("\nID            : %s\n",res.ID);
                     fflush(stdin);
                     sem= res.sem;
                     x = res.n;
                     for(k =0;k<x;k++)
                         {
                             printf("\nCourse code    : %s",res.code[k]);
                             printf("\nCredit         : %d",res.credit[k]);
                             printf("\nResult         : %.2f",res.result[k]);
                             printf("\n");
                          }
                           b =1;
                           break;

                     }

               }
         total_result = fopen("final_result.txt","rb");
                     while(fread(&semresult, sizeof(semresult),1,total_result) == 1)
                     {
                           if((strcmp(mainID,semresult.ID) == 0) && (sem == semresult.sem))
                           {
                               printf("\n\nTotal semester result : %.2f",semresult.results);
                               break;
                           }
                     }
                     fclose(total_result);
                     if(sem ==12)
                     {
                         float sum =0.00;
                         float end_result;
                         total_result = fopen("final_result.txt","rb");
                         while(fread(&semresult, sizeof(semresult),1,total_result) == 1)
                         {
                           if(strcmp(mainID,semresult.ID) == 0)
                           {
                               sum += semresult.results;
                           }
                        }
                         fclose(total_result);
                         end_result = sum/sem;
                         printf("\n\nFinal result after graduation is  : %.2f",end_result);
                     }
        if(b !=1)
            {
            printf("\n\n\t\aERROR IN FINDING !!!!\n");
           }
    fclose(s_result);
    return;
}
void all_teacher()
{
    system("cls");
    front();
    printf("\n\t\t'ALL TEACHERS'\n\n");

    sms = fopen("teacher_record.txt","rb");
    while(fread(&per, sizeof(per),1,sms) == 1)
        {
         printf("\nID : %s      %s -- Courses ",per.ID,per.name);
         int k,x;
        x = per.n;
        for(k =0;k<x;k++)
            {
                printf("%s ",per.code[k]);
           }
        }
        fclose(sms);
   printf("\n");
  return;
}
void all_student()
{
    int sem;
    int batch;
    system("cls");
    front();
    printf("\n\t\t'ALL STUDENTS'");
    printf("\n\nEnter batch number : ");
    scanf("%d",&batch);
    sms = fopen("student_record.txt","rb");
    while(fread(&stud, sizeof(stud),1,sms) == 1)
        {
            if(stud.batch==batch)
            {
                 printf("\nID : %s     %s    %s",stud.ID,stud.name,stud.dept);
            }
        }
        fclose(sms);
      return;

}
void all_student_pass()
{
    system("cls");
    front();
    printf("\n\t\t'ALL TEACHERS PASSORD'\n\n");
    sms = fopen("student_pass.txt","rb");
    while(fread(&pass, sizeof(pass),1,sms) == 1)
        {
         printf("\nID : %s     ",pass.ID);
        }
    fclose(sms);
    char ID[15];
     printf("\n\nEnter students ID : ");
     fflush(stdin);
     gets(ID);
     int k =0;
     sms = fopen("student_pass.txt","rb");
    while(fread(&pass, sizeof(pass),1,sms) == 1)
        {
            if(strcmp(ID,pass.ID)==0)
            {
                 printf("\nID : %s   password : %s",pass.ID,pass.password);
                k = 1;
                 break;
            }

        }
    fclose(sms);
    if(k != 1)
        printf("\nNot found !!!");
   printf("\n");
  return;
}
void all_teacher_pass()
{
    system("cls");
    front();
    printf("\n\t\t'ALL STUDENT PASSWORD'\n\n");
    sms = fopen("teacher_pass.txt","rb");
    while(fread(&pass, sizeof(pass),1,sms) == 1)
        {
         printf("\nID : %s  ",pass.ID);
        }
    fclose(sms);
     char ID[15];
     printf("\n\nEnter teachers ID : ");
     fflush(stdin);
     gets(ID);
     int k =0;
     sms = fopen("teacher_pass.txt","rb");
    while(fread(&pass, sizeof(pass),1,sms) == 1)
        {
            if(strcmp(ID,pass.ID)==0)
            {
                 printf("\nID : %s   password : %s",pass.ID,pass.password);
                k = 1;
                 break;
            }

        }
    fclose(sms);
    if(k != 1)
        printf("\nNot found !!!");
   printf("\n");
  return;
}
void search_student(char givenID[15])
{
    char mainID[15];
    int b=0;
    if(strcmp(givenID,"0") == 1)
    {
        strcpy(mainID,givenID);
        system("cls");
        front();
        printf("\n  YOUR INFORMATION\n\n");
    }
    else
    {
    system("cls");
    printf("\n\t\tENTER STUDENT ID ");
    fflush(stdin);
    gets(mainID);
    system("cls");
    front();
    printf("\n  STUDENT INFORMATION\n\n");
    }
    sms = fopen("student_record.txt","rb");
    while(fread(&stud, sizeof(stud),1,sms) == 1)
        {
           if(strcmp(mainID,stud.ID) == 0)
              {
                     printf("\nID            : %s",stud.ID);
                     printf("\nName          : %s",stud.name);
                     printf("\nAddress       : %s",stud.address);
                     printf("\nParents Name  : %s",stud.parents);
                     printf("\nDept. Name    : %s",stud.dept);
                     printf("\nBatch no      : %d",stud.batch);
                     printf("\nsem no        : %d",stud.sem);
                     printf("\nPhone Number  : 0%ld",stud.phn_num);
                     b=1;
                     break;
               }
        }
    if(b != 1)
        {
             printf("\n\n\t\aERROR IN FINDING !!!!\n");
        }
    fclose(sms);

     int l =0;
      printf("\nTaken courses are : ");
      FILE *s_result;
    s_result = fopen("student_result.txt","rb");
    while(fread(&res, sizeof(res),1,s_result) == 1)
        {
           if(strcmp(mainID,res.ID) == 0)
              {
                     int k,x;
                     x = res.n;
                     for(k =0;k<x;k++)
                         {
                             printf("%s ",res.code[k]);
                          }

                     l =1;
                     break;
               }
       }
     fclose(s_result);
     if(l != 1)
        {
             printf("\n\n\t\aERROR IN FINDING !!!!\n");
        }
    if(strcmp(givenID,"0") == 0 && b ==1 && l==1)
    {
    printf("\n\n\t\tMONEY RECIEPT\n");
    payment_data(mainID);
    }
    return;
}
int payment_data(char mainID[15])
{
    int c= 0;
    int sem;
    printf("\nENTER SEMESTER NUMBER : ");
    fflush(stdin);
    scanf("%d",&sem);
    sms = fopen("moneyreciept.txt","rb");
    while(fread(&reciept, sizeof(reciept),1,sms) == 1)
        {
           if((strcmp(mainID,reciept.ID) == 0) && (sem == reciept.sem))
              {

            printf("\n");
            printf("\nTotal fees                 : %.2f",reciept.total);
            printf("\nFirst payment amount       : %.2f",reciept.first_pay);
            printf("\nFirst payment information  : %s",reciept.first_pay_data);
            printf("\nSecond payment amount      : %.2f",reciept.second_pay);
            printf("\nSecond payment information : %s",reciept.second_pay_data);
            c =1;
            break;
            }
        }
        if( c != 1)
        {
            printf("\nERROR IN FINDING!!!\n");
        }
    fclose(sms);
    return sem;
}
void teacher_passField()
{
    system("cls");
    char givenID[15];
    int x=1;
    printf("\n\t\tENTER ID ");
    correction:
    fflush(stdin);
    gets(givenID);
    int b=0;
    sms = fopen("teacher_pass.txt","rb");
    while(fread(&pass, sizeof(pass),1,sms) == 1){
        if(strcmp(givenID,pass.ID) == 0){
               b = 1;
               break;
        }
    }
        if(b==1)
        {
          login(pass.password);
          teacher_window(pass.ID);

        }
        else
        {
             x++;
             if(x>3)
             {   printf("\n\n\n\t\t\aUsername didn't matched for three times\n\t\tGoing to main window");
        for(int i=0;i<5;i++)
        {
            delay(100000000);

            printf(". ");
        }
        for(int i=0;i<5;i++)
        {
            delay(100000000);

            printf(". ");
        }
            mainwindow();
        }
             printf("\n\n\t\aERROR IN FINDING !!!!\n");
             printf("\n Enter correct ID ");
             goto correction;
        }
        fclose(sms);
        return;

}
void student_passField()
{
    system("cls");
    char givenID[15];
    int x=1;
    printf("\n\t\tENTER ID ");
    correction:
    fflush(stdin);
    gets(givenID);
    int b=0;
    sms = fopen("student_pass.txt","rb");
    while(fread(&pass, sizeof(pass),1,sms) == 1){
        if(strcmp(givenID,pass.ID) == 0){
               b = 1;
               break;
        }
    }
        if(b==1)
        {
          login(pass.password);
          student_window(pass.ID);
        }
        else
        {
            x++;
             if(x>3)
             {   printf("\n\n\n\t\t\aUsername didn't matched for three times\n\t\tGoing to main window");
        for(int i=0;i<5;i++)
        {
            delay(100000000);

            printf(". ");
        }
        for(int i=0;i<5;i++)
        {
            delay(100000000);

            printf(". ");
        }
            mainwindow();
        }
             printf("\n\n\t\aERROR IN FINDING !!!!\n");
             printf("\n Enter correct ID ");
             goto correction;
        }
        fclose(sms);
return;
}

void login(char pass[10])
{
    char enterredPass[15];
    int wrong =1;
    printf("\n\t\tPASSWORD  ");
   correction:
    fflush(stdin);
   gets(enterredPass);

    if(strcmp(enterredPass,pass)==0)
    {
        printf("\n\t\tPassword matched\n\t\tLOADING");
        for(int i=0;i<5;i++)
        {
            delay(100000000);

            printf(". ");
        }

    }
    else
    {
        wrong++;
        if(wrong >3)
        {   printf("\n\t\t\aPassword didn't matched for three times\n\t\tGoing to main window");
        for(int i=0;i<10;i++)
        {
            delay(100000000);

            printf(". ");
        }
            mainwindow();
        }
        system("cls");
        system("color 04");
        printf("\a\n\t\tIncorrect Password !!!");
        printf("\n\t\tEnter correct password ");
        goto correction;
    }
    return;
}
void delay(int n)
{
    int j,k;
    for(j=0;j<n;j++)
        k=j;
    return;
}
void add_teacher()
{
    int b,n,x;
    char password[15];
    system("cls");
    front();
    printf("\n\n  'NEW TEACHER INFORMATION'\n\n");
    sms =fopen("teacher_record.txt","ab+");
    if(sms==NULL)
        printf("\n\tERROR!!!\ncan't open file");
    else
    {
       fflush(stdin);
       printf("Give an ID    : ");
       gets(per.ID);
       printf("Name          : ");
       gets(per.name);
       printf("Address       : ");
       gets(per.address);
       printf("Qualifiaction : ");
       gets(per.qua);
       printf("Phone Number  : ");
       scanf("%ld",&per.phn_num);
       printf("Password      : ");
       fflush(stdin);
       gets(password);
       printf("\nEnter total course number teacher will take : ");
       scanf("%d",&n);
       fflush(stdin);
       per.n = n;
        printf("\nEnter Information : \n");
         for(x =0;x< n ; x++)
         {
             char code[15];
             fflush(stdin);
             printf("Course code : ");
             fflush(stdin);
             gets(code);
             fflush(stdin);
             strcpy(per.code[x], strupr(code));
         }
       fwrite(&per,sizeof(per),1,sms);
    }
    fclose(sms);
    sms= fopen("teacher_pass.txt","ab+");
    if(sms==NULL)
        printf("\n\tERROR!!!\ncan't open file");
    else
    {

       fflush(stdin);
       strcpy(pass.ID,per.ID);
       strcpy(pass.password,password);
       fwrite(&pass,sizeof(pass),1,sms);
    }
    printf("\n\tNEW RECORD WRITTEN SUCCEFULLY\n");
    fclose(sms);
    return;

}
int check_pre_student_record(char ID[15])
{
    int b=0;
    sms =fopen("student_record.txt","rb");
     while(fread(&stud,sizeof(stud),1,sms) == 1)
    {
        if( strcmp(ID,stud.ID)==0 )
        {
            b =1;
            break;
        }
    }
       if(b==1)
        {
            return 1;
        }
        else if(b ==0 )
        {
            return 0;
        }
    return;
}

void add_student()
{
    char ID[15];
    char password[15];
    int n,x,sem_no;
    int check_info;
    float total_credit =0;
    system("cls");
    front();
    printf("\n\n  'NEW STUDENT INFORMATION'\n\n");
    printf("\nGive an ID    : ");
    fflush(stdin);
    retypeID:
    gets(ID);
    check_info = check_pre_student_record(ID);
    if(check_info != 0)
    {
        printf("\nThis ID is already taken!!!\n");
        printf("\nGive another ID : ");
        goto retypeID;
    }
    sms =fopen("student_record.txt","ab+");
    if(sms==NULL)
        printf("\n\tERROR!!!\ncan't open file");
    else
    {
        int choose;
       fflush(stdin);
       strcpy(stud.ID,ID);
       printf("Name          : ");
       gets(stud.name);
       printf("Address       : ");
       gets(stud.address);
       printf("Parents Name  : ");
       gets(stud.parents);
       printf("Phone Number  : ");
       scanf("%ld",&stud.phn_num);
       printf("Dept. Name    : ");
       printf("\n1. CSE        5. LAW");
       printf("\n2. EEE        6. ENGLISH");
       printf("\n3. PHARMACY   7. TEXTILE");
       printf("\n4. BBA        8. SCIENCE");
       printf("\n\nChoose department : ");
       correction:
       scanf("%d",&choose);
       switch (choose)
       {
        case 1:
           {
                strcpy(stud.dept,"CSE");
                break;
           }
        case 2:
           {
                strcpy(stud.dept,"EEE");
                break;
           }
        case 3:
           {
                strcpy(stud.dept,"PHARMACY");
                break;
           }
        case 4:
           {
                strcpy(stud.dept,"BBA");
                break;
           }
        case 5:
           {
                strcpy(stud.dept,"LAW");
                break;
           }
        case 6:
           {
                strcpy(stud.dept,"ENGLISH");
                break;
           }
        case 7:
           {
                strcpy(stud.dept,"TEXTILE");
                break;
           }
        case 8:
           {
                strcpy(stud.dept,"SCIENCE");
                break;
           }
           default :
            {
                printf("\nEnter correct option: ");
                goto correction;
            }

       }
       printf("Semester No.  : ");
       scanf("%d",&stud.sem);
       printf("Batch No.     : ");
       scanf("%d",&stud.batch);
       printf("Password : ");
       fflush(stdin);
       gets(password);
        fwrite(&stud,sizeof(stud),1,sms);
        fclose(sms);
    }
    system("cls");
    front();
    printf("\n\n  'NEW STUDENT INFORMATION'\n\n");
    printf("\nEnter university current session ");
    char uni_batch[15];
    fflush(stdin);
    gets(uni_batch);
    printf("\nEnter total course number ");
     fflush(stdin);
    scanf("%d",&n);
    s_result =fopen("student_result.txt","ab+");
    if(s_result==NULL)
        printf("\n\tERROR!!!\ncan't open file");
    else
    {
    fflush(stdin);
    strcpy(res.university_batch, strupr(uni_batch));
    fflush(stdin);
    strcpy(res.ID,stud.ID);
    fflush(stdin);
    res.n = n;
     fflush(stdin);
    res.sem = stud.sem;
    printf("\nEnter Information : \n");
    for(x =0;x<n ; x++)
         {
             char code[15];
             printf("Enter No.%d course code : ",x+1);
             fflush(stdin);
             gets(code);
             fflush(stdin);
             strcpy(res.code[x], strupr(code));
             printf("Course credit: ");
             scanf("%d",&res.credit[x]);
             total_credit += res.credit[x];
             res.result[x] = 0;
             printf("\n");
         }
       fwrite(&res,sizeof(res),1,s_result);
    }
    fclose(s_result);

    sms= fopen("student_pass.txt","ab+");
    if(sms==NULL)
        printf("\n\tERROR!!!\ncan't open file");
    else
    {
       fflush(stdin);
       strcpy(pass.ID,stud.ID);
       strcpy(pass.password,password);
       fwrite(&pass,sizeof(pass),1,sms);
    }
    fclose(sms);
    system("cls");
    front();
    printf("\n\n  'NEW STUDENT INFORMATION'\n\n");
    float credit_value;
    float charge;
    float total_money;
    sms = fopen("moneyreciept.txt","ab+");
    if(sms==NULL)
        printf("\n\tERROR!!!\ncan't open file");
    else
    {
        fflush(stdin);
        reciept.sem = stud.sem;
        printf("\nEnter per credit value : ");
        fflush(stdin);
        scanf("%f",&credit_value);
        printf("\nEnter charge for the semester : ");
        fflush(stdin);
        scanf("%f",&charge);
        fflush(stdin);
        strcpy(reciept.ID,stud.ID);
        total_money = (total_credit * credit_value) + charge;
        reciept.total = total_money;
        printf("\n%s have to pay total = %.2f taka",stud.ID,total_money);
        reciept.first_pay = total_money/2;
        strcpy(reciept.first_pay_data,"Not Paid");
        reciept.second_pay = total_money/2;
        strcpy(reciept.second_pay_data,"Not Paid");
        fwrite(&reciept,sizeof(reciept),1,sms);
    }
    fclose(sms);
    printf("\n\n\n\tNEW RECORD WRITTEN SUCCEFULLY\n");
    return;
}
void payment()
{
    char ID[15];
    int sem;
    system("cls");
    front();
    printf("\n\n  'STUDENT PAYMENT ENTRY'\n\n");
    printf("\nEnter student ID : ");
    fflush(stdin);
    gets(ID);
    sms =fopen("moneyreciept.txt","rb");
    while(fread(&reciept,sizeof(reciept),1,sms)==1)
    {
        if(strcmp(ID,reciept.ID) ==0)
        {
            sem = payment_data(ID);
            break;
        }
    }
    fclose(sms);
    sms =fopen("moneyreciept.txt","rb+");
    while(fread(&reciept,sizeof(reciept),1,sms)==1)
    {
        if((strcmp(ID,reciept.ID) ==0) && (sem == reciept.sem))
        {
            if((strcmp(reciept.first_pay_data,"Not Paid") ==1) && (strcmp(reciept.second_pay_data,"Not Paid") ==1))
               {
                   printf("\n\nTotal payment done");
                   return;
               }
            else
            {
                if(strcmp(reciept.first_pay_data,"Not Paid") == 0)
              {
                int choice;
                printf("\n\n\nFirst payment is not done");
                printf("\n\nFirst payment confirmation :\n\n");
                printf("\n1. CONFIRMED ");
                printf("\n2. Cancel");
                printf("\n\nEnter choice :");
                c1:
                fflush(stdin);
                scanf("%d",&choice);
                if(choice == 1)
                {
                    fflush(stdin);
                    strcpy(reciept.first_pay_data,"PAID");
                }
                else if(choice==2)
                {
                    return;
                }
                else{
                        printf("\n\aInvalid Option!!!");
                    goto c1;
                }
            }
            else
            {
                int choice;
                printf("\n\nFirst payment is done & second payment is not done");
                printf("\n\nSecond payment confirmation :\n\n");
                printf("\n1. CONFIRMED ");
                printf("\n2. Cancel");
                printf("\n\nEnter choice :");
                c2:
                fflush(stdin);
                scanf("%d",&choice);
                if(choice == 1)
                {
                    fflush(stdin);
                    strcpy(reciept.second_pay_data,"PAID");
                }
                else if(choice==2)
                {
                    return;
                }
                else
                {
                    printf("\n\aInvalid Option!!!");
                    goto c2;
                }
            }
        }
        fseek(sms,-sizeof(reciept),SEEK_CUR);
        fwrite(&reciept,sizeof(reciept),1,sms);
       break;
      }
    }
    fclose(sms);
    return;
}
int date_check( int d,int m,int y)
{
    int a = 1;
     if(( m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 ) &&(d>=1 && d<=31))
   {
       a =0;
   }
   else if((m==4 || m==6 || m==9 || m==11) && (d>=1 && d<=30))
   {
       a =0;
   }

   else if(m==2 && (d>=1 && d<=28))
   {
       a =0;
   }

    else if ( d == 29 && m == 2 &&(y%400==0 ||(y%4==0 && y%100!= 0)))
    {
      a =0;
    }
    return a;
}
void add_attendence(char ID[15])
{
    int choose;
    char code[15];
    int batch[10];
    int date,month,year;
    int check;
    int taken =0;
    char attendence[5];
    char present[5]= {"p"};
    char absent[5]= {"a"};
    system("cls");
    front();
    printf("\n\n  'ATTENDENCE INFORMATION'\n\n");
      sms = fopen("teacher_record.txt","rb");
    while(fread(&per, sizeof(per),1,sms) == 1)
        {
           if(strcmp(ID,per.ID) == 0)
         {
           int k,x;
            x = per.n;
            printf("\n\nYour courses are   : ");
            for(k =0;k<x;k++)
              {
                printf("\n%d - %s",k+1,per.code[k]);
               }
            break;
      }
    }
    fclose(sms);
    printf("\nEnter your choice : ");
    fflush(stdin);
    scanf("%d",&choose);
    fflush(stdin);
    switch (choose)
       {
        case 1:
           {
                strcpy(code,per.code[0]);
                break;
           }
        case 2:
           {
                strcpy(code,per.code[1]);
                break;
           }
        case 3:
           {
               strcpy(code,per.code[2]);
                break;
           }
        case 4:
           {
               strcpy(code,per.code[3]);
                break;
           }
        case 5:
           {
                strcpy(code,per.code[4]);
                break;
           }
        case 6:
           {
                strcpy(code,per.code[5]);
                break;
           }
        case 7:
           {
                strcpy(code,per.code[6]);
                break;
           }
        case 8:
           {
                strcpy(code,per.code[7]);
                break;
           }
            case 9:
           {
                strcpy(code,per.code[8]);
                break;
           }
            case 10:
           {
                strcpy(code,per.code[9]);
                break;
           }
           default :
            {
                teacher_window(ID);
                break;
            }
       }
    system("cls");
    front();
    printf("\n\n  'ATTENDENCE INFORMATION'\n\n");
    printf("Enter current date [dd mm yy] : ");
    correction_date:
    fflush(stdin);
    scanf("%d%d%d",&date,&month,&year);
    check = date_check(date,month,year);
    if (check ==1)
    {
        printf("\n\aEnter valid date [dd mm yy] : ");
        goto correction_date;
    }
    att_info= fopen("student_attendence.txt","rb");
    while(fread(&att_data,sizeof(att_data),1,att_info) == 1)
    {
        if( att_data.date == date && att_data.month == month && att_data.year == year && (strcmp(att_data.code,code) ==0 ) )
        {
            taken =1;
        }
    }
    fclose(att_info);
    system("cls");
    front();
    printf("\n\n  'ATTENDENCE INFORMATION'\n\n");
    int i,wrong;
    if(taken == 0)
    {
       s_result =fopen("student_result.txt","rb");
       printf("\n\nDATE : %d-%d-%d",date,month,year);
       while (fread(&res,sizeof(res),1,s_result)==1)
          {
              att_info= fopen("student_attendence.txt","ab+");
              int j;
              j = res.n;
                   for(i=0;i<=j;i++)
                      {
                          if(strcmp(res.code[i],code) ==0 )
                          {
                            att_info= fopen("student_attendence.txt","ab+");
                            printf("\n\nID : %s",res.ID);
                           fflush(stdin);
                           strcpy(att_data.ID,res.ID);
                           strcpy(att_data.code,res.code[i]);
                           att_data.date = date;
                           att_data.month = month;
                           att_data.year = year;
                           printf("\nPress [p] for present and [a] for absent  :   ");
                           correction2:
                               fflush(stdin);
                           gets(attendence);
                           if(strcmp(present,attendence)==0)
                                {
                                    strcpy(att_data.att_story,"p");
                                }
                            else if(strcmp(absent,attendence)==0)
                                 {
                                    strcpy(att_data.att_story,"a");
                                 }
                            else
                                 {
                                    printf("INVALID\a !!!\nEnter correct option : ");
                                    goto correction2;
                                }
                                wrong =1;
                                fwrite(&att_data,sizeof(att_data),1,att_info);
                                fclose(att_info);
                        }
                    }

               }
                fclose(sms);
       }
    if(taken ==1 && wrong !=1)
    {
        printf("\n\n\a             ERROR !!!!!");
        printf("\n      INVALID COURSE CODE or");
        printf("\n  ATTENDENCE OF THAT DAY IS TAKEN\n");
    }
    return;
}

void search_attendence(char ID[15])
{
    char givenID[15];
    char studentID[15];
    char code[15];
    char present_info[5]= {"p"};
    char absent_info[5]= {"a"};
    int choose, batch,a;
    int founded =0;
    int present =0;
    int absent =0;
    int total_class =0;
    int x =0;
    int y = 0;
    int i;
    float ratio;
    char department[25];
    search_again:
    if(strcmp(ID,"0") == 1)
    {
        strcpy(givenID,ID);
        system("cls");
        front();

    printf("\n\n  'ATTENDENCE INFORMATION'\n\n");
    sms = fopen("teacher_record.txt","rb");
    while(fread(&per, sizeof(per),1,sms) == 1)
        {
             if(strcmp(ID,per.ID) == 0)
                {
                    int k,x;
        x = per.n;
        printf("\n\nYour courses are   : ");
        for(k =0;k<x;k++)
           {
                printf("\n%d - %s",k+1,per.code[k]);
           }
            break;
        }

    }
    fclose(sms);
    printf("\nEnter your choice : ");
    fflush(stdin);
    scanf("%d",&choose);
    fflush(stdin);
    switch (choose)
       {
        case 1:
           {
                strcpy(code,per.code[0]);
                break;
           }
        case 2:
           {
                strcpy(code,per.code[1]);
                break;
           }
        case 3:
           {
               strcpy(code,per.code[2]);
                break;
           }
        case 4:
           {
               strcpy(code,per.code[3]);
                break;
           }
        case 5:
           {
                strcpy(code,per.code[4]);
                break;
           }
        case 6:
           {
                strcpy(code,per.code[5]);
                break;
           }
        case 7:
           {
                strcpy(code,per.code[6]);
                break;
           }
        case 8:
           {
                strcpy(code,per.code[7]);
                break;
           }
            case 9:
           {
                strcpy(code,per.code[8]);
                break;
           }
            case 10:
           {
                strcpy(code,per.code[9]);
                break;
           }
           default :
            {
                teacher_window(ID);
                break;
            }
       }
    }
    else
    {
    char tempsave[15];
    system("cls");
    printf("\n\t\tENTER COURSE CODE ");
    fflush(stdin);
    gets(tempsave);
    strcpy(code,strupr(tempsave));
    system("cls");
    front();
    printf("\n\n  'ATTENDENCE INFORMATION'\n\n");
    }
    Information:
    system("cls");
    front();

    printf("\nStudents in this course are : \n");
    s_result = fopen("student_result.txt","rb");
    // ID list for that batch
    while(fread(&res,sizeof(res),1,s_result) == 1)
    {
        int i,n;
        n= res.n;
        for(i=0;i<n;i++)
        {
              if(strcmp(res.code[i],code) ==0)
                    {
                        x =1;
                        printf("\nID  : %s",res.ID);
                    }

        }
    }
    fclose(s_result);
    if(x != 1)
        {
            int q;
            printf("\n\aINVALID INFORMATION");
            printf("\n    NOT FOUND !!!");
            printf("\npress 0 to return DASHBOARD or 1 for correction  ");
            scanf("%d",&q);
            if(q ==0 )
                return;
            else {
            printf("\nEnter correct information : ");
            goto search_again;
            }
        }
    printf("\nEnter ID you want to search from this list : ");
    fflush(stdin);
    gets(studentID);
    system("cls");
    front();
    printf("\n\tAttendence Information of %s",studentID);
    att_info= fopen("student_attendence.txt","rb");
    while(fread(&att_data,sizeof(att_data),1,att_info) == 1)
                 {
                       if((strcmp(att_data.code,code) == 0) && (strcmp(att_data.ID,studentID) == 0 ) )
                             {
                                        printf("\n%d-%d-%d  ",att_data.date,att_data.month,att_data.year);
                                        if((strcmp(att_data.att_story,present_info)==0))
                                             {
                                                       printf("Present");
                                                        present+=1;
                                              }
                                        else if((strcmp(att_data.att_story,absent_info)==0))
                                             {
                                                       printf("Absent");
                                                       absent+=1;
                                              }
                                     total_class+=1;
                                     founded =1;
                            }
                }
    fclose(att_info);
    if(founded ==1 )
    {
        ratio = (((float)present * 100) /(float)total_class);
        printf("\n\n\nTotal class was taken %d",total_class);
        printf("\n%s was present in %d class",studentID,present);
        printf("\n%s was absent in %d class",studentID,absent);
        printf("\n%s presence ratio is %.2f  ",studentID,ratio);
        printf("%");
    }

   else if (founded !=1)
        {
            printf(" is NOT FOUND !!!!");
        }
   printf("\n\n\n\nPress 0 to SEARCH AGAIN or\nPress 1 to for different course or\nPress 2 to goto DASHBOARD : ");
   scanf("%d",&a);
    if(a==0)
    {
    founded =0;
    present =0;
    absent =0;
     total_class =0;
     x =0;
     y = 0;
    goto Information;
    }


    else if (a == 1)
    {
        founded =0;
        present =0;
        absent =0;
        total_class =0;
        x =0;
        y = 0;
       goto search_again;
    }

    else
    {
        return;
    }
}
void del_data()
{
     att_info= fopen("student_attendence.txt","w");
    while(fread(&att_data,sizeof(att_data),1,att_info) == 1)
                {
                    if(feof(att_info))
                    {
                        break;
                    }
                }
    fclose(att_info);
    sms = fopen("student_result.txt","w");
     while(fread(&res,sizeof(res),1,sms) == 1)
                {
                    if(feof(sms))
                    {
                        break;
                    }
                }
    fclose(sms);
}
void edit_student()
{
    system("cls");
    char ID[15];
    int could_not_found =0;
    front();
    printf("\n\n  'MODIFY STUDENT INFORMATION'\n\n");
    printf("\nEnter student ID : ");
    fflush(stdin);
    gets(ID);
    sms =fopen("student_record.txt","rb+");
    while(fread(&stud,sizeof(stud),1,sms)==1)
    {
        if(strcmp(ID,stud.ID) ==0)
        {
       fflush(stdin);
       printf("Name          : ");
       gets(stud.name);
       printf("Address       : ");
       gets(stud.address);
       printf("Parents Name  : ");
       gets(stud.parents);
       printf("Phone Number  : ");
       scanf("%ld",&stud.phn_num);
       fseek(sms,-sizeof(stud),SEEK_CUR);
       fwrite(&stud,sizeof(stud),1,sms);
       could_not_found = 1;
       break;
        }
    }
    fclose(sms);
     if(could_not_found != 1)
    {
        printf("\n\aSTUDENT ID NOT FOUND !!!");
    }

   return;
}
void new_sem()
{
    system("cls");
    char ID[15];
    int could_not_found =0;
    front();
    printf("\n\n  'MODIFY STUDENT INFORMATION'\n\n");
    int sem;
    int batch;
    int z=0;
    system("cls");
    front();
    printf("\n\nEnter batch number : ");
    scanf("%d",&batch);
     printf("\n'Students of this batch are : '");
    sms = fopen("student_record.txt","rb");
    while(fread(&stud, sizeof(stud),1,sms) == 1)
        {
            if(stud.batch==batch)
            {
                 printf("\nID : %s     %s    %s",stud.ID,stud.name,stud.dept);
                 z=1;
            }
        }
    fclose(sms);
    if(z!=1)
    {
        int d;
        printf("\n\n\n\tNot found");
        printf("\n press 0 to go Dashboard ");
        scanf("%d",&d);
        admin_window();

    }
    printf("\n\nEnter student ID : ");
    fflush(stdin);
    gets(ID);
    sms =fopen("student_record.txt","rb+");
    while(fread(&stud,sizeof(stud),1,sms)==1)
    {
        if(strcmp(ID,stud.ID) ==0)
        {
       fflush(stdin);
       printf("Semester no   : ");
       scanf("%d",&stud.sem);
       fseek(sms,-sizeof(stud),SEEK_CUR);
       fwrite(&stud,sizeof(stud),1,sms);
       could_not_found = 1;
       break;
        }
    }
    fclose(sms);
    if(could_not_found == 1)
    {
        int total_credit =0;
        int n,x;
        printf("\nEnter university current session ");
        char uni_batch[15];
        fflush(stdin);
        gets(uni_batch);
        printf("\nEnter total course number ");
        fflush(stdin);
        scanf("%d",&n);
        s_result =fopen("student_result.txt","ab+");
        if(s_result==NULL)
            printf("\n\tERROR!!!\ncan't open file");
        else
         {

            fflush(stdin);
            strcpy(res.university_batch, strupr(uni_batch));
            fflush(stdin);
            strcpy(res.ID,ID);
            fflush(stdin);
            res.n = n;
            fflush(stdin);
            res.sem = stud.sem;
            printf("\nEnter Information : \n");
            for(x =0;x<n ; x++)
              {
                char code[15];
                printf("Enter No.%d course code : ",x+1);
                fflush(stdin);
                gets(code);
                fflush(stdin);
                strcpy(res.code[x], strupr(code));
                printf("Course credit: ");
                scanf("%d",&res.credit[x]);
                total_credit += res.credit[x];
                res.result[x] = 0;
                printf("\n");
              }
           fwrite(&res,sizeof(res),1,s_result);
         }
       fclose(s_result);
       sms = fopen("moneyreciept.txt","ab+");
    if(sms==NULL)
        printf("\n\tERROR!!!\ncan't open file");
    else
    {
         float credit_value;
        float charge;
        float total_money;
        fflush(stdin);
        reciept.sem = stud.sem;
        printf("\nEnter per credit value : ");
        fflush(stdin);
        scanf("%f",&credit_value);
        printf("\nEnter charge for the semester : ");
        fflush(stdin);
        scanf("%f",&charge);
        fflush(stdin);
        strcpy(reciept.ID,ID);
        total_money = (total_credit * credit_value) + charge;
        reciept.total = total_money;
        printf("\n%s have to pay total = %.2f taka",stud.ID,total_money);
        reciept.first_pay = total_money/2;
        strcpy(reciept.first_pay_data,"Not Paid");
        reciept.second_pay = total_money/2;
        strcpy(reciept.second_pay_data,"Not Paid");
        fwrite(&reciept,sizeof(reciept),1,sms);
    }
    fclose(sms);
    }
     if(could_not_found != 1)
    {
        printf("\n\aSTUDENT ID NOT FOUND !!!");
    }
   return;
}
void edit_teacher()
{
    system("cls");
    char ID[15];
    int x,n;
    int could_not_found =0;
    front();
    printf("\n\n  'MODIFY TEACHER INFORMATION'\n\n");
    printf("\nEnter teacher ID : ");
    fflush(stdin);
    gets(ID);
    FILE *sms;
    sms =fopen("teacher_record.txt","rb+");
    while(fread(&per,sizeof(per),1,sms)==1)
    {
        if(strcmp(ID,per.ID) ==0)
        {
        printf("\nEnter total course number teacher will take : ");
       scanf("%d",&n);
       fflush(stdin);
       per.n = n;
        printf("\nEnter Information : \n");
         for(x =0;x< n ; x++)
         {
             char code[15];
             fflush(stdin);
             printf("Course code : ");
             fflush(stdin);
             gets(code);
             fflush(stdin);
             strcpy(per.code[x], strupr(code));
         }
          fseek(sms,-sizeof(per),SEEK_CUR);
       fwrite(&per,sizeof(per),1,sms);
       could_not_found =1;
       break;
        }
    }
    fclose(sms);
    if(could_not_found != 1)
    {
        printf("\n\n\a    ERROR !!!");
    }
    return;
}
void main()
{
    front();
    mainwindow();
}
