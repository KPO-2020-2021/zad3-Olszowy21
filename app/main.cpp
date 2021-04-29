// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
#include "rectangle.hh"
#include "vector.hh"
#include "matrix.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */


int main() {
  std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << std::endl;
       // std::system("cat ../LICENSE");
       // do zadania Rotacja 2D
       // std::cout << "Vector:" << std::endl;
       // Vector tmpV1 = Vector();
       // std::cout << "Vector - konstruktor bezparametryczny:\n" << tmpV1 << std::endl;
       // double argumentsV[] = {1.0, 2.0};
       // Vector tmpV2 = Vector(argumentsV);
       // std::cout << "Vector - konstruktor parametryczny:\n" << tmpV2 << std::endl;

       // std::cout << "Matrix:" << std::endl;
       // Matrix tmpM1 = Matrix();
       // std::cout << "Matrix - konstruktor bezparametryczny:\n" << tmpM1 << std::endl;
       // double argumentsM[][SIZE] = {{1.0, 2.0},{3.0, 4.0}};
       // Matrix tmpM2 = Matrix(argumentsM);
       // std::cout << "Matrix - konstruktor parametryczny:\n" << tmpM2 << std::endl;

       std::string File_name = "../datasets/prostokat.dat";
       const char* WSK_FILE = File_name.c_str();
       std::ofstream FILE;
       Rectangle rectangle = Rectangle();
       Vector Przesuniecie = Vector();
       Matrix macierz;
       PzG::LaczeDoGNUPlota  Lacze;       // Ta zmienna jest potrzebna do wizualizacji
                                          // rysunku prostokata

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Ciagly,2);
       //
       //   2. Rysowane jako zbior punktow reprezentowanych przez kwadraty,
       //      których połowa długości boku wynosi 2.
       //
       Lacze.DodajNazwePliku("../datasets/prostokat.dat",PzG::RR_Punktowy,2);
       //
       //  Ustawienie trybu rysowania 2D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy tylko x,y.
       //
       Lacze.ZmienTrybRys(PzG::TR_2D);


       if (!rectangle.ZapisWspolrzednychDoPliku( WSK_FILE )) { return 1; }

  while(1){

       int x;


       std::cout<<"\nWybieram : ( 0 - menu ) > ";
       std::cin>>x;
       switch (x)
       {
       case 0:
              std::cout<<"\n\t**********************MENU***********************"<<std::endl;
              std::cout<<"\t0. Wyświetlenie MENU"<<std::endl;
              std::cout<<"\t1. Obrot prostokata o zadany kat i ilość powtórzeń"<<std::endl;
              std::cout<<"\t2. Przesuniecie prostokata o zadany wektor"<<std::endl;
              std::cout<<"\t3. Wyswietlenie wspolrzednych wierzcholkow"<<std::endl;
              std::cout<<"\t4. Koniec dzialania programu"<<std::endl;
              break;
       case 1:
              int z, y;
              std::cout<< "Proszę podać kąt obrotu prostokąta" <<std::endl;
              std::cin>>z;
              std::cout<< "Oraz ilość powtórzeń tych obrotów" <<std::endl;
              std::cin>>y;
              for(int i = 1; i < y; i++){
                     macierz.obrotmacierzy(z);
              }

              rectangle.throwing_rectangle(macierz);

              if (!rectangle.ZapisWspolrzednychDoPliku( WSK_FILE )) {
                     return 1;
              }

              Lacze.Rysuj();
              std::cin.ignore(10000, '\n');
              break;
       case 2:
              Przesuniecie.Load_vector();
              rectangle.Kicking_rectangle(Przesuniecie);
              if (!rectangle.ZapisWspolrzednychDoPliku( WSK_FILE )) {
                     return 1;
              }

              Lacze.Rysuj();
              std::cin.ignore(10000, '\n');
              break;
       case 3:
              std::cout << rectangle;

              if(rectangle.length_of_the_sides()){
                     std::cout << "\n\tDlugosci naprzeciwleglych bokow sa rowne" << std::endl;
              }
              else{
                     std::cout << "\n\tDlugosci naprzeciwleglych bokow nie sa rowne!!!" << std::endl;
              }

              break;
       case 4:
              if (!rectangle.ZapisWspolrzednychDoPliku( WSK_FILE )) { return 1; }
              exit(1);
              break;
       default:
              std::cout<<" Niepoprawna operacja, numerek 0 to MENU"<<std::endl;
              break;
       }
















       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout,0);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat",0)) return 1;
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       // std::cin.ignore(100000,'\n');
       // //----------------------------------------------------------
       // // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
       // //
       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout,50);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/prostokat.dat",50)) return 1;
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       // std::cin.ignore(100000,'\n');

       // Z bazy projektu-wydmuszki Boiler Plate C++:
       // Bring in the dummy class from the example source,
       // just to show that it is accessible from main.cpp.
}
}