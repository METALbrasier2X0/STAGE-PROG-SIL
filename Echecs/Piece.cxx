/**
 * Mise en oeuvre de Piece.h
 *
 * @file Piece.cxx
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "Piece.h"

using namespace std;

Piece::Piece()
{
  cout << "Une Piece construite par defaut" << endl;
  // ne fait rien => objet instancie mais non valide.
}

Piece::~Piece()
{
  cout << "Une Piece detruite" << endl;
}

Piece::Piece( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
  cout << "Une Piece construite specialisee" << endl;
}

Piece::Piece( const Piece & autre)
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "Une Piece construite par copie" << endl;
}

Roi::Roi( bool white ) : Piece(5, white?1:8, white)
{
  cout << "Un Roi" << endl;
}

/* =delete
Piece &
Piece::operator=( const Piece & autre )
{
  m_x = autre.m_x;
  m_y = autre.m_y;
  m_white = autre.m_white;
  cout << "Une Piece affectee" << endl;
  return *this;
}
*/

bool Piece::mouvementValide(Echiquier &e, int x, int y) const
{
  cout << "mouvementValide de Piece" << endl;
  return false;
}

bool Roi::mouvementValide(Echiquier &e, int x, int y) const
{
  cout << "mouvementValide de Roi" << endl;
  return false;
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
