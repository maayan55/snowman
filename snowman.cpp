#include "snowman.hpp"

/* this file contains one big main function that build a snowman.
the function get number with 8 digits, all between 1-4
and make a snow man.*/

const int MIN_VALID_NUM = 11111111;
const int MAX_VALID_NUM = 44444444;
const int MIN_LEN = 10000000;
const int MAX_LEN = 99999999;

    string base(int x) {
        if(x == 1) {return " ( : )\n";}
        if(x == 2) {return " (\" \")\n";}
        if(x == 3) {return " (___)\n";}
        if(x == 4) {return " (   )\n";}
        throw std::out_of_range{"invalid digit"};
    }
    string torso(int x) {
        if(x == 1) {return "( : )";} 
        if(x == 2) {return "(] [)";}
        if(x == 3) {return "(> <)";}
        if(x == 4) {return "(   )";}
        throw std::out_of_range{"invalid digit"};
    }
    string right_arm(int x) {
        if(x == 1) {return ">";}
        if(x == 2) {return "/";}
        if(x == 3) {return "\\";}
        if(x == 4){return " ";}
        throw std::out_of_range{"invalid digit"};
    }
    string left_arm(int x) {
        if(x == 1) {return "<";}
        if(x == 2) {return "\\";}
        if(x == 3) {return "/";}
        if(x == 4){return " ";}
        throw std::out_of_range{"invalid digit"};
    }
    string eye(int x) {
        if(x == 1) {return ".";}
        if(x == 2) {return "o";}
        if(x == 3) {return "O";}
        if(x == 4) {return "-";}
        throw std::out_of_range{"invalid digit"};
    }
    string nose_mouth(int x) {
        if(x == 1) {return ",";}
        if(x == 2) {return ".";}
        if(x == 3) {return "_";}
        if(x == 4) {return " ";}
        throw std::out_of_range{"invalid digit"};
    }
    string hat(int x) {
        if(x == 1) {return  " _===_\n";}
        if(x == 2) {return "  ___\n .....\n";}
        if(x == 3) {return "   _\n  /_\\\n";}
        if(x == 4) {return "  ___\n (_*_)\n";}
        throw std::out_of_range{"invalid digit"};
    }


namespace ariel{
    string snowman(int num){
        if(num<MIN_LEN || num > MAX_LEN){
            throw std::length_error{"the input should have exactly 8 digits, so " + to_string(num) + " invalid"};
        }
        if(num > MAX_VALID_NUM || num < MIN_VALID_NUM){
            throw std::out_of_range{"the input should be between 11111111 to 44444444, SO "+ to_string(num) + "invalid"};
        }
        if(num < 0){
            throw std::domain_error{"the input should be positive, so " + to_string(num) + " invalid"};
        }
        int B = num %10;
        num /= 10;
        int T = num %10;
        num /= 10;
        int Y = num %10;
        num /= 10;
        int X = num %10;
        num /= 10;
        int R = num %10;
        num /= 10;
        int L = num %10;
        num /= 10;
        int N = num %10;
        num /= 10;
        int H = num %10; 

        string t1;
        string face = "(" + eye(L) + nose_mouth(N) + eye(R) + ")";
        if(Y == 2 && X == 2) {
            t1 = left_arm(X) + face + right_arm(Y) + "\n " + torso(T) + " \n";
        }
        else if(X == 2) {
            t1 = left_arm(X) + face + " \n " + torso(T) + right_arm(Y) + "\n";
        }
        else if(Y == 2) {
            t1 = " " +  face + right_arm(Y) + "\n" + left_arm(X) + torso(T) + " \n";
        }
        else {
            t1 = " " +  face + " \n" + left_arm(X) + torso(T) + right_arm(Y) + "\n";
        }
        string ans = hat(H) + t1 + base(B);
        return ans; 
    }
}
