#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"
#include "PrintArr.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

void binaryInsertionSort(unsigned, int*);

int main(){
    fstream filein(USarr, ios_base::in);
    fstream fileout(Sarr, ios_base::out);

    if (!filein.is_open()){
        cout << "Ошибка: входной файл не открывается.\n";
        return 0;
    }

    cout << "Алгоритм сортировки вставками с бинарным поиском\n\n";

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
    binaryInsertionSort(size, arr);
    printArr(&fileout, arr, size);
    cout << "Сортировка завершена.\n";

    delete[] arr;
    return 0;
}



void binaryInsertionSort(unsigned size, int* arr){
    for (int i = 1; i < size; i++){
        int key = arr[i];
        int left = 0, right = i - 1;

        while (left <= right){
            int mid = (left + right) / 2;

            if (key < arr[mid]){
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }   
        }

        for (int j = i; j > left; j--) {
            arr[j] = arr[j-1];
        }

        arr[left] = key;
    }
}