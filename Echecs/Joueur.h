#if !defined JOUEUR_H
#define JOUEUR_H

#include "Piece.h"

class Joueur
{
private:
    Piece m_pieces[16];
public:
    Joueur();
    Joueur(bool white);
    bool isWhite();
    void affiche();
};

#endif