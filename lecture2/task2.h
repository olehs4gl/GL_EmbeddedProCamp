
typedef struct my_ll {
	int number;
	char name[16];
	struct my_ll *next;
} myll;

void copy_digits(char* ,char*);

int biggest(int* , int);

myll *ListAdd(myll*);

void ListLs(myll*);

//remove all records from list
void ListRemoveAll(myll*);

//remove one record from list
int ListRemove(myll*, myll*);
