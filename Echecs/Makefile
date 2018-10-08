SRC_CXX=Piece.cxx Joueur.cxx Echiquier.cxx

OBJ=${SRC_CXX:.cxx=.o}

all: testPiece

testPiece: $(OBJ) testPiece.o
	g++ $(OBJ) testPiece.o -o testPiece

%.o: %.cxx
	g++ -std=c++11 -c -g $<

clean:
	@rm -f $(OBJ) testPiece.o testPiece *~

