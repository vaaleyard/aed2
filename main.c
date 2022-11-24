#include <stdio.h>
#include <stdlib.h>
#include "src/sort.h"
#include "src/utils.h"

// const unsigned int slices[5] = { 10000, 25000, 50000, 75000, 100000 };
const unsigned int slices[5] = { 6, 4, 5, 6, 7 };

int main (int argc, char *argv[])
{
    struct Transaction *first_slice_transactions  = malloc(slices[0] * sizeof(struct Transaction));
    // struct Transaction *second_slice_transactions = malloc(slices[1] * sizeof(struct Transaction));

    randomize_transactions(first_slice_transactions, slices[0]);
    // randomize_transactions(second_slice_transactions, slices[1]);

    printf("random generated transactions:\n");
    print_transactions(first_slice_transactions, slices[0]);

    printf("\nshell sorting by value:\n");
    shellsort(first_slice_transactions, slices[0], cmp_valor);
    print_transactions(first_slice_transactions, slices[0]);

    // pancakeSort(first_slice_transactions, slices[0], cmp_id);
    // heapSort(first_slice_transactions, slices[0], cmp_id);
    // Bucket_Sort(first_slice_transactions, slices[0]);

    free(first_slice_transactions);
    // free(second_slice_transactions);
    return 0;
}
