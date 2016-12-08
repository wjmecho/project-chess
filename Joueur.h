#ifndef JOUEUR_H
#define JOUEUR_H
//#include "Plateau.h"
#include "Piece.h"
#include "Pion.h"
#include "dame.h"
#include<vector>
class Joueur      //玩家类 基类
{
    public:
        Joueur();
        virtual ~Joueur();
        virtual void move();
        Piece retab(Position p) const;
        void settab(Position p,Piece pi);
        vector<vector<Piece> > tableau,tab;
        Pion p1;
        Dame p2;
        Piece p3;
    protected:


          vector<Position>      memtab;//noter les positions des piece


};

#endif // JOUEUR_H
