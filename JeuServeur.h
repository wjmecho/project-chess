#ifndef JEUSERVEUR_H
#define JEUSERVEUR_H
#include "Joueur.h"
#include<vector>
#include "Piece.h"
#include<iostream>
#include "Humain.h"
#include "Ordinateur.h"
#include  "OrdinateurSup.h"
using namespace std;


class JeuServeur
{
    public:
        JeuServeur();
        virtual ~JeuServeur();
        void choisirmode();
        void Initialplateau();
        void afficher() const;
        void Jouer();
        int terminer();
    protected:
    private:
         Joueur *J1,*J2;
         vector<vector<Piece> >   tableau,tabtmp1,tabtmp2;     //tableau is the plateau,tabtmp1 tabtmp2 for judge the game
         int stack;
         bool inverse;

};

#endif // JEUSERVEUR_H
