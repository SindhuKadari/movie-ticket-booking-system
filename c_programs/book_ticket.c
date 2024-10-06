#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Booking {
    int bookingId;
    char name[50];
    char show[50];
    struct Booking* next;
} Booking;

Booking* head = NULL;
int nextBookingId = 1;

void addBooking(char* name, char* show) {
    Booking* newBooking = (Booking*)malloc(sizeof(Booking));
    newBooking->bookingId = nextBookingId++;
    strcpy(newBooking->name, name);
    strcpy(newBooking->show, show);
    newBooking->next = head;
    head = newBooking;

    printf("%d\n", newBooking->bookingId); // Output the booking ID
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./book_ticket <name> <show>\n");
        return 1;
    }

    addBooking(argv[1], argv[2]);
    return 0;
}
