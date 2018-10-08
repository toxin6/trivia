#include "Game.h"

unsigned int
getRolledNumber() {
	return static_cast<unsigned int>(rand() % 5 + 1);
}

bool
getAnswerWasCorrectOrNot() {
	return (rand() % 9) == 7;
}

int
main() {
	srand(time(NULL));

	Game game(50);
	game.addPlayer("Chet");
	game.addPlayer("Pat");
	game.addPlayer("Sue");

	do {
		if (game.roll(getRolledNumber())) {
			game.setAnswerCorrectOrNot(getAnswerWasCorrectOrNot());
		}
	} while (!game.checkCurrentPlayerWon());
}
