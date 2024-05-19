#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h" //future reference: struct defining file must come first or it throws errors
#include "display.h"
#include "input.h"
#include "search.h"


void main() {
    printf("======Billing and Management System======\n");
    //printf("Enter amount of items: ");
    //int n; scanf("%d", &n);

    struct customer cst = {" "};
    struct item initItem = {0, 0, NULL};
    struct item *ptr = &initItem;

    while (1) {
        printf("\nEnter\n1. To add items\n2. To remove items\n3. To view cart\n4. To view all items\n5. Search for item\n6. To enter customer details\n7. To print final bill\n8. To exit\nYour choice: ");
        short int ch; scanf("%hd", &ch);

        switch(ch) {
            case 1:
                displayItems();
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
                displayItems();
                break;

            case 5:
                char name[30];
                printf("\nEnter name of item to search for: ");
                scanf(" %[^\n]s", name);
                short int sID = search(name);

                if (sID != -1) {
                    struct details det = getDetails(sID);
                    printf("Item ID: %d, Item Price: INR %.2f\n\n", sID, det.price);
                } else
                    printf("Item not found!");

                break;

            case 6:
                cst = custEntry(cst);
                break;

            case 7:
                if (!strcmp(" ", cst.name)) {
                    printf("\nEnter customer details first!\n");
                    break;
                }
                displayBill(ptr);
                displayDetails(cst);
                exit(0);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid option entered! Try again.\n");

        }

    }

}
