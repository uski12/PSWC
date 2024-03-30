#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include "input.h"

void main() {
    printf("======Billing and Management System======\n\n");
    //printf("Enter amount of items: ");
    //int n; scanf("%d", &n);

    int n = 50;

    char cust_name[50], email[50], mobno[11];
    custEntry(cust_name, email, mobno);

    char name[n][50]; int qty[n]; float price[n];
    n = itemEntry(name, qty, price, 0);

    displayBill(name, qty, price, n);

    displayDetails(cust_name, email, mobno);
}
