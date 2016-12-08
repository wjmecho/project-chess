#ifndef PION_H
#define PION_H

#include <Piece.h>


class Pion : public Piece        //棋子的派生类  兵
{
    public:
        Pion();
        virtual ~Pion();
        void setisDame(bool res);

//        void movepion();         //针对人走棋是移动兵      兵和王走法不一样
//        void moveordinateur();   //电脑移动兵      我目前只是随便写了写  还有一些问题 而且 要求分高级和初级 初级要求随机性 = =||好难。。。。
    protected:
    private:

};

#endif // PION_H
