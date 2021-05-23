#pragma once
namespace ariel{
    template<typename T>
     struct Node
        {
            T data;
            Node *root;
            Node *right;
            Node *left;

            Node(){}
            Node(const T &data) : data(data) {}
            void add_left (const Node &father, const Node &){}
            void add_right (const Node &father, const Node &){}
            
        };
}