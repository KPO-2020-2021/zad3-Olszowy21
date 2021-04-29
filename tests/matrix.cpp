#include "../tests/doctest/doctest.h"
#include "matrix.hh"
#include "size.hh"
#include "vector.hh"
#include "rectangle.hh"

TEST_CASE("Test konstruktorów bezparametrycznych")
{
    Matrix macierz = Matrix();

    Matrix test;

    test(0, 0) = 0;
    test(1, 0) = 0;
    test(0, 1) = 0;
    test(1, 1) = 0;

    CHECK(macierz == test);
}

TEST_CASE("Test konstruktorów parametrycznych")
{
    double tmp[SIZE][SIZE];
    tmp[0][0] = 1;
    tmp[0][1] = 2;
    tmp[1][0] = 3;
    tmp[1][1] = 4;

    Matrix macierz = Matrix(tmp);

    Matrix test;

    test(0, 0) = 1.000001;
    test(1, 0) = 3.0000009;
    test(0, 1) = 2.0000005;
    test(1, 1) = 4.00000000005;

    CHECK(macierz == test);
}

TEST_CASE("Test przeciążenia mnożenia MACIERZ * WEKTOR")
{


    Matrix macierz;
    Vector wektor(2, 2);
    Vector test;
    Vector Wynik(6, 12);

    macierz(0, 0) = 1;
    macierz(1, 0) = 2;
    macierz(0, 1) = 2;
    macierz(1, 1) = 4;

    test = macierz * wektor;

    CHECK(Wynik == test);
}

TEST_CASE("Test operatora [] ")
{
    Matrix macierz = Matrix();

    Matrix test;

    test(0, 0) = 0;
    test(1, 0) = 0;
    test(0, 1) = 0;
    test(1, 1) = 0;

    CHECK(macierz == test);
}

TEST_CASE("Test zabezpieczenia operatora ()")
{
    Matrix macierz = Matrix();
    std::ostringstream Strumien_out;

    WARN_THROWS(Strumien_out << macierz(2, 2));
}

TEST_CASE("Test operatora []")
{
    Matrix macierz = Matrix();
    std::ostringstream Strumien_out;

    Strumien_out << macierz.operator[](0);


    CHECK("0" == Strumien_out.str());
}

TEST_CASE("Test operatora ()")
{
    Matrix macierz = Matrix();
    std::ostringstream Strumien_out;

    Strumien_out << macierz(1, 1);

    CHECK("0" == Strumien_out.str());
}
