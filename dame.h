#ifndef DAME_H
#define DAME_H

#include <Piece.h>


class Dame : public Piece    //����������û��ʼ��
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
