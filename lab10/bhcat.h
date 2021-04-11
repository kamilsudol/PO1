// Tutaj należy pisać program
#pragma once
#include <iostream>
#include <vector>
#include "blackhole.h"
#include <initializer_list>
#include <map>
#include <algorithm>
#include <functional>

class BHCatalogue{
    public:
        BHCatalogue(){ //ctor domyslny ustawiajacy literaly
            nowy = {};
            liter.insert(std::pair<int, std::string>(1,"I."));
            liter.insert(std::pair<int, std::string>(2,"II."));
            liter.insert(std::pair<int, std::string>(3,"III."));
            liter.insert(std::pair<int, std::string>(4,"IV."));
            liter.insert(std::pair<int, std::string>(5,"V."));
        }
        
        std::string get_num(int i){ //metoda pomocnicza zwracajaca odpowiedni literal
            return liter[i];
        }
        void add(const BlackHole &A){ //metoda dodajaca pojedyncza czarna dziure
            lista.insert(std::pair<std::string, BlackHole>(get_num(lista.size()), A));
        }
        
        void add(std::initializer_list<BlackHole> A){ //metoda dodajaca czarne dziury z listy inicjalizacyjnej
            for(auto x:A){
                if(lista.size()<5){
                    lista.insert(std::pair<std::string, BlackHole>(get_num(lista.size()+1), x));
                }else{
                    std::cout << ">> Catalogue full. "<<x.nazwa<<" not added.\n";
                }
            }
            
        }
        
        BlackHole &get(std::string i){ //metoda zwracajaca nazwe czarnej dziury
            return lista[i];
        }
        
        std::map<std::string, BlackHole> &get_map(){return lista;} //metoda zwracajaca liste
        
        std::vector<BlackHole> &get_ordered_by_mass(){ //metoda sortujaca czarne dziury wg masy
            nowy.clear();
            //std::for_each(lista.begin(), lista.end(), [&nowy](auto &A){nowy.push_back(A.second);});
            for(auto &x:lista){
                nowy.push_back(x.second);
            }
            std::sort(nowy.begin(),nowy.end(),[](BlackHole &A, BlackHole &B){return A.masa<B.masa;});
            return nowy;
        }
        
         std::vector<BlackHole> &get_custom(std::function<bool(const BlackHole& bh_)> fun){ //metoda zwracajaca porzadany wektor czarnych dziur
            nowy.clear();
            for(auto &x:lista){
                if(fun(x.second)){
                    nowy.push_back(x.second);
                }
            }
            return nowy;
         }
         
    protected:
        std::map<int, std::string> liter;
        std::map<std::string, BlackHole> lista;
        std::vector<BlackHole> nowy; //wektor dla sort i get_custom
};
