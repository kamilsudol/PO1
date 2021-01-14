#include "sapper.h"

Sapper::Sapper():Game(){;} //konstruktor domyslny
Sapper::~Sapper(){;}  //destruktor

void Sapper::new_board(const Board &board){  //metoda tworzaca nowy obszar gry
    //int k=0;
    int x=board.get_geometry(1);
    int y=board.get_geometry(2);
    get_matrix_pl() = MyStuff::matrix(x,y); 
    get_matrix_help() = MyStuff::matrix(x,y);

    int random_x, random_y;
    for(int i=0; i<board.get_geometry(3);i++){    //losowe rozmieszczenie min
        random_x = rand()%x;
        random_y = rand()%y;
        if(get_matrix_pl()[random_y][random_x]==0){
            get_matrix_pl()[random_y][random_x]=-200;
        }else{
            i--;
        }
    }
    board_prepare(x,y);  //wykorzystanie metody ustalajacej wartosci pol na podstawie rozmieszczenia min
    
    //std::cout << get_matrix_pl();
}

void Sapper::print_board(){  //metoda wyswietlajaca obszar gry
    //std::cout << get_matrix_pl();
    std::cout<<"\n";
    for(int i=0;i<get_matrix_pl().get_y();i++){
        for(int j=0;j<get_matrix_pl().get_x();j++){
            if(get_matrix_help()[i][j]){  //jesli wspolrzedna z obszaru pomocniczego jest rozna od 0, mozna wyswietlic wartosc
                std::cout << get_matrix_pl()[i][j] <<" ";
            }else{  //w przeciwnym wypadku drukuje mine
                std::cout << "* ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<"\n\n";
    
}

bool Sapper::operator()(int x, int y){  //funktor modyfikujacy obszar gry
    int count = 0;
    if(x >= get_matrix_pl().get_x() || y >= get_matrix_pl().get_y()){  //sprawdzenie, czy podane spolrzedne nie wychodza poza zakres
        std::cout << "out of range...\n\n";
        return true;  //zwrocenie true w ramach dalszej gry
    }else{
        int miny = 0;
        for(int i=0;i<get_matrix_pl().get_y();i++){
            for(int j=0;j<get_matrix_pl().get_x();j++){
                if(get_matrix_pl()[i][j]==-200){  //zliczanie min
                    miny++;
                }
            }
        }
        int max = get_matrix_pl().get_x()*get_matrix_pl().get_y()- miny;  //zmienna pomocnicza ustalajaca liczbe mozliwych wspolrzednych do odloniecia
        for(int i=0;i<get_matrix_pl().get_y();i++){
            for(int j=0;j<get_matrix_pl().get_x();j++){
                if(get_matrix_help()[i][j]){
                    count++;     //zliczanie odslonietych pol
                }
            }
        }
        if(get_matrix_pl()[y][x]!=-200 && get_matrix_help()[y][x]==0){  //sprawdzenie czy zadane pole nie bylo juz wczesniej odkryte i czy nie jest one mina
            get_matrix_pl()[y][x]=get_matrix_pl()[y][x]+100;
            get_matrix_help()[y][x]=1;
            count++;
            //std::cout << count << "max "<< max << std::endl;
            if(count == max){  //sprawdzenie, czy nie nastapil koniec gry z pozytywnym wynikiem
                std::cout << "Good job! You survived!" << std::endl;
                return false;
            }else{
                return true;
            }  
        }else if(get_matrix_pl()[y][x] ==-200){  //koniec gry w przypadku, gdy pole jest mina
            std::cout << "\n!!!   BOOOOM    !!!\n     Game Over"<<std::endl;
            return false;
        }
    }
    return true;
}

void Sapper::board_prepare(int x, int y){  //metoda ustalajaca wartosci na obszarze gry na podstawie rozmieszczenia min
    
    int counter = 0;  //zmienna pomocnicza ustalajaca liczbe min wokol badanego pola

    for(int i=0; i<y;i++){
        for(int j=0;j<x;j++){
            counter = 0;
            if(get_matrix_pl()[i][j]!=-200){ //warunek zapeniajacy, ze nie bedziemy badac pol bedacymi minami

                if(i>0 && i<y-1 && j>0 && j<x-1){///////////////Badanie obszaru 3x3//////////////////////////
                    for(int k=i-1;k<i+2;k++){
                        for(int l=j-1;l<j+2;l++){
                            if(get_matrix_pl()[k][l]==-200){
                                counter++;
                            }
                        }
                    }
                    get_matrix_pl()[i][j]=-100+counter;
                    
                }else if(i==0){///////////////////////////Badanie gornego wiersza//////////////////////////////////
                    if(j==0){  //badanie lewego rogu
                        for(int k=i;k<i+2;k++){
                            for(int l=j;l<j+2;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }else if(j==x-1){ 
                        for(int k=i;k<i+2;k++){  //badanie prawego rogu
                            for(int l=j-1;l<j+1;l++){
                                if(get_matrix_pl()[k][l]==-200){    
                                    counter++;
                                }
                            }
                        }
                    }else{  //badanie srodka wiersza
                        for(int k=i;k<i+2;k++){
                            for(int l=j-1;l<j+2;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }
                    get_matrix_pl()[i][j]=-100+counter;

                }else if(i==y-1){///////////////////////////Badanie dolnego wiersza/////////////////////////////
                    if(j==0){  //badanie lewego rogu
                        for(int k=i-1;k<i+1;k++){
                            for(int l=j;l<j+2;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }else if(j==x-1){  //badanie prawego rogu
                        for(int k=i-1;k<i+1;k++){
                            for(int l=j-1;l<j+1;l++){
                                if(get_matrix_pl()[k][l]==-200){   
                                    counter++;
                                }
                            }
                        }
                    }else{  //badanie srodka wiersza
                        for(int k=i-1;k<i+1;k++){
                            for(int l=j-1;l<j+2;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }
                    get_matrix_pl()[i][j]=-100+counter;
                }else if(j==0){////////////////////////////Badanie lewej kolumny////////////////////////////////////
                    if(i==0){ //badanie gornego rogu
                        for(int k=i;k<i+2;k++){
                            for(int l=j;l<j+2;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }else if(i==y-1){ //badanie dolnego rogu
                        for(int k=i-1;k<i+1;k++){
                            for(int l=j;l<j+2;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }else{  //badanie srodka kolumny
                        for(int k=i-1;k<i+2;k++){
                            for(int l=j;l<j+2;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }
                    get_matrix_pl()[i][j]=-100+counter;
                }else if(j==x-1){/////////////////////////Badanie prawej kolumny///////////////////////////////////
                    if(i==0){  //badanie gornego rogu
                        for(int k=i;k<i+2;k++){
                            for(int l=j-1;l<j+1;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }else if(i==y-1){ //badanie dolnego rogu
                        for(int k=i-1;k<i+1;k++){
                            for(int l=j-1;l<j+1;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }else{  //badanie srodka kolumny
                        for(int k=i-1;k<i+2;k++){
                            for(int l=j-1;l<j+1;l++){
                                if(get_matrix_pl()[k][l]==-200){
                                    counter++;
                                }
                            }
                        }
                    }
                    get_matrix_pl()[i][j]=-100+counter;
                }
            }
        }
    }
}