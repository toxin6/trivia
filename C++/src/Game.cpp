#include <iostream>
#include <sstream>
#include "Game.h"

Game::Game(unsigned int numberOfQuestionsPerCategory) {
	generateQuestionsForCategory(Category::pop, numberOfQuestionsPerCategory);
	generateQuestionsForCategory(Category::science, numberOfQuestionsPerCategory);
	generateQuestionsForCategory(Category::sports, numberOfQuestionsPerCategory);
	generateQuestionsForCategory(Category::rock, numberOfQuestionsPerCategory);
}

void
Game::addPlayer(std::string name) {
	players_.push_back(Player(name));
	std::cout << name << " was added" << std::endl;
	std::cout << "They are player number " << players_.size() << std::endl;
	currentPlayer_ = players_.end();
}

bool
Game::roll(unsigned int rolledNumber) {
	if (!checkHasEnoughPlayers() || (rolledNumber == 0)) {
		return false;
	}

	Player& player = nextPlayer();
	std::cout << player << " is the current player" << std::endl;
	std::cout << "They have rolled a " << rolledNumber << std::endl;

	bool isSuccessRoll = true;
	if (player.inPenaltyBox()) {
		if ((rolledNumber % 2) == 0) {
			isSuccessRoll = false;
			std::cout << player << " is not getting out of the penalty box" << std::endl;
		} else {
			player.getOutFromPenaltyBox();
			std::cout << player << " is getting out of the penalty box" << std::endl;
		}
	}

	if (isSuccessRoll) {
		moveCurrentPlayerByRolledNumber(rolledNumber);
		const Category category = getCategoryByPosition(player.position());
		std::cout << "The category is " << category << std::endl;
		return askQuestion(category);
	}
	return false;
}

bool
Game::setAnswerCorrectOrNot(bool isAnswerCorrect) {
	if (!checkHasEnoughPlayers() || currentPlayer().inPenaltyBox()) {
		return false;
	}

	if (isAnswerCorrect) {
		handleCorrectAnswer();
	} else {
		handleWrongAnswer();
	}
	return true;
}

bool
Game::checkCurrentPlayerWon() {
	const bool isWinner = currentPlayer().coins() >= 6;
	if (isWinner) {
		std::cout << "The winner is " << currentPlayer() << "!" << std::endl;
	}
	return isWinner;
}

void
Game::generateQuestionsForCategory(Category category, unsigned int numberOfQuestions) {
	std::list<Question> questionsForCategory;
	for (int i = 0; i < numberOfQuestions; ++i) {
		std::ostringstream oss;
		oss << category << " Question " << i;
		questionsForCategory.emplace_back(oss.str());
	}
	questions_.insert(std::make_pair(category, questionsForCategory));
}

bool
Game::checkHasEnoughPlayers() {
	const bool hasEnough = (players_.size() >= 2);
	if (!hasEnough) {
		std::cout << "There isn't enough player in game" << std::endl;
	}
	return hasEnough;
}

Player&
Game::currentPlayer() {
	return (*currentPlayer_);
}

Player&
Game::nextPlayer() {
	if (currentPlayer_ != players_.end()) {
		++currentPlayer_;
	}
	if (currentPlayer_ == players_.end()) {
		currentPlayer_ = players_.begin();
	}
	return currentPlayer();
}

void
Game::moveCurrentPlayerByRolledNumber(unsigned int rolledNumber) {
	Player& player = currentPlayer();
	unsigned int newPosition = player.position() + rolledNumber;
	if (newPosition > 11) newPosition = newPosition - 12;
	player.position(newPosition);
	std::cout << player << "'s new location is " << player.position() << std::endl;
}

Category
Game::getCategoryByPosition(unsigned int position) {
	switch (position % 4) {
		case 0:
			return Category::pop;
		case 1:
			return Category::science;
		case 2:
			return Category::sports;
		default:
			return Category::rock;
	}
}

bool
Game::askQuestion(Category category) {
	std::list<Question>& questionsForCategory = questions_.at(category);
	if (questionsForCategory.empty()) {
		std::cerr << "Question list for " << category << " category is empty!" << std::endl;
		return false;
	} else {
		std::cout << questionsForCategory.front() << std::endl;
		questionsForCategory.pop_front();
		return true;
	}
}

void
Game::handleCorrectAnswer() {
	std::cout << "Answer was corrent!!!!" << std::endl;
	Player& player = currentPlayer();
	player.incrementCoins();
	std::cout << player << " now has " << player.coins() << " Gold Coins." << std::endl;
}

void
Game::handleWrongAnswer() {
	std::cout << "Question was incorrectly answered" << std::endl;
	Player& player = currentPlayer();
	player.putIntoPenaltyBox();
	std::cout << player << " was sent to the penalty box" << std::endl;
}
