// Tutaj proszę wpisać kod
#pragma once
#include<iostream>
#include<map>
#include<vector>
#include<typeinfo>

class WaterContainer{
    public:
        WaterContainer(double x = 0):max_size{x}, current{0}{;} //ctor domyslny
        void put(double a){ //metoda wypelniajaca kontener
            if(a <= max_size){
                current = a;
            }else{
                std::string err = "Error: Container too small."; //wyrzucenie wyjatku w przypadku przepelnienia
                throw err;
            }
        }
        double get() const {return current;} //metoda zwracajaca akutalne wypelnienie
        
        void clean(){current = 0;} //metoda czyszczaca zawartosc
        
        void operator+=(WaterContainer &A){ //operator dodajacy wode
            try{
                put(current + A.get()); //dodanie nowej objetosci
                A.clean(); //w przypadku powodzenia oproznianie kontenera, z ktorego otrzymano dodatkowa objetosc
            }
            catch (const std::string& info) { //przechwycenie wyjatku
		        std::cout << info << std::endl; }
        }
        ~WaterContainer(){;} //dtor domyslny
        
    protected:
        double max_size;
        double current;
};

enum Bill{ //enum dla Bill
    Ten_PLN = 10,
    Twenty_PLN = 20,
    Fifty_PLN = 50,
    Hundred_PLN = 100
};

class Wallet{
    public:
        Wallet(double x = 0):max_size{x}{//ctor domyslny wraz z tworzeniem mapy dla bill
            banknoty.insert(std::pair<int, std::string>(10, "Ten"));
            banknoty.insert(std::pair<int, std::string>(20, "Twenty"));
            banknoty.insert(std::pair<int, std::string>(50, "Fifty"));
            banknoty.insert(std::pair<int, std::string>(100, "Hundred"));
            
        }
        void put(std::vector<Bill> A){//metoda wypelniajaca kontener
            if(A.size() <= max_size){
                current = A;
            }else{
                std::string err = "Error: Wallet too small.";//wyrzucenie wyjatku w przypadku przepelnienia
                throw err;
            }
        }
        
        std::string get(){ //metoda zwracajaca akutalne wypelnienie w formie napisu
            std::string napis;
            if(current.size()){
                for(auto x:current){
                    napis += static_cast<std::string>(banknoty[x]) + " "; //wykorzystanie mapy
                }
                return napis;
            }else{// przypadek, w ktorym portfel jest pusty
                napis = "No bills.";
                return napis;
            }
        }
        
        std::vector<Bill> &gettr(){return current;} //prosta metoda zwracajaca wektor billow
        
        void clean(){current.clear();} //metoda czyszczaca portfel
        
        void operator+=(Wallet &A){
            std::vector<Bill> tmp; //tymczasowy wektor dla nowego rozmiaru portfela
            for(auto x: current){
                tmp.push_back(x);
            }
            for(auto x: A.gettr()){
                tmp.push_back(x);
            }
            try{
                put(tmp); //dodanie nowej kwoty
                A.clean(); //w przypadku powodzenia oproznianie portfela, z ktorego otrzymano dodatkowa wartosc
            }
            catch (const std::string& info) { //przechwycenie wyjatku
		        std::cout << info << std::endl; }
        }
        
        ~Wallet(){;} //dtor domyslny
            
    protected:
        double max_size;
        std::vector<Bill> current;
        std::map<int, std::string> banknoty;
    
};

template<typename T>
void move_to_container(T &a, T &b){ //szablon funckji dodajacej wartosci
    a+=b;
}

template<int a, typename T>
std::vector<T> replicate_container(const T &container){ //szablon funkcji zwracający wektor o zadanym rozmiarze, skladajacy sie tego samego elementu
    std::vector<T> tmp;
    for(int i = 0; i < a; i++){
        tmp.push_back(container);
    }
    return tmp;
}


template<typename T1, typename T2>
void compare_container_type(const T1 &a, const T2 &b){ //szablon funckji sprawdzajacy, czy podane obiekty sa tego samego typu
    if(typeid(a).name() == typeid(b).name()){
        std::cout << "The containers are of same type." << std::endl;
    }else{
        std::cout << "The containers are of different type." << std::endl;
    }
}