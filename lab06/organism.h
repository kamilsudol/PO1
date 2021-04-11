#pragma once
#include "dna.h"
//#include "gene_utils.h"

class DNA;

class Organism{
    public:
        friend class DNA;
        Organism(std::string s, const DNA &A):name{s}, sequence{A}{;}
        std::string get_name(){return name;}
        DNA get_dna() const{return sequence;}
        virtual Organism* reproduce(Organism *a) {return a;} //czysto wirtualna metoda reprodukujaca 
        virtual Organism* reproduce() {return this;} //czysto wirtualna metoda reprodukujaca 
       
        void operator<<(Virus &A){
            //int losuj = rand()%2;   //niestety nie wystarczylo mi czasu na dokonczenie tej sekcji
            //mutation(sequence[losuj]);
        }
        virtual ~Organism(){;}
       
    protected:
        std::string name;
        DNA sequence;
};