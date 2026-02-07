#include "progress_bar.h"

void selectionSortMax(unsigned size, int* arr){
    for (int i=size-1; i > 0; i--){
        int maxindex = 0;
        for (int j=1; j<=i; j++){
            if (arr[j] > arr[maxindex]) maxindex = j;
        }

        if (maxindex != i){
            int temp = arr[i];
            arr[i] = arr[maxindex];
            arr[maxindex] = temp;
        }

        //progress bar
        progress_bar(size, size-i);
    }
}