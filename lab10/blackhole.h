// Tutaj należy pisać program
#pragma once
#include <iostream>
#include <cmath>

/*
Tak, jak Pan wspomniał w poleceniu, daję tylko znać, że bonusowe polecenia wykonują się (mam nadzieję) poprawnie.
*/

const double G = 6.67*pow(10,-20);
const double Sl = 2*pow(10,30);
const double c = 3*pow(10,5);

class BlackHole{
    public:
        BlackHole(std::string nam = " ", double m = 0, double odl = 0):nazwa{nam}, masa{m}, odleglosc{odl}{ //ctor domysly wyznaczajacy promien Schwarzschilda
            promien = 2*G*Sl*masa/pow(c,2);
        }
        
        friend std::ostream &operator<<(std::ostream &out, const BlackHole &A){ //przeladowany operator <<
            out << A.nazwa << " : M="<< A.masa << " solar mass, Rh=" << A.promien << " km, dist=" << A.odleglosc << " pc\n";
            return out;
        }
        
        double get_mass() const{return masa;} //metoda zwracajaca mase
        double get_Rh() const{return promien;} //metoda zwracajaca odleglosc
        
        
        
    //protected:
        std::string nazwa;
        double masa;
        double odleglosc;
        double promien;
};

double operator""_pc(long double a){ //operator literalu
    return a*3.1e13;
}