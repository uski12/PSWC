#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

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


void itemEntry(struct item *ptr) {
    printf("\n==\tEnter item data (enter '-1' to stop)\t==\n");
    int i = 0;
    while (++i) {
        printf("\nItem %d ID: ", i);
        scanf("%hd", &ptr->ID);
        ptr->qty = 0;

        if(ptr->ID == -1) //exit condition
            break;

        printf("Quantity: ");
        scanf("%hd", &ptr->qty);

        ptr->next = (struct item*) malloc(sizeof(struct item));
        ptr = ptr->next;
        ptr->next = NULL;
    }

    /*int i = 100;
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
    } */
}

struct item* deleteItem(short int delID, struct item *ptr) {
    struct item* initPtr = ptr;
    if (ptr->ID == delID) {
        printf("ye");
        ptr = ptr->next;
        return ptr;
    }

    while (ptr->next != NULL) {
        if (ptr->next->ID == delID) {
            ptr->next = ptr->next->next;
        }
        ptr = ptr->next;
    }
    return initPtr;
}

struct customer custEntry(struct customer cust) {
    printf("==\tEnter customer data\t==");
    printf("\nCustomer name: ");        scanf(" %[^\n]*c", cust.name);
    printf("Customer e-mail: ");        scanf(" %[^\n]s", cust.email);
    printf("Customer phone number: ");  scanf(" %[^\n]s", cust.mob_no);
    return cust;
}

