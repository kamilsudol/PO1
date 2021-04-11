// Tutaj należy wpisać kod
#pragma once
#include <iostream>
#include <tuple>

typedef std::tuple<int,int,int,int,int> human_readable;

const int minutes = 60;
const int hours = 60*minutes;
const int day = 24*hours;
const int year = 365*day;
static double i = 1;


std::ostream &operator<<(std::ostream &out, const human_readable &A){
    out << std::get<0>(A) << "y:"<<std::get<1>(A)<<"d:"<<std::get<2>(A)<<"h:"<<std::get<3>(A)<<"m:"<<std::get<4>(A)<<"s";  //przeladowany operator << wypisujacy human readable
    return out;
}

human_readable operator+(const human_readable &A, const human_readable &B){  //przeladowany operator +, sumujacy human readable
    human_readable nowy {std::get<0>(A)+std::get<0>(B), std::get<1>(A)+std::get<1>(B), std::get<2>(A)+std::get<2>(B), std::get<3>(A)+std::get<3>(B), std::get<4>(A)+std::get<4>(B),};
    return nowy;
}

const human_readable operator""_yrs(unsigned long long int a){ //literal konwetujacy lata na human readable
    const human_readable nowy {a,0,0,0,0};
    return nowy;
}

const human_readable operator""_sec(unsigned long long int a){ //literal konwetujacy sekundy na human readable
    int sekundy = a%minutes;
    int lata = a/year;
    int dni = (a-lata*year)/day;
    int godziny = (a-lata*year-dni*day)/hours;
    int minuty = (a-lata*year-dni*day - godziny*hours)/minutes;
    
    const human_readable nowy {lata,dni,godziny,minuty,sekundy};
    return nowy;
}

int to_sec(const human_readable &A){ //funckja zwracajaca sekundy na podstawie human readable
    return std::get<0>(A)*year+std::get<1>(A)*day+std::get<2>(A)*hours+std::get<3>(A)*minutes+std::get<4>(A);
}

human_readable from_sec(int a){ // funkcja zwracajaca human readable na podstawie sekund
    return operator""_sec(a);
}


class Human{
    public:
        Human(std::string nam, human_readable ag):name{nam},age{ag}{;} //ctor domyslny
        std::string get_name() const {return name;} //metoda zwracajaca name
        human_readable get_age() const {return age;} //metoda zwracajaca age
        void update_time(const human_readable t){age+t;} //metoda aktualizujaca wiek
        ~Human(){;}
    protected:
        std::string name;
        human_readable age;
};

class Clone:public Human{
    public:
        Clone(Human &A):Human(A.get_name()+"_"+std::to_string(static_cast<int>(i)),A.get_age()){i+=0.5;} //ctor domyslny, nie za bardzo mialem pomysl, jak rozwiazac problem z numerowaniem klonow, stad taka prowizorka
        ~Clone(){;}
    protected:
};