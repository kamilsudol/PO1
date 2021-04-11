#pragma once
#include <iostream>
#include <vector>
#include "gene_sequence.h"

class Virus{
    public:
        Virus(std::string nam):name{nam},rna_seq{new char}, age{0}, dlugosc{1}{;}
        void set_RNA(std::vector<Nucleotide>);
        int get_age(){return age;}
        std::string get_name(){return name;}
        char * get_RNA(){return rna_seq;}
        friend std::ostream& operator<<( std::ostream&, char *);
        ~Virus(){delete [] rna_seq;}
        Virus(Virus&);
        Virus(Virus&&);
        Virus &operator=(Virus&);
        Virus &operator=(Virus&&);
    private:
        std::string name;
        char* rna_seq;
        int age;
        int dlugosc;
        
};