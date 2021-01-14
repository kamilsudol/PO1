#include <iostream>
#pragma once
#include "virus.h"
#include "gene_sequence.h"
#include <vector>

class CoronaVirus:public Virus{
    private:
        std::string animal_name;

    public:
        CoronaVirus(std::string, std::string,std::vector< Nucleotide >);
        CoronaVirus();
        std::string get_animal_host(){return animal_name;}
        CoronaVirus(CoronaVirus&);
        CoronaVirus(CoronaVirus&&);
        CoronaVirus &operator=(CoronaVirus&);
        CoronaVirus &operator=(CoronaVirus&&);
};