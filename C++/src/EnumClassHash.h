#ifndef TRIVIA_ENUMCLASSHASH_H
#define TRIVIA_ENUMCLASSHASH_H

#include <cstddef>

struct EnumClassHash
{
	template <typename T>
	std::size_t operator()(T t) const
	{
		return static_cast<std::size_t>(t);
	}
};

#endif //TRIVIA_ENUMCLASSHASH_H
