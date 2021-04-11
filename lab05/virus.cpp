#include "virus.h"

std::ostream& operator<<( std::ostream& out, char *seq){
    int n = sizeof(seq)/sizeof(char);
    for(int i=0;i<n;i++){
        out << *(seq+i) << " ";
    }
    out << std::endl;
    return out;
}

void Virus::set_RNA(std::vector<Nucleotide> A){
    int i=0;
    delete [] rna_seq;
    dlugosc=A.size();
    rna_seq = new char[dlugosc];
    for(auto x:A){
        rna_seq[i]=static_cast<char>(x);
    }
}

Virus::Virus(Virus &A){
    name=A.name;
    age=0;
    dlugosc=A.dlugosc;
    //delete [] rna_seq; 
    //rna_seq=new char[dlugosc];
    rna_seq=A.rna_seq;
    A.age++;
}
Virus::Virus(Virus &&A){
    name=std::__exchange(A.name," ");
    age=std::__exchange(++A.age,0);
    dlugosc=std::__exchange(A.dlugosc,0);
    delete [] rna_seq; 
    rna_seq=std::__exchange(A.rna_seq,nullptr);
}

Virus &Virus::operator=(Virus &A){
    if(this!=&A){
        name=A.name;
        age=0;
        dlugosc=A.dlugosc;
        delete [] rna_seq; 
        rna_seq=new char[dlugosc];
        rna_seq=A.rna_seq;
        A.age++;
    }
    return *this;
}
Virus &Virus::operator=(Virus &&A){
    if(this!=&A){
        name=std::__exchange(A.name," ");
        age=std::__exchange(++A.age,0);
        dlugosc=std::__exchange(A.dlugosc,0);
        delete [] rna_seq; 
        rna_seq=std::__exchange(A.rna_seq,nullptr);
        
    }
    return *this;
    
}