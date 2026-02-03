#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"
#include "PrintArr.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

void selectionSortMin(fstream*, unsigned, int*);

int main(){
    fstream filein(USarr, ios_base::in);
    fstream fileout(Sarr, ios_base::out);

    if (!filein.is_open()){
        cout << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "Алгоритм сортировки выбором с помощью поиска максимума\n\n";

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
    selectionSortMin(&fileout, size, arr);
    printArr(&fileout, arr, size);
    cout << "Сортировка завершена.\n";


    delete[] arr;
    return 0;
}   



void selectionSortMin(fstream* fileout, unsigned size, int* arr){
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
        //Вывод в выходной файл
        *fileout << arr[i] << " ";
        if (i%15 == 0 && i != 0) *fileout << endl;
    }
}