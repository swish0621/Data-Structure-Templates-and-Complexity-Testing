/*
Name: Nicholas Swisher
Purpose: Verify that the Linear, Tree and HashMap templates function correctly 
Usage: When run Linear, Tree and HashMap objects will be created and tested using catch2 unittesting.
make clean - removes all executable and object files
make all - builds all necessary object files and executables
./test - runs the unittesting 
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Linear.hpp"
#include "Tree.hpp"
#include "HashMap.hpp"
#include "Person.h"
#include <string>
#include <fstream>
#include <chrono>


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

TEST_CASE("Test Linear<struct>", "[Linear]"){
    SECTION("Test getElementAtIndex()"){
        Linear<Person> p;
        REQUIRE_THROWS(p.getElementAtIndex(2));
    }

    SECTION("Test insertElement()"){
        Linear<Person> p;
        Person p1 = {"John", 24};
        Person p2 = {"Angie",37};
        Person p3 = {"Alex", 51};
        p.insertElement(p1);
        p.insertElement(p2);
        p.insertElement(p3);
        REQUIRE(p.getElementAtIndex(0) == p1);
        REQUIRE(p.getElementAtIndex(1) == p2);
        REQUIRE(p.getElementAtIndex(2) == p3);
    }

    SECTION("Test search()"){
        Linear<Person> p;
        Person p1 = {"John", 24};
        Person p2 = {"Angie",37};
        Person p3 = {"Alex", 51};
        p.insertElement(p1);
        p.insertElement(p2);
        p.insertElement(p3);
        REQUIRE(p.search(p1) == true);
        REQUIRE(p.search(p2) == true);
        REQUIRE(p.search(p3) == true);
        REQUIRE(p.search({"Johnny", 21}) == false);
        REQUIRE(p.search({"Jackie", 29}) == false);
    }
    
    SECTION("Test deleteElement()"){
        Linear<Person> p;
        Person p1 = {"John", 24};
        Person p2 = {"Angie",37};
        Person p3 = {"Alex", 51};
        p.insertElement(p1);
        p.insertElement(p2);
        p.insertElement(p3);
        p.deleteElement(p2);
        REQUIRE(p.getElementAtIndex(1) == p3);
        REQUIRE_THROWS(p.getElementAtIndex(2));
    }

    SECTION("Test overloaded operator <<"){
        Linear<Person> p;
        Person p1 = {"John", 24};
        Person p2 = {"Angie",37};
        Person p3 = {"Alex", 51};
        p.insertElement(p1);
        p.insertElement(p2);
        p.insertElement(p3);
        std::cout << "Checking Linear<struct> operator output: " << std::endl;
        std::cout << "Should be: {\"John\", 24}, {\"Angie\",37}, {\"Alex\", 51}" << std::endl << "Is: " << p << std::endl << std::endl;
    }
}

TEST_CASE("Test Tree<int>", "[Tree]"){
    SECTION("Test Tree()"){
        Tree<int> t(10);
        REQUIRE(t.search(10) == true);
        REQUIRE(t.search(20) == false);
    }
    

    SECTION("Test insertElement() / search()"){
        Tree<int> t(40);
        
        t.insertElement(20);
        t.insertElement(60);
        t.insertElement(10);
        t.insertElement(30);
        t.insertElement(50);
        t.insertElement(70);
        REQUIRE(t.search(10) == true);
        REQUIRE(t.search(20) == true);
        REQUIRE(t.search(25) == false);
        REQUIRE(t.search(35) == false);
    }

    SECTION("Testing deleteElement()"){
        Tree<int> t(40);
        
        t.insertElement(20);
        t.insertElement(60);
        t.insertElement(10);
        t.insertElement(30);
        t.insertElement(50);
        t.insertElement(70);

        // delete node with 2 children
        t.deleteElement(60);
        REQUIRE(t.search(60) == false);
        REQUIRE(t.search(10) == true);
        REQUIRE(t.search(20) == true);
        REQUIRE(t.search(30) == true);
        REQUIRE(t.search(40) == true);
        REQUIRE(t.search(50) == true);
        REQUIRE(t.search(70) == true);

        // delete root 
        t.deleteElement(40);
        REQUIRE(t.search(40) == false);
        REQUIRE(t.search(10) == true);
        REQUIRE(t.search(20) == true);
        REQUIRE(t.search(30) == true);
        REQUIRE(t.search(50) == true);
        REQUIRE(t.search(70) == true);

        // delete node with only one child 
        t.insertElement(80);
        t.deleteElement(70);
        REQUIRE(t.search(70) == false);
        REQUIRE(t.search(10) == true);
        REQUIRE(t.search(20) == true);
        REQUIRE(t.search(30) == true);
        REQUIRE(t.search(50) == true);
        REQUIRE(t.search(80) == true);
    }

    SECTION("Test overloaded operator"){
        Tree<int> t(40);
        
        t.insertElement(20);
        t.insertElement(60);
        t.insertElement(10);
        t.insertElement(30);
        t.insertElement(50);
        t.insertElement(70);
        std::cout << "Checking Tree<int> operator output: " << std::endl;
        std::cout << "Should be: 10, 20, 30, 40, 50, 60, 70" << std::endl << "Is: " << t << std::endl << std::endl;
    }
}

TEST_CASE("Test Tree<std::string>", "[Tree]"){
    SECTION("Test Tree()"){
        Tree<std::string> t("aaa");
        REQUIRE(t.search("aaa") == true);
        REQUIRE(t.search("bbb") == false);
    }
    

    SECTION("Test insertElement() / search()"){
        Tree<std::string> t("ddd");
        
        t.insertElement("bbb");
        t.insertElement("fff");
        t.insertElement("aaa");
        t.insertElement("ccc");
        t.insertElement("eee");
        t.insertElement("ggg");
        REQUIRE(t.search("aaa") == true);
        REQUIRE(t.search("bbb") == true);
        REQUIRE(t.search("abc") == false);
        REQUIRE(t.search("hhh") == false);
    }

    SECTION("Testing deleteElement()"){
        Tree<std::string> t("ddd");
        
        t.insertElement("bbb");
        t.insertElement("fff");
        t.insertElement("aaa");
        t.insertElement("ccc");
        t.insertElement("eee");
        t.insertElement("ggg");

        // delete node with 2 children
        t.deleteElement("fff");
        REQUIRE(t.search("fff") == false);
        REQUIRE(t.search("aaa") == true);
        REQUIRE(t.search("bbb") == true);
        REQUIRE(t.search("ccc") == true);
        REQUIRE(t.search("ddd") == true);
        REQUIRE(t.search("eee") == true);
        REQUIRE(t.search("ggg") == true);

        // delete root 
        t.deleteElement("ddd");
        REQUIRE(t.search("ddd") == false);
        REQUIRE(t.search("aaa") == true);
        REQUIRE(t.search("bbb") == true);
        REQUIRE(t.search("ccc") == true);
        REQUIRE(t.search("eee") == true);
        REQUIRE(t.search("ggg") == true);

        // delete node with only one child 
        t.insertElement("hhh");
        t.deleteElement("ggg");
        REQUIRE(t.search("ggg") == false);
        REQUIRE(t.search("ddd") == false);
        REQUIRE(t.search("aaa") == true);
        REQUIRE(t.search("bbb") == true);
        REQUIRE(t.search("ccc") == true);
        REQUIRE(t.search("eee") == true);
        REQUIRE(t.search("hhh") == true);
    }

    SECTION("Test overloaded operator"){
        Tree<std::string> t("ddd");
        
        t.insertElement("bbb");
        t.insertElement("fff");
        t.insertElement("aaa");
        t.insertElement("ccc");
        t.insertElement("eee");
        t.insertElement("ggg");
        std::cout << "Checking Tree<std::string> operator output: " << std::endl;
        std::cout << "Should be: aaa, bbb, ccc, ddd, eee, fff, ggg" << std::endl << "Is: " << t << std::endl << std::endl;
    }
}

TEST_CASE("Test Tree<struct>", "[Tree]"){
    SECTION("Test Tree()"){
        Person p1 = {"John", 24};
        Person p2 = {"Angie",37};
        Person p3 = {"Alex", 51};
        Person p4 = {"Jane", 83};
        Person p5 = {"Mary", 36};
        Person p6 = {"Ryan", 28};
        Person p7 = {"Caleb", 26};
        Tree<Person> t(p1);
        REQUIRE(t.search({"John", 24}) == true);
        REQUIRE(t.search({"Jason", 34}) == false);
    }
    

    SECTION("Test insertElement() / search()"){
        Person p1 = {"John", 24};
        Person p2 = {"Angie",37};
        Person p3 = {"Alex", 51};
        Person p4 = {"Jane", 83};
        Person p5 = {"Mary", 36};
        Person p6 = {"Ryan", 28};
        Person p7 = {"Caleb", 26};
        Tree<Person> t(p1);
        t.insertElement(p2);
        t.insertElement(p3);
        t.insertElement(p4);
        t.insertElement(p5);
        t.insertElement(p6);
        t.insertElement(p7);
        REQUIRE(t.search(p4) == true);
        REQUIRE(t.search(p7) == true);
        REQUIRE(t.search({"Jason", 63}) == false);
        REQUIRE(t.search({"James", 21}) == false);
    }

    SECTION("Testing deleteElement()"){
        Person p1 = {"John", 24};
        Person p2 = {"Caleb", 26};
        Person p3 = {"Ryan", 28};
        Person p4 = {"Mary", 36};
        Person p5 = {"Angie",37};
        Person p6 = {"Alex", 51};
        Person p7 = {"Jane", 83};
        

        Tree<Person> t(p4);
        t.insertElement(p2);
        t.insertElement(p6);
        t.insertElement(p1);
        t.insertElement(p3);
        t.insertElement(p5);
        t.insertElement(p7);

        // delete node with 2 children
        t.deleteElement(p6);
        REQUIRE(t.search(p6) == false);
        REQUIRE(t.search(p1) == true);
        REQUIRE(t.search(p2) == true);
        REQUIRE(t.search(p3) == true);
        REQUIRE(t.search(p4) == true);
        REQUIRE(t.search(p5) == true);
        REQUIRE(t.search(p7) == true);

        // delete root 
        t.deleteElement(p4);
        REQUIRE(t.search(p4) == false);
        REQUIRE(t.search(p1) == true);
        REQUIRE(t.search(p2) == true);
        REQUIRE(t.search(p3) == true);
        REQUIRE(t.search(p5) == true);
        REQUIRE(t.search(p7) == true);

        // delete node with only one child 
        Person p8 = {"Carol", 91};
        t.insertElement(p8);
        t.deleteElement(p7);
        REQUIRE(t.search(p7) == false);
        REQUIRE(t.search(p1) == true);
        REQUIRE(t.search(p2) == true);
        REQUIRE(t.search(p3) == true);
        REQUIRE(t.search(p5) == true);
        REQUIRE(t.search(p8) == true);
    }

    SECTION("Test overloaded operator"){
        Person p1 = {"John", 24};
        Person p2 = {"Caleb", 26};
        Person p3 = {"Ryan", 28};
        Person p4 = {"Mary", 36};
        Person p5 = {"Angie",37};
        Person p6 = {"Alex", 51};
        Person p7 = {"Jane", 83};
        

        Tree<Person> t(p4);
        t.insertElement(p2);
        t.insertElement(p6);
        t.insertElement(p1);
        t.insertElement(p3);
        t.insertElement(p5);
        t.insertElement(p7);
        std::cout << "Checking Tree<struct> operator output: " << std::endl;
        std::cout << "{John, 24}, {Caleb, 26}, {Ryan, 28}, {Mary, 36}, {Angie,37}, {Alex, 51}, {Jane, 83}" << std::endl << "Is: " << t << std::endl << std::endl;
    }
}

TEST_CASE("Test HashMap<int>", "[HashMap]"){
    SECTION("Test HashMap()"){
        std::vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        HashMap<int> h(vals, 9);
        REQUIRE(h.search(1) == true);
        REQUIRE(h.search(2) == true);
        REQUIRE(h.search(3) == true);
        REQUIRE(h.search(4) == true);
        REQUIRE(h.search(5) == true);
        REQUIRE(h.search(6) == true);
        REQUIRE(h.search(7) == true);
        REQUIRE(h.search(8) == true);
        REQUIRE(h.search(9) == true);
        REQUIRE(h.search(10) == false);
    }

    SECTION("Test resize by forcing collisions"){
        std::vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        HashMap<int> h(vals, 9);
        for(std::size_t i = 0; i < 100; i++){
            h.insertElement(i % 10);
        }
        REQUIRE(h.search(1) == true);
        REQUIRE(h.search(2) == true);
        REQUIRE(h.search(3) == true);
        REQUIRE(h.search(4) == true);
        REQUIRE(h.search(5) == true);
        REQUIRE(h.search(6) == true);
        REQUIRE(h.search(7) == true);
        REQUIRE(h.search(8) == true);
        REQUIRE(h.search(9) == true);
        REQUIRE(h.search(10) == false);
    }

    SECTION("Test delete"){
        std::vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        HashMap<int> h(vals, 9);
        REQUIRE(h.search(1) == true);
        REQUIRE(h.search(2) == true);
        REQUIRE(h.search(3) == true);
        REQUIRE(h.search(4) == true);
        REQUIRE(h.search(5) == true);
        REQUIRE(h.search(6) == true);
        REQUIRE(h.search(7) == true);
        REQUIRE(h.search(8) == true);
        REQUIRE(h.search(9) == true);
        REQUIRE(h.search(10) == false);

        h.deleteElement(1);
        h.deleteElement(2);
        h.deleteElement(3);
        REQUIRE(h.search(1) == false);
        REQUIRE(h.search(2) == false);
        REQUIRE(h.search(3) == false);
    }
}

TEST_CASE("Test HashMap<std::string>", "[HashMap]"){
    SECTION("Test Insert"){
        std::vector<std::string> vals = {"aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii"};
        HashMap<std::string> h(vals, 9);
        REQUIRE(h.search("aaa") == true);
        REQUIRE(h.search("bbb") == true);
        REQUIRE(h.search("ccc") == true);
        REQUIRE(h.search("ddd") == true);
        REQUIRE(h.search("eee") == true);
        REQUIRE(h.search("fff") == true);
        REQUIRE(h.search("ggg") == true);
        REQUIRE(h.search("hhh") == true);
        REQUIRE(h.search("iii") == true);
        REQUIRE(h.search("jjj") == false);
    }

    SECTION("Test resize by forcing collisions"){
        std::vector<std::string> vals = {"aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii"};
        HashMap<std::string> h(vals, 9);
        for(std::size_t i = 0; i < 100; i++){
            switch(i % 10){
                case 0: h.insertElement("aaa"); break;
                case 1: h.insertElement("bbb"); break;
                case 2: h.insertElement("ccc"); break;
                case 3: h.insertElement("ddd"); break;
                case 4: h.insertElement("eee"); break;
                case 5: h.insertElement("fff"); break;
                case 6: h.insertElement("ggg"); break;
                case 7: h.insertElement("hhh"); break;
                case 8: h.insertElement("iii"); break;
            }
        }
        REQUIRE(h.search("aaa") == true);
        REQUIRE(h.search("bbb") == true);
        REQUIRE(h.search("ccc") == true);
        REQUIRE(h.search("ddd") == true);
        REQUIRE(h.search("eee") == true);
        REQUIRE(h.search("fff") == true);
        REQUIRE(h.search("ggg") == true);
        REQUIRE(h.search("hhh") == true);
        REQUIRE(h.search("iii") == true);
        REQUIRE(h.search("jjj") == false);
    }

    SECTION("Test delete"){
        std::vector<std::string> vals = {"aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii"};
        HashMap<std::string> h(vals, 9);
        REQUIRE(h.search("aaa") == true);
        REQUIRE(h.search("bbb") == true);
        REQUIRE(h.search("ccc") == true);
        REQUIRE(h.search("ddd") == true);
        REQUIRE(h.search("eee") == true);
        REQUIRE(h.search("fff") == true);
        REQUIRE(h.search("ggg") == true);
        REQUIRE(h.search("hhh") == true);
        REQUIRE(h.search("iii") == true);
        REQUIRE(h.search("jjj") == false);

        h.deleteElement("aaa");
        h.deleteElement("bbb");
        h.deleteElement("ccc");
        REQUIRE(h.search("aaa") == false);
        REQUIRE(h.search("bbb") == false);
        REQUIRE(h.search("ccc") == false);
    }
}

TEST_CASE("Test HashMap<struct>", "[HashMap]"){
    SECTION("Test Insert"){
        Person p1 = {"John", 24};
        Person p2 = {"Caleb", 26};
        Person p3 = {"Ryan", 28};
        Person p4 = {"Mary", 36};
        Person p5 = {"Angie",37};
        Person p6 = {"Alex", 51};
        Person p7 = {"Jane", 83};
        std::vector<Person> vals = {p1, p2, p3, p4, p5, p6, p6, p7};
        HashMap<Person> h(vals, 9);
        REQUIRE(h.search(p1) == true);
        REQUIRE(h.search(p2) == true);
        REQUIRE(h.search(p3) == true);
        REQUIRE(h.search(p4) == true);
        REQUIRE(h.search(p5) == true);
        REQUIRE(h.search(p6) == true);
        REQUIRE(h.search(p7) == true);
        REQUIRE(h.search({"Jason", 63}) == false);
        REQUIRE(h.search({"James", 21}) == false);
    }

    SECTION("Test resize by forcing collisions"){
        Person p1 = {"John", 24};
        Person p2 = {"Caleb", 26};
        Person p3 = {"Ryan", 28};
        Person p4 = {"Mary", 36};
        Person p5 = {"Angie",37};
        Person p6 = {"Alex", 51};
        Person p7 = {"Jane", 83};
        std::vector<Person> vals = {p1, p2, p3, p4, p5, p6, p6, p7};
        HashMap<Person> h(vals, 9);
        for(std::size_t i = 0; i < 100; i++){
            switch(i % 10){
                case 0: h.insertElement(p1); break;
                case 1: h.insertElement(p2); break;
                case 2: h.insertElement(p3); break;
                case 3: h.insertElement(p4); break;
                case 4: h.insertElement(p5); break;
                case 5: h.insertElement(p6); break;
                case 6: h.insertElement(p7); break;
            }
        }
        REQUIRE(h.search(p1) == true);
        REQUIRE(h.search(p2) == true);
        REQUIRE(h.search(p3) == true);
        REQUIRE(h.search(p4) == true);
        REQUIRE(h.search(p5) == true);
        REQUIRE(h.search(p5) == true);
        REQUIRE(h.search(p6) == true);
        REQUIRE(h.search(p7) == true);
        REQUIRE(h.search({"Jason", 63}) == false);
        REQUIRE(h.search({"James", 21}) == false);
        
    }

    SECTION("Test delete"){
        Person p1 = {"John", 24};
        Person p2 = {"Caleb", 26};
        Person p3 = {"Ryan", 28};
        Person p4 = {"Mary", 36};
        Person p5 = {"Angie",37};
        Person p6 = {"Alex", 51};
        Person p7 = {"Jane", 83};
        std::vector<Person> vals = {p1, p2, p3, p4, p5, p6, p6, p7};
        HashMap<Person> h(vals, 9);
        REQUIRE(h.search(p1) == true);
        REQUIRE(h.search(p2) == true);
        REQUIRE(h.search(p3) == true);
        REQUIRE(h.search(p4) == true);
        REQUIRE(h.search(p5) == true);
        REQUIRE(h.search(p5) == true);
        REQUIRE(h.search(p6) == true);
        REQUIRE(h.search(p7) == true);
        REQUIRE(h.search({"Jason", 63}) == false);
        REQUIRE(h.search({"James", 21}) == false);

        h.deleteElement(p1);
        h.deleteElement(p2);
        h.deleteElement(p3);
        REQUIRE(h.search(p1) == false);
        REQUIRE(h.search(p2) == false);
        REQUIRE(h.search(p3) == false);
    }
}

TEST_CASE("TESTING LINEAR TIME COMPLEXITY", "[Linear Time Complexity]"){
    std::cout << std::endl << "TESTING LINEAR RUNTIMES" << std::endl;
    SECTION("Testing INT"){
        Linear<int> l;
        std::ifstream file("data/integers.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            int num = stoi(str);
            l.insertElement(num);
            
        }
        file.close();
        {
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(82272);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(43028);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(35149);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
        

    }
    SECTION("Testing decimails"){
        Linear<double> l;
        std::ifstream file("data/decimals.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            double num = stod(str);
            l.insertElement(num);
            
        }
        file.close();
        {
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(192.46);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(637.79);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(112.87);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
    }

    SECTION("Testing strings"){
        Linear<std::string> l;
        std::ifstream file("data/strings.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            if(str.back() == '\r'){
                str.pop_back();
            }
            l.insertElement(str);
            
        }
        file.close();
        {
            std::string find = "adpaehyyk";
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::string find = "dfbdfhrty";
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::string find = "vvcmaz";
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = l.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
    }

}

TEST_CASE("TESTING TREE TIME COMPLEXITY", "[Tree Time Complexity]"){
    std::cout << std::endl << "TESTING TREE RUNTIME" << std::endl;
    SECTION("Testing INT"){
        Tree<int> t;
        std::ifstream file("data/integers.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            int num = stoi(str);
            t.insertElement(num);
            
        }
        file.close();
        {
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(82272);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(43028);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(35149);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
        

    }
    SECTION("Testing decimails"){
        Tree<double> t;
        std::ifstream file("data/decimals.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            double num = stod(str);
            t.insertElement(num);
            
        }
        file.close();
        {
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(192.46);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(637.79);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(112.87);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
    }

    SECTION("Testing strings"){
        Tree<std::string> t;
        std::ifstream file("data/strings.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            if(str.back() == '\r'){
                str.pop_back();
            }
            t.insertElement(str);
            
        }
        file.close();
        {
            std::string find = "adpaehyyk";
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::string find = "dfbdfhrty";
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::string find = "vvcmaz";
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = t.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
    }

}

TEST_CASE("TESTING HASHMAP TIME COMPLEXITY", "[HashMap Time Complexity]"){
    std::cout << std::endl << "TESTING HASHMAP RUNTIME" << std::endl;
    SECTION("Testing INT"){
        HashMap<int> h;
        std::ifstream file("data/integers.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            int num = stoi(str);
            h.insertElement(num);
            
        }
        file.close();
        {
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(82272);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(43028);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(35149);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
        

    }
    SECTION("Testing decimails"){
        HashMap<double> h;
        std::ifstream file("data/decimals.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            double num = stod(str);
        h.insertElement(num);
            
        }
        file.close();
        {
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(192.46);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(637.79);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(112.87);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
    }

    SECTION("Testing strings"){
        HashMap<std::string> h;
        std::ifstream file("data/strings.csv");
        if(!file.is_open()){
            std::cerr << "file did not open.";
        }
        std::string str;
        while(getline(file, str)){
            if(str.back() == '\r'){
                str.pop_back();
            }
            h.insertElement(str);
            
        }
        file.close();
        {
            std::string find = "adpaehyyk";
            std::cout << "Search for first element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::string find = "dfbdfhrty";
            std::cout << "Search for last element took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }

        {
            std::string find = "vvcmaz";
            std::cout << "Search for element position 10000 took ";
            auto start = std::chrono::high_resolution_clock::now();
            bool found = h.search(find);
            REQUIRE(found == true);
            auto end = std::chrono::high_resolution_clock::now();
            auto time = std::chrono::duration<double, std::milli>(end - start);
            std::cout << time.count() << " milliseconds." << std::endl;
        }
    }

}
