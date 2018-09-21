/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare(Piece a, Piece b)
{
  return (a.x()==b.x()) && (a.y()==b.y()) && (a.isWhite()==b.isWhite());
}

/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  // instancie un objet p1 de type Piece
  Piece p1;
  // p1 est une piece blanche de coordonnees (3,3)
  p1.init( 3, 3, true );
  p1.move( 2, 2);

  Piece p2( 4, 4, false);

  if (p2.isBlack())
    cout << "Une Piece noire" << endl;

  // On l'affiche
  p1.affiche();
  p2.affiche();

/*
  Joueur jb(true);
  Joueur jn(false);

  jb.affiche();
  jn.affiche();
*/

  if (compare( p1, p2 ))
    cout << "memes pieces" << endl;
  else
    cout << "pieces differentes" << endl;


  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1
}
