#include "rectangle.hh"

/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami domyslnymi.                            |
 */
Rectangle::Rectangle() {

top[0] = Vector(10, 10);
top[1] = Vector(160, 10);
top[2] = Vector(160, 110);
top[3] = Vector(10, 110);

}

/******************************************************************************
 |  Konstruktor klasy Rectangle.                                              |
 |  Argumenty:                                                                |
 |      Cztery wektory klasy Vector sluzace jako wspolrzedne prostokata.      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona  zadanymi mu wartosciami.                          |
 */
Rectangle::Rectangle(Vector first, Vector second, Vector third, Vector fourth){

this->top[0] = first;
this->top[1] = second;
this->top[2] = third;
this->top[3] = fourth;

}

/*!
 * Realizuje porownanie dwoch prostokatow ze soba dopuszczajac margines bledu.
 * \param[in] tmp - nazwa prostokata sprawdzanego z prostokatem zawartym wewnatrz klasy
 * 
 * \retval true - gdy oba sa sobie rowne.
 * \retval false - w przypadku przeciwnym.
 */
bool Rectangle::operator == (const Rectangle &tmp) const{

    for(int i = 0; i < SIZE*2; i++){
        if(!(this->top[i] == tmp.top[i])){
            return false;
        }
    }
    return true;
}

/*!
 * Przeciazenie operatora [] dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
Vector& Rectangle::operator [] (unsigned int index){
    return top[index];
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsidned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
const Vector& Rectangle::operator [] (unsigned int index) const{
    return top[index];
}

/*!
 * Przeciazenie operatora wypisywania.
 * \param[in] out - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wiechrzolki.
 * \param[in] tmp - skladowa klasy Rectangle ktora bedzie wypisywana na
 *                      wyjscie.
 * 
 */
std::ostream &operator << (std::ostream &out, Rectangle const &tmp){

    for(int i = 0; i < SIZE*2; i++){
        out << i + 1 << " Wiechołek prostokąta - " << tmp.operator[](i) << std::endl;
    }
    return out;
}

/*!
 * Zapis wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * 
 */

void Rectangle::ZapisWspolrzednychDoStrumienia( std::ofstream& StrmWy)
{

  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[0][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[0][1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[1][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[1][1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[2][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[2][1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[3][0]
         << std::setw(16) << std::fixed << std::setprecision(10) << top[3][1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[0][0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[0][1] << std::endl; 
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}


/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] File_name - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * 
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool Rectangle::ZapisWspolrzednychDoPliku( const char *File_name)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(File_name, std::ios::trunc);

  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << File_name << "\"" << std::endl
    << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  ZapisWspolrzednychDoStrumienia(StrmPlikowy);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

/*!
 * Metoda obracania punktow szczegolnych figury.
 * \param[in] tmp - nazwa macierzy która przysłuży się do obracania punktow prostokata
 *                         
 */
void Rectangle::throwing_rectangle(const Matrix &tmp){
    
    for(int i=0;i<SIZE*2;i++){

        top[i] = tmp * top[i];

    }
}

/*!
 * Metoda przesuwania punktow szczegolnych figury o zadany wektor.
 * \param[in] tmp - nazwa wektora która przysluzy się do przesuniecia punktow prostokata
 *                         
 */
void Rectangle::Kicking_rectangle(const Vector &tmp){
    
    for(int i=0;i<SIZE*2;i++){

        top[i] = top[i] + tmp;

    }
}

/*!
 * Metoda sprawdzania dlugosci przeciwleglych bokow aktualnej figury
 * znajdujacej sie w klasie rectangle ( prostokata ).
 * \param[in] tmp - nazwa macierzy która przysłuży się do obracania punktow prostokata
 *  
 * \retval true - gdy boki prostokata sa rowne
 * \retval false - w przypadku przeciwnym.                       
 */
bool Rectangle::length_of_the_sides(){
    double side1; //                                      side3
                  //             top[0] ---> *------------------------------* <--- top[2]
    double side2; //                         |                              |
                  //                         |                              |
    double side3; //           side4 --->    |                              |   <--- side2
                  //                         |                              |
    double side4; //                         |                              |
                  //             top[0] ---> *------------------------------* <--- top[1]
                  //                                      side1
    
    side1 = sqrt( pow( std::abs(top[1][0] - top[0][0]),2)  +  pow( std::abs(top[1][1] - top[0][1]),2));

    side2 = sqrt( pow( std::abs(top[2][0] - top[1][0]),2)  +  pow( std::abs(top[2][1] - top[1][1]),2));

    side3 = sqrt( pow( std::abs(top[3][0] - top[2][0]),2)  +  pow( std::abs(top[3][1] - top[2][1]),2));

    side4 = sqrt( pow( std::abs(top[0][0] - top[3][0]),2)  +  pow( std::abs(top[0][1] - top[3][1]),2));

    if((std::abs(side1 - side3) <= MIN_DIFF) && (std::abs(side2 - side4) <= MIN_DIFF )){
        return true;
    }
    else{

        std::cout << side1 << " != " << side3 << " Mozliwe przekroczenie dopuszczalnego marginesu bledu" << std::endl;
        std::cout << side2 << " != " << side4 << " Mozliwe przekroczenie dopuszczalnego marginesu bledu" << std::endl;

        return false;
    }
    
}
