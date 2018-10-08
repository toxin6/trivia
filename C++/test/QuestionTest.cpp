#include <cppunit/extensions/HelperMacros.h>
#include "../src/Question.h"

class QuestionTest : public CppUnit::TestFixture {
	CPPUNIT_TEST_SUITE(QuestionTest);
	CPPUNIT_TEST(testGettingAsString);
	CPPUNIT_TEST_SUITE_END();

public:
	void
	testGettingAsString() {
		const std::string value("How do you do?");
		Question question(value);
		std::ostringstream oss;
		oss << question;
		CPPUNIT_ASSERT(oss.str() == value);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(QuestionTest);
