#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "sort.h"

void swap(Transaction *tr1, Transaction *tr2) {
    Transaction temp = *tr1;
    *tr1 = *tr2;
    *tr2 = temp;
}

int cmp_id(Transaction *tr1, Transaction *tr2) {
    if (tr1->id > tr2->id)
        return 1;
    else if (tr1->id == tr2->id)
        return 0;

    return -1;
}

int cmp_value(Transaction *tr1, Transaction *tr2) {
    if (tr1->value > tr2->value)
        return 1;

    if (tr1->value == tr2->value)
        return 0;

    return -1;
}

int cmp_cpf(Transaction *tr1, Transaction *tr2) {
    int res = strcmp(tr1->cpf, tr2->cpf);

    if (res > 0)
        return 1;
    else if (res == 0)
        return 0;

    return -1;
}

/* Insertion sort */
void insertionsort(Transaction *transactions, int len, cmp_func cmp) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (cmp(&transactions[j - 1], &transactions[j]) == 1) {
                swap(&transactions[j - 1], &transactions[j]);
            }
        }
    }
}

/* Shell sort */
void shellsort(Transaction *transactions, int len, cmp_func cmp) {
    int i, j, k, h = 1;
    Transaction aux;

    do { h = h * 3 + 1;
    } while (h < len);

    do {
        h /= 3;
        for(i = h ; i < len ; i++) {
            aux = transactions[i];
            j = i;
            while (cmp(&transactions[j - h],  &aux) == 1) {
                transactions[j] = transactions[j - h];
                j -= h;
                if (j < h) break;
            }
            transactions[j] = aux;
        }
    } while (h != 1);
}

/* Pancake sort */
void pancakesort_flip(Transaction *arr, int i) {
    int start = 0;
    Transaction *temp;
    while (start < i) {
        swap(&arr[start], &arr[i]);
        start++;
        i--;
    }
}

int pancakesort_findMax(Transaction *arr, int n, cmp_func cmp) {
    int mi, i;

    for (mi = 0, i = 0; i < n; ++i)
        if (cmp(&arr[i], &arr[mi]) == 1)
            mi = i;

    return mi;
}

void pancakesort(Transaction* arr, int n, cmp_func cmp) {
    for (int curr_size = n; curr_size > 1; --curr_size) {
        int mi = pancakesort_findMax(arr, curr_size, cmp);

        if (mi != curr_size - 1) {
            pancakesort_flip(arr, mi);
            pancakesort_flip(arr, curr_size - 1);
        }
    }
}

/* Heap sort */
void heapsort_heapify(Transaction arr[], int n, int i, cmp_func cmp) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && cmp(&arr[left], &arr[largest]) == 1)
        largest = left;

    if (right < n && cmp(&arr[right], &arr[largest]) == 1)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapsort_heapify(arr, n, largest, cmp);
    }
}

void heapsort_(Transaction arr[], int n, cmp_func cmp) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapsort_heapify(arr, n, i, cmp);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapsort_heapify(arr, i, 0, cmp);
    }
}

/* Cocktail Sort */
void cocktailsort(Transaction *transaction, int len, cmp_func cmp) {
    int swapped = 1, start = 0;
    int end = len - 1;

    while (swapped) {
        swapped = 0;

        for (int i = 0; i < end; i++) {
            if (cmp(&transaction[i], &transaction[i + 1]) == 1) {
                swap(&transaction[i], &transaction[i + 1]);
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        end -= 1;

        for (int i = end - 1; i < start - 1; i--) {
            if (cmp(&transaction[i], &transaction[i + 1]) == 1) {
                swap(&transaction[i], &transaction[i + 1]);
                swapped = 1;
            }
        }

        swapped = 1;
    }
}

/* Bucket Sort */
int bucketsort_max_element(int array[], int size) {  
    int max = array[0];
    for (int i = 0; i < size; i++) {
            if (array[i] > max)
                max = array[i];
        }

    return max;
}

void bucketsort(int array[], int len) {
    int m, j;
    int *bucket = malloc(bucketsort_max_element(array, len) * sizeof(int));

    for(m = 0; m < len; m++) {
        bucket[m] = 0;
    }

    for(m = 0; m < len; m++) {
        bucket[array[m]] += 1;
    }

    for(m = 0, j = 0; m < len; m++) {
        for (; bucket[m] > 0; ( bucket [m])--) {
            array[j++] = m;
        }
    }

    free(bucket);
}

/* Quick sort */
int quicksort_partition(Transaction *array, int left, int right, cmp_func cmp) {
    int mid = (left + right) / 2;
    Transaction a = array[left];
    Transaction b = array[mid];
    Transaction c = array[right];

    int medianaIndice;
    if (cmp(&a, &b) == -1) {
        if (cmp(&b, &c) == -1) {
            medianaIndice = mid;
        } else {
            if (cmp(&a, &c) == -1) {
                medianaIndice = right;
            } else {
                medianaIndice = left;
            }
        }
    } else {
        if (cmp(&c, &b) == -1) {
            medianaIndice = mid;
        } else {
            if (cmp(&c, &a) == -1) {
                medianaIndice = right;
            } else {
                medianaIndice = left;
            }
        }
    }

    swap(&array[medianaIndice], &array[right]);

    Transaction pivot = array[right];
    int i = left - 1;
    int j;

    for (j = left; j <= right - 1; j++) {
        if (cmp(&array[j], &pivot) <= 0) {
            i = i + 1;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[right]);
    return i + 1;
}

void quicksort_aux(Transaction *array, int left, int right, cmp_func cmp) {
    if (right <= left)
        return;

    if ((right - left) < 5) {
        insertionsort(&array[right], right - left, cmp);
        return;
    }

    int i = quicksort_partition(array, left, right, cmp);
    quicksort_aux(array, left, i - 1, cmp);
    quicksort_aux(array, i + 1, right, cmp);
}

void quicksort(Transaction *array, int len, cmp_func cmp) {
    quicksort_aux(array, 0, len, cmp);
}
