/*
Name: Nicholas Swisher
Purpose: Define a template for a creating a Linear data type
*/
#include <vector>
#include <iostream>
#include <stdexcept>

template<typename T>
class Linear {
    public:
        // Input: value to be stored
        // Result: the value is appended to the end of the store
        void insertElement(T val){ store.push_back(val); }

        // Input: an Integer representing the index to get the value from (0 based) 
        // Result: returns the value that is stored at that index if the index exists 
        T getElementAtIndex(int index) const {
            if(store.empty() || index >= store.size()){
                throw std::runtime_error("Store is empty or invalid index.");
            }
            else{
                return store.at(index); 
            }
        }

        // Input: the value to be searched for
        // Result: returns true if the value is in the store, false otherwise
        bool search(T val) const {
            std::size_t size = store.size();
            for(std::size_t i = 0; i < size; i++){
                if(store.at(i) == val){
                    return true;
                }
            }
            return false;
        }

        // Input: the value to be deleted from the store
        // Result: the value is removed and all other values are shifted up by one
        void deleteElement(T val){
            if(!search(val) || store.empty()){
                return; 
            }
            std::size_t size = store.size();
            for( std::size_t i = 0; i < size; i++){
                if(store.at(i) == val){
                    for(std::size_t j = i; j < size - 1; j++){
                        store.at(j) = store.at(j+1);
                    }
                store.pop_back();
                break;
                }
            }
        }

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Linear<U> &l);

    private:
        std::vector<T> store; 
};

// iterates over the store and displays the value at each index 
template<typename U>
std::ostream& operator<<(std::ostream& os, const Linear<U> &l){
    std::size_t size = l.store.size();
    if(size == 0){
        return os;
    }
    for(std::size_t i = 0; i < size - 1; i++){
        os << l.getElementAtIndex(i) << ", ";
    }
    os << l.getElementAtIndex(size - 1);
    return os;
};
