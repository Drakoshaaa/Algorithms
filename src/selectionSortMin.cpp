#include "progress_bar.h"

void selectionSortMin(unsigned size, int* arr){
    for (int i=0; i < size-1; i++){
        int minindex = i;
        for (int j=i+1; j<size; j++){
            if (arr[j] < arr[minindex]) minindex = j;
        }

        if (minindex != i){
            int temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }

        //progress bar
        progress_bar(size, i);
    }
}