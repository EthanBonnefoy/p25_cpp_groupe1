#include <iostream>

//Je travaille sans exceptions pour l'instant

class IntStack
{

private:
int size; //taille de la pile
int nb; //nombre d'éléments dans le tableau. Est-ce qu'il y a besoin d'utiliser une référence dans ce cas-là ? 
int* tab;  //pointeur vers le tableau 

public:
IntStack(int size) : size(size), nb(0)
{
    tab = new int [size];
}

IntStack(const IntStack &pile) : size(pile.size), nb(pile.nb) 
{
    //Allocation de mémoire pour la nouvelle stack
    tab = new int [size]; 

    //Copie des éléments de la première stack

    for (int i = 0; i<nb; i++)
    {
        tab[i] = (pile.tab)[i];
    }

}

~IntStack()
{
    delete[] tab;
}

IntStack& operator=(const IntStack& pile)
{
    if(this != &pile)
    {
        size = pile.size;
        nb = pile.nb;
        delete [] tab;
        tab = new int [size];
        for (int i = 0; i<nb; i++)
        {
            tab[i]=pile.tab[i];
        }
    }
    return *this;
}

void print()
// cette fonction affiche les entiers empilés
{
    std::cout << "[";
    for (int i = 0; i < nb; i++)
    {
        std::cout << tab[i] << ", ";
    }
    std::cout << "]" << std::endl;
}

// renvoie true si la pile est vide, false sinon
bool is_empty()
{
    return (nb <= 0);
}

// renvoie true si la pile est pleine, false sinon
bool is_full()
{
    return (nb >= size);
}

void push(int elt)
// cette fonction ajoute un entier à la pile passé en argument
// elle doit s'assurer que la pile n'est pas pleine avant d'empiler
// elle lance une exception si problème
{
    if (nb >= size)
    {
        throw std::overflow_error(std::string("Pile pleine"));
    }
    tab[nb] = elt;
    (nb)++;
}

int top() // (cette fonction ne dépile pas)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné reste dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
// elle lance une exception si problème
{
    if (is_empty())
    {
        throw std::overflow_error(std::string("Pile vide"));
    }
    return tab[nb-1];
}

int pop() // (cette fonction dépile)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné n'est plus compté dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
// elle lance une exception si problème
{
    if (is_empty())
    {
        throw std::overflow_error(std::string("Pile vide"));
    }
    (nb)--;
    return (tab[nb]);
}

};

int main()
{

IntStack stack(5);

stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);
stack.push(5);

stack.print();

IntStack stack2(stack);

stack2.print();

IntStack stack3(7);
stack3.push(-17);
stack3.push(20);
stack3.push(0);
stack3.push(0);
stack3.push(0);
stack3.push(0);
stack3.push(0);

stack2 = stack3;

stack2.print();

return 0;
}