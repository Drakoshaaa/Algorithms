#include "progress_bar.h"

void binaryInsertionSort(unsigned size, int* arr){
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int left = 0, right = i - 1;

        while (left <= right){
            int mid = (left + right) / 2;

            if (key < arr[mid]){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }   
        }

        for (int j = i; j > left; j--) {
            arr[j] = arr[j-1];
        }

        arr[left] = key;

        //progress bar
        progress_bar(size, i);
    }
}