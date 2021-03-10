#include "doctest.h"

#include "snowman.hpp"

using namespace ariel;

#include <string>

#include <algorithm>

using namespace std;

TEST_CASE ("Good snowman code") {
    CHECK(snowman(11111111) == string("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(snowman(22222222) == string("  ___  \n ..... \n\\(o.o)/\n (] [) \n (\" \") "));
    CHECK(snowman(33333333) == string(" _ \n/_\\n(O_O)\n/(> <)\\n(___)"));
    CHECK(snowman(44444444) == string("  ___  \n (_*_) \n (- -) \n (   ) \n (   ) "));
    CHECK(snowman(23232223) == string("  ___  \n ..... \n\\(o_O)/\n (] [) \n (___) "));
    CHECK(snowman(44112214) == string("___ \n(_*_)\n\\(. .)/\n]( : )[\n(   )"));
    CHECK(snowman(11111213) == string("_===_\n(.,.)/\n<( : )\n( ___ )"));
    CHECK(snowman(31112214) == string("_/_\\\n\\(.,.)/\n]( : )[\n(   )")) ;
    CHECK(snowman(41112214) == string("___ \n(_*_)\n\\(.,.)/\n]( : )[\n(   )"));
    CHECK(snowman(31333342) == string("   _   \n  /_\\ \n (O,O) \n/(   )\\\n (\" \") "));
    CHECK(snowman(41341144) == string("  ___  \n (_*_) \n (O,-) \n<(   )>\n (   ) ")); 
    CHECK(snowman(33232124) == string("   _   \n  /_\\ \n\\(o_O) \n (] [)>\n (   ) "));
    CHECK(snowman(32443333) == string("_/_\\\n\\(-.-)/\n(> <)\n(___)"));
    CHECK(snowman(44442214) == string( "___ \n(_*_)\n\\(- -)/\n]( : )[\n(   )"));
}

TEST_CASE ("Bad snowman code") {

    //input too short\ too long\ negative\ values not in range
    CHECK_THROWS(snowman(1234321)); 
    CHECK_THROWS(snowman(23));
    CHECK_THROWS(snowman(2413));
    CHECK_THROWS(snowman(55));

    CHECK_THROWS(snowman(4321432143));
    CHECK_THROWS(snowman(1223334444));  
    CHECK_THROWS(snowman(413232441));
    CHECK_THROWS(snowman(112324341));

    CHECK_THROWS(snowman(-11111112));
    CHECK_THROWS(snowman(-43421213));
    CHECK_THROWS(snowman(-44332211));
    CHECK_THROWS(snowman(-24323213));

    CHECK_THROWS(snowman(98989898));
    CHECK_THROWS(snowman(24132744));
    CHECK_THROWS(snowman(79251235));
    CHECK_THROWS(snowman(87654321));
}