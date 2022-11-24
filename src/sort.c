#include <string.h>
#include <limits.h>
#include "sort.h"

void swap(Transaction *tr1, Transaction *tr2) {
    Transaction *temp = tr1;
    tr1 = tr2;
    tr2 = temp;
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
    return strcmp(tr1->cpf, tr2->cpf);
}

int insertion_sort(Transaction *transactions, int len, cmp_func cmp) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (cmp(&transactions[j - 1], &transactions[j]))
                swap(&transactions[j-1], &transactions[j]);
        }
    }

    return 0;
}

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

/* Reverses arr[0..i] */
void pancakesort_flip(Transaction *arr, int i) {
    int start = 0;
    Transaction *temp;
    while (start < i) {
        swap(&arr[start], &arr[i]);
        start++;
        i--;
    }
}

/* Returns index of the maximum element in arr[0..n-1] */
int pancakesort_findMax(Transaction *arr, int n, cmp_func cmp) {
    int mi, i;

    for (mi = 0, i = 0; i < n; ++i)
        if (cmp(&arr[i], &arr[mi]) == 1)
            mi = i;

    return mi;
}

// The main function that sorts given array using pancakesort_flip
// operations
void pancakesort(Transaction* arr, int n, cmp_func cmp)
{
    // Start from the complete array and one by one reduce
    // current size by one
    for (int curr_size = n; curr_size > 1; --curr_size) {
        // Find index of the maximum element in
        // arr[0..curr_size-1]
        int mi = pancakesort_findMax(arr, curr_size, cmp);

        // Move the maximum element to end of current array
        // if it's not already at the end
        if (mi != curr_size - 1) {
            // To move at the end, first move maximum number
            // to beginning
            pancakesort_flip(arr, mi);

            // Now move the maximum number to end by reversing
            // current array
            pancakesort_flip(arr, curr_size - 1);
        }
    }
}

/* Heap sort */

void heapsort_heapify(Transaction arr[], int n, int i, cmp_func cmp) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // if (left < n && arr[left] > arr[largest])
    if (left < n && cmp(&arr[left], &arr[largest]) == 1)
        largest = left;

    // if (right < n && arr[right] > arr[largest])
    if (right < n && cmp(&arr[right], &arr[largest]) == 1)
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapsort_heapify(arr, n, largest, cmp);
    }
}

// Main function to do heap sort
void heapsort_(Transaction arr[], int n, cmp_func cmp) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapsort_heapify(arr, n, i, cmp);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at root again
        heapsort_heapify(arr, i, 0, cmp);
    }
}

/* Bucket Sort */

//Function to find maximum element of the array
int bucketsort_max_element(Transaction array[], int size)
{  
    // Initializing max variable to minimum value so that it can be updated
    // when we encounter any element which is greater than it.
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
        {
            //Updating max when array[i] is greater than max
            if (array[i].id > max)
                max = array[i].id;
        }
    //return the max element
    return max;
}

//Implementing bucket sort 
void bucketsort(Transaction array[], int size) 
{
    //Finding max element of array which we will use to create buckets
    int max = bucketsort_max_element(array, size);

    // Creating buckets
    int bucket[max+1];

    //Initializing buckets to zero
    for (int i = 0; i <= max; i++)
        bucket[i] = 0;

    // Pushing elements in their corresponding buckets
    for (int i = 0; i < size; i++)
        bucket[array[i].id]++;

    // Merging buckets effectively
    int j=0;   // j is a variable which points at the index we are updating
    for (int i = 0; i <= max; i++)
        {
            // Running while loop until there is an element in the bucket
            while (bucket[i] > 0)
                {
                    // Updating array and increment j          
                    array[j++].id = i;  

                    // Decreasing count of bucket element
                    bucket[i]--;
                }
        }
}

