/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#if !defined Joueur_h
#define Joueur_h

#include <vector>
#include "Piece.h"
#include "Echiquier.h"

using namespace std;

/**
 * Declaration d'une classe modelisant un joueur de jeu d'echec.
 */
class Joueur
{
protected:
  vector<Piece*> m_pieces;

public:
  Joueur();
  //Joueur(bool white);
  ~Joueur();
  Joueur(const Joueur &autre) = delete;
  Joueur &operator=(const Joueur &autre) = delete;
  void placerPieces(Echiquier &e);
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