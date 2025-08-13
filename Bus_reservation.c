#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 10
#define MAX_BUSES 3

int isNumeric(char str[]) 
{
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// bus data
int busNumbers[MAX_BUSES] = {101, 102, 103};
char sourceCities[MAX_BUSES][20] = {"Delhi", "Mumbai", "Chennai"};
char destinationCities[MAX_BUSES][20] = {"Bihar", "Pune", "Hyderabad"};
int totalSeats[MAX_BUSES] = {80, 60, 50};
int availableSeats[MAX_BUSES] = {80, 60, 50};
float fares[MAX_BUSES] = {725.0, 650.0, 520.0};

// User data
char usernames[MAX_USERS][30];
char passwords[MAX_USERS][30];
int userCount = 0;

// bus index
int findBusIndex(int busNum) 
{
    for (int i = 0; i < MAX_BUSES; i++) 
    {
        if (busNumbers[i] == busNum)
            return i;
    }
    return -1;
}

// Sign Up
void signUp() 
{
    if (userCount >= MAX_USERS) 
    {
        printf("User limit reached.\n");
        return;
    }
    char newUser[30], newPass[30];
    printf("\nEnter new username: ");
    scanf("%s", newUser);
    printf("Enter new password: ");
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

// Sign In
int signIn() {
    char user[30], pass[30];
    printf("\nEnter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(usernames[i], user) == 0 && strcmp(passwords[i], pass) == 0) {
            printf("Login successful. Welcome, %s!\n", user);
            return 1;
        }
    }
    printf("Invalid credentials.\n");
    return 0;
}

// Book the Ticket
void bookTicket() 
{
    int busNum, seats;
    printf("\nEnter Bus Number: ");
    scanf("%d", &busNum);
    int index = findBusIndex(busNum);
    if (index == -1) 
    {
        printf("Invalid Bus Number.\n");
        return;
    }
    printf("Enter Number Of Seats: ");
    scanf("%d", &seats);
    if (seats <= availableSeats[index]) 
    {
        availableSeats[index] -= seats;
        printf("Booking Successful! %d seats booked on Bus Number %d\n", seats, busNum);
    } 
    else 
    {
        printf("Not enough seats available. Only %d left.\n", availableSeats[index]);
    }
}

// Cancel the Ticket
void cancelTicket() 
{
    int busNum, seats;
    printf("\nEnter Bus Number: ");
    scanf("%d", &busNum);
    int index = findBusIndex(busNum);
    if (index == -1) 
    {
        printf("Invalid Bus Number.\n");
        return;
    }
    printf("Enter Number Of Seats to Cancel: ");
    scanf("%d", &seats);
    if (availableSeats[index] + seats <= totalSeats[index]) 
    {
        availableSeats[index] += seats;
        printf("Cancellation Successful! %d seats canceled on Bus Number %d\n", seats, busNum);
    } else 
    {
        printf("Cancellation Failed! Cannot exceed total seats (%d).\n", totalSeats[index]);
    }
}

// Check the status of the Bus 
void checkBusStatus() 
{
    int busNum;
    printf("\nEnter Bus Number: ");
    scanf("%d", &busNum);
    int index = findBusIndex(busNum);
    if (index == -1) 
    {
        printf("Bus not found.\n");
        return;
    }
    printf("\nBus Number:          %d\n", busNumbers[index]);
    printf("Source City:         %s\n", sourceCities[index]);
    printf("Destination City:    %s\n", destinationCities[index]);
    printf("Total Seats:         %d\n", totalSeats[index]);
    printf("Available Seats:     %d\n", availableSeats[index]);
    printf("Fare:                %.2f\n", fares[index]);
}

// User Menu
void userMenu() 
{
    char input[10];
    int choice;
    do {
        printf("\n=== User Menu ===\n");
        printf("1. Book a Ticket\n");
        printf("2. Cancel a Ticket\n");
        printf("3. Check Bus Status\n");
        printf("4. Logout\n");
        printf("Enter your choice: ");
        scanf("%s", input);

         choice = atoi(input);

        switch (choice) 
        {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: checkBusStatus(); break;
            case 4: printf("Logging out...\n"); break;
            default: printf("Invalid choice. Try again.\n");
                        userMenu();
        }
    } while (choice != 4);
}

// Main Menu
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

        if (!isNumeric(input)) 
        {
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
                userMenu();
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


