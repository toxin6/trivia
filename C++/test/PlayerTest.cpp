#include <cppunit/extensions/HelperMacros.h>
#include "../src/Player.h"

class PlayerTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(PlayerTest);
	CPPUNIT_TEST(testGettingAsString);
	CPPUNIT_TEST(testCoinIncrementation);
	CPPUNIT_TEST(testPositionChanging);
	CPPUNIT_TEST(testPenaltyBoxStatusChanging);
	CPPUNIT_TEST_SUITE_END();

public:
	void
	testGettingAsString() {
		const std::string playerName("abc123");
		Player player(playerName);
		std::ostringstream oss;
		oss << player;
		CPPUNIT_ASSERT(oss.str() == playerName);
	}

	void
	testCoinIncrementation() {
		Player player("a");
		CPPUNIT_ASSERT(player.coins() == 0);
		player.incrementCoins();
		CPPUNIT_ASSERT(player.coins() == 1);
		player.incrementCoins();
		CPPUNIT_ASSERT(player.coins() == 2);
	}

	void
	testPositionChanging() {
		Player player("a");
		CPPUNIT_ASSERT(player.position() == 0);
		player.position(4);
		CPPUNIT_ASSERT(player.position() == 4);
		player.position(3);
		CPPUNIT_ASSERT(player.position() == 3);
	}

	void
	testPenaltyBoxStatusChanging() {
		Player player("a");
		CPPUNIT_ASSERT(!player.inPenaltyBox());
		player.putIntoPenaltyBox();
		CPPUNIT_ASSERT(player.inPenaltyBox());
		player.getOutFromPenaltyBox();
		CPPUNIT_ASSERT(!player.inPenaltyBox());
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(PlayerTest);
