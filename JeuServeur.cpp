#include "JeuServeur.h"
#include <vector>
#include<iostream>
using namespace std;


JeuServeur::JeuServeur():J1(NULL),J2(NULL),inverse(0)
{
    //ctor
}

JeuServeur::~JeuServeur()
{
    //dtor
}

void JeuServeur::choisirmode()     //choisir le mode       toujours J1 commence
{
     cout<<"Choisir le mode (0---humain VS ordinateur 1---ordinateur VS ordinateur)"<<endl;  //选择人机还是电脑对电脑
    int tmp;
    do{
            cin>>tmp;
    if (tmp==0)
    {
         cout<<"Vous voulez commencer?(0-----non 1-----oui)"<<endl;     //人机模式下谁先开始
       int n;
       do{
           cin>>n;
           if(n==0)             //机器先开始时棋盘倒过来 人类玩家的子由x变成o
           {
             inverse=1;
             J2=new Humain();
             cout<<"Vous etes Joueur 2"<<endl;
             cout<<"-------------------------------"<<endl;   //ordinateur commence    表示电脑先开始
             cout<<"Choisi le niveau(0 ou 1)"<<endl;        //niveau 0:facile   niveau 1:difficile
             int tmp2;
             do{
                 cin>>tmp2;
                 if(tmp2==0){
                    J1=new Ordinateur();
                 }        //初级
                 else if(tmp2==1){
                     J1=new OrdinateurSup();
                 }       //高级
                 else {cout<<"valeur invalide!entrez encore"<<endl; }   //数字无效要重新输入
              }while(tmp2!=0&&tmp2!=1);
           }
           else if(n==1){
               inverse=0;
               J1=new Humain();
               cout<<"Vous etes Joueur 1"<<endl;
               cout<<"-------------------------------"<<endl;
               cout<<"Choisi le niveau(0 ou 1)"<<endl;        //niveau 0:facile   niveau 1:difficile
                 int tmp2;
                 do{
                     cin>>tmp2;
                     if(tmp2==0){
                         J2=new Ordinateur();
                      }        //初级
                     else if(tmp2==1){
                         J2=new OrdinateurSup();
                      }       //高级
                    else {cout<<"valeur invalide!entrez encore"<<endl; }   //数字无效要重新输入
                 }while(tmp2!=0&&tmp2!=1);
            }   //humain commence  表示人先开始
           else
              {cout<<"valeur invalide!encore une fois"<<endl;}     //数字无效 要重输
       }while (n!=0&&n!=1);                                                              //人机模式 选择初级或高级
    }
    else if(tmp==1)      //电脑对战模式。。。。一脸懵逼= =
    {
       cout<<"Pour Ordinateur 1,Elementaire(0) ou Superieur(1)"<<endl;
       int t;
       do {
           cin>>t;
           if(t==0){J1=new Ordinateur();}
           else if(t==1){J1=new OrdinateurSup();}
           else {cout<<"Invalide! Entrez encore!"<<endl;}
       }while(t!=0&&t!=1);
       cout<<"Pour Ordinateur 2,Elementaire(0) ou Superieur(1)"<<endl;
        do {
           cin>>t;
           if(t==0){J2=new Ordinateur();}
           else if(t==1){J2=new OrdinateurSup();}
           else {cout<<"Invalide! Entrez encore!"<<endl;}
       }while(t!=0&&t!=1);

    }
    else {cout<<"valeur invalide!entrez encore"<<endl;}     //选择模式的数字输入无效是 要重新输入
  }while (tmp!=0&&tmp!=1);

}

