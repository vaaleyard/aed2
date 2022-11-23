#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int swap(int *arr, int a, int b) {
  int aux = arr[a];
  arr[a] = arr[b];
  arr[b] = aux;

  return 0;
}

int particao(int v[], int esq, int dir) {
  int i, fim;
  fim = esq;
  for (i = esq + 1; i <= dir; i++)
    if (v[i] < v[esq]) {
      fim = fim + 1;
      swap(v, fim, i);
    }
  swap(v, esq, fim);
  return fim;
}

void quicksort(int v[], int esq, int dir) {
  int i;
  if (esq >= dir)
    return;
  i = particao(v, esq, dir);
  quicksort(v, esq, i - 1);
  quicksort(v, i + 1, dir);
}

void intercala(int v[], int e, int m, int d) {
  int *r; // vetor auxiliar para armazenar a mistura
  int i, j, k;
  r = (int *)malloc(((d + 1) - e) * sizeof(int));
  i = e;
  j = m + 1;
  k = 0;
  while ((i <= m) &&
         (j <= d)) {    // intercala enquanto nenhuma das partes do vetor
    if (v[i] <= v[j]) { // foi consumida totalmente
      r[k] = v[i];
      i++;
    } else {
      r[k] = v[j];
      j++;
    }
    k++;
  }
  while (i <= m) {
    r[k] = v[i];
    i++;
    k++;
  } // termina de intercalar se sobrou à esquerda
  while (j <= d) {
    r[k] = v[j];
    j++;
    k++;
  } // termina de intercalar se sobrou à direita
  // Cópia do vetor auxiliar (contendo os dados ordenados) sobre o vetor
  // original
  j = 0;
  for (i = e; i <= d; i++) {
    v[i] = r[j];
    j++;
  }
  free(r);
}

void merge_sort(int v[], int e, int d) {
  int m;
  if (e < d) {
    m = (e + d) / 2;
    merge_sort(v, e, m);
    merge_sort(v, m + 1, d);
    intercala(v, e, m, d);
  }
}

int selection_sort(int *arr, int len) {
  for (int left = 0; left < len - 1; left++) {
    int smallest = left;

    for (int right = left + 1; right < len; right++) {
      if (arr[right] < arr[smallest]) {
        smallest = right;
      }
    }
    swap(arr, left, smallest);
  }

  return 0;
}

int bubble_sort(int *arr, int len) {
  bool sorted = false;
  int end = len;

  do {
    sorted = true;
    for (int i = 0; i < len - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr, i, i + 1);
        sorted = false;
      }
    }
  } while (!sorted);

  return 0;
}

int insertion_sort(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    for (int j = i; j > 0; j--) {
      if (arr[j - 1] > arr[j])
        swap(arr, j - 1, j);
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int LEN = 100000;
  int array[LEN];
  clock_t t;

  for (int i = 0; i < LEN; i++) {
    array[i] = random();
  }

  t = clock();
  selection_sort(array, LEN);
  t = clock() - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("Selection sort: %f seconds\n", time_taken);

  for (int i = 0; i < LEN; i++) {
    array[i] = random();
  }
  t = clock();
  bubble_sort(array, LEN);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("Bubble sort: %f seconds\n", time_taken);

  for (int i = 0; i < LEN; i++) {
    array[i] = random();
  }
  t = clock();
  insertion_sort(array, LEN);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("Insertion sort: %f seconds\n", time_taken);

  for (int i = 0; i < LEN; i++) {
    array[i] = random();
  }
  t = clock();
  quicksort(array, 0, LEN - 1);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("Quick sort: %f seconds\n", time_taken);

  for (int i = 0; i < LEN; i++) {
    array[i] = random();
  }
  t = clock();
  merge_sort(array, 0, LEN - 1);
  t = clock() - t;
  time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
  printf("Merge sort: %f seconds\n", time_taken);
  return 0;
}
