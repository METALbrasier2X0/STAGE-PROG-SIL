SRC_CXX=Piece.cxx Joueur.cxx Echiquier.cxx

OBJ=${SRC_CXX:.cxx=.o}

all: testPiece

testPiece: $(OBJ) testPiece.o Piece.h
	g++ $(OBJ) testPiece.o -o testPiece

%.o: %.cxx
	g++ -g -c $<

Piece.o: Piece.h
	g++ -g -c Piece.cxx

clean:
	@rm -f $(OBJ) testPiece.o testPiece *~

