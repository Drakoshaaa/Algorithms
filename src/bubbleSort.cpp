#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"
#include "PrintArr.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

void bubbleSort(unsigned, int*);

int main(){
    fstream filein(USarr, ios_base::in);
    fstream fileout(Sarr, ios_base::out);

    if (!filein.is_open()){
        cout << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "Алгоритм сортировки обменом (пузырьковая)\n\n";

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
    bubbleSort(size, arr);
    printArr(&fileout, arr, size);
    cout << "Сортировка завершена.\n";

    delete[] arr;
    return 0;
}



void bubbleSort(unsigned size, int* arr){
    for (int i = 0; i < size - 1; i++){
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        if (!swapped){
            break;
        }
    }
    
    return;
}