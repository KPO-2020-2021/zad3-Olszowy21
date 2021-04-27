#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <cstdlib>
#include <math.h>

class Matrix {

    double value[SIZE][SIZE];                  // Wartosci macierzy

public:

// Konstruktory

    Matrix(double tmp[SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                                  // Konstruktor klasy

// Metody

    Vector operator * (Vector tmp) const;            // Operator mnożenia przez wektor

    Vector operator * (const Vector &tmp);

    Matrix operator + (Matrix tmp);

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;

    void obrotmacierzy(double kat);

    bool operator == (const Matrix tmp) const;

    const double &operator [] (int index) const;
    
    double &operator [] (int index);

};

std::istream &operator >> (std::istream &in, Matrix &mat);

std::ostream &operator << (std::ostream &out, Matrix const &mat);
