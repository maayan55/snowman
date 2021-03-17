#include "snowman.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	cout << ariel::snowman(11114411) << endl;  
/* the right answer is:
_===_
(.,.)
( : )
( : ) */
	cout << ariel::snowman(22223333) << endl;
	try {
		cout << ariel::snowman(67) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "the input should have exactly 8 digits, so 67 invalid"
	}
}