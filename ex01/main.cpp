/*#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
*/



#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    std::cout << "=== Étape 1 : Constructeur par defaut ===" << std::endl;
    Fixed a;
    std::cout << "a (toFloat) = " << a << std::endl;
    std::cout << "a (toInt)   = " << a.toInt() << std::endl;
    std::cout << "a (raw)     = " << a.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 2 : Constructeur int (10) ===" << std::endl;
    Fixed b(10);
    std::cout << "b (toFloat) = " << b << std::endl;
    std::cout << "b (toInt)   = " << b.toInt() << std::endl;
    std::cout << "b (raw)     = " << b.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 3 : Constructeur float (42.42f) ===" << std::endl;
    Fixed c(42.42f);
    std::cout << "c (toFloat) = " << c << std::endl;
    std::cout << "c (toInt)   = " << c.toInt() << std::endl;
    std::cout << "c (raw)     = " << c.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 4 : Constructeur de copie (d copie de b) ===" << std::endl;
    Fixed d(b);
    std::cout << "d (toFloat) = " << d << " / b (toFloat) = " << b << std::endl;
    std::cout << "d (raw)     = " << d.getRawBits() << " / b (raw) = " << b.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 5 : Operateur d'affectation (a = c) ===" << std::endl;
    a = c;
    std::cout << "a (toFloat) = " << a << " / c (toFloat) = " << c << std::endl;
    std::cout << "a (raw)     = " << a.getRawBits() << " / c (raw) = " << c.getRawBits() << std::endl;
    std::cout << std::endl;

    std::cout << "=== Étape 6 : Effet de setRawBits sur un objet ===" << std::endl;
    Fixed e;
    std::cout << "e (avant) raw = " << e.getRawBits() << std::endl;
    e.setRawBits(2560); // 10 << 8
    std::cout << "e (après) raw = " << e.getRawBits() << std::endl;
    std::cout << "e (toInt)     = " << e.toInt() << std::endl;
    std::cout << "e (toFloat)   = " << e << std::endl;
    std::cout << std::endl;

    std::cout << "=== Fin du programme (destructeurs vont s'appeler) ===" << std::endl;

    return 0;
}
