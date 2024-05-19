#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"

struct details getDetails(int ID) {
    FILE *fp = fopen("items.csv", "r");
    char line[30]; char *details[3];

    struct details det = {"Not found", 0};

    while (fgets(line, 30, fp)) {
        details[0] = strtok(line, ",");
        details[1] = strtok(NULL, ",");
        details[2] = strtok(NULL, ",");

        if (atoi(details[0]) == ID) {
            strcpy(det.name, details[1]);
            det.price = atof(details[2]);
            fclose(fp);
            return det;
        }
    }
    fclose(fp);
}

void displayItems() {
    FILE *fp = fopen("items.csv", "r");
    char line[30]; char *details[3];

    printf("\n\nID\tItem Name\tItem Price\n\n");
    while (fgets(line, 30, fp)) {
        details[0] = strtok(line, ",");
        details[1] = strtok(NULL, ",");
        details[2] = strtok(NULL, ",");

        printf("%2d\t%-9s\t%10.2f/-\n", atoi(details[0]), details[1], atof(details[2]));

    }
    fclose(fp);
    printf("\n");
}

void displayBill(struct item *ptr) {

    float total = 0;

    printf("\n\n\t\t======  FINAL BILL  ======\n\n");
    printf("ID\tItem Name\tQuantity\tBase Price\tTotal\n\n");

    while (ptr->next != NULL) {
        struct details dtls = getDetails(ptr->ID);
        printf("%2d\t%-9s\tx%-8d\tINR %-10.2f\tINR %-8.2f\n", ptr->ID, dtls.name, ptr->qty, dtls.price, dtls.price*(ptr->qty));

        total += dtls.price * (ptr->qty);

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
