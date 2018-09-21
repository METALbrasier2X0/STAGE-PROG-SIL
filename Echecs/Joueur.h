#if !defined JOUEUR_H
#define JOUEUR_H

#include "Piece.h"
#include "Echiquier.h"

class Joueur
{
protected:
    Piece m_pieces[16];
public:
    Joueur();
    Joueur(bool white);
    void placerPieces(Echiquier & e);
    bool isWhite();
    void affiche();
};

class JoueurBlanc : public Joueur
{
public:
    JoueurBlanc();
};

class JoueurNoir : public Joueur
{
public:
    JoueurNoir();
};

#endif