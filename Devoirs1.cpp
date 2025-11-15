#include <iostream>

// Nous allons implémenter une pile d'entiers de manière très basique.
// Nous la complexifierons par la suite.

// La pile est constituée:
//    - d'un tableau d'entier, avec sa taille et son nombre d'éléments empilés
//    - des quatre fonctions: push, pop, top, print, is_empty et is_full
//      (qui testent si la pile est resp. vide ou pleine)
//      il faut les utiliser dans votre code de push et pop

void print(int* tab, int size, int nb)
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
bool is_empty(int* tab, int size, int nb)
{
    return (nb == 0);
}

// renvoie true si la pile est pleine, false sinon
bool is_full(int* tab, int size, int nb)
{
    return (nb >= size);
}

void push(int* tab, int size, int* nb, int elt)
// cette fonction ajoute un entier à la pile passé en argument
// elle doit s'assurer que la pile n'est pas pleine avant d'empiler
// elle lance une exception si problème
{
    if (*nb == size)
    {
        throw std::overflow_error(std::string("Pile pleine"));
    }
    else{
        tab[*nb] = elt;
        (*nb)++;
    }
}

int top(int* tab, int size, int nb) // (cette fonction ne dépile pas)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné reste dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
// elle lance une exception si problème
{
    if (is_empty(tab, size, nb))
    {
        throw std::overflow_error(std::string("Pile vide"));
    }
    else
    {
        return tab[nb-1];
    }
}

int pop(int* tab, int size, int* nb) // (cette fonction dépile)
// cette fonction retourne l'entier en haut de la pile (le dernier empilé)
// à la sortie de cette fonction l'élément retourné n'est plus compté dans la pile
// elle doit s'assurer que la pile n'est pas vide avant de la dépiler
// elle lance une exception si problème
{
    if (is_empty(tab, size, *nb))
    {
        throw std::overflow_error(std::string("Pile vide"));
    }
    else
    {
        (*nb)--;
        return (tab[*nb]);
    }
}

#include <stdexcept>
// https://en.cppreference.com/w/cpp/header/stdexcept.html
// pour un exemple d'exception voir le fichier exception.cpp

int main()
{

    // on définit les 3 variables constituant la pile
    int size = 5;
    int stack[size];
    int nb = 0;

    // rajoutez aux blocks catch les erreurs
    // pouvant être déclenchées par les opérations sur la pile
    try
    {
        print(stack, size, nb); // affiche [ [
        push(stack, size, &nb, -17);

        // on affiche l'élément en haut de pile
        std::cout << top(stack, size, nb) << std::endl; // affiche -17

        push(stack, size, &nb, 90);
        print(stack, size, nb); // affiche [-17 90 [

        int e = pop(stack, size, &nb);
        std::cout << e << std::endl;
        print(stack, size, nb); // affiche [-17 [

        push(stack, size, &nb, 20);
        push(stack, size, &nb, -78);
        push(stack, size, &nb, -9);
        push(stack, size, &nb, -56);
        push(stack, size, &nb, -9);
        push(stack, size, &nb, 68);

        return EXIT_SUCCESS;
    }
    catch (std::overflow_error &e)
    {
        // ce catch ramasse toutes les exceptions...
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}