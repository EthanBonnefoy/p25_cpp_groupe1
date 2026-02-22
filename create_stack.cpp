#include <iostream>

int* create(int size){
    int* tab = new int[size];
    return tab;
}

int main(){
    int* stack = create(5);
    std::cout << stack << std::endl;
    delete[] stack;
    return 0;
}
