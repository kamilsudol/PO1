// Tutaj proszę napisać klasę Rover
#pragma once
#include<iostream>
#include "utils.h"
#include <vector>
#include <functional>

class Rover{
    public:
        Rover(std::string nam=" "):name{nam},online{false}, coordinates{Coordinates(0,0)}{;} //ctor dla string
       
        virtual void execute(std::function<void()> const &fun){ //metoda wywolujaca dana akcje, sprawdzajaca przy okazji, czy jestesmy podlaczeni do interfejsu
            if(online){
                fun();
            }else{
                std::cout << "ERROR: Rover not linked to an interface." << std::endl;
            }
        }
        typedef std::vector<double> vec;
        typedef std::vector<std::function<void()>> Program; //typedef wektora obiektow
        
        virtual std::string get_name() const { return name;};
        virtual Coordinates get_coordinates() const {return coordinates;}

        virtual void drive(const Program &A) {//metoda wykonująca przemieszczenie sie lazika
            for(auto x: A){
                std::cout<<"Arriving at ";
                //auto nowy = x();                                //Niestety nie mam pomyslu, jak poradzic sobie w tej czesci zadania, na pewno wynika to z tego, ze w typedefie mam voida, co uniemozliwia dalsze operacje,
                                                                  //ale tylko przy voidzie moj program moze sie skompilowac, bo w przeciwnym wypadku wyrzuca blad o brace-enclosed initializer list
                //coordinates += nowy;
                std::cout<< coordinates <<std::endl;
            }
		 }
        
        virtual ~Rover(){;} //wirtualny dtor
    //protected:
        std::string name;
        bool online;
        Coordinates coordinates;
};