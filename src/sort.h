typedef struct Transaction {
    unsigned int id;
    char *cpf;
    double value;
} Transaction;

typedef int(*cmp_func)(Transaction*, Transaction*);

int cmp_id(Transaction *tr1, Transaction *tr2);
int cmp_value(Transaction *tr1, Transaction *tr2);
int cmp_cpf(Transaction *tr1, Transaction *tr2);

void insertionsort(Transaction *transactions, int len, cmp_func cmp);
void shellsort(struct Transaction *transactions, int len, cmp_func cmp);
void pancakesort(Transaction* arr, int n, cmp_func cmp);
void heapsort_(Transaction arr[], int n, cmp_func cmp);
void cocktailsort(Transaction *transaction, int len, cmp_func cmp);
void bucketsort(Transaction array[], int size);
