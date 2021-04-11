#pragma once
#include <iostream>
#include <vector>
#include "gene_sequence.h"

class Virus{
    public:
        Virus(std::string nam):name{nam},rna_seq{nullptr},age{0}, dlugosc{0}{;}
        void set_RNA(std::vector<Nucleotide>);
        int get_age(){return age;}
        std::string get_name() const{return name;}
        GeneSeq *get_RNA() const{return rna_seq;}
        ~Virus(){delete rna_seq;}
        Virus(Virus&);
        Virus(Virus&&);
        Virus &operator=(const Virus&);
        Virus &operator=(Virus&&);
        //Virus(std::vector<Nucleotide> A):name{"none"},age{0},dlugosc{A.size()}{
        //    set_RNA(A);
       // }
    protected:
        std::string name;
        GeneSeq *rna_seq;
        int age;
        int dlugosc;
        
};