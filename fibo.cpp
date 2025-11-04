#include <iostream>
#include <cstdlib>


int fibo(int n)
{
    if (n < 2)
    {
        return 1;
    }

    return fibo(n-1) + fibo(n-2);
}


int main(int argc, char *argv[])
{
    int n = std::atoi(argv[1]);
    int res = fibo(n);

    std::cout << res << std::endl;

    return 0;
}






