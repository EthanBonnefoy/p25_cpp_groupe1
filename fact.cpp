#include <iostream>
#include <cstdlib>


int ascii_to_int(char* c)
{
    return int(c - 48);
}



int main(int argc, char *argv[])
{
    //int n = std::atoi(argv[1]);
    int n = ascii_to_int(argv[1]);
    int res = 1;
    while (n>0)
    {
        res = res * n;
        n = n-1;
    }

    std::cout << res << std::endl;

    return 0;
}









