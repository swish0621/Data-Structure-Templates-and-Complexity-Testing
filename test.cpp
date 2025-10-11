/*
Name: Nicholas Swisher
Purpose: Verify that the Linear, Tree and HashMap templates function correctly 
Usage:
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Linear.hpp"
//#include "Tree.hpp"
//#include "HashMap.hpp"
#include <string>


TEST_CASE("Test Linear<int>", "[Linear]"){
    SECTION("Test getElementAtIndex()"){
        Linear<int> i;
        REQUIRE_THROWS(i.getElementAtIndex(3));
    }

    SECTION("Test insertElement()"){
        Linear<int> i;
        i.insertElement(10);
        i.insertElement(20);
        i.insertElement(30);
        REQUIRE(i.getElementAtIndex(0) == 10);
        REQUIRE(i.getElementAtIndex(1) == 20);
        REQUIRE(i.getElementAtIndex(2) == 30);
    }

    SECTION("Test search()"){
        Linear<int> i;
        i.insertElement(10);
        i.insertElement(20);
        i.insertElement(30);
        REQUIRE(i.search(10) == true);
        REQUIRE(i.search(20) == true);
        REQUIRE(i.search(30) == true);
        REQUIRE(i.search(0) == false);
        REQUIRE(i.search(100) == false);
    }
    
    SECTION("Test deleteElement()"){
        Linear<int> i;
        i.insertElement(10);
        i.insertElement(20);
        i.insertElement(30);
        i.deleteElement(20);
        REQUIRE(i.getElementAtIndex(1) == 30);
        REQUIRE_THROWS(i.getElementAtIndex(2));
    }

    SECTION("Test overloaded operator <<"){
        Linear<int> i;
        i.insertElement(10);
        i.insertElement(20);
        i.insertElement(30);
        std::cout << "Checking Linear<int> operator output: " << std::endl;
        std::cout << "Should be: 10, 20, 30" << std::endl << "Is: " << i << std::endl << std::endl;
    }
}

TEST_CASE("Test Linear<std::string>", "[Linear]"){
    SECTION("Test getElementAtIndex()"){
        Linear<std::string> s;
        REQUIRE_THROWS(s.getElementAtIndex(2));
    }

    SECTION("Test insertElement()"){
        Linear<std::string> s;
        s.insertElement("aaa");
        s.insertElement("bbb");
        s.insertElement("ccc");
        REQUIRE(s.getElementAtIndex(0) == "aaa");
        REQUIRE(s.getElementAtIndex(1) == "bbb");
        REQUIRE(s.getElementAtIndex(2) == "ccc");
    }

    SECTION("Test search()"){
        Linear<std::string> s;
        s.insertElement("aaa");
        s.insertElement("bbb");
        s.insertElement("ccc");
        REQUIRE(s.search("aaa") == true);
        REQUIRE(s.search("bbb") == true);
        REQUIRE(s.search("ccc") == true);
        REQUIRE(s.search("ddd") == false);
        REQUIRE(s.search("zzz") == false);
    }
    
    SECTION("Test deleteElement()"){
        Linear<std::string> s;
        s.insertElement("aaa");
        s.insertElement("bbb");
        s.insertElement("ccc");
        s.deleteElement("bbb");
        REQUIRE(s.getElementAtIndex(1) == "ccc");
        REQUIRE_THROWS(s.getElementAtIndex(2));
    }

    SECTION("Test overloaded operator <<"){
        Linear<std::string> s;
        s.insertElement("aaa");
        s.insertElement("bbb");
        s.insertElement("ccc");
        std::cout << "Checking Linear<std::string> operator output: " << std::endl;
        std::cout << "Should be: aaa, bbb, ccc" << std::endl << "Is: " << s << std::endl << std::endl;
    }
}

TEST_CASE("Test Tree Structure", "[Tree]"){}
TEST_CASE("Test HashMap Structure", "[HashMap]"){}

