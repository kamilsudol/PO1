// Tutaj proszę napisać pozostały kod
#pragma once
#include <iostream>
#include <vector>
#include <functional>


class Coordinates{
  public:
    
    typedef std::vector<double> vec; //typedef dla wektora
    
    Coordinates(double a, double b): x{a}, y{b}{;} //ctor przyjmujacy double
    Coordinates(vec a): x{a[0]}, y{a[1]}{;} //ctor przyjmujacy vector

    ~Coordinates(){;}
    friend std::ostream &operator<<(std::ostream &out, const Coordinates &A){ //operator wypisania
        out << "("<< A.x << ", " << A.y << ")";
        return out;
    }
    
    typedef std::vector<std::function<void()>> Program;  //typedef wektora obiektow
    
    Coordinates &operator+=(const std::vector<double> &A){ //przeladowany operator +=
        x += A[0];
        y += A[1];
        return *this;
    }
    
    friend Coordinates operator-(const Coordinates A, Coordinates B){ //zaprzyjazniony przeladowany operator -
        //x -= A.x;
        //y -= A.y;
        //Coordinates nowy = new Coordinates(A.x-B.x, A.y-B.y);
        return B;
    }
    
  protected:
    double x,y;
};

namespace MarsRoutes{  //przestrzen nazw MarsRoutes

    typedef std::vector<std::function<void()>> Program; //typedef jak wyzej
    typedef std::vector<double> vec;
    //funkcje lazika
    Program route1(){ 
        return {[](){return vec{0,0};}};
    }
    Program go_to(const Coordinates &A, const Coordinates &B){
        return {[](){return vec{0,0};}};
        
    }
    
    
}