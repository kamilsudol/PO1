#include "sapper_board.h"

SapperBoard::SapperBoard():Board(){;}  //konsturkor domyslny
SapperBoard::SapperBoard(int a, int b, int c):Board(ustal_x(a),ustal_x(b),ustal_miny(a,b,c)){;}  //konsturktor ustawiajacy zadane wartosci
     
SapperBoard::~SapperBoard(){;}  //destruktor

int SapperBoard::get_geometry(int k) const{ //metoda zwrcacajaca informacje o obszarze gry
    if(k==1){
        return get_wym_x();
    }else if(k==2){
        return get_wym_y();
    }else if(k==3){
        return get_l_min();
    }
    return 0;
}

double SapperBoard::get_params(int k) const{  //metoda zwracajaca parametry gry (nie jest wykorzystywana)
    std::cout << "Some params" << std::endl;
    return 0;
}