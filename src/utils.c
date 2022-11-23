#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "sort.h"

// don't ask shhhhh
long random_id_from_time(unsigned long u_id) {
    struct timeval t;
    unsigned long id;

    gettimeofday(&t,NULL);
    id = ((t.tv_sec * 1000 * 1000) + (t.tv_usec * 1000)) << 42;
    id |= (u_id % 16777216) << 24;

    return id;
}

void randomize_transactions(Transaction *transaction, int len) {
    // starts at 1 because random_id_from_time returns 0 receiving 0 as parameter
    Transaction *transaction_tmp = malloc(len * sizeof(Transaction));
    for (int i = 1; i <= len; i++) {
        char *cpf = malloc(11 * sizeof(int));
        sprintf(cpf, "%.11u", (unsigned) random_id_from_time(random()));
        transaction_tmp[i-1].cpf = cpf;

        transaction_tmp[i-1].id = random_id_from_time(i);
        transaction_tmp[i-1].value = (unsigned) random_id_from_time(random());
        printf("cpf: %s value: %f id: %d\n", transaction_tmp[i-1].cpf, transaction_tmp[i-1].value, transaction_tmp[i-1].id);
        transaction[i] = transaction_tmp[i];
    }
}

void print_transactions(Transaction *transaction, int len) {
    for (int i = 0; i < len; i++) {
        printf("cpf: %s value: %f id: %d\n", transaction[i].cpf, transaction[i].value, transaction[i].id);
    }
}
