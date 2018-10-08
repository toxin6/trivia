#include "Game.h"

std::ostream&
operator<<(std::ostream& os, const Category& category) {
	switch (category) {
		case Category::pop:
			os << "Pop";
			break;
		case Category::science:
			os << "Science";
			break;
		case Category::sports:
			os << "Sports";
			break;
		case Category::rock:
			os << "Rock";
			break;
	}
	return os;
}
