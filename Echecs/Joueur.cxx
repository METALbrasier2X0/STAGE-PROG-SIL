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
  int p=0;
  m_pieces[p++] = new Roi(true);
  m_pieces[p++] = new Reine(true);
  m_pieces[p++] = new Tour(true,true);
  m_pieces[p++] = new Tour(true,false);
  m_pieces[p++] = new Cavalier(true,true);
  m_pieces[p++] = new Cavalier(true,false);
  m_pieces[p++] = new Fou(true,true);
  m_pieces[p++] = new Fou(true,false);

  for (int x=1; x<=8; ++x)
    m_pieces[p++] = new Pion(true,x);

  cout << "Une JoueurBlanc construit" << endl;
}

JoueurNoir::JoueurNoir()
{
  int p=0;
  m_pieces[p++] = new Roi(false);
  m_pieces[p++] = new Reine(false);
  m_pieces[p++] = new Tour(false,true);
  m_pieces[p++] = new Tour(false,false);
  m_pieces[p++] = new Cavalier(false,true);
  m_pieces[p++] = new Cavalier(false,false);
  m_pieces[p++] = new Fou(false,true);
  m_pieces[p++] = new Fou(false,false);

  for (int x=1; x<=8; ++x)
    m_pieces[p++] = new Pion(false,x);

  cout << "Une JoueurNoir construit" << endl;
}

void
Joueur::placerPieces(Echiquier & e)
{
    for (int i=0; i<16; i++)
        e.placer( m_pieces[i] );
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