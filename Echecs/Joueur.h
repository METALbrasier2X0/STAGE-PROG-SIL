#if !defined JOUEUR_H
#define JOUEUR_H

#include <vector>
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

class Joueur
{
protected:
    //Piece *m_pieces[16];
    vector<Piece*> m_pieces;
public:
    Joueur();
    virtual ~Joueur();
    Joueur(bool white);
    void placerPieces(Echiquier & e);
    virtual bool isWhite()=0;
    void affiche();
};

class JoueurBlanc : public Joueur
{
public:
    JoueurBlanc();
    bool isWhite();
};

class JoueurNoir : public Joueur
{
public:
    JoueurNoir();
    bool isWhite();
};

#endif