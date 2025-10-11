#include <vector>
#include <iostream>

template<typename T, typename U>
class Linear {
    public:
        Linear(){}
        void insertElement(T val){}
        T getElementAtIndex(int index){}
        bool search(T val){}
        void deleteElement(T val){}
        std::ostream& operator<<(std::ostream& os, const Linear<U> &l){}
};
