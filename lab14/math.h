// Tutaj proszę wpisać rozwiązanie
#pragma once
#include <iostream>
#include <cmath>
#include <map>
#include <initializer_list>

template<const int n, const double *x1, const double *x2>
class IntegralXn{
    public:
        constexpr static double value = (n >=0)? (1./(n+1))*pow(*x2, n + 1) - (1./(n+1))*pow(*x1, n + 1) : 0.0; //proces obliczania calki
};

template<typename T>
class GroupZn{
    public:
        GroupZn(std::initializer_list<T> grupy){ //ctor wypelniajacy mapy
            int i = 0;
            for(auto x: grupy){
                list1.insert(std::pair<int, T>(i, x));
                list2.insert(std::pair<T, int>(x, i++));
            }
        }
        
        T operator()(T x, T y){ //funktor zwracajacy odpowiadni produkt z mnozenia elementow grupy
            if(x == y ){//jezeli oba elementy takie same, zwroc element neutralny
                return list1[0];
            }else if(x == list1[0]){//jezeli element neutralnt, zwroc drugi element
                return y;
            }else if(y == list1[0]){//jezeli element neutralnt, zwroc drugi element
                return x;
            }else{//pozostale przypadki
                return list1[(list2[x]*list2[y])%(list1.size()-1)+1];
            }
        }
        
        ~GroupZn(){;} //dtor
    private:
        std::map<int, T> list1;
        std::map<T, int> list2;//pomocnicza mapa
};