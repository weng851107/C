#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *arr, int n)
{
    for (int i = 0;i < (n-1);i++) {
        for (int j = 0;j < (n-1-i);j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void select_sort(int *arr, int n)
{
    for (int i = 0;i < (n-1);i++) {
        int min_index = i;
        for (int j = i+1;j < n;j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            swap(&arr[i], &arr[min_index]);
        }
    }
}

void insert_sort(int *arr, int n)
{
    for (int i = 1;i < n;i++) {
        int key = arr[i];
        int j = i - 1;
        while ((j >= 0) && (arr[j] > key)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void quick_sort(int *arr, int left, int right)
{
    if (left < right) {
        int pivot = arr[(left+right)/2];
        int i = left - 1;
        int j = right + 1;
        while (1) {
            while (arr[++i] < pivot);
            while (arr[--j] > pivot);
            if (i >= j) {
                break;
            }
            swap(&arr[i], &arr[j]);
        }
        quick_sort(arr, left, i);
        quick_sort(arr, i+1, right);
    }
}

void merge(int *arr, int *left, int left_size, int *right, int right_size)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i < left_size) && (j < right_size)) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        }
        else {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) {
        arr[k++] = left[i++];
    }

    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void merge_sort(int *arr, int n)
{
    if (n < 2) {
        return;
    }
    int mid = n/2;
    int left[mid];
    int right[n-mid];
    for (int i = 0;i < mid;i++) {
        left[i] = arr[i];
    }
    for (int i = 0;i < (n-mid);i++) {
        right[i] = arr[mid+i];
    }

    merge_sort(left, mid);
    merge_sort(right, n-mid);
    merge(arr, left, mid, right, n-mid);
}

void print_array(int *arr, int n)
{
    for (int i = 0;i < n;i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    print_array(arr, n);

    //bubble_sort(arr, n);
    //select_sort(arr, n);
    //insert_sort(arr, n);
    //quick_sort(arr, 0, n-1);
    merge_sort(arr, n);

    printf("Sorted array: \n");
    print_array(arr, n);
    return 0;
}