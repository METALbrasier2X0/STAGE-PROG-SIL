#include "Joueur.h"

Joueur::Joueur()
{
}

Joueur::Joueur( bool white)
{
    int p=0;
    int y=(white)?1:8;
    for (int x=1; x<=8; ++x)
    {
        m_pieces[p].init( x, y, white );
        p=p+1; // p+=1 // p++
    }
    y=(white)?2:7;
    for (int x=1; x<=8; ++x)
        m_pieces[p++].init( x, y, white );
}

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
}

JoueurNoir::JoueurNoir()
{
    int p=0;
    for (int x=1; x<=8; ++x)
    {
        m_pieces[p].init( x, 8, false );
        p=p+1; // p+=1 // p++
    }
    for (int x=1; x<=8; ++x)
        m_pieces[p++].init( x, 7, false );
}

void
Joueur::placerPieces( Echiquier & e )
{
    for (int i = 0; i < 16; i++)
        e.placer( m_pieces+i /*&(m_pieces[i])*/ );
}

void
Joueur::affiche()
{
    for (int i=0; i<16; i++)
        m_pieces[i].affiche();
}