#include "Ordinateur.h"
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>


Ordinateur::Ordinateur()
{
    p1.setcolor(1);     //表示黑色兵
    p2.setcolor(1);     //表示黑色王
    p3.setcolor(-1);    //表示空
    //ctor
}

Ordinateur::~Ordinateur()
{
    //dtor
}


void Ordinateur::move(){
//    int dir[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};
    int tl=tableau.size();        //棋盘的行数
    int tc=tableau[1].size();      //棋盘的列数
    int n=0;                         //记录黑色棋子的个数
    for(int i=0;i<tl;i++){          //find all the positions of noir pieces
        for(int j=0;j<tc;j++){
            if((tableau[i][j]).getcolor()==1){
                Position tmp;
                char a;
                a=i+65;
                tmp.setligne(a);
                tmp.setcolonne(j+1);
                memtab.push_back(tmp);        //存放的是position  所有黑棋子的位置
                n++;
            }
        }
    }
    Position position;             //为了书写方便。。。
    int maxmove=0;                // the longest steps
    int maxchemin[100][2]={0};    //le longest route
    int essaychemin[100][2]={0};      //temporary record of the route
//    bool manger[100][100]={0};

    for(int i=0;i<n;i++){        //find the longest road
        position=memtab[i];
        int l=position.getligne()-65;      // THE SAME index with the tableau
        int c=position.getcolonne()-1;
        essaychemin[0][0]=l;
        essaychemin[0][1]=c;

        int tmpmove=DFS(l,c,1,essaychemin);
        if(maxmove<tmpmove){
            maxmove=tmpmove;
            for(int i=0;i<tmpmove;i++)
            {
                maxchemin[i][0]=essaychemin[i][0];
                maxchemin[i][1]=essaychemin[i][1];
            }
        }
    }
    if(maxmove==1)                    //no piece to skip
    {
        int r;
        bool res=0;        //判断是否终止循环不用再随机确定一个棋子的参数
        do                                    //randomly get a position of a piece and if it can walk then walk one step forward
        {
            srand(time(NULL));
            r=rand()%n;
            position=memtab[r];
            int l=position.getligne()-65;
            int c=position.getcolonne()-1;
            if((retab(position)).getisDame()==0){    //retab是一个可以由一个坐标返还棋盘对应的棋子的函数
               if(l+1<tl)    //往前走不超出棋盘
               {
                    if(c+1<tc&&(tableau[l+1][c+1]).getcolor()==-1){   //不超出棋盘且要到达的地方是空的
                         settab(position,p3);     //一个把棋盘对应坐标的地方变成棋子p3的函数
                         position.setligne(l+1+65);
                         position.setcolonne(c+1+1);
                         if(position.getligne()==tl+64){settab(position,p2);}      //到达的地方是棋盘底部 变成王
                         else{settab(position,p1);}     //否则到达的地方是兵
                         res=1;



                     }
                    if(c-1>=0&&tableau[l+1][c-1]==p3){
                        settab(position,p3);
                        position.setligne(l+1+65);
                        position.setcolonne(c-1+1);
                        if(position.getligne()==tl+64){settab(position,p2);}
                        else{settab(position,p1);}
                        res=1;
                    }
               }
            }
            else{//   王的走法。。。

            }
        }while(res==0);

    }
    else{                          //execute le longest route and display the route
        cout<<"Total etape:"<<maxmove<<endl;
        cout<<"=============chemin============="<<endl;
        Piece tmppi=tableau[maxchemin[0][0]][maxchemin[0][1]];
        for(int i=0;i<maxmove-1;i++){
            int ml=maxchemin[i][0];         //ml cl index the same with tableau
            char mlchar;
            mlchar=ml+65;
            int mc=maxchemin[i][1]+1;
            cout<<'('<<mlchar<<','<<mc<<')'<<"->";  //maxchemin保存的行列坐标是比tableau保存的要大一的
            int d1=(maxchemin[i+1][0]-ml)/2;
            int d2=(maxchemin[i+1][1]-mc)/2;
            tableau[ml][mc]=p3;
            tableau[ml+d1][mc+d2]=p3;
            tableau[ml+2*d1][mc+2*d2]=tmppi;
        }
        char mlchar;
        mlchar=maxchemin[maxmove-1][0]+65;
        cout<<'('<<mlchar<<','<<maxchemin[maxmove-1][1]+1<<')'<<endl;
        if(maxchemin[maxmove-1][0]==tl-1){
            tableau[maxchemin[maxmove-1][0]][maxchemin[maxmove-1][1]]=p2;
        }
    }
}


int Ordinateur::DFS(const int l,const int c, const int initmove,int (&essaychemin)[100][2])     //deep first search    l c the same index with tableau

{
    int maxsize=initmove;         //max moves
    int tl=tableau.size();      //Nnombre de ligne de plateau
    int tc=tableau[1].size();    //nombre de colonne de plateau
//    bool manger[100][100]={0};
//    essaychemin[0][0]=l;            //initial ligne
//    essaychemin[0][1]=c;            //initial colonne
    int dir[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};   //quatre directions
    for(int d=0;d<4;d++)
    {
        int tmpl=l+2*dir[d][0];
        int tmpc=c+2*dir[d][1];
        int mangerl=l+dir[d][0];
        int mangerc=c+dir[d][1];
        if(tmpl>=0&&tmpl<tl&&tmpc>=0&&tmpc<tc){    //la position est dans le plateau
            if((tableau[mangerl][mangerc]).getcolor()==0&&(tableau[tmpl][tmpc]).getcolor()==-1)
            {
                int tmpchemin[100][2]={0};     //temporary route
                int tmpmove=initmove;             //temprary step
                tmpchemin[tmpmove][0]=tmpl;
                tmpchemin[tmpmove][1]=tmpc;
                tmpmove++;
                int dfsmove=DFS(tmpl,tmpc,tmpmove,tmpchemin);
                if(maxsize<dfsmove){
                    maxsize=dfsmove;
                    for(int i=initmove;i<dfsmove;i++)
                    {
                        essaychemin[i][0]=tmpchemin[i][0];
                        essaychemin[i][1]=tmpchemin[i][1];
                    }
                }
            }
        }
    }
    return maxsize;
}

