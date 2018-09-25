#include <iostream>
#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
    cout << "Une Joueur construit par defaut" << endl;
}

Joueur::Joueur(bool white)
{
    int p=0;
    int y=(white?1:8);
    for (int x=1; x<=8; ++x)
        m_pieces[p++].init( x, y, white );

    y=(white?2:7);
    for (int x=1; x<=8; ++x)
    {
       m_pieces[p].init( x, y, white );
       p++;
    }

    cout << "Une Joueur construit" << endl;
}

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
    cout << "Une JoueurBlanc construit" << endl;
}

JoueurNoir::JoueurNoir()
{
    int p=0;
    for (int x=1; x<=8; ++x)
        m_pieces[p++].init( x, 8, false );
    for (int x=1; x<=8; ++x)
    {
       m_pieces[p].init( x, 7, false );
       p++;
    }
    cout << "Une JoueurNoir construit" << endl;
}

void
Joueur::placerPieces(Echiquier & e)
{
    for (int i=0; i<16; i++)
        e.placer( &(m_pieces[i]) /* m_piece+i */);
}

/*
bool
Joueur::isWhite()
{
    return m_pieces[0].isWhite();
}
*/

bool
JoueurBlanc::isWhite()
{
  return true;
}

bool
JoueurNoir::isWhite()
{
  return false;
}

void
Joueur::affiche()
{
    for (int i=0; i<16; i++)
        m_pieces[i].affiche();
}