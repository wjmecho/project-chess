#include "Piece.h"
#include "Position.h"
#include<iostream>
#include "../Plateau.h"
using namespace std;

Piece::Piece()
{
   //ctor
}

Piece::~Piece()
{
    //dtor
}
//
//
//void Piece::saisirdepart(){                                                  //输入要走的棋子
//    do{
//            cout<<"La piece depart:"<<endl;
//           podepart.saisirposition();                                     //输入坐标
//          if(plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]!=plateau.p1&&
//             plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]!=plateau.P1)    //如果棋盘上相应坐标对应的地方没有棋子 则错误重新输入
//           {
//               cout<<"Valeur invalide! Entrez encore!"<<endl;
//           }
//    }
//    while(plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]!=plateau.p1&&
//             plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]!=plateau.P1);
//}
//
//void Piece::afficherdepart() const{                    //显示要走的棋子
//    cout<<"Le piece depart est:";
//    podepart.afficherposition();                        //显示坐标
//
//}
//
//void Piece::saisirarrivee(){                            //输入要走到的地方
//   do{
//    cout<<"La position arrivee"<<endl;
//    poarrivee.saisirposition();                     //输入坐标
//    if(plateau.tableau[poarrivee.getligne()-65][poarrivee.getcolonne()-1]!=' ')       // 如果要到的位置不是空的 则输入无效重新输入
//           {
//               cout<<"valeur invalide! entrez encore!"<<endl;
//           }
//    }
//    while(plateau.tableau[poarrivee.getligne()-65][poarrivee.getcolonne()-1]!=' ');
//
//}
//
//void Piece::afficherarrivee() const{                                   //显示要走到的位置
//    cout<<"La position arrivee est:";
//    poarrivee.afficherposition();                                        //显示坐标
//}
//
//
//
// void Piece::annuleruncoup(){                                                   //悔棋
//     cout<<"Annuler la marche ?(0-------non   1------oui)"<<endl;      //0---不悔棋  1----悔棋
//     int p;
//     do{
//       cin>>p;
//     if(p==1)
//     {
//         plateau.tableau=tab;                 //悔棋 则棋盘变回走之前  并且再次显示棋盘    如果不悔棋则不再再次显示棋盘
//         plateau.afficher();
//     }
//     else if(p!=0&&p!=1){cout<<"Invalide! Encore une fois!"<<endl;}      //如果输入的p不是0 或1 则输入无效再次输入
//     }
//     while(p!=0&&p!=1);
//
//
//
//
// }
//
//
// void Piece::movepiece(){          //移动棋子 输入要走的棋子和要到达的位置
//
//
//     do{
//            saisirdepart();
//            saisirarrivee();
//            if(podepart.getligne()==poarrivee.getligne()||podepart.getcolonne()==poarrivee.getcolonne()){
//                cout<<"Invalid ! Entrez encore !"<<endl;
//            }
//     }while(podepart.getligne()==poarrivee.getligne()||podepart.getcolonne()==poarrivee.getcolonne());
// }
//

//new version

void Piece::setcolor(int c){
    color=c;
}
void Piece::setisDame(bool res){
    isDame=res;
}
int Piece::getcolor()const{
    return(color);
}
bool Piece::getisDame()const{
    return(isDame);
}

bool Piece::operator==(const Piece & piece) const{


    return(color==piece.getcolor()&&isDame==piece.getisDame());
//    if(!(isDame==piece.getisDame()))
//    {return false;}
//    else{
//        if(color==poece.getcoor())
//        {return true;}
//        else{return false;}
//    }
}

ostream &operator<<(ostream &f,const Piece &p){
    if(p.getcolor()==0&&p.getisDame()==0){
        f<<'o';
    }
    else if(p.getcolor()==0&&p.getisDame()==1){
        f<<'O';
    }
    else if(p.getcolor()==1&&p.getisDame()==0){
        f<<'x';
    }
    else if(p.getcolor()==1&&p.getisDame()==1){
        f<<'X';
    }
    else if(p.getcolor()==-1){
        f<<' ';
    }
    return f;
}




