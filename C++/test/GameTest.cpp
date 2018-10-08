#include <cppunit/extensions/HelperMacros.h>
#include "../src/Game.h"

class GameTest : public CppUnit::TestFixture {
CPPUNIT_TEST_SUITE(GameTest);
		CPPUNIT_TEST(testRollingWithoutEnoughPlayers);
		CPPUNIT_TEST(testRollingWithEnoughPlayers);
		CPPUNIT_TEST(testRollingANull);
		CPPUNIT_TEST(testPlayerGettingOutFromPenaltyBox);
		CPPUNIT_TEST(testPlayerWinning);
	CPPUNIT_TEST_SUITE_END();

public:
	void
	testRollingWithoutEnoughPlayers() {
		Game game(1);
		CPPUNIT_ASSERT(!game.roll(1));
		game.addPlayer("A");
		CPPUNIT_ASSERT(!game.roll(2));
	}

	void
	testRollingWithEnoughPlayers() {
		Game game(1);
		game.addPlayer("A");
		game.addPlayer("B");
		CPPUNIT_ASSERT(game.roll(1));
	}

	void
	testRollingANull() {
		Game game(1);
		game.addPlayer("A");
		game.addPlayer("B");
		CPPUNIT_ASSERT(!game.roll(0));
	}

	void
	testPlayerGettingOutFromPenaltyBox() {
		Game game(50);
		game.addPlayer("A");
		game.addPlayer("B");

		// player A
		CPPUNIT_ASSERT(game.roll(1));
		CPPUNIT_ASSERT(game.setAnswerCorrectOrNot(false));
		// player B
		CPPUNIT_ASSERT(game.roll(1));
		CPPUNIT_ASSERT(game.setAnswerCorrectOrNot(false));
		// player A
		CPPUNIT_ASSERT(!game.roll(2));
		CPPUNIT_ASSERT(!game.setAnswerCorrectOrNot(false));
		// player B
		CPPUNIT_ASSERT(!game.roll(4));
		CPPUNIT_ASSERT(!game.setAnswerCorrectOrNot(false));
		// player A
		CPPUNIT_ASSERT(game.roll(3));
		CPPUNIT_ASSERT(game.setAnswerCorrectOrNot(false));
		// player B
		CPPUNIT_ASSERT(game.roll(5));
		CPPUNIT_ASSERT(game.setAnswerCorrectOrNot(false));
	}

	void
	testPlayerWinning() {
		Game game(50);
		game.addPlayer("A");
		game.addPlayer("B");

		// player A when i is even, player B when i is odd
		for (int i = 0; i < 10; ++i) {
			CPPUNIT_ASSERT(game.roll(1));
			game.setAnswerCorrectOrNot(true);
			CPPUNIT_ASSERT(!game.checkCurrentPlayerWon());
		}
		// player A
		CPPUNIT_ASSERT(game.roll(1));
		game.setAnswerCorrectOrNot(false);
		CPPUNIT_ASSERT(!game.checkCurrentPlayerWon());
		// player B
		CPPUNIT_ASSERT(game.roll(1));
		game.setAnswerCorrectOrNot(true);
		CPPUNIT_ASSERT(game.checkCurrentPlayerWon());
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(GameTest);
