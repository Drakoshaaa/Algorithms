#include <random>
#include <iostream>
#include <fstream>

using namespace std;

void randomizer(){
    const char USarr[] = "assets/UnsortedArr.txt";
    long int range_min, range_max, volume;
    ofstream fileout(USarr);

    cout << "\n-------------------------------------------------------------------------\n";
    cout << "                 ГЕНЕРАТОР\n";
    cout << "Выберите диапазон генерации значений (от 'n' до 'm'): ";
    cin >> range_min >> range_max;
    cout << "Выберите количество генерируемых чисел: ";
    cin >> volume; cout << endl;

    //Генерация рандомных чисел в диапазоне, заданном пользователем
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> rand(range_min, range_max);
    cout << "Генерация чисел...";
    for (int i = 1; i <= volume; i++) {
        fileout << rand(gen) << " ";
        
        if (i%15 == 0) fileout << endl;
    }
    cout << "\rУспешно, было сгенерировано " << volume << " случайных чисел в диапазоне ("
         << range_min << " , " << range_max << ")\n" << "Проверьте файл '" << USarr;

    cout << "\n-------------------------------------------------------------------------\n";
    fileout.close();
}
