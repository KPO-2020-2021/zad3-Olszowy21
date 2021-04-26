#include "rectangle.hh"


Rectangle::Rectangle() {

top[0] = Vector(10, 10);
top[1] = Vector(160, 10);
top[2] = Vector(160, 110);
top[3] = Vector(10, 10);

}

Rectangle::Rectangle(Vector first, Vector second, Vector third, Vector fourth){

this->top[0] = first;
this->top[1] = second;
this->top[2] = third;
this->top[3] = fourth;

}

bool Rectangle::operator != (const Rectangle &tmp){
    return !(*this == tmp);
}

bool Rectangle::operator == (const Rectangle &tmp){

    for(int i = 0; i < SIZE*2; i++){
        if(this->top[i] == tmp.top[i]){
            return false;
        }
    }
    return true;
}


Vector& Rectangle::operator [] (int index){
    return top[index];
}


const Vector& Rectangle::operator [] (int index) const{
    return top[index];
    //return const_cast<double &>(const_cast<const Rectangle *>(this)->operator[](index));
}


std::ostream &operator << (std::ostream &out, Rectangle const &tmp){

    for(int i = 0; i < SIZE*2; i++){
        out << i + 1 << " Wiechołek prostokąta - " << tmp.operator[](i) << std::endl;
    }
    return out;
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

void Rectangle::ZapisWspolrzednychDoStrumienia( std::ofstream& StrmWy, Vector Przesuniecie)
{

//   double  x1, y1, x2, y2, x3, y3, x4, y4; 

//   x1 = y1 = 10;
//   x2 = x1 + DL_DLUGI_BOK;  y2 = y1;
//   x3 = x2;  y3 = y2 + DL_KROTKI_BOK;
//   x4 = x3 - DL_DLUGI_BOK; y4 = y3;


  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[0][0] + Przesuniecie[0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[0][1] + Przesuniecie[1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[1][0] + Przesuniecie[0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[1][1] + Przesuniecie[1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[2][0] + Przesuniecie[0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[2][1] + Przesuniecie[1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[3][0] + Przesuniecie[0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[3][1] + Przesuniecie[1] << std::endl;
  StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << top[0][0] + Przesuniecie[0] 
         << std::setw(16) << std::fixed << std::setprecision(10) << top[0][1] + Przesuniecie[1] << std::endl; 
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}


// std::ofstream &operator << (std::ofstream &out, Rectangle const &tmp){
    
//     std::ofstream File;

//     out << std::setprecision(10) << std::fixed;

//     for(int i = 0; i < SIZE*2; i++){
//         File << tmp.operator[](i);
//     }

//     return out;
// }

// void Rectangle::load_data(std::string namefile, int corner){
    
//     std::ofstream file_data;

//     //file_data.open();

// }

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] File_name - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

bool Rectangle::ZapisWspolrzednychDoPliku( const char *File_name, Vector Przesuniecie)
{
  std::ofstream  StrmPlikowy;

  StrmPlikowy.open(File_name, std::ios::trunc);

  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << File_name << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  ZapisWspolrzednychDoStrumienia(StrmPlikowy, Przesuniecie);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}


void Rectangle::Miotanie_prostokata(Matrix tmp){
    
    for(int i=0;i<SIZE*2;i++){

        top[i] = tmp * top[i];

    }
}





#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "../tests/doctest/doctest.h"
TEST_CASE("we can have tests written here, to test impl. details")
{
    CHECK(true);
}
#endif
