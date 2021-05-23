#include "Node.hpp"

namespace ariel{
    template<typename T>
    class InOrderIterator {
        private:
            /*Pointer to the current element.*/
            Node<T> *current;
        public:
            /*Default Constructor.*/
            InOrderIterator(){}
            /*Constructor.*/
            InOrderIterator(Node<T> *curr) {
                this->current = curr;
            }
            /*Returns the data of current object.*/
            T &operator*(){
                return current->data;
            }
            /*Returns current object.*/
            T *operator->(){
                return &(current);
            }
            /*Returns iterator and then increments data.*/
            InOrderIterator &operator++() {
                return *this;
            }
            /*Increments data and then returns iterator.*/
            InOrderIterator operator++(int) {
                InOrderIterator tmp = *this;
                return tmp;
            }
            /*Equal operator.*/
            bool operator==(const InOrderIterator &rhs) const {
                return current == rhs.current;
            }
            /*Inequal operator.*/
            bool operator!=(const InOrderIterator &rhs) const {
                return current != rhs.current;
            }
        };
}