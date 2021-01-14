#pragma once
#include <iostream>
#include <vector>
#include "gene_sequence.h"


class DNA: public GeneSeq{
    public:
        DNA(GeneSeq&, GeneSeq&);
        DNA():GeneSeq{std::vector< Nucleotide >(A)},dlugosc{1}{;}
        friend std::ostream& operator<<( std::ostream&, const DNA&);
        
        std::vector< Nucleotide > operator[](int i) const{ //przeladowany operator [] zwracajacy porzadana sekwecje DNA
            int iter = dlugosc/2;
            int j=0;
            std::vector< Nucleotide > nowy;
            if(i == 0){  //gorna sekwencja
                for(auto x:chain){
                    if(j<iter){
                        nowy.push_back(x);
                    }
                }
            }else{ //dolna sekwencja
                for(auto x:chain){
                    if(iter<=j && j<dlugosc){
                        nowy.push_back(x);
                    }
                }
                j++;
            }
            return nowy;
        }
        DNA(std::vector< Nucleotide > A,std::vector< Nucleotide > B):GeneSeq(A),dlugosc(A.size()){
            for(auto x: B){
                chain.push_back(x);
            }
        }
        std::vector< Nucleotide > get_chain(bool x) const{return chain;}
    //protected:
        int dlugosc;
};