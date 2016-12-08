#include "Dame.h"
#include <cstdlib>

Dame::Dame()
{
   isDame=1;
    //ctor
}

Dame::~Dame()
{
    //dtor
}


//void Dame::movedame(){
//    bool res=0;
//    movepiece();
//    do{
//        tab=plateau.tableau;
//        position=podepart;
//        if(plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]!=plateau.P1){
//            cout<<"Invalide!Entrez encore!"<<endl;
//            movepiece();
//        }
//        else{
//         if(abs(podepart.getligne()-poarrivee.getligne())!=abs(podepart.getcolonne()-poarrivee.getcolonne()))
//         {
//            cout<<"Invalide.Entrez encore!"<<endl;
//            movepiece();
//         }
//         else {
//                int n=0;
//                int i;
//                int s1,s2;
//                s1=abs(podepart.getligne()-poarrivee.getligne())/poarrivee.getligne()-podepart.getligne();
//                s2=abs(podepart.getcolonne()-poarrivee.getcolonne())/poarrivee.getcolonne()-podepart.getcolonne();
//            for(i=0;i<abs(podepart.getligne()-poarrivee.getligne());i++){
//
//                if(plateau.tableau[podepart.getligne()+s1*i-64][podepart.getcolonne()+s2*i]==plateau.p1||
//                   plateau.tableau[podepart.getligne()+s1*i-64][podepart.getcolonne()+s2*i]==plateau.P1){
//                     cout<<"Invalide ! Entrez encore!"<<endl;
//                     movepiece();
//                     break;
//                }
//                else if(plateau.tableau[podepart.getligne()+s1*i-64][podepart.getcolonne()+s2*i]==plateau.p2||
//                        plateau.tableau[podepart.getligne()+s1*i-64][podepart.getcolonne()+s2*i]==plateau.P2)
//                {
//                    n++;
//                }
//            }
//            if((n==1||n==0)&&i==abs(podepart.getligne()-poarrivee.getligne()))
//               {
//                   plateau.tableau[podepart.getligne()-65][podepart.getcolonne()-1]=' ';
//                   for(int i=0;i<abs(podepart.getligne()-poarrivee.getligne());i++){
//                       plateau.tableau[podepart.getligne()+s1*i][podepart.getcolonne()+s2*i]=' ';
//                   }
//                   position=poarrivee;
//                   plateau.tableau[position.getligne()-65][position.getcolonne()-1]=plateau.P1;
//                   res=1;
////                   do{
////                    for(i=0;i<plateau.getligne()-position.getligne()&&i<plateau.getcolonne()-position.getcolonne();i++)
////                    {
////                        if(plateau.tableau[position.getligne()-64+i][position.getcolonne()+i]==plateau.p1||
////                           plateau.tableau[position.getligne()-64+i][position.getcolonne()+i]==plateau.P1){
////                               break;
////                           }
////                        else if(plateau.tableau[position.getligne()-64+i][position.getcolonne()+i]==plateau.p2||
////                           plateau.tableau[position.getligne()-64+i][position.getcolonne()+i]==plateau.P2){
////                            break;
////                           }
////                    }
////                    if(plateau.tableau[position.getligne()-64+i][position.getcolonne()+i]==plateau.p2||
////                           plateau.tableau[position.getligne()-64+i][position.getcolonne()+i]==plateau.P2)
////
////                   }
//               }
//        }
//      }
//
//    }while(res==0);
//}
//
//
//
//void Dame::moveordinateur(){
//
//}
//



void Dame::setisDame(bool res){
    cout<<"On ne peut pas changer!"<<endl;
}
