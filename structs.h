struct customer {
    char name[50];
    char email[50];
    char mob_no[11];
};


struct item {
    short int ID;
    short int qty;
    struct item* next;
};

struct details {
    char name[20];
    float price;
};


