#include "progress_bar.h"

void selectionSortMaxMin(unsigned size, int* arr){
    int left = 0, right = size - 1;

    while (left < right) {
        int minindex = left;
        int maxindex = right;

        for (int i = left; i <= right; i++){
            if (arr[i] < arr[minindex]) minindex = i;
            if (arr[i] > arr[maxindex]) maxindex = i;
        }

        if (minindex != left){
            int temp = arr[left];
            arr[left] = arr[minindex];
            arr[minindex] = temp;
        }
        if (maxindex == left){
            maxindex = minindex;
        }
        if (maxindex != right){
            int temp = arr[right];
            arr[right] = arr[maxindex];
            arr[maxindex] = temp;
        }

        left++;
        right--;

        //progress bar
        progress_bar(size, left);
    }
}