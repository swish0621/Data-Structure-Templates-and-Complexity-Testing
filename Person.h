/*
Name: Nicholas Swisher
Purpose: Create a custom data type to test the templated data structure
*/
#include <string>
#include <iostream>

struct Person{
    std::string name;
    int age;

    bool operator==(const Person& other ) const {
        if(this->name == other.name && this->age == other.age){
            return true;
        }
        else {
            return false;
        }
    }
    bool operator>(const Person& other ) const {
        if(this->age > other.age){
            return true;
        }
        else {
            return false;
        }
    }
    bool operator<(const Person& other ) const {
        if(this->age < other.age){
            return true;
        }
        else {
            return false;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& p){
        os << "{" << p.name << ", " << p.age << "}";
        return os;
    }
};

namespace std{
        template<>
        struct hash<Person>{
            std::size_t operator()(const Person& p) const {
                return std::hash<std::string>()(p.name) + std::hash<int>()(p.age);
            }
        };
    }
