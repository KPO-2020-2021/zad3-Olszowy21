#include "rectangle.hh"


Rectangle::Rectangle() {

top[0] = Vector();
top[1] = Vector();
top[2] = Vector();
top[3] = Vector();

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
    return const_cast<double &>(const_cast<const Rectangle *>(this)->operator[](index));
}


std::ostream &operator << (std::ostream &out, Rectangle const &tmp){

    for(int i = 0; i < SIZE*2; i++){
        out << tmp.operator[](i);
    }
    return out;
}


// std::ofstream &operator << (std::ofstream &out, Rectangle const &tmp){
      
//       for(int i = 0; i < SIZE*2; i++){
//         out << tmp.operator[](i);
//     }
//     return out;
// }







#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "../tests/doctest/doctest.h"
TEST_CASE("we can have tests written here, to test impl. details")
{
    CHECK(true);
}
#endif
