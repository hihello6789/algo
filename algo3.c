/* Write a program that takes an aay of n positive integers and sort them using linear insertion sort
and binary insertion sort and output to a file. The no. of n can be hard coded in the program but changed before compiling*/
#include <stdio.h>
#define N 1000
void linearInsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int binarySearch(int a[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (item == a[mid])
            return mid + 1;
        else if (item > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
void binaryInsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        int loc = binarySearch(a, key, 0, j);
        while (j >= loc) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
void writeToFile(const char *filename, int a[], int n, const char *label) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fprintf(fp, "%s:\n", label);
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", a[i]);
    }
    fprintf(fp, "\n\n");

    fclose(fp);
}
int main() {
    int original[N] = {34, 7, 23, 32, 5, 62, 78, 1, 45, 19};
    int linearSorted[N], binarySorted[N];
    for (int i = 0; i < N; i++) {
        linearSorted[i] = original[i];
        binarySorted[i] = original[i];
    }
    linearInsertionSort(linearSorted, N);
    binaryInsertionSort(binarySorted, N);
    writeToFile("sorted_output.txt", linearSorted, N, "Linear Insertion Sort");
    writeToFile("sorted_output.txt", binarySorted, N, "Binary Insertion Sort");
    printf("Sorting completed. Results saved to 'sorted_output.txt'.\n");
    return 0;
}