#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  login();
void  mainmenu();
void  newacc();
void  display();
void  search();
void  update();
void  depwithbal();
void  deleteacc();

struct bank
{
    char name[15];
    char fname[15];
    char surname[15];
    int  dob_yyyy;
    char aadhar[15];
    char city[20];
    char address[30];
    char mobile[11];
    char acc_type[10];
    char acc_no[15];

};
    struct bank b;


int main()
{
 printf("\n\t\t\t\tWelcome to AVS Bank!\n");
    printf("\n\t\t\t\tPress any key to continue");
    getch();
    login();
}

void login(){
    char user[15],pass[15];
    system("cls");
printf("\nEnter Username and Password to login !\n\n");
printf("\nEnter Username: \n");
gets(user);
printf("\nEnter Password: \n");
gets(pass);
if(strcmp(user,"bank")==0){
   if(strcmp(pass,"bank1")==0){
       printf("\n Login Successful!");
       printf("\n Press any key to continue");
       getch();
       mainmenu();
   }
}
else{
    printf("\nInvalid Username or password\n");
}
}

void mainmenu(){
    int choice;
    lineno65:
system("cls");
printf("\t\t\tMenu\t\t\t\n");
printf("\n\t\t 1. Create New Account\n");
printf("\n\t\t 2. Display Details\n");
printf("\n\t\t 3. Search Account\n");
printf("\n\t\t 4. Update Account\n");
printf("\n\t\t 5. Deposit,Withdraw,Balance\n");

printf("\n\t\t 6. Delete Account\n");
printf("\n\t\t 7. Exit\n");
printf("\n Enter Your Choice");
scanf("%d",&choice);

switch(choice){
case 1:
    newacc();
    goto lineno65;
case 2:
    display();
goto lineno65;
case 3:
     search();
     goto lineno65;
case 4:
    update();
     goto lineno65;
case 5:
    depwithbal();
     goto lineno65;
case 6:
    deleteacc();
    goto lineno65;
case 7:
    printf("\n\t\t Thank You for Visiting Us!!");
    printf("Press any key to exit");
    getch();
    exit(0);

default:
    printf("\nInvalid Choice!Please enter a valid selection between 1 to 8");
    printf("\nPress any key to continue");
    getch();
    goto lineno65;
}

}

void newacc(){

        system("cls");
        FILE *fp;
        fp=fopen("bank.txt","ab+");
        if(fp==NULL)
        {
        printf("\nError! Can't Open File");
        return;
        }
        printf("\nEnter Name: ");
        scanf("%s",b.name);
        printf("\nEnter Father's Name: ");
        scanf("%s",b.fname);
        printf("\nEnter Surname: ");
        scanf("%s",b.surname);
        printf("\nEnter Birth Year: ");
        scanf("%d",&b.dob_yyyy);
        printf("\nEnter Aadhar Number: ");
        scanf("%s",b.aadhar);
        printf("\nEnter City: ");
        scanf("%s",b.city);
        printf("\nEnter Address: ");
        scanf("%s",b.address);
        printf("\nEnter Mobile Number: ");
        scanf("%s",b.mobile);
        printf("\nEnter Account Type you want to open savings or current: ");
        scanf("%s",b.acc_type);
        printf("\nEnter 13 digit Account Number Of your choice: ");
        scanf("%s",b.acc_no);

        fwrite(&b,sizeof(b),1,fp);
        {
            printf("\nAccount Created Successfully ");
        }
        fclose(fp);
        printf("\nPress any key to continue");
        getch();
}

void display(){
    system("cls");
    FILE *fp;
    fp=fopen("bank.txt","rb");
    if(fp==NULL)
    {
        printf("\nError While Opening File");
        return;
    }
    printf("\nExisting Accounts\n\n");
    while(fread(&b,sizeof(b),1,fp)==1)
    {
   printf("\nName of Customer: %s",b.name);
   printf("\nSurname of Customer: %s",b.surname);
   printf("\nAccount Number: %s",b.acc_no);
   printf("\nAccount Type: %s",b.acc_type);
   printf("\nMobile Number: %s",b.mobile);
   printf("\nAadhar Number: %s",b.aadhar);
   printf("\n\n");
    }
    fclose(fp);
      printf("\npress any key to continue");
     getch();

}

