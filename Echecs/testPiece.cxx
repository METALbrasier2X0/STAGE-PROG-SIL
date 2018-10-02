/**
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"

// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;

bool compare (Piece p, Piece q)
{
  return (p.x() == q.x()) && (p.y() == q.y());
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

  Piece p2( 4, 4, false );
  if (p2.isBlack())
    cout << "Une Piece noire" << endl;

  // On l'affiche
  p1.affiche();
  p2.affiche();

  if (compare(p1,p2))
    cout << "meme position" << endl;
  else
    cout << "position differente" << endl;

  p1 = p2;

  Echiquier e;
  Joueur jb(true);
  Joueur jn(false);
  jb.affiche();
  jn.affiche();
  jb.placerPieces(e);
  jn.placerPieces(e);
  e.affiche();

  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1
}
