void selectionSortMax(unsigned size, int* arr){
    for (unsigned i=size-1; i > 0; i--){
        int maxindex = 0;
        for (unsigned j=1; j<=i; j++){
            if (arr[j] > arr[maxindex]) maxindex = j;
        }

        if (maxindex != i){
            int temp = arr[i];
            arr[i] = arr[maxindex];
            arr[maxindex] = temp;
        }
    }
}