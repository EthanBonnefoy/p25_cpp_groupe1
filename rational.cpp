#include <iostream>
#include <stdexcept>

struct Stack
{
    int nb;
    int size;
    int *tab;

    Stack(int s) : nb(0)
    {
        if (s < 0)
        {
            throw std::runtime_error("Negative stack size");
        }
        size = s;
        tab = new int[size]; // allocation
    }

    ~Stack()
    {
        delete[] tab;
    }

    bool is_full()
    {
        return nb >= size;
    }

    void push(int v)
    {
        if (nb < size)
        {
            tab[nb] = v;
            nb = nb + 1;
        }
    }
};

struct Rational
{
    int num;
    int denom;

    Rational(int n, int d) : num(n), denom(d) // liste d'initialisation
    {
        // corps du constructeur (vide)
    }

    void print()
    {
        std::cout << num << "/" << denom << std::endl;
    }
};

int main()
{
    Stack *ps = new Stack(20000);
    ps->push(-17);
    // Equivalent à (*ps).push(-17);
    delete ps;

    return 0;
}
