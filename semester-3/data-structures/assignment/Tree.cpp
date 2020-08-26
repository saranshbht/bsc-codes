#include<bits/stdc++.h>
using namespace std;

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

template<typename T>
class BST{
    TNode<T>* root;
    void preOrder(TNode<T>*);
    void postOrder(TNode<T>*);
    void inOrder(TNode<T>*);
    void insert(T, TNode<T>*&);
    TNode<T>* search(T, TNode<T>*);
    int height(TNode<T>*);
    int countNodes(TNode<T>*);
    int countLeaves(TNode<T>*);
	public :
        BST(){
            root = NULL;
        }
        void preOrder();
        void postOrder();
        void inOrder();
        void levelOrder();
        void insert(T);
        TNode<T>* search(T);
        int height();
        int countNodes();
        int countLeaves();
        void deleteNode(T);
};

//preOrder Traversal
template<typename T>
void BST<T> :: preOrder(TNode<T>* root){
    if(!root)
        return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

template<typename T>
void BST<T> :: preOrder(){
    if(!root)
        cout << "Tree is Empty!!";
    else
        preOrder(root);
    cout << endl;
}

//postOrder Traversal
template<typename T>
void BST<T> :: postOrder(TNode<T>* root){
    if(!root)
        return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

template<typename T>
void BST<T> :: postOrder(){
    if(!root)
        cout << "Tree is Empty!!";
    else
        postOrder(root);
    cout << endl;
}

//inOrder Traversal
template<typename T>
void BST<T> :: inOrder(TNode<T>* root){
    if(!root)
        return;
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

template<typename T>
void BST<T> :: inOrder(){
    if(!root)
        cout << "Tree is Empty!!";
    else
        inOrder(root);
    cout << endl;
}

//levelOrder Traversal
template<typename T>
void BST<T> :: levelOrder(){
    if(!root)
        cout << "Tree is Empty!!";
    else{
        queue<TNode<T>*> q;
        q.push(root);
        while(!q.empty()){
            cout << q.front() -> data << " ";
            if(q.front() -> left)
                q.push(q.front() -> left);
            if(q.front() -> right)
                q.push(q.front() -> right);
            q.pop();
        }
    }
    cout << endl;
}

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

//count nodes
template<typename T>
int BST<T> :: countNodes(TNode<T>* root){
	if(root == NULL)
		return 0;
	return 1 + countNodes(root -> right) + countNodes(root -> left);
}

template<typename T>
int BST<T> :: countNodes(){
	return countNodes(root);
}

//count leaves
template<typename T>
int BST<T> :: countLeaves(TNode<T>* root){
	if(root == NULL)
		return 0;
	if(root -> left == NULL && root -> right == NULL)
		return 1;
	return countLeaves(root -> left) + countLeaves(root -> right);
}

template<typename T>
int BST<T> :: countLeaves(){
	return countLeaves(root);
}

//search(Recursive)
TNode<T>* search(T x, TNode<T>* root){										
	if(root == NULL)
		return NULL;
	if(root -> data == x)
		return root;
	if(x > root -> data)
		return search(x, root -> right);
	else
		return search(x, root -> left);
}

TNode<T> *search(T x){
	return search(x, root);
}
//insert(Iterative)
//template<typename T>
//void BST<T> :: insert(T x){
//    TNode<T> *temp = new TNode<T>(x);
//    if(!root)
//        root = temp;
//    else{
//        TNode<T> *p = root, *prev = NULL;
//        while(p){
//            prev = p;
//            if(x > p -> data)
//                p = p -> right;
//            else
//                p = p -> left;
//        }
//        if(x > prev -> data)
//            prev -> right = temp;
//        else
//            prev -> left = temp;
//    }
//}


//count non - leaves
template<typename T>
int BST<T> :: countNonLeaves(TNode<T>* root){
	if(root == NULL || root -> left == NULL && root -> right == NULL)
		return 0;
	return 1 + countNonLeaves(root -> left) + countNonLeaves(root -> right);
}

template<typename T>
int BST<T> :: countNonLeaves(){
	return countNonLeaves(root);
}


//template<typename T>
void BST<T> :: getParent(T x, TNode<T> *&prev, TNode<T> *&p){
	while(p && p -> data != x){
		prev = p;
		if(x > p -> data)
			p = p -> right;
		else
			p = p -> left;
	}
}

void deleteLeaf(TNode<T> *&prev, TNode<T> *&p){
	if(prev -> right == p)
		prev -> right = NULL;
	else
		prev -> left = NULL;
	delete p;
}

void deleteOneChildLeaf(TNode<T> *&prev, TNode<T> *&p){
	if(p -> right == NULL){
		if(prev -> right == p)
			prev -> right = p -> left;
		else
			prev -> left = p -> left;
	}
		
	else{
		if(prev -> right == p)
			prev -> right == p -> right;
		else
			prev -> left = p -> right;
	}
	delete p;
}

void deleteByCopy(TNode<T> *&prev, TNode<T> *&p){
		
}

//delete a node
template<typename T>
void BST<T> :: deleteNode(T x){
	TNode<T> *p = root;
	TNode<T> *prev = NULL;
	getParent(x, prev, p);
	
	if(!p)
		throw "Element not present in tree";
	else{
		if(p -> right == NULL && p -> left == NULL)
			deleteLeaf(prev, p);
		else if(p -> right == NULL || p -> left == NULL)
			deleteOneChildLeaf(prev, p);
		else
			deleteByCopy(prev, p);
	}
}

//Driver Code
int main() {
  BST<int> bst;
	int choice;
	bool quit = false;
	int elem;
	while(true){
		cout << "\n1.Insert\n2.Pre-Order Traversal\n3.Post-Order Traversal\n4.In-Order Traversal\n5.Level-Order Traversal\n0.Exit\n\n";
		cout << "Enter your choice: ";
		cin >> choice;

	try{
		switch(choice){
			case 1: cout << "Enter element to be inserted: ";
					cin >> elem;
				  bst.insert(elem);
					break;

			case 2: bst.preOrder();
					break;

			case 3: bst.postOrder();
					break;

			case 4: bst.inOrder();
					break;

			case 5: bst.levelOrder();
					break;

			case 0: quit = true;
					break;

			default: cout << "Wrong choice" << endl;
		}
		if(quit)
			break;
	}
	catch(const char *s){
		cout << s << endl;
	}
	}

    return 0;
}
