/*#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}*/


#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Étape 1 : creation de a ===" << std::endl;
    Fixed a;
    std::cout << "Valeur brute de a : " << a.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 2 : on modifie a avec setRawBits ===" << std::endl;
    a.setRawBits(42);
    std::cout << "Nouvelle valeur brute de a : " << a.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 3 : creation de b par copie de a ===" << std::endl;
    Fixed b(a);
    std::cout << "Valeur brute de a : " << a.getRawBits() << std::endl;
    std::cout << "Valeur brute de b (copie de a) : " << b.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 4 : creation de c par defaut ===" << std::endl;
    Fixed c;
    std::cout << "Valeur brute de c (avant affectation) : " << c.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 5 : on affecte c = b ===" << std::endl;
    c = b;
    std::cout << "Valeur brute de b : " << b.getRawBits() << std::endl;
    std::cout << "Valeur brute de c (après c = b) : " << c.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 6 : on modifie b pour voir si c change ou pas ===" << std::endl;
    b.setRawBits(100);
    std::cout << "Nouvelle valeur brute de b : " << b.getRawBits() << std::endl;
    std::cout << "Valeur brute de c (doit rester la même) : " << c.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Fin du programme, destruction des objets ===" << std::endl;

    return 0;
}

