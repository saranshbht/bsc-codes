#include "treePrinter.cpp"

//BST Node class
template<typename T>
class TNode{
    T data;
    TNode *right,*left;
    public:
        TNode(T d = 0, TNode* l = 0, TNode* r = 0){
            data = d;
            left = l;
            right = r;
        }
        template<typename U> friend class BST;
};


//BST class
template<typename T>
class BST{
    TNode<T>* root;
    void insert(T, TNode<T>*&);
    void buildTree(TNode<T>*, BinTree<T>&);
        public :
        BST(){
            root = NULL;
        }

        void insert(T);
        void display();
};

//insert(Recursive)
template<typename T>
void BST<T> :: insert(T x, TNode<T>* &root){
        if(root == NULL){
                root = new TNode<T>(x);
                return;
        }
        if(x > root -> data)
                insert(x, root -> right);
        else
                insert(x, root -> left);
}

template<typename T>
void BST<T> :: insert(T x){
        insert(x, root);
}

template<typename T>
void BST<T> :: buildTree(TNode<T>* root, BinTree<T> &bt){
        if(root)
                bt.insert(root -> data);
        if(root -> left)
                buildTree(root -> left, bt);
        if(root -> right)
                buildTree(root -> right, bt);
}

template<typename T>
void BST<T> :: display(){
        BinTree<T> bt;
        buildTree(root, bt);
        bt.Dump();
        cout << "\n\n";
        bt.clear();
}

