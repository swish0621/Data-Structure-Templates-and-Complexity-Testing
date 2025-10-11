#include <iostream>
#include <functional>

template<typename T, typename U>
class HashMap {
    public:
        HashMap(std::vector<T> cals, inst size){}
        int hashKey(T val){}
        void insertElement(T val){}
        bool search(T val){}
        void deleteElement(T val){}
        std::ostream& operator<<(std::ostream& os, const HashMap<U> &m){}
};
