#include "dna.h"

DNA::DNA(const GeneSeq &a, const GeneSeq &b):GeneSeq(a.get_sequence()){
    dna_chain1.push_back(a);
    dna_chain2.push_back(b);
    dlugosc = a.get_sequence().size();
}
std::ostream& operator<<( std::ostream &out, const DNA &A){
    for(auto x: A.dna_chain1){
        out << x << " ";
    }
    out << std::endl;
    for(int i=0;i<A.dlugosc;i++){
        out << "|";
    }
    out << std::endl;
    for(auto x: A.dna_chain2){
        out << x << " ";
    }
    out << std::endl;
    return out;
}