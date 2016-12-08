#include "Position.h"
#include<iostream>
using namespace std;

Position::Position()
{
    //ctor
}

Position::~Position()
{
    //dtor
}

//Position::Position(const Position & p):l(p.getligne()),c(p.getcolonne){}
//
void Position::saisirposition(){
     char tmp;
     int n;
     cin>>tmp>>n;
//     cout<<"le ligne:"<<endl;
//     cin>>tmp;                //输入行号
//     setligne(tmp);
//     cout<<"le colonne:"<<endl;
//     int n;
//     cin>>n;                    //输入列号
     setligne(tmp);
     setcolonne(n);
}//有没有办法连着输入行号列号比如G3 这样子 虽然好像我的程序里面直接这样输也是可读的

void Position::afficherposition() const{

    cout<<"La position:"<<"("<<l<<","<<c<<")"<<endl;   //显示坐标
}


void Position::setligne(char a){
       if(a>64)                                    //行号要是从A开始往后的字母
       {l=a;}
       else
       {
        cout<<"valeur invalide!"<<endl;
       }
}


void Position::setcolonne(int n){
    if(n>=1&&n<=10){
        c=n;                         //发现一个错误！ 我应该想要我输入的坐标在棋盘范围内。。。难道要加棋盘作为position的成员函数 然后用他的行数列数？
                                  //可是这样又要考虑初始值的问题 有没有别的方法？
    }
    else {cout<<"valeur invalide!"<<endl;}
}

int Position::getcolonne() const{
    return(c);
}

char Position::getligne() const{
    return(l);
}

bool Position::operator==(const Position &p) const {
    return(l==p.getligne()&&c==p.getcolonne());
}


 Position & Position::operator=(const Position &p){
     l=p.getligne();
     c=p.getcolonne();
     return(*this);

 }
