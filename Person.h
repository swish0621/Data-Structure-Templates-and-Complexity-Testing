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

    friend std::ostream& operator<<(std::ostream& os, const Person& p){
        os << "{" << p.name << ", " << p.age << "}";
        return os;
    }
};

