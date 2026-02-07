#include "progress_bar.h"

void shakerSort(unsigned size, int* arr){
    int left = 0, right = size - 1; 
    bool swapped = true;

    while (swapped && left < right){
        swapped = false;

        for (int i = left; i < right; i++){
            if (arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped=  true;
            }
        }

        right--;

        if (!swapped) break;
        swapped = false;

        for (int i = right; i > left; i--){
            if (arr[i-1] > arr[i]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                swapped=  true;
            }
        }

        left++;

        //progress bar
        progress_bar(size, left);
    }    
}