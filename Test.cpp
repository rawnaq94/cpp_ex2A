
/**
 *
 * AUTHORS: yuval yahod
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include "Direction.hpp"
using ariel::Direction;

#include <string>
#include <algorithm>
using namespace std;

/*

    this tests check the post mathod in board class.

*/
// chack the post on Horizontal direction 

TEST_CASE("The lest post is on the board -> Horizontal"){
    ariel::Board board;
	board.post(0, 0, Direction::Horizontal, "Atest1");
	board.post(0, 0, Direction::Horizontal, "Btest2");
	board.post(0, 0, Direction::Horizontal, "Ctest3");
	board.post(0, 0, Direction::Horizontal, "Dtest4");
    CHECK(board.read(0,0,Direction::Horizontal,6) == "Dtest4"); // the curr post on board
    CHECK(board.read(0,0,Direction::Horizontal,6) != "Atest1"); // the first post i posted

    board.post(53, 78, Direction::Horizontal, "Atest1");
	board.post(53, 78, Direction::Horizontal, "Btest2");
	board.post(53, 78, Direction::Horizontal, "Ctest3");
	board.post(53, 78, Direction::Horizontal, "Dtest4");
    CHECK(board.read(53,78,Direction::Horizontal,6) == "Dtest4"); // the curr post on board
    CHECK(board.read(53,78,Direction::Horizontal,6) != "Atest1"); // the first post i posted

    board.post(99, 99, Direction::Horizontal, "Atest1");
	board.post(99, 99, Direction::Horizontal, "Btest2");
	board.post(99, 99, Direction::Horizontal, "Ctest3");
	board.post(99, 99, Direction::Horizontal, "Dtest4");
    CHECK(board.read(99,99,Direction::Horizontal,6) == "Dtest4"); // the curr post on board
    CHECK(board.read(99,99,Direction::Horizontal,6) != "Atest1"); // the first post i posted

    board.post(27, 55, Direction::Horizontal, "Atest1");
	board.post(27, 56, Direction::Horizontal, "Btest2");
	board.post(27, 57, Direction::Horizontal, "Ctest3");
	board.post(27, 58, Direction::Horizontal, "Dtest4");
    CHECK(board.read(27,55,Direction::Horizontal,4) == "ABCD"); // the curr post on board
    CHECK(board.read(0,0,Direction::Horizontal,6) != "Atest1"); // the first post i posted

}

TEST_CASE("Nothing to read -> Horizontal"){
    ariel::Board board;
    CHECK(board.read(0,0,Direction::Horizontal,10) == "__________");
    CHECK(board.read(12,60,Direction::Horizontal,9) == "_________");
    CHECK(board.read(90,90,Direction::Horizontal,2) == "__"); 
    
    board.post(0, 0, Direction::Horizontal, "Atest1");
    board.post(12, 60, Direction::Horizontal, "Atest2");
    board.post(90, 90, Direction::Horizontal, "Atest3");

    CHECK(board.read(0,0,Direction::Horizontal,10) == "Atest1____");
    CHECK(board.read(12,60,Direction::Horizontal,9) == "Atest2___");
    CHECK(board.read(12,58,Direction::Horizontal,9) == "__Atest2_"); 
    CHECK(board.read(90,90,Direction::Horizontal,2) == "At"); 
}


// chack the post on Vertical direction 

TEST_CASE("The lest post is on the board -> vertical"){
    ariel::Board board;
	board.post(0, 0, Direction::Vertical, "Atest1");
	board.post(0, 0, Direction::Vertical, "Btest2");
	board.post(0, 0, Direction::Vertical, "Ctest3");
	board.post(0, 0, Direction::Vertical, "Dtest4");
    CHECK(board.read(0,0,Direction::Vertical,6) == "Dtest4"); // the curr post on board
    CHECK(board.read(0,0,Direction::Vertical,6) != "Atest1"); // the first post i posted

    board.post(53, 78, Direction::Vertical, "Atest1");
	board.post(53, 78, Direction::Vertical, "Btest2");
	board.post(53, 78, Direction::Vertical, "Ctest3");
	board.post(53, 78, Direction::Vertical, "Dtest4");
    CHECK(board.read(53,78,Direction::Vertical,6) == "Dtest4"); // the curr post on board
    CHECK(board.read(53,78,Direction::Vertical,6) != "Atest1"); // the first post i posted

    board.post(99, 99, Direction::Vertical, "Atest1");
	board.post(99, 99, Direction::Vertical, "Btest2");
	board.post(99, 99, Direction::Vertical, "Ctest3");
	board.post(99, 99, Direction::Vertical, "Dtest4");
    CHECK(board.read(99,99,Direction::Vertical,6) == "Dtest4"); // the curr post on board
    CHECK(board.read(99,99,Direction::Vertical,6) != "Atest1"); // the first post i posted

    board.post(27, 55, Direction::Vertical, "Atest1");
	board.post(28, 55, Direction::Vertical, "Btest2");
	board.post(29, 55, Direction::Vertical, "Ctest3");
	board.post(30, 55, Direction::Vertical, "Dtest4");
    CHECK(board.read(27,55,Direction::Vertical,4) == "ABCD"); // the curr post on board
    CHECK(board.read(0,0,Direction::Vertical,6) != "Atest1"); // the first post i posted

}

