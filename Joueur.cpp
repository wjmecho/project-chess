#include "Joueur.h"

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}

void Joueur::move(){

}

Piece Joueur::retab(Position p)const{
    return(tableau[p.getligne()-65][p.getcolonne()-1]);
}

void Joueur::settab(Position p,Piece pi){
    tableau[p.getligne()-65][p.getcolonne()-1]=pi;
}
