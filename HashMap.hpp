#include <iostream>
#include <functional>
#include <stdexcept>

template<typename T>
class HashMap {
    public:
        HashMap(std::vector<T> vals, int size){
            num_buckets_ = size;
            std::vector<std::vector<T>> new_store_(num_buckets_);
            store_ = new_store_; 
            for(auto val : vals ){
                insertElement(val);
            }
        }

        // Input: a value to be put into the hashtable
        // Result: an integer with the bucket index 
        int hashKey(T val) const {
            std::hash<T> func;
            return func(val) % num_buckets_;
        }

        // Input: value to be inserted
        // Result: calls the hash function to get the index to insert the value into
        // if bucket reaches max size the hashtable is expanded and values are redistributed 
        void insertElement(T val){
            int key = hashKey(val);
            size_t size = store_[key].size();
            if(size > max_size_){
                Hashmap_Resize();
                key = hashKey(val);
            }
            store_[key].push_back(val);
        }

        // Input: value to be searched for
        // Result: gets the hash key and check the values in that bucket if found returns true else returns false
        bool search(T val) const {
            std::size_t idx = hashKey(val);
            for(auto i : store_[idx]){
                if(i == val){
                    return true;
                }
            }
            return false;
        }

        // Input: the value to be deleted
        // Result: finds the val and pops it from the internal vector
        void deleteElement(T val){
            std::size_t idx = hashKey(val);
            auto it = find(store_[idx].begin(), store_[idx].end(), val);
            if(it != store_[idx].end()){
                store_[idx].erase(it);
            }
        }

        void Hashmap_Resize(){}

        // template<typename U>
        // friend std::ostream& operator<<(std::ostream& os, const HashMap<U> &m);

        private:
            int num_buckets_;
            std::vector<std::vector<T>> store_;
            const int max_size_ = 5;
};
