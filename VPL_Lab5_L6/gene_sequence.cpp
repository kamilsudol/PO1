#include "gene_sequence.h"

std::ostream& operator<<( std::ostream& out, const GeneSeq& seq_){
    for(auto x : seq_.chain){
        out << static_cast<char>(x);
    }
    return out;
}