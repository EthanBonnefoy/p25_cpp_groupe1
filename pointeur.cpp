#include <iostream>

void push(int* tab, int size, int& nb, int k)
{
    if (nb >= size)
    {
        std::cerr << "error: not more space in this array" << std::endl;
    }

    tab[nb] = k;

    nb = nb + 1;
}

int pop(int* tab, int size, int& nb)
{
    if (nb == 0)
    {
        std::cerr << "error: can't remove element from empty array" << std::endl;
    }
    int e = tab[nb];
    nb = nb - 1;

    return e;
}

void print(int* tab, int size, int& nb)
{
    for (int i = 0; i <= nb; i++)
    {
        std::cout << tab[i] << std::endl;
    }
}

int main()
{
    int size = 5;
    int tab[size];
    int nb = 0;

    print(tab, size, nb);
    push(tab, size, nb, -17);
    std::cout << nb << std::endl;
    print(tab, size, nb);
    push(tab, size, nb, 90);
    print(tab, size, nb);
    int e = pop(tab, size, nb);
    std::cout << e << std::endl;
    print(tab, size, nb);

    return 0;
}
