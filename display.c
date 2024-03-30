#include <stdio.h>

void displayBill(char names[][50], int *qty, float *price, int n) {
    printf("\n\n\t\t======  FINAL BILL  ======\n\n");
    printf("Item Name\tQuantity\tBase Price\tTotal\n\n");

    float total = 0;

    for(int i = 0; i<n; i++) {
        float sum = *(qty+i)**(price+i);
        total += sum;

        printf("%-9s\tx%-8d\tINR %-10.2f\tINR %-8.2f\n", *(names+i), *(qty+i), *(price+i), sum);
    }
    printf("\n====== Gross total: INR %.2f/- ======\n\n", total);
}

void displayDetails(char name[50], char email[50], char mobno[11]) {
    printf("Billed to %s, contact no. %s\n", name, mobno);
}
