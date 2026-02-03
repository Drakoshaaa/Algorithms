void printArr(fstream* fileout, int* arr, unsigned size){
    for(unsigned i = 1; i < size; i++){
        *fileout << arr[i] << " ";

        if (i % 15 == 0) *fileout << endl;
    }
}