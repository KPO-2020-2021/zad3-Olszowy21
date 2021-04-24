#pragma once
#include "size.hh"
#include "vector.hh"


class Vector;

class Rectangle {

  Vector top[SIZE*2];

public:
// Konstruktory 

  Rectangle();

  Rectangle(Vector first, Vector second, Vector third, Vector fourth);

// Metody

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
