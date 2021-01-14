#include <iostream>
#include "organism.h"
#include "dna.h"
#include "gene_utils.h"



class Bacteria:public Organism{
    public:
        
        Bacteria(std::string s,const DNA &A):Organism(s,A){;}
        Bacteria *reproduce(Bacteria *A){mutation(A->sequence);return new Bacteria(*A);} //metoda reprodukujaca bakterie
        Bacteria *reproduce(){return new Bacteria(*this);}//metoda reprodukujaca bakterie
        ~Bacteria(){;}
    protected:
        
};