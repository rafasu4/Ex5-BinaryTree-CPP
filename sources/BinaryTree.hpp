#pragma once
namespace ariel {
    template<typename T>
    class BinaryTree {
    private:
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
            friend class PostorderIterator;
        };
    public:
        //class BinaryTree//
        Node *root;
        /*Default constructor.*/
         BinaryTree(){root = new Node();}
        /*Destructor.*/
        ~BinaryTree(){delete[] root;} 

        class InorderIterator {
          

        private:
            Node *current;
        public:
            InorderIterator(){}
            InorderIterator(Node *curr) {
                this->current = curr;
            }

            T &operator*() const {
                return current->data;
            }

            T *operator->() const {
                return &(current);
            }

            InorderIterator &operator++() {
                return *this;
            }

            const InorderIterator operator++(int) {
                InorderIterator tmp = *this;
                return tmp;
            }

            bool operator==(const InorderIterator &rhs) const {
                return current == rhs.current;
            }

            bool operator!=(const InorderIterator &rhs) const {
                return current != rhs.current;
            }
        };
        //end class InorderIterator//

        InorderIterator begin_inorder() {
            return InorderIterator();
        }

        InorderIterator end_inorder() {
            return InorderIterator();
        }

        class PreOrederIterator {
                 private:
            Node *current;
            public:
            PreOrederIterator(){}
            PreOrederIterator(Node& n){current = &n; }
            PreOrederIterator &operator++() { return *this;}
            PreOrederIterator operator++(int junk) {return this; }
            PreOrederIterator& operator*() { return *this; }
            T* operator->() { return &this; }
            bool operator==(const PreOrederIterator& other) { return true; }
            bool operator!=(const PreOrederIterator& other) { return true; }
            friend ostream &operator<<(ostream &os, const PreOrederIterator &p) { return os; }
        };

        PreOrederIterator begin_preorder() {
            return PreOrederIterator();
        }

        PreOrederIterator end_preorder() {
            return PreOrederIterator();
        }

        class InOrderIterator{
            Node* current;
        
        public:
            InOrderIterator(){}
            InOrderIterator(Node& n){current = &n; }
            InOrderIterator operator++() { return this;}
            InOrderIterator operator++(int junk) {return *this; }
            InOrderIterator& operator*() { return *this; }
            InOrderIterator* operator->() { return this; }
            bool operator==(const InOrderIterator& other) { return true; }
            bool operator!=(const InOrderIterator& other) { return true; }
            friend ostream &operator<<(ostream &os, const InOrderIterator &p) { return os; }
        };

            class PostorderIterator {
                 private:
            Node *current;
            public:
            PostorderIterator(){}
            PostorderIterator(Node& n){current = &n; }
            PostorderIterator &operator++() { return *this;}
            PostorderIterator operator++(int junk) {return this; }
            PostorderIterator& operator*() { return *this; }
            T* operator->() { return &(current->data); }
            bool operator==(const PostorderIterator& other) { return true; }
            bool operator!=(const PostorderIterator& other) { return true; }
            friend ostream &operator<<(ostream &os, const PostorderIterator &p) { return os; }
        };


        PostorderIterator begin_postorder() {
            return PostorderIterator();
        }

        PostorderIterator end_postorder() {
            return PostorderIterator();
        }

        BinaryTree<T>& add_root(const T& t){
            delete[] root;
            root = new Node(t);
            return *this;}
        /*Adds left son to the first argument. If one already exist, replaces it.*/
        BinaryTree& add_left(T father, T son){return *this;}
        /*Adds right son to the first argument. If one already exist, replaces it.*/
        BinaryTree& add_right(T father, T son){return *this;}
        /*Prints this tree.*/
        friend ostream &operator<<(ostream &os, const BinaryTree &tree) { return os; }
        InorderIterator begin(){return InorderIterator(root);}
        InorderIterator end(){return InorderIterator();}
    };
}