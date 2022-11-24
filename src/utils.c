#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "sort.h"
#include "fort.h"

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
    for (int i = 1; i <= len; i++) {
        char *cpf = malloc(11 * sizeof(int));
        sprintf(cpf, "%.11u", (unsigned) random_id_from_time(random()));
        transaction[i-1].cpf = cpf;

        transaction[i-1].id = random_id_from_time(i);
        transaction[i-1].value = (unsigned) random_id_from_time(random());
    }
}

void print_transactions(Transaction *transaction, int len) {
    for (int i = 0; i < len; i++) {
        printf("cpf: %s value: %f id: %d\n", transaction[i].cpf, transaction[i].value, transaction[i].id);
    }
}

void generate_table() {
    ft_table_t *table = ft_create_table();
    const char *slices[5] = { "10000", "25000", "50000", "75000", "100000" };

    ft_set_border_style(table, FT_DOUBLE2_STYLE);
    /* Set "header" type for the first row */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_ROW_TYPE, FT_ROW_HEADER);
    /* Center header row */
    ft_set_cell_prop(table, 0, FT_ROW_HEADER, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);
    ft_set_cell_prop(table, 0, 0, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);

    /* Center non-header rows */
    ft_set_cell_prop(table, FT_ANY_ROW, FT_ANY_COLUMN, FT_CPROP_TEXT_ALIGN, FT_ALIGNED_CENTER);

    /* Set header row foreground to cyan and bold */
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_CPROP_CONT_FG_COLOR, 5);
    ft_set_cell_prop(table, 0, FT_ANY_COLUMN, FT_TSTYLE_BOLD, (1U << 1));

    ft_write_ln(table, slices[0], slices[1], slices[2], slices[3], slices[4]);

    ft_write_ln(table, "Insertion Sort",       "Tempo 1", "Tempo 1", "Tempo 1", "Tempo 1");
    ft_write_ln(table, "Shell Sort",           "Tempo 2", "Tempo 2", "Tempo 2", "Tempo 2");
    ft_write_ln(table, "Cocktail Sort",        "Tempo 2", "Tempo 2", "Tempo 2", "Tempo 2");
    ft_write_ln(table, "Pancake Sort",         "Tempo 3", "Tempo 3", "Tempo 3", "Tempo 3");
    ft_write_ln(table, "Heap Sort",            "Tempo 4", "Tempo 4", "Tempo 4", "Tempo 4");
    ft_write_ln(table, "Bucket Sort (id)",     "Tempo 5", "Tempo 5", "Tempo 5", "Tempo 5");
    ft_write_ln(table, "Quick Sort (mediana)", "Tempo 6", "Tempo 6", "Tempo 6", "Tempo 6");

    printf("%s\n", ft_to_string(table));
    ft_destroy_table(table);
}

