#include <iostream>
#include "progress_bar.h"

void progress_bar(unsigned size, int i){
    if (size < 100) return;

    int step = size / 100;
    
    if (i % step == 0){
        std::cout << "\rИдёт сортировка...  " << i / step << "%" << std::flush;
    }
}