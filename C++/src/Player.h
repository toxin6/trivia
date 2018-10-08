#ifndef TRIVIA_PLAYER_H
#define TRIVIA_PLAYER_H

#include <string>

class Player {
public:
	Player(std::string name) : name_(name), coins_(0), position_(0), inPenaltyBox_(false) {}

	void
	incrementCoins() {
		++coins_;
	}

	unsigned int
	coins() const {
		return coins_;
	}

	void
	position(unsigned int newPosition) {
		position_ = newPosition;
	}

	unsigned int
	position() const {
		return position_;
	}

	void
	putIntoPenaltyBox() {
		inPenaltyBox_ = true;
	}

	void
	getOutFromPenaltyBox() {
		inPenaltyBox_ = false;
	}

	bool
	inPenaltyBox() const {
		return inPenaltyBox_;
	}

	friend std::ostream&
	operator<<(std::ostream& os, const Player& player) {
		os << player.name_;
		return os;
	}

private:
	std::string name_;
	unsigned int coins_;
	unsigned int position_;
	bool inPenaltyBox_;
};

#endif //TRIVIA_PLAYER_H
