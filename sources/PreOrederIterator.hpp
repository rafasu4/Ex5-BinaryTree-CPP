#include "Node.hpp"
namespace ariel{
    template<typename T>
    class PreOrederIterator {
                /*Pointer to the current element.*/
                Node<T> *current;
            public:
                /*Default Constructor.*/
                PreOrederIterator(){}
                /*Constructor.*/
                PreOrederIterator(Node<T> *curr) {
                    this->current = curr;
                }
                /*Returns the data of current object.*/
                T &operator*(){
                    return current->data;
                }
                T* operator->() { return &this; }
                /*Returns iterator and then increments data.*/
                PreOrederIterator &operator++() {
                    return *this;
                }
                /*Increments data and then returns iterator.*/
                PreOrederIterator operator++(int) {
                    PreOrederIterator tmp = *this;
                    return tmp;
                }
                /*Equal operator.*/
                bool operator==(const PreOrederIterator &rhs) const {
                    return current == rhs.current;
                }
                /*Inequal operator.*/
                bool operator!=(const PreOrederIterator &rhs) const {
                    return current != rhs.current;
                }
                // friend ostream &operator<<(ostream &os, const PreOrederIterator &p) { return os; }
        };
}