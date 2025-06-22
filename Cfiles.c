//no matter what do not let C, try to update and create new tools, however, try to learn another programms so they can hire you quickly!


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void greet(char name[]){

    printf("\t****Welcome %s****\n", name);

}
int main(){
    char name[30];
    int options;
    char Y_N;
    int option;
    char login[30];
    char password[30];
    char regisuser[40];
    char regispassword[40];

printf("ingrese su nombre: ");
scanf("%s", name); 

printf("===Welcome  to your dedicate programming page!===\n");
      greet(name); 

printf("\tPress 1 to long it: \n");
     printf("\tPress 2 to register for the first time: \n");

     printf("select an option here: ");
scanf("%d", &option);

     switch(option){

        case 1: printf(" you have submitted logged in: ");

    printf("\nEnter your username: ");
    scanf("%s", login);

 fflush(stdin);

    printf("\nEnter your password:");
    scanf("%s", password);
//to save the data of the user that is going to log into
    FILE *fptr;
    fptr = fopen("data.txt", "r");

    if (fptr==NULL){
        printf("error opening this file! (no users registered)\n");
    return 1;
    }
    char file_user[40], file_pass[40];
    bool found =false;
    
      while (fscanf(fptr, "%s %s", file_user, file_pass) != EOF) {
            if (strcmp(file_user, login) == 0 && strcmp(file_pass, password) == 0) {
                found = true;
                break;
            }
        }

        fclose(fptr);

        if (!found) {
            printf("\nInvalid username or password.\n");
            return 1;
        }

    printf("\nYou have successfully logged in!\n");

        printf("You have multiples options to choose from:\n");
        printf("1. View your profile\n");
        printf("2. Edit your profile\n");
        printf("3. Logout\n");
        printf("4. Delet your account\n");
        printf("5. Exit\n");
        printf("6. See all the users availables\n");


while ((getchar())!='\n'); 

printf("Please select an option: ");
scanf("%d", &options);
     
switch(options){
    case 1:
    printf("viewing your profile...\n");
    printf("your profile name is: %s", name);
break;

case 2:
printf("Editing your profile...\n");
printf("Your current name is: %s\n", name);

printf("enter your new name: ");
scanf("%s", name);
printf("your new name is: %s", name);
fflush(stdin);

do{ //to printf the condition and then the while to make sure that read the first steps which is Y or N
printf("\nwould you like to edit your Password? Y/N:\n");
scanf("%c", &Y_N);  

 if(Y_N=='Y' || Y_N=='y'){
    printf("To change your password enter the new one: ");
    scanf("%s", password);

 printf("your new password is: %s", password);
    printf("\nYou have changed your password already!");
    break;

} else if(Y_N== 'N' || Y_N=='n') {
printf("We have cancel the process, try it again");
break;

} else{
    printf("invalid option...");

} 
} while(1);
break;

case 3:
printf("you are loggin out from your account!");

printf("\nThanks for using our programm goodbye!");

return 0;
break;


case 4:
{
    // Declare a string, not an int
    char deleteConfirm[10];
    printf("To delete your account, type 'Delete' or 'delete': ");
    scanf("%s", deleteConfirm);

    if (strcmp(deleteConfirm, "Delete") == 0 || strcmp(deleteConfirm, "delete") == 0) {
        FILE *fp = fopen("data.txt", "r");
        FILE *temp = fopen("temp.txt", "w");

        if (fp == NULL || temp == NULL) {
            printf("Error opening files.\n");
            return 1;
        }

        char file_user[40], file_pass[40];

        while (fscanf(fp, "%s %s", file_user, file_pass) != EOF) {
            // Write to temp only if not the user we want to delete
            if (strcmp(file_user, login) != 0) {
                fprintf(temp, "%s %s\n", file_user, file_pass);
            }
        }

        fclose(fp);
        fclose(temp);

        remove("data.txt");
        rename("temp.txt", "data.txt");

        printf("Your account has been deleted successfully.\n");
        return 0;
    } else {
        printf("Account deletion canceled.\n");
    }
    break;
}
case 6: {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL){
        printf("No registered users found \n");
        break;
    }
    char u[40], p[40];
    printf("\n=== Registered user===\n");
    while (fscanf(fp, "%s %s", u, p) != EOF){
        printf("-%s\n", u);
    }
    fclose(fp);
    break;
}
}
break;

case 2:
printf("Please enter your username:");
scanf("%s", regisuser);

printf("\nEnter your password: ");
scanf("%s",regispassword);


FILE *fwriteptr = fopen("data.txt", "a");
if (fwriteptr == NULL){
    printf("Error opening file for writing.\n");
    return 1;
}
// this is to make a registration of the password as the user,
fprintf(fwriteptr, "%s %s\n", regisuser, regispassword);
fclose(fwriteptr);

printf("\nYou have successfully logged in!\n");

        printf("You have multiples options to choose from:\n");
        printf("1. View your profile\n");
        printf("2. Edit your profile\n");
        printf("3. Logout\n");
        printf("4. Delet your account\n");
        printf("5. Exit\n");
        printf("6. See all the users availables\n");

while ((getchar())!='\n'); 

printf("Please select an option: ");
scanf("%d", &options);
     
switch(options){
    case 1:
    printf("viewing your profile...\n");
    printf("your profile name is: %s", name);
break;

case 2:
printf("Editing your profile...\n");
printf("Your current name is: %s\n", name);

printf("enter your new name: ");
scanf("%s", name);
printf("your new name is: %s", name);
fflush(stdin);

do{ //to printf the condition and then the while to make sure that read the first steps which is Y or N
printf("\nwould you like to edit your Password? Y/N:\n");
scanf("%c", &Y_N);  

 if(Y_N=='Y' || Y_N=='y'){
    printf("To change your password enter the new one: ");
    scanf("%s", password);

 printf("your new password is: %s", password);
    printf("\nYou have changed your password already!");
    break;

} else if(Y_N== 'N' || Y_N=='n') {
printf("We have cancel the process, try it again");
break;

} else{
    printf("invalid option...");

} 
} while(1);
break;

case 3:
printf("you are loggin out from your account!");

printf("\nThanks for using our programm goodbye!");

return 0;
break;

  case 4: {
    // Declare a string, not an int
    char deleteConfirm[10];
    printf("To delete your account, type 'Delete' or 'delete': ");
    scanf("%s", deleteConfirm);

    if (strcmp(deleteConfirm, "Delete") == 0 || strcmp(deleteConfirm, "delete") == 0) {
        FILE *fp = fopen("data.txt", "r");
        FILE *temp = fopen("temp.txt", "w");

        if (fp == NULL || temp == NULL) {
            printf("Error opening files.\n");
            return 1;
        }

        char file_user[40], file_pass[40];

        while (fscanf(fp, "%s %s", file_user, file_pass) != EOF) {
            // Write to temp only if not the user we want to delete
            if (strcmp(file_user, login) != 0) {
                fprintf(temp, "%s %s\n", file_user, file_pass);
            }
        }

        fclose(fp);
        fclose(temp);

        remove("data.txt");
        rename("temp.txt", "data.txt");

        printf("Your account has been deleted successfully.\n");
        return 0;
    } else {
        printf("Account deletion canceled.\n");
    }
    break;
}
case 6: {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL){
        printf("No registered users found \n");
        break;
    }
    char u[40], p[40];
    printf("\n=== Registered user===\n");
    while (fscanf(fp, "%s %s", u, p) != EOF){
        printf("-%s\n", u);
    }
    fclose(fp);
    break;
}
}


 return 0;
}
}



