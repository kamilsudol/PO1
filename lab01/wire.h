#pragma once
#include <iostream>

class QuantumWire{
    public:
        QuantumWire(double,int);
        QuantumWire();
        QuantumWire(const QuantumWire&);
        QuantumWire(const QuantumWire&&);
        ~QuantumWire();

        friend std::ostream &operator<<(std::ostream&, const QuantumWire&);

        QuantumWire &operator!();
        QuantumWire &operator*(double,QuantumWire&);
        QuantumWire &operator*=(double);
        //QuantumWire operator[](const QuantumWire&);
    private:
        double wir_len;
        bool *liczba;
        //int stan;

};
