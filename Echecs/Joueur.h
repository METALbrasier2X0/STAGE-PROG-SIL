/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include "Piece.h"
#include "Echiquier.h"

/**
 * Declaration d'une classe modelisant un joueur de jeu d'echec.
 */
class Joueur
{
protected:
  Piece m_pieces[16];

public:
  Joueur();
  Joueur(bool white);
  void placerPieces( Echiquier & e );
  void affiche();
  virtual bool isWhite() const =0;
};

class JoueurBlanc : public Joueur
{
  public:
    JoueurBlanc();
    bool isWhite() const;
};

class JoueurNoir : public Joueur
{
  public:
    JoueurNoir();
    bool isWhite() const;
};

#endif // !defined Joueur_h