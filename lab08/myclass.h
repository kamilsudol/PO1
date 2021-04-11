// Tutaj należy wpisać rozwiązanie
#pragma once
#include <iostream>
#include <memory>
#include "terrorist.h"
#include "weapon.h"

class Terrorist1 : public Terrorist, Knife, Rifle{
    public:
        using Terrorist::Terrorist; //uzycie konstroktorow klasy bazowej
        
        void what() const override{ print(w); }//wykorzystanie wczesniej utworzonej metody print do wyswietlenia info o terro
        
        void attack() const override{ // wywolanie funkcji broni
            Knife::cut();
            Rifle::shoot();
        }
        
        ~Terrorist1(){;}
        
    protected:
        weapons w = {Knife::name,Rifle::name}; //dodanie uzbrojenia
};

class Terrorist2 : public Terrorist, Axe, Bomb{
    public:
        using Terrorist::Terrorist; //uzycie konstroktorow klasy bazowej
        
        void what() const override{ print(w); }//wykorzystanie wczesniej utworzonej metody print do wyswietlenia info o terro
            
        void attack() const override{ // wywolanie funkcji broni
            Axe::chop();
            Bomb::explode();
        }
        
        ~Terrorist2(){;}
        
    protected:
        weapons w = {Axe::name, Bomb::name}; //dodanie uzbrojenia
};

class Safety : public Terrorist{
    public:
        Safety(Terrorist *A):ptr{A}, protect_flag{true}{;} //konstruktor dla Terrorist*
        Safety(std::unique_ptr<Terrorist> &A):ptr{A.get()}, protect_flag{true}{;} //konstruktor dla unique_ptr<Terrorist>
        
        void what() const override{ ptr->what(); } //wykorzystanie wczesniej utworzonej metody print do wyswietlenia info o proxy
        
        void attack() const override{ // wywolanie funkcji broni
            if(protect_flag){
                ptr->attack();
            }
        }
        
        void apply_safety_measures(){ protect_flag = false; } //metoda unieszkodliwiajaca terro
        
        ~Safety(){;}
        
    protected:
        Terrorist *ptr;
        bool protect_flag;
};