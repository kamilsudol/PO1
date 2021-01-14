#include "coronavirus.h"

CoronaVirus::CoronaVirus(std::string a, std::string b,std::vector< Nucleotide > c):Virus(a),animal_name{b}{
    set_RNA(c);
}

CoronaVirus::CoronaVirus():Virus("none"),animal_name {"none"}{;}

CoronaVirus::CoronaVirus(CoronaVirus &A):Virus(A.name){
    animal_name=A.animal_name;
    name = A.name;
    age = 0;
    dlugosc = A.dlugosc;
    if(A.rna_seq){
        rna_seq = new GeneSeq(A.rna_seq->get_sequence());
    }else{
        rna_seq = nullptr;
    }
    A.age++;
}

CoronaVirus::CoronaVirus(CoronaVirus &&A):Virus(A.name){
    animal_name=std::move(A.animal_name);
    name = std::move(A.name);
    age = std::move(A.age);
    dlugosc = std:: move(A.dlugosc);
    rna_seq=std::__exchange(A.rna_seq,nullptr);
}
CoronaVirus &CoronaVirus::operator=(const CoronaVirus &A){
    if(this!=&A){
        animal_name=A.animal_name;
        name = A.name;
        age = 0;
        dlugosc = A.dlugosc;
        if(A.rna_seq){
            rna_seq = new GeneSeq(A.rna_seq->get_sequence());
        }else{
            rna_seq = nullptr;
        }
    }
    return *this;
}

CoronaVirus &CoronaVirus::operator=(CoronaVirus &&A){
    if(this!=&A){
        if(rna_seq){
            delete rna_seq; 
        }
        std::swap(A.animal_name,animal_name);
        std::swap(A.name,name);
        std::swap(A.age,age);
        std::swap(A.dlugosc,dlugosc);
        std::swap(A.rna_seq,rna_seq);
        
    }
    return *this;
}