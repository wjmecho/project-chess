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
     bool res=0;      //�����ж��Ƿ�Ҫ��������depart ��arrivee����  ������һ����Χ��ʱres=0 Ҫ��������
//             movepiece();      //����Ҫ�ߵ����Ӻ�Ҫ����ĵط�
             do{
                tab=tableau;      //�ݴ����̱��
                position=podepart;        //����λ�ñ�ΪҪ�ƶ�������


             if(position.getligne()-poarrivee.getligne()==1&&abs(position.getcolonne()-poarrivee.getcolonne())==1)      //û�г��� ǰ��һ��
               {
                position=poarrivee;
                settab(podepart,p3);
                settab(position,p1);
//                                plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]=' ';
//                plateau.tableau[position.getligne()-65][position.getcolonne()-1]=plateau.p1;
                res=1;

               }
            else if(abs(position.getligne()-poarrivee.getligne())==2&&abs(position.getcolonne()-poarrivee.getcolonne())==2){     //�г���


                if((tableau[(position.getligne()+poarrivee.getligne())/2-65][(position.getcolonne()+poarrivee.getcolonne())/2-1]).getcolor()==1)
                //�뿪�����Ӻ͵���������м��ǶԷ�����ʱ  �Ե������ �����ߵ�����ĵ���ĵط�
                    {
                        int l=(position.getligne()+poarrivee.getligne())/2-65;
                        int c=(position.getcolonne()+poarrivee.getcolonne())/2-1;
                        tableau[l][c]=p3;
                        position=poarrivee;
                        settab(podepart,p3);
                        settab(position,p1);
//                        plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]=' ';
//                        plateau.tableau[position.getligne()-65][position.getcolonne()-1]=plateau.p1;


                        bool tmp;//Ϊ�����ಽ    һ��������Ϊ0 ��Ϊ��һ���ж��Ƿ���������

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
                                                                 tmp=1;   //����
                                             }
                         }//������ӵ�ǰ�������½��ǶԷ����Ӷ��������½��ǿյ� �������һ��   ���������̷�Χ��
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
                         }//�������Ͻ��Ƿ���Լ�����
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
                         }//�������Ͻ�
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
                          }//�������½�
//
//
//
                        } while(tmp==1);
                 position.afficherposition();  //��ʾ�������ӵ�λ��
                          res=1;
                    }


                else    //Ҫ�ߵ��Ӻ�Ҫ����ĵط��м�û�жԷ�����ʱû�취�� ��Ч �ٴ�����
                {
                    cout<<"Invallide!vous voulez saisir encore?(0--non 1---oui)"<<endl;
                    int s;
                    cin>>s;
                    if(s==1){move();}

                }
            }
            else {      //������뵽���λ�ó�������һ���ķ�Χ ��Ҫ��������
                    cout<<"invalide!encore une fois"<<endl;
                    move();
            }
        }while (res==0);
        if (position.getligne()=='A'){    // ���������󵽴�ĵط��Ƕ���ĵ���  ������
               settab(position,p2);
            }
            //ÿ��һ����Ҫ��ʾ����
}// �����ڵ����� �Ǻ�����������ĵط��е�����  Ȼ�����������ʱ�� �е�ʱ���Һ���û�취������ ���������б���滹��һ���ӱ������Լ������Ļ���������= =





