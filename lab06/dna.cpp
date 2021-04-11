#include "dna.h"

DNA::DNA(GeneSeq &a,GeneSeq &b):GeneSeq(a.get_sequence()){
    dlugosc = a.get_sequence().size();
    for(auto x: b.get_sequence()){
        chain.push_back(x);
    }
    
}

std::ostream& operator<<( std::ostream &out, const DNA &A){ //przeladowany operator << wypisujacy sekwencje dna
    int i=0;
    for(auto x: A.chain){
        if(i==A.dlugosc){
            out << std::endl;
            for(int i=0;i<A.dlugosc;i++){
                out << "| ";
            }
            out << std::endl;
            out << static_cast<char>(x) << " ";
        }else{
            out << static_cast<char>(x) << " ";
        }
        i++;
    }
    out << std::endl;
    return out;
}