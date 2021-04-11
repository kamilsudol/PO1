#include <iostream>
#include "organism.h"
#include "gene_utils.h"

class Protozoa:public Organism{
     public:
        
        Protozoa(std::string s,const DNA &A):Organism(s,A){;}
        Protozoa *reproduce(Protozoa *A){mutation(A->sequence);return new Protozoa(*A);} //metoda reprodukujaca pierwotniaki
        Protozoa *reproduce(){return new Protozoa(*this);} //metoda reprodukujaca pierwotniaki
        ~Protozoa(){;}
    protected:
        
    
};