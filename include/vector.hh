#pragma once

#include "size.hh"
#include <iostream>
#include <math.h>
#define MIN_DIFF 0.000001

class matrix;
class Rectangle;
class Vector {

    double size[SIZE];     //Tablica wektora

public:

    double MIN[SIZE];
    
// Konstruktory
    Vector();

    Vector(double [SIZE]);

// Metody

    Vector operator + (const Vector &v);

    Vector operator - (const Vector &tmp);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    Vector operator * (matrix &tmp);

    bool operator == (const Vector &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);

    Vector loadtofile(Vector &tmp);

    Vector display();
    

};

std::istream &operator >> (std::istream &in, Vector &tmp);

std::ifstream &operator >> (std::ifstream &in, Vector &tmp);

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::ofstream &operator << (std::ofstream &out, Vector const &tmp);