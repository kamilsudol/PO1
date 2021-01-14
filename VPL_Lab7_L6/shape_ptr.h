#pragma once
#include <iostream>
#include "shape.h"

class Shape_ptr{
    public:
        Shape_ptr(Shape *A=nullptr):ptr{A}{;}
        ~Shape_ptr(){
            if(ptr){
                delete ptr;
                //ptr = nullptr;
            }
        }
        Shape &operator*() const {return *ptr;} //przeladowany operator dereferencji
        operator bool(){//przeladowany operator bool
            if(ptr){
                return true;
            }else{
                return false;
            }
        }
        
        Shape_ptr *operator=(Shape_ptr &A){  //przeladowany operator =, przepisujacy wskazniki dla shape_ptr
            delete ptr;
            ptr = new Rectangle(A.ptr->getName(), A.ptr->getParam());
            delete A.ptr;
            A.ptr = nullptr;
            return nullptr;
        }
        Shape_ptr *operator=(Shape *A){   //przeladowany operator =, przepisujacy wskazniki dla shape
            delete ptr;
            //ptr = A;
            ptr = new Rectangle(A->getName(), A->getParam());
            //delete A;
            A = nullptr;    //nie mam pojecia, dlaczego w tym miejscu polecenie nie dziala porpawnie oraz zauwazylem, za odkomentowujac delete A wypisuje mi w tym miejscu wartosci dla rectangle 2 mimo, ze przyjmuje w ifie rect1
            return nullptr;
        }
    protected:
        Shape *ptr;
    
};