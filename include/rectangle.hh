#pragma once
#include "size.hh"
#include "vector.hh"
#include "matrix.hh"

class Rectangle {

  Vector top[SIZE*2];

public:
// Konstruktory 

  Rectangle();

  Rectangle(Vector first, Vector second, Vector third, Vector fourth);

// Metody

  void Miotanie_prostokata(Matrix tmp);

  void load_data(std::string File_name, int corner);

  void ZapisWspolrzednychDoStrumienia( std::ofstream& StrmWy, Vector Przesuniecie);

  bool ZapisWspolrzednychDoPliku( const char *File_name, Vector Przesuniecie);

  const Vector &operator [] (int index) const;

  Vector &operator [] (int index);

  bool operator != (const Rectangle &tmp);

  bool operator == (const Rectangle &tmp);

};

std::ostream &operator << (std::ostream &out, Rectangle const &tmp);

// std::ofstream &operator << (std::ofstream &out, Rectangle const &tmp);

std::ostream &operator << (std::ostream &out, Vector const &tmp);


#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "../tests/doctest/doctest.h"
TEST_CASE("we can have tests in headers if we want")
{


}

#endif
