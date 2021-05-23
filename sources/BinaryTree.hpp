#pragma once
#include "Node.hpp"
#include "PreOrederIterator.hpp"
#include "InOrderIterator.hpp"
#include "PostOrderIterator.hpp"

using namespace std;

namespace ariel {
    template<typename T>
    class BinaryTree {
        Node<T> *root;

    public:
        
        /*Default constructor.*/
         BinaryTree(){root = new Node<T>();}
        /*Destructor.*/
        ~BinaryTree(){root->~Node();} 
        /*Adds left son to the first argument. If one already exist, replaces it.*/
        BinaryTree& add_left(T father, T son){
            // Node<T> f(father);
            // root = &f;
            // Node<T> s(son);
            // root->add_leftN(s);
            return *this;}
        /*Adds right son to the first argument. If one already exist, replaces it.*/
        BinaryTree& add_right(T father, T son){
            // Node<T> f(father);
            // root = &f;
            // Node<T> s(son);
            // root->add_rightN(s);
            return *this;}

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
            root->~Node();
            root = new Node<T>(t);
            return *this;}
        
        InOrderIterator<T> begin(){return InOrderIterator<T>(root);}
        InOrderIterator<T> end(){return InOrderIterator<T>();}
        Node<T>* getRoot(){return root;}
        /*Prints this tree.*/
        friend ostream &operator<<(ostream &os, const BinaryTree &tree) { return os; }
        
    };
}