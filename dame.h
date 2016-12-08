#ifndef DAME_H
#define DAME_H

#include <Piece.h>


class Dame : public Piece    //王。。。还没开始想
{
    public:
        Dame();
        virtual ~Dame();
//        void movedame();
//        void moveordinateur();
        void setisDame(bool res);

    protected:

    private:

};

#endif // DAME_H
