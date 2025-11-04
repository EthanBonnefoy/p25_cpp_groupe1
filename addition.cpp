#include <iostream>
#include <cstdlib>



int main(int argc, char *argv[])
{
    int res = 0;
    int i = 0;
    while (i < argc)
    {
        int n_i = std::atoi(argv[i]);
        res = res + n_i;
        i = i + 1;
    }

    std::cout << res << std::endl;

    return 0;
}




