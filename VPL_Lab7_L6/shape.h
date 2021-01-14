#pragma once
#include <iostream>
#include <vector>
#include <string>

class Shape{
    public:
        Shape(std::string name, std::vector<double> a):nazwa_kszt{name}{
            for(auto x:a){
                params.push_back(x);
            }
        }
        virtual double area() const = 0;
        virtual double circumference() const = 0;
        friend std::ostream &operator<<(std::ostream &o, const Shape &A){ //przeladowany operator << wypisujacy nazwe ksztaltu
            o << A.nazwa_kszt;
            return o;
        }
        virtual ~Shape(){;}
        std::string getName(){return nazwa_kszt;} //pomocnicza metoda zwracajaca nazwe ksztaltu
        std::vector<double> getParam(){return params;} //pomocnicza metoda zwracajaca wektor parametrow
       
    protected:
        std::string nazwa_kszt;
        std::vector<double> params;
};

class Rectangle: public Shape{
    public:
        using Shape::Shape; //wykorzystanie konstruktorow klasy bazowej
        double area() const{ //metoda obliczajaca pole prostokata
            double iloczyn=1;
            for(auto x:params){
                iloczyn*=x;
            }
            //return static_cast<std::string>(iloczyn);
            return iloczyn;
        }
        double circumference() const{ //metoda obliczajaca obwod prostokata
            double suma = 0;
            for(auto x:params){
                suma+= 2*x;
            }
            //return static_cast<std::string>(suma);
            return suma;
        }
        
        ~Rectangle(){;}
        
    protected:
        
    
};
class Circle: public Shape{
    public:
        using Shape::Shape;//wykorzystanie konstruktorow klasy bazowej
        double area() const{ //metoda obliczajaca pole kola
            return 3.14*params[0]*params[0];
        }
        double circumference() const{ //metoda obliczajaca obwod kola
            return 2*3.14*params[0];
        }
        ~Circle(){;}
        
    protected:
};