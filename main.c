#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h" //future reference: struct defining file must come first or it throws errors
#include "display.h"
#include "input.h"


void main() {
    printf("======Billing and Management System======\n");
    //printf("Enter amount of items: ");
    //int n; scanf("%d", &n);

    struct customer cst = {" "};
    struct item initItem = {0, 0, NULL};
    struct item *ptr = &initItem;

    while (1) {
        printf("\nEnter\n1. To add items\n2. To remove items\n3. To view items\n4. To enter customer details\n5. To print final bill\n6. To exit\nYour choice: ");
        short int ch; scanf("%hd", &ch);

        switch(ch) {
            case 1:
                itemEntry(ptr);
                break;

            case 2:
                printf("\n\nEnter ID of item to delete: ");
                short int ID;
                scanf("%hd", &ID);
                ptr = deleteItem(ID, ptr);
                displayBill(ptr);
                break;

            case 3:
                displayBill(ptr);
                break;

            case 4:
                cst = custEntry(cst);
                break;

            case 5:
                if (!strcmp(" ", cst.name)) {
                    printf("\nEnter customer details first!\n");
                    break;
                }
                displayBill(ptr);
                displayDetails(cst);

                break;

            case 6:
                exit(0);

            default:
                printf("Invalid option entered! Try again.\n");

        }










    }

}
