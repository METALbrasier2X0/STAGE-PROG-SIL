/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"

/**
 * Declaration d'une classe modelisant un joueur de jeu d'echec.
 */
class Joueur
{
private:
  Piece m_pieces[16];

public:
  Joueur( bool white );
  void affiche();
};

#endif // !defined Joueur_h