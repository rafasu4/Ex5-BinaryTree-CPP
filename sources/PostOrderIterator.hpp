#include "Node.hpp"

namespace ariel{
    template<typename T>
    class PostOrderIterator {
                /*Pointer to the current element.*/
                 Node<T> *current;
            public:
                /*Default Constructor.*/
                PostOrderIterator(){}
                /*Constructor.*/
                PostOrderIterator(Node<T> *curr) {
                    this->current = curr;
                }
                /*Returns the data of current object.*/
                T &operator*(){
                    return current->data;
                }
                /*Returns current object.*/
                T* operator->() { return &(current->data); }
                /*Returns iterator and then increments data.*/
                PostOrderIterator &operator++() {
                    return *this;
                }
                /*Increments data and then returns iterator.*/
                PostOrderIterator operator++(int) {
                    PostOrderIterator tmp = *this;
                    return tmp;
                }
                /*Equal operator.*/
                bool operator==(const PostOrderIterator &rhs) const {
                    return current == rhs.current;
                }
                /*Inequal operator.*/
                bool operator!=(const PostOrderIterator &rhs) const {
                    return current != rhs.current;
                }
        
                //friend ostream &operator<<(ostream &os, const PostOrderIterator &p) { return os; }
        };
}