#ifndef TRIVIA_CATEGORY_H
#define TRIVIA_CATEGORY_H

#include <string>
#include <ostream>

enum class Category {
	pop = 0,
	science = 1,
	sports = 2,
	rock = 3
};

std::ostream& operator<<(std::ostream& os, const Category& category);

#endif //TRIVIA_CATEGORY_H
