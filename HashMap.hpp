#include <iostream>
#include <functional>

template<typename T>
class HashMap {
    public:
        HashMap(std::vector<T> cals, int size){}

        // Input: a value to be put into the hashtable
        // Result: an integer with the bucket index 
        int hashKey(T val){
            std::hash<T> func;
            std::size_t index = func(val);
            return index;
        }

        // Input: value to be inserted
        // Result: calls the hash function to get the index to insert the value into
        // if bucket reaches max size the hashtable is expanded and values are redistributed 
        void insertElement(T val){
            int key = hashKey(val);
            size_t size = store[key].size();
            if(size > max_size_){
                resize();
                key = hashKey(val);
            }
            store[key].push_back(val);
        }

        bool search(T val){}
        void deleteElement(T val){}
        void resize(){}

        // template<typename U>
        // friend std::ostream& operator<<(std::ostream& os, const HashMap<U> &m);

        private:
            int num_buckets_;
            std::vector<std::vector<T>> store_;
            const int max_size = 10;
};
