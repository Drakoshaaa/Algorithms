#include <random>
#include <iostream>
#include <fstream>

using namespace std;

const char filename[] = "UnsortedArr.txt";

int main(){
    long int range_min, range_max, volume;
    fstream fileout(filename, ios_base::out);

    cout << "Выберите диапазон генерации значений (от 'n' до 'm'): ";
    cin >> range_min >> range_max;
    cout << "Выберите количество генерируемых чисел: ";
    cin >> volume; cout << endl;

    
    //Генерация рандомных чисел в диапазоне, заданном пользователем
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> rand(range_min, range_max);
    cout << "Генерация чисел... \n";
    for (int i = 1; i <= volume; i++) {
        fileout << rand(gen) << " ";
        
        if (i%15 == 0) fileout << endl;
    }
    cout << "Успешно, было сгенерировано " << volume << " случайных чисел в диапазоне ("
         << range_min << " , " << range_max << ")\n" << "Проверьте файл '" << filename << "'\n\n";
}
