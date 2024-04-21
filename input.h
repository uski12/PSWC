
//void itemEntry(char name[][50], int* qty, float* price, int n);

void itemEntry(struct item *initItem);

struct item* deleteItem(short int ID, struct item *initItem);

struct customer custEntry(struct customer cst);
