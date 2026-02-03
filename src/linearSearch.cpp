int linearSearch(unsigned size, int* arr, int target){
    for(unsigned i=0; i<size; i++){
        if (arr[i] == target) return i;
    }
    return -1;
}