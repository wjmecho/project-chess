#include "Pion.h"
#include "../Plateau.h"
#include <cstdlib>
//#include <utility>
#include<iostream>
using namespace std;
#include<vector>
#include <Piece.h>


Pion::Pion()
{
    isDame=0;
 //ctor
}

Pion::~Pion()
{
    //dtor
}




//new version
void Pion::setisDame(bool res){
    cout<<"On ne peut pas changer !"<<endl;
}
