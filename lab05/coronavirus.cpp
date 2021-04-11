#include "coronavirus.h"

CoronaVirus::CoronaVirus(std::string a, std::string b,std::vector< Nucleotide > c):Virus(a){
    animal_name = b;
    set_RNA(c);
}
CoronaVirus::CoronaVirus():Virus(" "){
    animal_name = " ";
}

CoronaVirus::CoronaVirus(CoronaVirus &A):Virus(" "){
    animal_name=A.animal_name;
}

CoronaVirus::CoronaVirus(CoronaVirus &&A):Virus(" "){
    animal_name=A.animal_name;
}
CoronaVirus &CoronaVirus::operator=(CoronaVirus &A){
    animal_name=A.animal_name;
    return *this;
}
CoronaVirus &CoronaVirus::operator=(CoronaVirus &&A){
    animal_name=A.animal_name;
    return *this;
}