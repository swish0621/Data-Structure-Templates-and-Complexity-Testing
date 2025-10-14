#include <iostream>
#include <stdexcept>

template<typename T>
class Tree {
        private: 
            struct Node{
                T value;
                Node* right = nullptr;
                Node* left = nullptr;
                Node(T val) : value(val){}
            };
            Node* root;

            // Helper funciton to delete
            // Input: the Node* to begin recursive deletion from 
            // Result: deleteTreeHelper will traverse the tree and delete all nodes from bottom to input Node*
            void deleteTreeHelper(Node* cursor){
                if(!cursor){
                    return;
                }
                deleteTreeHelper(cursor->left);
                deleteTreeHelper(cursor->right);
                delete cursor;
            }

            // Helper function to insertElement
            // Input: root of the tree, value to be inserted
            // Result: traverses tree recursively to find approriate position / creates a new node at that position 
            void insertHelper(Node* cursor, T val){
                if(cursor->value == val){
                    return;
                }
                if(cursor->value > val){
                    if(cursor->left == nullptr){
                        cursor->left = new Node(val);
                    }
                    else {
                        insertHelper(cursor->left, val);
                    }
                }
                else {
                    if(cursor->right == nullptr){
                        cursor->right = new Node(val);
                    }
                    else {
                        insertHelper(cursor->right, val);
                    }
                }
            }

            // Helper function to search
            // Input: root Node* of the tree and the value that is being searched for
            // Result: if the value is found true is returned, else false
            bool searchHelper(Node* cursor, T val) const {
                if(cursor == nullptr){
                    return false;
                }
                if(cursor->value == val){
                    return true;
                }
                if(cursor->value > val){
                    return searchHelper(cursor->left, val);
                }
                else {
                    return searchHelper(cursor->right, val);
                }
            }

            // delete helper searches recursively for the value and removes it handling 3 possibly cases (Node w/ 2 children, Node w/ 1 child, Node w/ no children)
            // Input: root node by reference because changes will need to apply to original and the value to be deleted
            // Result: will delete the node holding the value input and maintain tree structure after deletion 
            void deleteHelper(Node*& cursor, T val){
                if(cursor->value == val){
                    // no children case 
                    if(cursor->left == nullptr && cursor->right == nullptr){
                        delete cursor;
                        cursor = nullptr;
                    }
                    // one child case
                    else if(cursor->left == nullptr){
                        Node* temp = cursor;
                        cursor = cursor->right;
                        delete temp;
                    }

                    // one child case
                    else if(cursor->right == nullptr){
                        Node* temp = cursor;
                        cursor = cursor->left;
                        delete temp;
                    }
                    // 2 children case 
                    else {
                        Node* successor = cursor->right;
                        while(successor->left != nullptr){
                            successor = successor->left;
                        }
                        cursor->value = successor->value;
                        deleteHelper(cursor->right, successor->value);
                    }
                }
                else {
                    if(cursor->value > val){
                        deleteHelper(cursor->left, val);
                    }
                    else {
                        deleteHelper(cursor->right, val);
                    }
                }
            }

        public:
        // Input: value to be root node of tree
        // Result: Tree will be created and root node will hold value of input 
        // private member root is initialized to the Node* created
        Tree(T val){
            root = new Node(val);
        }
        // only responsible for calling the deleteHelper 
        ~Tree(){
            deleteTreeHelper(root);
        }

        // creates a copy of root Node* and calls InsertHelper
        void insertElement(T val){
            insertHelper(root, val);
            return;
        }

        // only calls search helper, see in private
        bool search(T val) const {
            return searchHelper(root, val);
        }

        // deleteElement calls search to verify the element is in the tree 
        // if the value is present it calls deleteHelper
        void deleteElement(T val){
            if(search(val)){
                deleteHelper(root, val);
            }
            else {
                throw std::runtime_error("Value not in tree.");
            }
        }

        // traverses the tree in order to print the value of each element 
        void getInOrder(Node* cursor, std::vector<T> &stream) const {
            if(cursor == nullptr){
                return;
            }
            getInOrder(cursor->left, stream);
            stream.push_back(cursor->value);
            getInOrder(cursor->right, stream);
        }

        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Tree<U> &t);
};

// overloaded operator to print the tree structure in order
template<typename U>
std::ostream& operator<<(std::ostream& os, const Tree<U> &t){
    std::vector<U> stream; 
    t.getInOrder(t.root, stream);
    for(auto i = stream.begin(); i != stream.end(); i++){
        os << *i;
        if(std::next(i) != stream.end()){
            os << ", ";
        }
    }
    return os;
}

