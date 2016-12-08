#ifndef PIECE_H
#define PIECE_H
#include "Position.h"
//#include "../Plateau.h"
//#include<vector>
#include<iostream>
using namespace std;


class Piece           //����  ����
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
//        void saisirdepart();                  //����Ҫ�ߵ�����
//        void afficherdepart() const;           //��ʾҪ�ߵ�����
//        void saisirarrivee();                  //����Ҫ���ĵط�
//        void afficherarrivee() const;          //��ʾҪ���ĵط�
//        void annuleruncoup();                  //����
//        void movepiece();                      //�ƶ�����
//        vector<vector<char> >  tab;            //���̱�����ڻ����ʱ���ݴ�
//
//

//        Plateau plateau;                        //����
//        Position podepart;                       //Ҫ�ߵ���������
//        Position poarrivee;                     //Ҫ���ĵط�����
//        Position position;                     //���ӵ�λ��

 };
 ostream &operator<<(ostream &f,const Piece &p);


#endif // PIECE_H
