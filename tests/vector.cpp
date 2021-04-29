#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "matrix.hh"
#include "size.hh"
#include "rectangle.hh"

TEST_CASE("Test konstruktorów bezparametrycznych")
{
    Vector wektor(0, 0);

    double TEST[SIZE];

    TEST[0] = 0;
    TEST[1] = 0;

    Vector test(TEST);

    CHECK(wektor == test);
}

TEST_CASE("Test konstruktorów parametrycznych")
{
    Vector wektor(16, 32);

    Vector test;

    test[0] = 16;
    test[1] = 32;

    CHECK(wektor == test);
}


TEST_CASE("Test Operatora Odejmowania")
{
    Vector wektor1(16, 32);

    Vector wektor2(-10, 30);

    Vector Wynik = wektor1 - wektor2;

    Vector test(26, 2);


    CHECK(Wynik == test);
}

TEST_CASE("Test Operatora Dodawania")
{
    Vector wektor1(16.5, 32);

    Vector wektor2(10.5, 30);

    Vector Wynik = wektor1 + wektor2;

    Vector test(27, 62);


    CHECK(Wynik == test);
}

TEST_CASE("Test Operatora Porównywania z zbyt małym błędem")
{
    Vector wektor1(1.000001, 32.0000004);

    Vector wektor2(1.00000005, 32.0000005);

    CHECK(wektor1 == wektor2);
}

TEST_CASE("Test Operatora Porównywania z zbyt dużym błędem")
{
    Vector wektor1(1.00001, 32.00003);

    Vector wektor2(1.00005, 32.00005);

    CHECK(!(wektor1 == wektor2));
}

TEST_CASE("Test Wyswietlania wektora") {
    
    Vector wektor1(2, 2);

    std::ostringstream Strumien;

    Strumien << wektor1;
 
   CHECK(Strumien.str() == "[ 2 ] [ 2 ] ");
}   



TEST_CASE("Test wczytywania wektora do strumienia")
{
    Vector wektor1;
    std::ostringstream Strumien_out;
    std::istringstream Strumien_in("-20 2.555 ");

    Strumien_in >> wektor1;

    Strumien_out << wektor1;

    CHECK("[ -20 ] [ 2.555 ] " == Strumien_out.str());
}

TEST_CASE("Test operatora []")
{
    Vector wektor1(1, 1);
    std::ostringstream Strumien_out;

    Strumien_out << wektor1.operator[](0);


    CHECK("1" == Strumien_out.str());
}