find_library(CPPUNIT_LIBRARY_DEBUG NAMES cppunit cppunit_dll cppunitd cppunitd_dll
        PATHS ${FOO_PREFIX}/lib
        /usr/lib
        /usr/lib64
        /usr/local/lib
        /usr/local/lib64
        PATH_SUFFIXES debug)

find_library(CPPUNIT_LIBRARY_RELEASE NAMES cppunit cppunit_dll
        PATHS ${FOO_PREFIX}/lib
        /usr/lib
        /usr/lib64
        /usr/local/lib
        /usr/local/lib64
        PATH_SUFFIXES release)

if (CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)
    set(CPPUNIT_LIBRARY_RELEASE ${CPPUNIT_LIBRARY_DEBUG})
endif (CPPUNIT_LIBRARY_DEBUG AND NOT CPPUNIT_LIBRARY_RELEASE)

set(CPPUNIT_LIBRARY debug ${CPPUNIT_LIBRARY_DEBUG}
        optimized ${CPPUNIT_LIBRARY_RELEASE})

file(GLOB Trivia_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "../src/*.cpp")
list(REMOVE_ITEM Trivia_SRCS "../src/GameRunner.cpp")

file(GLOB UnitTests_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*Test.cpp")
add_executable(triviaUnitTester TestRunner.cpp ${UnitTests_SRCS} ${Trivia_SRCS})
target_link_libraries(triviaUnitTester ${CPPUNIT_LIBRARY})
foreach (test ${UnitTests_SRCS})
    get_filename_component(TestName ${test} NAME_WE)
    add_test(${TestName} triviaUnitTester ${TestName})
endforeach (test)
