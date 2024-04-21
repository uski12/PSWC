#include <stdio.h>
#include "structs.h"

void displayBill(struct item *ptr) {

    char names[][20] = {"Ice Cream", "Butter", "Apples", "Jam", "Chocolates", "Biscuits", "Soap", "Chips", "Soda", "Pencil", "Moisturizer", "Oranges"};
    float prices[] = {15, 80, 90, 50, 20, 40, 70, 20, 40, 5, 90, 120};

    printf("\n\n\t\t======  FINAL BILL  ======\n\n");
    printf("ID\tItem Name\tQuantity\tBase Price\tTotal\n\n");

    float total = 0;

    while (ptr->next != NULL) {
        total += prices[ptr->ID] * (ptr->qty);

        printf("%2d\t%-9s\tx%-8d\tINR %-10.2f\tINR %-8.2f\n", ptr->ID, names[ptr->ID], ptr->qty, prices[ptr->ID], prices[ptr->ID]*(ptr->qty));
        ptr = ptr->next;
    }

    printf("\n====== Gross total: INR %.2f/- ======\n\n", total);

    /* OLD CODE
    float total = 0;

    for(int i = 0; i<n; i++) {
        float sum = *(qty+i)**(price+i);
        total += sum;

        printf("%-9s\tx%-8d\tINR %-10.2f\tINR %-8.2f\n", *(names+i), *(qty+i), *(price+i), sum);
    }*/
}

void displayDetails(struct customer c) {

    printf("Billed to %s, contact no. %s\n", c.name, c.mob_no);
}
