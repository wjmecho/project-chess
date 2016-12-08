#include "Humain.h"
#include<vector>
#include <cstdlib>
Humain::Humain()
{
    p1.setcolor(0);     //blanc pion
    p2.setcolor(0);       //blanc dame
    p3.setcolor(-1);      //vide
    //ctor
}

Humain::~Humain()
{
    //dtor
}

void Humain::move(){
//    int n=0;
//    for(unsigned int i=0;i<tableau.size();i++)
//    {
//        for(unsigned int j=0;j<tableau[1].size();j++){
//            if((tableau[i][j]).getcolor()==0){
//                char tmp;
//                tmp=i+65;
//                (memtab[n]).setligne(tmp);
//                (memtab[n]).setcolonne(j);
//                n++;
//            }
//        }
//    }
    cout<<"Entrez le piece pour depart"<<endl;
    Position pd;
    int i=0;
    do{
        pd.saisirposition();

//        for(i=0;i<n;i++){
            if((retab(pd)).getcolor()==0)
            {
                break;
            }
//        }
    }while((retab(pd)).getcolor()!=0);
    cout<<"Entrez le position pour arrivee"<<endl;
    Position pa;
    do{
        pa.saisirposition();
    }while((tableau[pa.getligne()-65][pa.getcolonne()-1]).getcolor()!=-1);
    if(retab(pd)==p1){movepion(pd,pa);}
//    else {movedame(pd,pa);}


}


void Humain::movepion(Position podepart,Position poarrivee){
     Position position;
//     int dir[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};
     bool res=0;      //用于判断是否要重新输入depart 和arrivee坐标  当不在一步范围内时res=0 要重新输入
//             movepiece();      //输入要走的棋子和要到达的地方
             do{
                tab=tableau;      //暂存棋盘表格
                position=podepart;        //棋子位置变为要移动的坐标


             if(position.getligne()-poarrivee.getligne()==1&&abs(position.getcolonne()-poarrivee.getcolonne())==1)      //没有吃子 前进一步
               {
                position=poarrivee;
                settab(podepart,p3);
                settab(position,p1);
//                                plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]=' ';
//                plateau.tableau[position.getligne()-65][position.getcolonne()-1]=plateau.p1;
                res=1;

               }
            else if(abs(position.getligne()-poarrivee.getligne())==2&&abs(position.getcolonne()-poarrivee.getcolonne())==2){     //有吃子


                if((tableau[(position.getligne()+poarrivee.getligne())/2-65][(position.getcolonne()+poarrivee.getcolonne())/2-1]).getcolor()==1)
                //离开的棋子和到达的坐标中间是对方的子时  吃掉这颗子 并且走到输入的到达的地方
                    {
                        int l=(position.getligne()+poarrivee.getligne())/2-65;
                        int c=(position.getcolonne()+poarrivee.getcolonne())/2-1;
                        tableau[l][c]=p3;
                        position=poarrivee;
                        settab(podepart,p3);
                        settab(position,p1);
//                        plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]=' ';
//                        plateau.tableau[position.getligne()-65][position.getcolonne()-1]=plateau.p1;


                        bool tmp;//为了跳多步    一旦跳了则为0 作为下一步判断是否跳的条件

                        do{
                            tmp=0;
                            int l=position.getligne();
                            int c=position.getcolonne();
                            if(l-65+1<tableau.size()&&c<tableau[1].size()&&
                            (tableau[l-65+1][c]).getcolor()==1){
                                            if(l-65+2<tableau.size()&&c+1<tableau[1].size()&&
                                               tableau[l-65+2][c+1]==p3){
                                                                 settab(position,p3);
                                                                 tableau[l-65+1][c]=p3;
                                                                 position.setligne(l+2);
                                                                 position.setcolonne(c+2);
                                                                 settab(position,p1);
                                                                 tmp=1;   //跳了
                                             }
                         }//如果棋子当前坐标右下角是对方的子而且再右下角是空的 则继续跳一步   控制在棋盘范围内
                         if(l-65-1>=0&&c<tableau[1].size()&&
                          (tableau[l-65-1][c]).getcolor()==1){
                                          if(l-65-2>=0&&c+1<tableau[1].size()&&
                                             tableau[l-65-2][c+1]==p3){
                                                                 settab(position,p3);
                                                                 tableau[l-65-1][c]=p3;
                                                                 position.setligne(l-2);
                                                                 position.setcolonne(c+2);
                                                                 settab(position,p1);
                                                                 tmp=1;
                                           }
                         }//考虑右上角是否可以继续跳
                         if(l-65-1>=0&&c-2>=0&&
                                 (tableau[l-65-1][c-2]).getcolor()==1){
                                                 if(l-65-2>=0&&c-3>=0&&
                                                    tableau[l-65-2][c-3]==p3){
                                                                settab(position,p3);
                                                                tableau[l-65-1][c-2]=p3;
                                                                 position.setligne(l-2);
                                                                 position.setcolonne(c-2);
                                                                 settab(position,p1);
                                                                 tmp=1;
                                                 }
                         }//考虑左上角
                         if(l-65+1<tableau.size()&&c-2>=0&&
                                 (tableau[l-65+1][c-2]).getcolor()==1) {
                                                 if(l-65+2<tableau.size()&&c-3>=0&&
                                                    tableau[l-65+2][c-3]==p3){
                                                                settab(position,p3);
                                                                tableau[l-65+1][c-2]=p3;
                                                                 position.setligne(l+2);
                                                                 position.setcolonne(c-2);
                                                                 settab(position,p1);

                                                                 tmp=1;
                                                 }
                          }//考虑左下角
//
//
//
                        } while(tmp==1);
                 position.afficherposition();  //显示最终棋子的位置
                          res=1;
                    }


                else    //要走的子和要到达的地方中间没有对方的子时没办法走 无效 再次输入
                {
                    cout<<"Invallide!vous voulez saisir encore?(0--non 1---oui)"<<endl;
                    int s;
                    cin>>s;
                    if(s==1){move();}

                }
            }
            else {      //如果输入到达的位置超过了走一步的范围 则要重新输入
                    cout<<"invalide!encore une fois"<<endl;
                    move();
            }
        }while (res==0);
        if (position.getligne()=='A'){    // 如果棋子最后到达的地方是对面的底盘  则变成王
               settab(position,p2);
            }
            //每下一次棋要显示棋盘
}// 我现在的问题 是好像重新输入的地方有点问题  然后就是连跳的时候 有的时候我好像没办法往回跳 就是如果我斜后面还有一个子本来可以继续跳的话它不跳了= =