TEST_CASE("Nothing to read -> Vertical"){
    ariel::Board board;
    CHECK(board.read(0,0,Direction::Vertical,10) == "__________");
    CHECK(board.read(12,60,Direction::Vertical,9) == "_________");
    CHECK(board.read(90,90,Direction::Vertical,2) == "__"); 
    board.post(0, 0, Direction::Vertical, "Atest1");
    board.post(12, 60, Direction::Vertical, "Atest2");
    board.post(90, 90, Direction::Vertical, "Atest3");

    CHECK(board.read(0,0,Direction::Vertical,10) == "Atest1____");
    CHECK(board.read(12,60,Direction::Vertical,9) == "Atest2___");
    CHECK(board.read(12,58,Direction::Vertical,9) == "__Atest2_"); 
    CHECK(board.read(90,90,Direction::Vertical,2) == "At"); 
}

//post - mix of Vertical and horizontal

TEST_CASE("The lest post is on the board -> mix"){
    ariel::Board board;
	board.post(0, 0, Direction::Horizontal, "OMG");
	board.post(0, 1, Direction::Vertical, "NANA");
	board.post(0, 2, Direction::Vertical, "LOVE");
	board.post(0, 3, Direction::Horizontal, "Y BNANA");
	board.post(0, 6, Direction::Vertical, "I DO");
    board.post(0, 7, Direction::Horizontal, "BNANA");
	board.post(0, 8, Direction::Vertical, "I KNOW");

    CHECK(board.read(0,0,Direction::Horizontal,9) == "ONLY BIBI");

    board.post(67, 50, Direction::Horizontal, "OMG");
	board.post(67, 51, Direction::Vertical, "NANA");
	board.post(67, 52, Direction::Vertical, "LOVE");
	board.post(67, 53, Direction::Horizontal, "Y BNANA");
	board.post(67, 56, Direction::Vertical, "I DO");
    board.post(67, 57, Direction::Horizontal, "BNANA");
	board.post(67, 58, Direction::Vertical, "I KNOW");

    CHECK(board.read(67,50,Direction::Horizontal,9) == "ONLY BIBI");
    
    board.post(90, 90, Direction::Horizontal, "OMG");
	board.post(90, 91, Direction::Vertical, "NANA");
	board.post(90, 92, Direction::Vertical, "LOVE");
	board.post(90, 93, Direction::Horizontal, "Y BNANA");
	board.post(90, 96, Direction::Vertical, "I DO");
    board.post(90, 97, Direction::Horizontal, "BNANA");
	board.post(90, 98, Direction::Vertical, "I KNOW");

    CHECK(board.read(90,90,Direction::Horizontal,9) == "ONLY BIBI");

}

/* 
    this tests its for test the read mathod in board class
*/

// Direction : horizontal

TEST_CASE("Invalid input length on Horizontal direction") {
    ariel::Board board;
    CHECK_THROWS(board.read(0,0,Direction::Horizontal , -1)); // the first negrive 
    CHECK_THROWS(board.read(0,0,Direction::Horizontal , -100)); 
    CHECK_THROWS(board.read(0,0,Direction::Horizontal , -12322342));//randomally negetive number

}

TEST_CASE("In range and len 0  -> Horizontal"){
    ariel::Board board;
    CHECK(board.read(0,0,Direction::Horizontal,0) == "");//At one end
    CHECK(board.read(99,0,Direction::Horizontal,0) == "");//At the other end
    CHECK(board.read(99,99,Direction::Horizontal,0) == "");//At the third end
    CHECK(board.read(0,99,Direction::Horizontal,0) == "");//At the fourth end
    CHECK(board.read(23,86,Direction::Horizontal,0) == "");//At a random number I chose
}
TEST_CASE("there is messeg but i read in len 0"){
    ariel::Board board;
    board.post(27, 55, Direction::Horizontal, "Atest1");
    CHECK(board.read(27,55,Direction::Horizontal,0) == "");
    CHECK(board.read(27,56,Direction::Horizontal,0) == "");
    CHECK(board.read(27,57,Direction::Horizontal,0) == "");

}

// Direction : Vertical

TEST_CASE("Invalid input length on Vertical direction") {
    ariel::Board board;
    CHECK_THROWS(board.read(0,0,Direction::Vertical , -1));
    CHECK_THROWS(board.read(0,0,Direction::Vertical , -100));
    CHECK_THROWS(board.read(0,0,Direction::Vertical , -123434342));

}


TEST_CASE("In range and len 0  -> Vertical"){
    ariel::Board board;
    CHECK(board.read(0,0,Direction::Vertical,0) == "");//At one end
    CHECK(board.read(99,0,Direction::Vertical,0) == "");//At the other end
    CHECK(board.read(99,99,Direction::Vertical,0) == "");//At the third end
    CHECK(board.read(0,99,Direction::Vertical,0) == "");//At the fourth end
    CHECK(board.read(23,86,Direction::Vertical,0) == "");//At a random number I chose
}

TEST_CASE("there is messeg but i read in len 0"){
    ariel::Board board;
    board.post(27, 55, Direction::Vertical, "Atest1");
    CHECK(board.read(27,55,Direction::Vertical,0) == "");
    CHECK(board.read(28,55,Direction::Vertical,0) == "");
    CHECK(board.read(29,55,Direction::Vertical,0) == "");

}

