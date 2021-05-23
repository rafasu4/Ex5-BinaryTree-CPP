#pragma once
namespace ariel{
    template<typename T>
     struct Node
        {
            T data;
            Node *root;
            Node *right;
            Node *left;
        
            Node(){right = left = nullptr;}
            Node(const T &data) : data(data) {}
            void add_leftN (Node &other){left = &other;}
            void add_rightN (Node &other){right = &other;}
            
        };
}