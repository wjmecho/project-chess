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
//     cin>>tmp;                //�����к�
//     setligne(tmp);
//     cout<<"le colonne:"<<endl;
//     int n;
//     cin>>n;                    //�����к�
     setligne(tmp);
     setcolonne(n);
}//��û�а취���������к��кű���G3 ������ ��Ȼ�����ҵĳ�������ֱ��������Ҳ�ǿɶ���

void Position::afficherposition() const{

    cout<<"La position:"<<"("<<l<<","<<c<<")"<<endl;   //��ʾ����
}


void Position::setligne(char a){
       if(a>64)                                    //�к�Ҫ�Ǵ�A��ʼ�������ĸ
       {l=a;}
       else
       {
        cout<<"valeur invalide!"<<endl;
       }
}


void Position::setcolonne(int n){
    if(n>=1&&n<=10){
        c=n;                         //����һ������ ��Ӧ����Ҫ����������������̷�Χ�ڡ������ѵ�Ҫ��������Ϊposition�ĳ�Ա���� Ȼ������������������
                                  //����������Ҫ���ǳ�ʼֵ������ ��û�б�ķ�����
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
