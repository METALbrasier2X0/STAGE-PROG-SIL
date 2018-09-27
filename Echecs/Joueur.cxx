#include <iostream>
#include "Joueur.h"

using namespace std;

Joueur::Joueur()
{
    cout << "Une Joueur construit par defaut" << endl;
}

Joueur::~Joueur()
{
    for (int i=0; i<16; i++)
        delete m_pieces[i];
    cout << "Une Joueur détruit" << endl;
}

Joueur::Joueur(bool white)
{
    cout << "Une Joueur construit" << endl;
}

JoueurBlanc::JoueurBlanc()
{
  m_pieces.push_back( new Roi(true) );
  m_pieces.push_back( new Reine(true) );
  m_pieces.push_back( new Tour(true,true) );
  m_pieces.push_back( new Tour(true,false) );
  m_pieces.push_back( new Cavalier(true,true) );
  m_pieces.push_back( new Cavalier(true,false) );
  m_pieces.push_back( new Fou(true,true) );
  m_pieces.push_back( new Fou(true,false) );

  for (int x=1; x<=8; ++x)
    m_pieces.push_back( new Pion(true,x) );

  cout << "Une JoueurBlanc construit" << endl;
}

JoueurNoir::JoueurNoir()
{
  m_pieces.push_back( new Roi(false) );
  m_pieces.push_back( new Reine(false) );
  m_pieces.push_back( new Tour(false,true) );
  m_pieces.push_back( new Tour(false,false) );
  m_pieces.push_back( new Cavalier(false,true) );
  m_pieces.push_back( new Cavalier(false,false) );
  m_pieces.push_back( new Fou(false,true) );
  m_pieces.push_back( new Fou(false,false) );

  for (int x=1; x<=8; ++x)
    m_pieces.push_back( new Pion(false,x) );

  cout << "Une JoueurNoir construit" << endl;
}

void
Joueur::placerPieces(Echiquier & e)
{
    /*
    for (int i=0; i<16; i++)
        e.placer( m_pieces[i] );
    */
   vector<Piece*>::iterator p = m_pieces.begin();
   while (p != m_pieces.end() )
    {
        e.placer( *p );
        p++;
    }
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
        m_pieces[i]->affiche();
}