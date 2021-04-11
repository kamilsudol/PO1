#include <iostream>
#pragma once
#include "virus.h"
#include "gene_sequence.h"
#include <vector>

class CoronaVirus:public Virus{
    public:
        CoronaVirus(std::string, std::string,std::vector< Nucleotide >);
        CoronaVirus();
        std::string get_animal_host() const{return animal_name;}
        CoronaVirus(CoronaVirus&);
        CoronaVirus(CoronaVirus&&);
        CoronaVirus &operator=(const CoronaVirus&);
        CoronaVirus &operator=(CoronaVirus&&);
        //CoronaVirus(std::vector<Nucleotide> A):Virus(A),animal_name{"none"}{;}
    private:
        std::string animal_name;
};