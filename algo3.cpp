/* Write a program that takes an array of n positive integers and sort them using linear insertion sort
and binary insertion sort and output to a file. The no. of n can be hard coded in the program but changed before compiling*/

#include <stdio.h>
#define N 10
void linear_insertion_sort(int arr[], int n){
    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    int binary_search(int arr[], int item, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void binary_insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        int loc = binary_search(arr, key, 0, j);

        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    int at min<max;
        for()
}

}


