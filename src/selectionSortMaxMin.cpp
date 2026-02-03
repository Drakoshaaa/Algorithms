#include <iostream>
#include <fstream>

using namespace std;

#include "ArrPrep.cpp"
#include "PrintArr.cpp"

const char USarr[] = "UnsortedArr.txt"; 
const char Sarr[] = "SortedArr.txt"; 

void selectionSortMaxMin(fstream*, unsigned, int*);

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
    selectionSortMaxMin(&fileout, size, arr);
    printArr(&fileout, arr, size);
    cout << "Сортировка завершена.\n";

    delete[] arr;
    return 0;
}



void selectionSortMaxMin(fstream* fileout, unsigned size, int* arr){
    int left = 0, right = size - 1;

    while (left < right) {
        int minindex = left;
        int maxindex = right;

        for (unsigned i = left; i <= right; i++){
            if (arr[i] < arr[minindex]) minindex = i;
            if (arr[i] > arr[maxindex]) maxindex = i;
        }

        if (minindex != left){
            int temp = arr[left];
            arr[left] = arr[minindex];
            arr[minindex] = temp;
        }
        if (maxindex == left){
            maxindex = minindex;
        }
        if (maxindex != right){
            int temp = arr[right];
            arr[right] = arr[maxindex];
            arr[maxindex] = temp;
        }

        left++;
        right--;
    }
}