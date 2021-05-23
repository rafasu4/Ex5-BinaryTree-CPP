#include "doctest.h"
#include <iostream>
#include "BinaryTree.hpp"
#include <array>
using namespace ariel;
using namespace std;

template<typename T>
bool hasNode(Node<T> n){
    return false;
}

TEST_CASE("add_root & add_left & add_right"){
    BinaryTree<int> i_tree; 

    SUBCASE("add_root"){
        CHECK_NOTHROW(i_tree.add_root(100));
        Node<int>* i_root = i_tree.getRoot();
        CHECK_EQ(i_root->data, 100);
    }
    SUBCASE("add_left & add_right"){
        i_tree.add_root(100);
        CHECK_NOTHROW(i_tree.add_right(100, 200).add_left(100, 50));
        CHECK_THROWS(i_tree.add_left(20,100));//can't add son to non-existing node
        CHECK_THROWS(i_tree.add_right(20,100));//can't add son to non-existing node
        Node<int>* i_root = i_tree.getRoot();
        // CHECK_EQ(i_root->left->data, 50);
        // CHECK_EQ(i_root->right->data, 200);
    }
}

TEST_CASE("begin"){
    BinaryTree<char> c_tree; 
    c_tree.add_root('H').add_right('H','R').add_right('R','S').add_left('S','M').add_left('M','L');
    CHECK_EQ(c_tree.getRoot()->data, 'H');//root data check
}

TEST_CASE("Pre-oreder Iterator"){
    char s[] = "Raphael";
    BinaryTree<char>c_tree;
    c_tree.add_root('R');
    Node<char>* temp = c_tree.getRoot();
    //adding "aph"
    for(unsigned long i = 1; i < 4; i++){
        char c = (char)s[i];
            c_tree.add_left(temp->data, c );
    }
    //adding "ael"
    for(unsigned long i = 4; i < 7; i++){
        char c = (char)s[i];
            c_tree.add_right(temp->data, c );
    }
    PostOrderIterator<char> it;
    CHECK_NOTHROW(it = c_tree.begin_postorder());
    for(int i = 0; i < 7; i++){
        CHECK_EQ(s[i], ++(*it));
        cout<<s[i];
    }
    cout<<endl;
}

TEST_CASE("In-order Iterator"){
    char s[] = "Raphael";
    BinaryTree<char>c_tree;
    c_tree.add_root('h');
    Node<char>* temp = c_tree.getRoot();
    //adding "Rap"
    for(unsigned long i = 0; i < 3; i++){
        char c = (char)s[i];
            c_tree.add_left(temp->data, c );
    }
    //adding ael
    for(unsigned long i = 4; i < 7; i++){
        char c = (char)s[i];
            c_tree.add_right(temp->data, c );
    }
    InOrderIterator<char> it;
    CHECK_NOTHROW(it = c_tree.begin_inorder());
    for(int i = 0; i < 7; i++){
        CHECK_EQ(s[i], ++(*it));
        cout<<s[i];
    }
    cout<<endl;
    //begin should have same effect
    cout<<"checkig begin and end: "<<endl;
    CHECK_NOTHROW(it = c_tree.begin());
    for(int i = 0; i < 7; i++){
        CHECK_EQ(s[i], ++(*it));
        cout<<s[i];
    }
    cout<<endl;
}

TEST_CASE("Post-order Iterator"){
    char s[] = "Raphael";
    BinaryTree<char>c_tree;
    c_tree.add_root('l');
    Node<char>* temp = c_tree.getRoot();
    //adding "Rap"
    for(unsigned long i = 0; i < 3; i++){
        char c = (char)s[i];
            c_tree.add_left(temp->data, c );
    }
    //adding "hae"
    for(unsigned long i = 4; i < 6; i++){
        char c = (char)s[i];
            c_tree.add_right(temp->data, c );
    }
    PostOrderIterator<char> it;
    CHECK_NOTHROW(it = c_tree.begin_postorder());
    for(int i = 0; i < 7; i++){
        CHECK_EQ(s[i], ++(*it));
        cout<<s[i];
    }
    cout<<endl;
}