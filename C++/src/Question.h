#ifndef TRIVIA_QUESTION_H
#define TRIVIA_QUESTION_H

#include <ostream>
#include "Category.h"

class Question {
public:
	Question(std::string value) : value_(std::move(value)) {}

	friend std::ostream&
	operator<<(std::ostream& os, const Question& question) {
		os << question.value_;
		return os;
	}

private:
	std::string value_;
};

#endif //TRIVIA_QUESTION_H
