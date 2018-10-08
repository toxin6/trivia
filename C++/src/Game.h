#ifndef TRIVIA_GAME_H
#define TRIVIA_GAME_H

#include <list>
#include <vector>
#include <unordered_map>
#include "Player.h"
#include "Category.h"
#include "Question.h"
#include "EnumClassHash.h"

class Game {
public:
	Game(unsigned int numberOfQuestionsPerCategory);

	void
	addPlayer(std::string name);

	bool
	roll(unsigned int rolledNumber);

	bool
	setAnswerCorrectOrNot(bool isAnswerCorrect);

	bool
	checkCurrentPlayerWon();

private:
	void
	generateQuestionsForCategory(Category category, unsigned int numberOfQuestions);

	bool
	checkHasEnoughPlayers();

	Player&
	currentPlayer();

	Player&
	nextPlayer();

	void
	moveCurrentPlayerByRolledNumber(unsigned int rolledNumber);

	Category
	getCategoryByPosition(unsigned int position);

	bool
	askQuestion(Category category);

	void
	handleCorrectAnswer();

	void
	handleWrongAnswer();

private:
	typedef std::vector<Player> Players;

	Players players_;
	Players::iterator currentPlayer_;

	std::unordered_map<Category, std::list<Question>, EnumClassHash> questions_;
};

#endif //TRIVIA_GAME_H
