unsigned Size_calc(fstream* filein){
    unsigned size = 0;
    int num;

    while (*filein >> num) size++;

    return size;
}

void Arr_in(fstream* filein, unsigned size, int* arr){

    for (unsigned i = 0; i < size; i++){
        *filein >> arr[i];
    }

    return;
}
