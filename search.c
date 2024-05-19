#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"

short int search(char name[30]) {
    FILE *fp = fopen("items.csv", "r");
    char line[30]; char *details[3];
    struct details det;


    while (fgets(line, 30, fp)) {
        details[0] = strtok(line, ",");
        details[1] = strtok(NULL, ",");
        details[2] = strtok(NULL, ",");

        if(!strcmp(name, details[1]))
            return atoi(details[0]);
    }
    return -1;
}
