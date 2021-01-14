// tutaj proszę wpisać kod
#pragma once
#include <iostream>
#include <memory>
#include <map>

class User{
    public:
    
        
        User(std::string nam = " "):imie{nam}{std::cout << "Creating User " << imie << std::endl;} //glosny ctor
        ~User(){std::cout << "Deleting User " << imie << std::endl;} //glosny dtor
        
        std::string get_name() const{return imie;} //metoda zwracajaca imie
        
        void authorize(bool a){
            if(!a){
                std::string err = "Authorisation for User " + imie + " was not granted.";
                throw err;
            }
        }
     
    protected:
        std::string imie;
};

class UserArray{
    public:
        UserArray(int n):size{n}{;} //ctor domyslny
        
        ~UserArray(){  //dtor
            for(auto x:lista){
                delete x.second;
            }
        }
        
        void set(int a, User *uzyt){ //metoda dodajaca uzytkownikow do listy
            try{
                if(a < size){ //sprawdzanie, czy nie wychodzimy poza umowiony rozmiar
                    lista.insert(std::pair<int, User *>(a, uzyt));
                }else{
                    delete uzyt; //usuniecie nadmiarowego uzytkownika
                    throw this; //wyrzucenie wyjatku
                }
            }
            
            catch(UserArray *&A){
                delete A; //usuniecie obiektu
                throw 0; //wyrzucenie wyjatku do catcha z maina
            }
        }
        
        User *get(int i) {return lista[i];}
        
        
    protected:
        int size;
        std::map<int, User *> lista;
};