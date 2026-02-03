#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"
#include "PrintArr.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

void selectionSortMin(unsigned, int*);

int main(){
    fstream filein(USarr, ios_base::in);
    fstream fileout(Sarr, ios_base::out);

    if (!filein.is_open()){
        cout << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "Алгоритм сортировки выбором с помощью поиска минимума\n\n";

    //Подсчёт размера массива
    unsigned size = Size_calc(&filein);
    filein.clear();
    filein.seekg(0);
    cout << "Размер массива: " << size << endl;

    //Динамическое выделение памяти под массив чисел
    int* arr = new int[size];
    Arr_in(&filein, size, arr);

    //Вызов функции сортировки
    cout << "Идёт сортировка...\n";
    selectionSortMin(size, arr);
    printArr(&fileout, arr, size);
    cout << "Сортировка завершена.\n";


    delete[] arr;
    return 0;
}



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