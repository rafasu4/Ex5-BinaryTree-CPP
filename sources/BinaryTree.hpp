#pragma once
#include "Node.hpp"
#include "PreOrederIterator.hpp"
#include "InOrderIterator.hpp"
#include "PostOrderIterator.hpp"
namespace ariel {
    template<typename T>
    class BinaryTree {
    private:
        
    public:
        //class BinaryTree//
        Node<T> *root;
        /*Default constructor.*/
         BinaryTree(){root = new Node<T>();}
        /*Destructor.*/
       // ~BinaryTree(){delete[] root;} 
        /*Adds left son to the first argument. If one already exist, replaces it.*/
        BinaryTree& add_left(T father, T son){return *this;}
        /*Adds right son to the first argument. If one already exist, replaces it.*/
        BinaryTree& add_right(T father, T son){return *this;}

        PreOrederIterator<T> begin_preorder() {
            return PreOrederIterator<T>();
        }

        PreOrederIterator<T> end_preorder() {
            return PreOrederIterator<T>();
        }

        InOrderIterator<T> begin_inorder() {
            return InOrderIterator<T>();
        }

        InOrderIterator<T> end_inorder() {
            return InOrderIterator<T>();
        }

        PostOrderIterator<T> begin_postorder() {
            return PostOrderIterator<T>();
        }

        PostOrderIterator<T> end_postorder() {
            return PostOrderIterator<T>();
        }

        BinaryTree<T>& add_root(const T& t){
            //delete[] root;
            root = new Node<T>(t);
            return *this;}
        
        InOrderIterator<T> begin(){return InOrderIterator<T>(root);}
        InOrderIterator<T> end(){return InOrderIterator<T>();}
      
        /*Prints this tree.*/
        friend ostream &operator<<(ostream &os, const BinaryTree &tree) { return os; }

    };
}