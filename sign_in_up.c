#include <stdio.h>
#include <string.h>

#define MAX_USERS 10

// User data
char usernames[MAX_USERS][30];
char passwords[MAX_USERS][30];
int  userCount = 0;

int isNumeric(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}



void signUp()
{
    if (userCount >= MAX_USERS) 
    {
        printf("User limit reached.\n");
        return;
    }
    char newUser[30], newPass[30];
    printf("\nEnter your new username: ");
    scanf("%s", newUser);
    printf("Enter your new password: ");
    scanf("%s", newPass);

    for (int i = 0; i < userCount; i++) 
    {
        if (strcmp(usernames[i], newUser) == 0) 
        {
            printf("Username already exists. Try a different one.\n");
            return;
        }
    }

    strcpy(usernames[userCount], newUser);
    strcpy(passwords[userCount], newPass);
    userCount++;
    printf("Sign Up successful! You can now Sign In.\n");
}

int signIn() 
{
    char user_name[30], password[30];
    printf("\nEnter username: ");
    scanf("%s", user_name);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) 
    {
        if (strcmp(usernames[i], user_name) == 0 && strcmp(passwords[i], password) == 0) 
        {
            printf("Login successful. Welcome, %s!\n", user_name);
            return 1;
        }
    }
    printf("Invalid credentials.\n");
    return 0;
}

int main() 
{
    char input[10];
    int choice;
    do {
        printf("\n********** BUS RESERVATION SYSTEM **********\n");
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%s",input);

        if (!isNumeric(input)) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        choice = atoi(input);

        if (choice == 1) 
        {
            signUp();
        } 
        else if (choice == 2) 
        {
            if (signIn()) 
            {
               //After login it will go to userMenu();
            }
        } 
        else if (choice == 3) 
        {
            printf("Thank you welcome again!!..\n");
        } 
        else 
        {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 3);

    return 0;
}


