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

Roi::Roi( bool white) : Piece(5, white?1:8, white)
{
  cout << "Un Roi cree" << endl;
}

Reine::Reine( bool white)
{
  m_x=4;
  m_y=white?1:8;
  m_white=white;
  cout << "Une Reine creee" << endl;
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