void search(){
system("cls");
char a[15];
    int flag=0;
        FILE *fp;
        fp=fopen("bank.txt","rb");
        if(fp==NULL)
        {
            printf("\nError Opening File");
            return;
        }
        printf("\nEnter Account Number you want to search: ");
        scanf("%s",a);
        while(fread(&b,sizeof(b),1,fp)>0&&flag==0)
        {
            if(strcmp(b.acc_no,a)==0)
            {
            flag=1;
            printf("\nName of Customer: %s",b.name);
   printf("\nSurname of Customer: %s",b.surname);
   printf("\nAccount Number: %s",b.acc_no);
   printf("\nAccount Type: %s",b.acc_type);
   printf("\nMobile Number: %s",b.mobile);
   printf("\nAddress: %s",b.address);
   printf("\n\n");
            }
        }
        if(flag==0)
        {
            printf("\n Error: No record found\a");
        }
        fclose(fp);
        printf("\n press any key to continue");
     getch();
}

void update(){
system("cls");
    int flag=0;
    char ad[15];
    FILE *fp;
    fp=fopen("bank.txt","rb+");
    if(fp==NULL)
    {
        printf("\nError In Opening File");
        return;
    }
    printf("\nEnter Aadhar Number of Customer: ");
    scanf("%s",ad);
        while(fread(&b,sizeof(b),1,fp)>0&&flag==0)
        {
            if(strcmp(b.aadhar,ad)==0)
            {
                 flag=1;
                    printf("\nEdit Record\n\t\a");
                    fflush(stdin);
                    printf("\nUpdate Customer Name:\t\a");
                    scanf("%s",b.name);
                    printf("\nUpdate Customer Surname:\t\a");
                    scanf("%s",b.surname);
                    printf("\nUpdate Customer's Mobile Number:\t\a");
                    scanf("%s",b.mobile);
                    printf("\nUpdate Address:\t\a");
                    scanf("%s",b.address);
                    printf("\nUpdate City: ");
                    scanf("%s",b.city);

                    fseek(fp,-(long)sizeof(b),1);
                    fwrite(&b,sizeof(b),1,fp);
                    printf("\nRecord Updated Successfully");
            }
             if(flag==0)
            {
                printf("\nNo such data exist!");
            }
        }
        fclose(fp);
        printf("\nPress any key to continue");
        getch();
}



void depwithbal(){
    system("cls");
float x,y;
int ch;
printf("\n\t\tEnter initial amount\n");
scanf("%f",&x);
system("cls");
printf("\t\t\tServices\t\t\t\n");
printf("\n\t\t 1. Deposit Money\n");
printf("\n\t\t 2. Withdraw Money\n");
printf("\n\t\t 3. Check Balance\n");
printf("\n\t\tChoose Your Service: ");
scanf("%d",&ch);
switch(ch){

 case 1:
     printf("\nEnter Amount you want to deposit:\n ");
     scanf("%f",&y);
     x=x+y;
     printf("\nNow Your total Amount is: %f\n",x);
    break;
 case 2:
     printf("\nEnter Amount you want to withdraw: ");
     scanf("%f",&y);
     if(x>=y){
     x=x-y;
     printf("\nNow Your total Amount is: %f\n",x);
     }
     else{
        printf("\n Insufficent amount in your account\n");
     }
     break;

 case 3:
    printf("\nYour Total Balance: %f\n",x);
    break;


 default:
    printf("\nInvalid selection\n");
}
  printf("\nPress any key to continue\n");
    getch();
}

void deleteacc(){
system("cls");
    char n[20];
    unsigned flag=0;
    FILE *fp,*ft;
    fp=fopen("bank.txt","rb");

    if(fp==NULL)
       {
           printf("\nError Opening File");
           return;
       }
       printf("\nEnter Account Number You want to delete:");
       scanf("%s",n);
       ft=fopen("bank1.txt","ab+");
       while(fread(&b,sizeof(b),1,fp)==1)
        {
            if(strcmp(b.acc_no,n)!=0)
            {
                printf("\n Account Deleted!\n ");
                fwrite(&b,sizeof(b),1,ft);
            }
            else
                flag=1;
        }
        if(flag==0)
        {
            printf("\nNo Such Record Found");
        }

        fclose(fp);
        fclose(ft);
        remove("bank.txt");
        rename("bank1.txt","bank.txt");
        printf("\nPress any key to continue");
        getch();
}
