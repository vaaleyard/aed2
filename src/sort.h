typedef struct Transaction {
    unsigned int id;
    char *cpf;
    double value;
} Transaction;

typedef int(*cmp_func)(Transaction*, Transaction*);

int cmp_id(Transaction *tr1, Transaction *tr2);
int cmp_valor(Transaction *tr1, Transaction *tr2);

void shellsort(struct Transaction *transactions, int len, cmp_func cmp);

int findMax(Transaction *arr, int n, cmp_func cmp);
void flip(Transaction *arr, int i);
void pancakeSort(Transaction* arr, int n, cmp_func cmp);

void heapSort(Transaction arr[], int n, cmp_func cmp);
void Bucket_Sort(Transaction array[], int size);