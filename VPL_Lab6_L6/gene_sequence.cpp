#include "gene_sequence.h"

std::ostream& operator<<( std::ostream& out, const GeneSeq& seq_){ //przeladowany operator << drukujacy sekwencje nukleotydow
    if(seq_.chain.size()){
        for(auto x : seq_.chain){
            out << static_cast<char>(x) << " ";
        }
    }else{
        out << "0";
    }
    out << "\n";
    return out;
}