void JeuServeur::Initialplateau()   //definir le plateau ,size,et afficher le plateau initial
{
    cout<<"============Choisir  Le Plateau============="<<endl;
    cout<<"Entrez le nombre de ligne"<<endl;
    int ligne;
    do{
        cin>>ligne;
        if(ligne>=10&&ligne%2==0){
              tableau.resize(ligne);
        }
    }while(ligne<10||ligne%2!=0);
    cout<<"Entrez le nombre de colonne"<<endl;
    int colonne;
    do{
        cin>>colonne;
        if(colonne>0&&colonne%2==0){
            for(int i=0;i<ligne;i++){tableau[i].resize(colonne);}
        }
    }while(colonne<=0||colonne%2!=0);
    Piece p1,p2,p3;
    if(inverse==0){
       p1.setcolor(0);       //blanc
       p1.setisDame(0);
       p2.setcolor(1);      //noir
       p2.setisDame(0);
       p3.setcolor(-1);}//vide
    else if(inverse==1){
       p1.setcolor(1);       //blanc
       p1.setisDame(0);
       p2.setcolor(0);      //noir
       p2.setisDame(0);
       p3.setcolor(-1);}//vide
    for(int i=0;i<4;i++){
        for(int j=0;j<colonne;j++){
                if(i%2==0){
                        if(j%2==1)
                        {tableau[i][j]=p2;}
                        else tableau[i][j]=p3;
                }
                else
                     if(j%2==1)
                        {tableau[i][j]=p3;}
                    else tableau[i][j]=p2;        }
    }

    for(int i=4;i<ligne-4;i++){
        for(int j=0;j<colonne;j++){
            tableau[i][j]=p3;
            tableau[i][j]=p3;
         }
    }
    for(int i=ligne-4;i<ligne;i++){
         for(int j=0;j<colonne;j++){
                if(i%2==0){
                        if(j%2==1){
                            tableau[i][j]=p1;}
                        else tableau[i][j]=p3;
                }
                else
                     if(j%2==1){
                            tableau[i][j]=p3;}
                        else tableau[i][j]=p1;
        }
     }


    cout<<"--------------PLATEAU INITIAL---------------"<<endl;
    afficher();

}



void JeuServeur::afficher() const{       //afficher le plateau

   cout<<"   ";
   for(unsigned int j=1;j<=tableau[1].size();j++){
        cout<<"  "<<j<<"  ";}
    cout<<endl;
     for(unsigned int j=1;j<=tableau[1].size();j++){
        cout<<"-----";}
        cout<<"---"<<endl;
    for(unsigned int i=0;i<tableau.size();i++){
            char a;
            a=65+i;
            cout<<a;
            for(unsigned int j=0;j<tableau[1].size();j++){
//                char c;
                cout<<"  | "<<tableau[i][j];
            }
            cout<<endl;
            cout<<"---";
            for(unsigned int j=0;j<tableau[1].size();j++)
            {cout<<"-----";}
        cout<<endl;
    }

}


void JeuServeur::Jouer()
{
    cout<<"===================Le Jeu de Dames================"<<endl;
    cout<<"===================   Bienvenue!  ================"<<endl;
    cout<<"Avant le Jeu, vous devez choisir le mode !"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    choisirmode();
    cout<<"Maintenant, vous devez dimensionner le plateau"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    Initialplateau();
    cout<<"Apres tout les choix, DEBUT DE JEU ! Bonne Chance!"<<endl;
    do{
        tabtmp1=tableau;
        (*J1).tableau=tableau;
//        for(int i=0;i<(*J1).tableau.size();i++){
//            for(int j=0;j<(*J1).tableau[1].size();j++){cout<<(*J1).tableau[i][j];}
//        }
//        break;
        (*J1).move();
        tableau=J1->tableau;
        afficher();
        tabtmp2=tableau;
        J2->tableau=tableau;
        J2->move();
        tableau=J2->tableau;
        afficher();
    }while(terminer()==0);
    if(tabtmp1==tabtmp2)
    {
        cout<<"~~~~~~~LE JEU EST TERMINE ! Joueur 2 gagne!~~~~~~~"<<endl;
    }
    else if(tabtmp2==tableau)
    {
        cout<<"~~~~~~~LE JEU EST TERMINE ! Joueur 1 gagne!~~~~~~~"<<endl;
    }
    else {cout<<"==========Match Nul========";}



}


int JeuServeur::terminer(){
     int ter=0;
     if(tabtmp1==tabtmp2||tabtmp2==tableau){
         ter=1;
     }
     else {
         int n1=0,n2=0;
         for(unsigned int i=0;i<tableau.size();i++){
             for(unsigned int j=0;j<tableau[1].size();j++)
             {
                 if(tableau[i][j].getcolor()==0){n1++;}
                 if(tableau[i][j].getcolor()==1){n2++;}
             }

         }
         if(n1==1&&n2==1){
             ter=1;
         }
     }
  return(ter);
}
