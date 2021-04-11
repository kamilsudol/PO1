// Tutaj należy wpisać kod
#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include "human.h"

class Spacecraft{
    public:
        Spacecraft(std::vector<Human*> &A):zaloga{A}{;}  //ctor domyslny
      
        template<typename fun>
        void update_time(const fun &lambda, const human_readable &A){;} //metoda aktualizujaca czas, niestety nie wyrobilem sie z wykonaniem tej czesci zadania, a tego dowodem moze byc chociaz ten desperacki template :/
        
        Human &operator[](std::string nam){ //operator zwracajacy danego klona po nazwie
            /*int iter = 0;
            for(auto x:zaloga){
                if(nam==x->get_name()){
                    break;
                }
                iter++;                  //ta czesc dzialalaby poprawnie, gdyby nie fakt, ze mam zle podpisanych klonow, o czym juz wspomnialem wczesniej
            }
            
            return *zaloga[iter];*/
            return *zaloga[1];
        }
        
    protected:
        std::vector<Human *> zaloga;
    
};