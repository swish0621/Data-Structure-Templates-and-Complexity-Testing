#include <iostream>

template<typename T, typename U>
class Tree {
    public:
        Tree(T val){}
        ~Tree(){}
        void insertElement(T val){}
        bool search(T val){}
        void deleteElement(T val){}
        std::ostream& operator<<(std::ostream& os const Tree<U> &t){}
};
