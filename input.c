#include <stdio.h>

/*
void itemEntry(char name[][50], int* qty, float* price, int n) {
    for(int i = 0; i<n; i++) {
        printf("\nItem %d name: ", i+1);
        scanf("%s", name[i]);
        printf("Quantity: ");
        scanf("%d", &qty[i]);
        printf("Price: ");
        scanf("%f", &price[i]);
    }
}*/


int itemEntry(char name[][50], int* qty, float* price, int n) {
    printf("\n==\tEnter item data (enter '-' to stop entry)\t==\n");

    int i = 100;
    while (i--) {
        printf("\nItem %d name: ", n+1);
        scanf(" %[^\n]s", name[n]);

        if(name[n][0] == '-') //exit condition
            break;

        printf("Quantity: ");
        scanf("%d", &qty[n]);
        printf("Price: ");
        scanf("%f", &price[n]);

        n++;
    }
    return n;
}

void custEntry(char name[50], char email[50], char mob_no[11]) {
    printf("==\tEnter customer data\t==");
    printf("\nCustomer name: "); scanf(" %[^\n]*c", name);
    printf("Customer e-mail: "); scanf(" %[^\n]s", email);
    printf("Customer phone number: "); scanf(" %[^\n]s", mob_no);
}

