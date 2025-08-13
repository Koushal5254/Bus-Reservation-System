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
    for (int i = 0; i < MAX_BUSES; i++) {
        if (busNumbers[i] == busNum)
            return i;
    }
    return -1;
}

void checkBusStatus() {
    int busNum;
    printf("\nEnter Bus Number: ");
    scanf("%d", &busNum);
    int index = findBusIndex(busNum);
    if (index == -1) {
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

int main()
{
    int choice;
    do {
        printf("\n********** BUS RESERVATION SYSTEM **********\n");
        printf("1. To check bus status..\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) 
        {
            checkBusStatus();
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
