#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"
#include "PrintArr.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

void shakerSort(unsigned, int*);

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
    shakerSort(size, arr);
    printArr(&fileout, arr, size);
    cout << "Сортировка завершена.\n";

    delete[] arr;
    return 0;
}



void shakerSort(unsigned size, int* arr){
    int left = 0, right = size - 1; 
    bool swapped = true;

    while (swapped && left < right){
        swapped = false;

        for (int i = left; i < right; i++){
            if (arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swapped=  true;
            }
        }

        right--;

        if (!swapped) break;
        swapped = false;

        for (int i = right; i > left; i--){
            if (arr[i-1] > arr[i]){
                int temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                swapped=  true;
            }
        }

        left++;
    }    
}