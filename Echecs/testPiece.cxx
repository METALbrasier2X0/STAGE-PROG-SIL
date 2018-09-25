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

bool compare(Piece *a, Piece *b)
{
  return (a->x()==b->x()) && (a->y()==b->y()) && (a->isWhite()==b->isWhite());
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

  Piece p3( p2 ); // constructeur par copie : Piece p3 = p2;
  p3 = p2 = p1; // affectations : p3.operator=(p2.operator=(p1));

  // On l'affiche
  p1.affiche();
  p2.affiche();
  p3.affiche();

  if (compare( &p1, &p2 ))
    cout << "memes pieces" << endl;
  else
    cout << "pieces differentes" << endl;

/*
  Joueur jb(true);
  Joueur jn(false);
*/

  // Joueur j; // non instanciable
  JoueurBlanc jb;
  JoueurNoir jn;

  jb.affiche();
  jn.affiche();

  Echiquier e;
  jb.placerPieces(e);
  jn.placerPieces(e);

  Roi rb(true);
  Roi rn(false);
  Reine qb(true);
  Reine qn(false);

  Tour tbb(true,true);
  Tour tbn(true,false);
  Tour tnb(false,true);
  Tour tnn(false,false);

  Cavalier cbb(true,true);
  Cavalier cbn(true,false);
  Cavalier cnb(false,true);
  Cavalier cnn(false,false);

  Fou fbb(true,true);
  Fou fbn(true,false);
  Fou fnb(false,true);
  Fou fnn(false,false);

  e.enleverPiece(5,1);
  e.placer(&rb);
  e.enleverPiece(5,8);
  e.placer(&rn);
  e.enleverPiece(4,1);
  e.placer(&qb);
  e.enleverPiece(4,8);
  e.placer(&qn);

  e.placer(&tbb);
  e.placer(&tbn);
  e.placer(&tnb);
  e.placer(&tnn);

  e.placer(&cbb);
  e.placer(&cbn);
  e.placer(&cnb);
  e.placer(&cnn);

  e.placer(&fbb);
  e.placer(&fbn);
  e.placer(&fnb);
  e.placer(&fnn);

  e.affiche();

  // les objets definis dans cette fonction sont automatiquement d�truits.
  // Ex : p1
}
