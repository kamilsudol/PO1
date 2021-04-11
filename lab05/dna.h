#pragma once
#include <iostream>
#include <vector>
#include "gene_sequence.h"

/*
Ogólnie zdaje sobie sprawę, że mój program to totalna katastrofa,
ale wyłożyłem sie na dosyć śmiesznych błędach, przez co nie jestem
już w stanie dokończyć programu tak, aby działał poprawnie, a bezsensowne
deklaracje funckji w klasie coronavirus są tylko po to, żeby całość się mogła 
skompilować.
Pozdrawiam!
*/

class DNA: public GeneSeq{
    public:
        DNA(const GeneSeq&, const GeneSeq&);
        friend std::ostream& operator<<( std::ostream&, const DNA&);
    private:
        std::vector<GeneSeq> dna_chain1;
        std::vector<GeneSeq> dna_chain2;
        int dlugosc;
};