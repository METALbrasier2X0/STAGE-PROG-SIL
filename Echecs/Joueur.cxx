#include "Joueur.h"

Joueur::Joueur()
{
}

/*
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
*/

Joueur::~Joueur()
{
    vector<Piece *>::iterator p = m_pieces.begin();
    while ( p != m_pieces.end() )
    {
        delete *p;
        p++;
    }
}

JoueurBlanc::JoueurBlanc()
{
    m_pieces.push_back( new Roi(true) );
    m_pieces.push_back( new Reine(true) );
    m_pieces.push_back( new Fou(true, true) );
    m_pieces.push_back( new Fou(true, false) );
    m_pieces.push_back( new Cavalier(true, true) );
    m_pieces.push_back( new Cavalier(true, false) );
    m_pieces.push_back( new Tour(true, true) );
    m_pieces.push_back( new Tour(true, false) );
    for (int x = 1; x <= 8; x++)
        m_pieces.push_back( new Pion(true, x));
}

JoueurNoir::JoueurNoir()
{
    m_pieces.push_back( new Roi(false) );
    m_pieces.push_back( new Reine(false) );
    m_pieces.push_back( new Fou(false, true) );
    m_pieces.push_back( new Fou(false, false) );
    m_pieces.push_back( new Cavalier(false, true) );
    m_pieces.push_back( new Cavalier(false, false) );
    m_pieces.push_back( new Tour(false, true) );
    m_pieces.push_back( new Tour(false, false) );
    for (int x = 1; x <= 8; x++)
        m_pieces.push_back( new Pion(false, x));
}

void
Joueur::placerPieces( Echiquier & e )
{
    for (int i = 0; i < 16; i++)
        e.placer( m_pieces[i] );
}

void
Joueur::affiche()
{
    for (int i=0; i<16; i++)
        m_pieces[i]->affiche();
}

bool
JoueurBlanc::isWhite() const
{
    return true;
}

bool
JoueurNoir::isWhite() const
{
    return false;
}