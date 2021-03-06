#include "../include/vector.hh"


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
Vector::Vector() {
    for (int i = 0; i < SIZE; ++i) {
        size[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

Vector::Vector(double tmp[SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        this->size[i] = tmp[i];
    }
}

/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      x - Wymiar w x.                                                       |
 |      y - Wymiar w y.                                                       |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumentach.                |
 */
Vector::Vector(double x, double y ) {
    
    this->size[0] = x;
    this->size[1] = y;
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
Vector Vector::operator + (const Vector &v) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] += v[i];
    }
    return result;
}

/*!
 * Metoda do szybkiego zapisu danych do wektora przydatne w testowaniu.
 *
 *                       
 */
void Vector::Load_vector(){
    double x,y;
    std::cout<<"Prosz?? poda?? wektor przesuni??cia"<<std::endl;
    std::cin>>x;
    std::cin>>y;

    this->size[0] = x;
    this->size[1] = y;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
Vector Vector::operator - (const Vector &tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] -= tmp[i];
    }
    return result;
}



/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

Vector Vector::operator * (const double &tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}



/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */

Vector Vector::operator / (const double &tmp) {
    Vector result;

    for (int i = 0; i < SIZE; ++i) {
        result[i] = size[i] / tmp;
    }

    return result;
}

/*!
 * Realizuje porownanie dwoch wektorow ze soba dopuszczajac margines bledu.
 * \param[in] tmp - nazwa wektora sprawdzanego z wektorem zawartym wewnatrz klasy
 * 
 * \retval true - gdy oba sa sobie rowne.
 * \retval false - w przypadku przeciwnym.
 */
bool Vector::operator == (const Vector &tmp) const{
    if((std::abs(this->size[0] - tmp.size[0]) <= MIN_DIFF ) && (std::abs(this->size[1] - tmp.size[1]) <= MIN_DIFF )){
        return true;
    }
    return false;
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych wektora.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */
const double &Vector::operator [] (int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}


/*!
 * Przeciazenie operatora [] dla danych chronionych wektora.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */ 
double &Vector::operator [] (int index) {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}


/*!
 * Przeciazenie operatora wypisywania.
 * \param[in] out - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Vektor ktora bedzie wypisywana na
 *                      wyjscie.
 * 
 */
std::ostream &operator << (std::ostream &out, Vector const &tmp){
    for (int i = 0; i < SIZE; ++i) {
        out << "[ " << tmp[i] << " ] ";
    }
    return out;
}


/*!
 * Przeciazenie operatora wpisywania.
 * \param[in] in - strumien wejsciowy, z ktorego maja zostac wypisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Vektor ktora bedzie przyjmowac dane
 *                      z wejscia.
 * 
 */
std::istream &operator >> (std::istream &in, Vector &tmp) {
    for (int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

/*!
 * Przeciazenie operatora wpisywania do pliku.
 * \param[in] in - strumien wejsciowy do pliku, z ktorego maja zostac wpisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Vektor ktora bedzie przyjmowac dane
 *                      z wejscia.
 * 
 */
std::ifstream &operator >> (std::ifstream &in, Vector &tmp){
    
    for (int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    return in;
}
