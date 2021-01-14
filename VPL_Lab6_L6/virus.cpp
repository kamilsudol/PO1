#include "virus.h"

void Virus::set_RNA(std::vector<Nucleotide> A){
    dlugosc=A.size();
    rna_seq = new GeneSeq(A);
}

Virus::Virus(Virus &A){
    //std::cout<<"wchodzi1";
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

Virus::Virus(Virus &&A){
    //std::cout<<"wchodzi2";
    name = std::move(A.name);
    age = std::move(A.age);
    dlugosc = std:: move(A.dlugosc);
    rna_seq=std::__exchange(A.rna_seq,nullptr);
}

Virus &Virus::operator=(const Virus &A){
    //std::cout<<"wchodzi3";
    if(this!=&A){
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
Virus &Virus::operator=(Virus &&A){
    //std::cout<<"wchodzi4";
    if(this!=&A){
        if(rna_seq){
            delete rna_seq; 
        }
        std::swap(A.name,name);
        std::swap(A.age,age);
        std::swap(A.dlugosc,dlugosc);
        std::swap(A.rna_seq,rna_seq);
        
    }
    return *this;
    
}