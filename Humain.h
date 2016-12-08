#ifndef HUMAIN_H
#define HUMAIN_H

#include <Joueur.h>
#include "Pion.h"
#include "dame.h"


class Humain : public Joueur    //»À¿‡ÕÊº“
{
    public:
        Humain();
        virtual ~Humain();
        void move();
        void movepion(Position podepart,Position poarrivee);
        void movedame(Position podepart,Position poarrivee);

    protected:

    private:




};

#endif // HUMAIN_H
