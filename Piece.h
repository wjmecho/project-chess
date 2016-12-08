#ifndef PIECE_H
#define PIECE_H
#include "Position.h"
//#include "../Plateau.h"
//#include<vector>
#include<iostream>
using namespace std;


class Piece           //基类  棋子
{
    public:
        Piece();
        virtual ~Piece();
        void setcolor(int c);
        virtual void setisDame(bool res);
        int getcolor()const;
        bool getisDame()const;
        bool operator==(const Piece & piece) const;
    protected:

            int color;      //0-----blanc  1-----noir  -1------vide
            bool isDame;    //1-----Dame   0-----pion

////        void saisir();
////        void afficher() const;
////        int getpiece() const;
////        void setpiece(int n);
//        void saisirdepart();                  //输入要走的棋子
//        void afficherdepart() const;           //显示要走的棋子
//        void saisirarrivee();                  //输入要到的地方
//        void afficherarrivee() const;          //显示要到的地方
//        void annuleruncoup();                  //悔棋
//        void movepiece();                      //移动棋子
//        vector<vector<char> >  tab;            //棋盘表格用于悔棋的时候暂存
//
//

//        Plateau plateau;                        //棋盘
//        Position podepart;                       //要走的棋子坐标
//        Position poarrivee;                     //要到的地方坐标
//        Position position;                     //棋子的位置

 };
 ostream &operator<<(ostream &f,const Piece &p);


#endif // PIECE_H
