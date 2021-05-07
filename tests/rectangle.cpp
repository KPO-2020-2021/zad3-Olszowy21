#include "../tests/doctest/doctest.h"
#include "rectangle.hh"
#include "vector.hh"

TEST_CASE("Test Konstruktora Parametrycznego")
{
    Vector Top1 = Vector(0, 0);
    Vector Top2 = Vector(10, 0);
    Vector Top3 = Vector(10, 10);
    Vector Top4 = Vector(0, 10);

    Rectangle Rectangle1(Top1, Top2, Top3, Top4);

    Rectangle Rectangle_test;

    Rectangle_test[0] = Vector(0, 0);
    Rectangle_test[1] = Vector(10, 0);
    Rectangle_test[2] = Vector(10, 10);
    Rectangle_test[3] = Vector(0, 10);


    CHECK(Rectangle_test == Rectangle1);
}

TEST_CASE("Test Konstruktora Bezparametrycznego ___TEST ZALEŻNY OD KONSTRUKTORÓW WEKTORA___ ")
{

    Rectangle Rectangle1 = Rectangle();

    Rectangle Rectangle_test;

    Rectangle_test[0] = Vector(10, 10);
    Rectangle_test[1] = Vector(160, 10);
    Rectangle_test[2] = Vector(160, 110);
    Rectangle_test[3] = Vector(10, 110);


    CHECK(Rectangle_test == Rectangle1);
}

TEST_CASE("Test translacji Prostokąta")
{
    Vector wektor1(0, 0);
    Vector wektor2(10, 0);
    Vector wektor3(10, 10);
    Vector wektor4(0, 10);


    Rectangle rectangle_test = Rectangle(wektor1, wektor2, wektor3, wektor4);
    Vector wektor(2, 2);
    Vector Przesuniecie_test(5, 5);
    Vector Wynik(4, 12);

    rectangle_test.Kicking_rectangle(Przesuniecie_test);

    Vector wynik_wektor1(5, 5);
    Vector wynik_wektor2(15, 5);
    Vector wynik_wektor3(15, 15);
    Vector wynik_wektor4(5, 15);

    Rectangle rectangle_wynik = Rectangle(wynik_wektor1, wynik_wektor2, wynik_wektor3, wynik_wektor4);

    CHECK(rectangle_test == rectangle_wynik);
}


TEST_CASE("Test obrotu Prostokąta dodatni kąt")
{
    int z = 180;
    int y = 1;

    Matrix macierz_test;

    for(int i = 0; i < y; i++){
            macierz_test.obrotmacierzy(z);
    }

    Vector wektor1(0, 0);
    Vector wektor2(10, 0);
    Vector wektor3(10, 10);
    Vector wektor4(0, 10);

    Rectangle rectangle_test = Rectangle(wektor1, wektor2, wektor3, wektor4);
    
    rectangle_test.throwing_rectangle(macierz_test);

    Vector wynik_wektor1(0, 0);
    Vector wynik_wektor2(-10, 0);
    Vector wynik_wektor3(-10, -10);
    Vector wynik_wektor4(0, -10);

    Rectangle rectangle_wynik = Rectangle(wynik_wektor1, wynik_wektor2, wynik_wektor3, wynik_wektor4);

    CHECK(rectangle_test == rectangle_wynik);
}

TEST_CASE("Test obrotu Prostokąta ujemny kąt")
{
    int z = -270;
    int y = 1;

    Matrix macierz_test;

    for(int i = 0; i < y; i++){
            macierz_test.obrotmacierzy(z);
    }

    Vector wektor1(0, 0);
    Vector wektor2(10, 0);
    Vector wektor3(10, 10);
    Vector wektor4(0, 10);

    Rectangle rectangle_test = Rectangle(wektor1, wektor2, wektor3, wektor4);
    
    rectangle_test.throwing_rectangle(macierz_test);

    Vector wynik_wektor1(0, 0);
    Vector wynik_wektor2(0, 10);
    Vector wynik_wektor3(-10, 10);
    Vector wynik_wektor4(-10, 0);

    Rectangle rectangle_wynik = Rectangle(wynik_wektor1, wynik_wektor2, wynik_wektor3, wynik_wektor4);

    CHECK(rectangle_test == rectangle_wynik);
}

TEST_CASE("Test operatora [] z const")
{
    Vector vektor1(1, 1);
    Vector vektor2(2, 2);
    Vector vektor3(3, 3);
    Vector vektor4(4, 4);
    
    Rectangle Prostokacik(vektor1, vektor2, vektor3, vektor4);
    std::ostringstream Strumien_out;

    Strumien_out << Prostokacik.operator[](0);


    CHECK("[ 1 ] [ 1 ] " == Strumien_out.str());
}

TEST_CASE("Test przeciążenia << do pliku")
{
    Vector vektor1(0, 0);
    Vector vektor2(10, 0);
    Vector vektor3(10, 10);
    Vector vektor4(0, 10);
    
    Rectangle Prostokacik(vektor1, vektor2, vektor3, vektor4);

    std::string File_name = "../datasets/prostokat.dat";
    const char* WSK_FILE = File_name.c_str();
    std::ofstream FILE;

    CHECK(Prostokacik.ZapisWspolrzednychDoPliku(WSK_FILE) == 1);
}

TEST_CASE("Test Metody sprzawdzajacej dlugosci bokow z dopuszczalnym marginesem bledu")
{
    Vector vektor1(0, 0);
    Vector vektor2(10.000001, 0);
    Vector vektor3(10.000001, 10.0000005);
    Vector vektor4(0, 10.0000002314123);
    
    Rectangle Prostokacik(vektor1, vektor2, vektor3, vektor4);

    CHECK(Prostokacik.length_of_the_sides() == 1);
}


