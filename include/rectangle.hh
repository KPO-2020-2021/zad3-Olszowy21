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

  void throwing_rectangle(const Matrix &tmp);

  bool length_of_the_sides();

  void Kicking_rectangle(const Vector &tmp);

  void ZapisWspolrzednychDoStrumienia( std::ofstream& StrmWy);

  bool ZapisWspolrzednychDoPliku( const char *File_name);

  const Vector &operator [] (unsigned int index) const;

  Vector &operator [] (unsigned int index);

  bool operator == (const Rectangle &tmp) const;

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
