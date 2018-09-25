/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

#include <iostream>
// A besoin de la declaration de la classe
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

Piece::Piece()
{
  // ne fait rien => objet instancie mais non valide.
  cout << "Une Piece creee par defaut" << endl;
}

Pion::Pion( bool white, int x ) : Piece(x, white?2:7, white)
{
  cout << "Un Pion cree" << endl;
}

Roi::Roi( bool white) : Piece(5, white?1:8, white)
{
  cout << "Un Roi cree" << endl;
}

Reine::Reine( bool white) : Piece(4, (white)?1:8, white),
                            Tour( white, true ), Fou ( white, true )
{
  cout << "Une Reine creee" << endl;
}

Tour::Tour( bool white, bool pos ) : Piece(pos?8:1, white?1:8, white)
{
  cout << "Une Tour creee" << endl;
}

Cavalier::Cavalier( bool white, bool pos ) : Piece(pos?2:7, white?1:8, white)
{
  cout << "Un Cavalier cree" << endl;
}

Fou::Fou( bool white, bool pos ) : Piece(pos?6:3, white?1:8, white)
{
  cout << "Un Fou cree" << endl;
}

Piece::~Piece()
{
  cout << "Une Piece detruite" << endl;
}

Piece::Piece( const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "Une Piece copiee" << endl;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  cout << "Une Piece creee" << endl;
}

Piece &
Piece::operator=( const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "Une Piece affectee" << endl;
  return *this;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

bool Piece::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Piece" << endl;
  return true;
}

bool Roi::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Roi" << endl;
  return true;
}

bool Reine::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Reine" << endl;
  return ( Tour::mouvementValide(e, x, y) ||
           Fou::mouvementValide(e, x, y) );
}

bool Tour::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Tour" << endl;
  return true;
}

bool Cavalier::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Cavalier" << endl;
  return true;
}

bool Fou::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Fou" << endl;
  return true;
}

bool Pion::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Pion" << endl;
  return true;
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool
Piece::isBlack() const
{
  return !m_white;
}

void
Piece::affiche() const
{
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << endl;
}

char
Piece::getCode() const
{
  return m_white ? 'B' : 'N';
}

char
Roi::getCode() const
{
  return m_white ? 'R' : 'r';
}

char
Reine::getCode() const
{
  return m_white ? 'Q' : 'q';
}

char
Tour::getCode() const
{
  return m_white ? 'T' : 't';
}

char
Cavalier::getCode() const
{
  return m_white ? 'C' : 'c';
}

char
Fou::getCode() const
{
  return m_white ? 'F' : 'f';
}

char
Pion::getCode() const
{
  return m_white ? 'P' : 'p';
}