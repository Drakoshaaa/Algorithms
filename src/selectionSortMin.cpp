void selectionSortMin(unsigned size, int* arr){
    for (unsigned i=0; i < size-1; i++){
        int minindex = i;
        for (unsigned j=i+1; j<size; j++){
            if (arr[j] < arr[minindex]) minindex = j;
        }

        if (minindex != i){
            int temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }
    }
}