#pragma once
#include <iostream>


namespace MyStuff{
class vector{
    public:
        
        friend std::ostream &operator<<(std::ostream &out, vector &A){ //przeladowany operator <<
                for(int i=0;i<A.size();i++){
                    out << A.tab[i]<< " ";
                }
                return out;
            }
            
        vector(int a):siz(a){ //konsturkor tworzacy wektor
            tab=new int[a];
            for(int i=0;i<a;i++){
                tab[i]=0;
        }
        }
        vector(const vector &A):siz(A.siz){//konstukror kopiujacy
            tab=new int[siz];
            for(int i=0;i<siz;i++){
                tab[i]=A.tab[i];
        }
        }

        int &operator[](int a){ //przeladowany operator []
            return tab[a];
        }
       

        int size(){ //metoda zwracajaca rozmiar wektora
            return siz;
        }

        void push_back(int a){ //metoda dodajaca element na koniec wektora
            int new_size=siz+1;
            int *temp = new int[size()+1];;
            for(int i=0;i<size();i++){
                temp[i]=tab[i];
            }
            delete [] tab;
            tab=new int[size()+1];
            for(int i=0;i<size();i++){
                tab[i]=temp[i];
            }
            tab[new_size-1]=a;
            siz=new_size;
        }

        void pop_back(){ // metoda usuwajaca ostatni element wektora
            int *temp = new int[size()-1];;
            for(int i=0;i<size()-1;i++){
                temp[i]=tab[i];
            }
            int new_size=siz-1;
            delete [] tab;
            for(int i=0;i<new_size;i++){
                tab[i]=temp[i];
            }
            siz=new_size;
        }

        vector operator=(const vector &A){ //przeladowany operator =
            vector new_vec(A);
            return new_vec;
        }
        /*
        ~vector(){ //destruktor (nie wiem czemu, ale przy odkomentowaniu pojawia sie blad przy sprawdzaniu pamieci)
            if(tab){
                delete [] tab;
            }
        }*/
    
    private:
        int *tab;
        int siz;
};
}

