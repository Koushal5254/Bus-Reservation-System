#include <stdio.h>
#include <string.h>

#define MAX_BUSES 3

int busNumbers[MAX_BUSES] = {101, 102, 103};
char sourceCities[MAX_BUSES][20] = {"Delhi", "Mumbai", "Chennai"};
char destinationCities[MAX_BUSES][20] = {"Bihar", "Pune", "Hyderabad"};
int totalSeats[MAX_BUSES] = {80, 60, 50};
int availableSeats[MAX_BUSES] = {80, 60, 50};
float fares[MAX_BUSES] = {725.0, 650.0, 520.0};

int findBusIndex(int busNum) {
    for (int i = 0; i < MAX_BUSES; i++) 
    {
        if (busNumbers[i] == busNum)
            return i;
    }
    return -1;
}

void bookTicket() 
{
    int busNum, seats;
    printf("\nEnter Bus Number: ");
    scanf("%d", &busNum);
    int index = findBusIndex(busNum);
    if (index == -1) {
        printf("Invalid Bus Number.\n");
        return;
    }
    printf("Enter Number Of Seats: ");
    scanf("%d", &seats);
    if (seats <= availableSeats[index]) {
        availableSeats[index] -= seats;
        printf("Booking Successful! %d seats booked on Bus Number %d\n", seats, busNum);
    } else {
        printf("Not enough seats available. Only %d left.\n", availableSeats[index]);
    }
}

int main() 
{
    int choice;
    do {
        printf("\n********** BUS RESERVATION SYSTEM **********\n");
        printf("1. For Booking\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", choice);

        if (choice == 1) 
        {
            bookTicket();
        } 
        else if(choice == 2)
        {
            printf("Thank you welcome again\n");
        }
        else
        {
            printf("Invalid choice");
        }
    } while (choice != 2);

    return 0;
}
