#ifndef _UTILSH_
#define _UTILSH_

#include "sort.h"
typedef int(*cmp_func)(Transaction*, Transaction*);

#endif

long random_id_from_time(unsigned long u_id);
void randomize_transactions(struct Transaction *transaction, int len);
void print_transactions(struct Transaction *transaction, int len);
char ***benchmark_all(Transaction *transaction, const unsigned int *slices, cmp_func cmp, int is_by_id);
void generate_table(char ***matriz, int is_by_id);
