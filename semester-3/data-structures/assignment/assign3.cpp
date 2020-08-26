#include "BSTClass.cpp"

int rootIndex(int *in, int start, int end, int root){
    for(int i = start; i <= end; i++){
        if(in[i] == root)
	    return i;
    }
    return -1;
}

void inpre(int *in, int *pre, int start, int end, BST<int> &bst){
    static int index = 0;
    if(start > end)
        return;
    int rIndex = rootIndex(in, start, end, pre[index]);

    bst.insert(pre[index++]);
    if(rIndex != start)
        inpre(in, pre, start, rIndex - 1, bst);
    if(rIndex != end)
        inpre(in, pre, rIndex + 1, end, bst);
}


void inpost(int *in, int *post, int start,int end, BST<int> &bst){

        static int index = end;
    if(start > end)
        return;
    int rIndex = rootIndex(in, start, end, post[index]);

    bst.insert(post[index--]);
    if(rIndex != end)
        inpost(in, post, rIndex + 1, end, bst);
    if(rIndex != start)
        inpost(in, post, start, rIndex - 1, bst);
}


int main (){
    int n, choice;
        cout << "\n1.Enter inorder and preorder\n2.Enter inorder and postorder\nEnter your choice: ";
        cin >> choice;
	while(choice != 1 && choice != 2){
	    cout << "Wrong Choice!!\nEnter your choice\n";
	    cin >> choice;
	}

        cout << "Enter number of nodes in tree: ";
        cin >> n;
	if(n < 0){
	    cout << "Number of nodes should be positive\n";
	    return - 1;
	}

	if(n == 0){
	    cout << "Empty Tree\n";
	    return 0;
	}

    	int inorder[n];
        cout << "Enter inorder traversal: ";
        for(int i = 0; i < n; i++)
      	    cin >> inorder[i];

	if(choice == 1){
	int preorder[n];
          cout << "Enter preorder traversal: ";
          for(int i = 0; i < n; i++)
              cin >> preorder[i];
          BST<int> bst;
          inpre(inorder, preorder, 0, n - 1, bst);
          bst.display();
        }


        else if(choice == 2){
          int postorder[n];
          cout << "Enter postorder traversal: ";
          for(int i = 0; i < n; i++)
              cin >> postorder[i];
          BST<int> bst;
          inpost(inorder, postorder, 0, n - 1, bst);
          bst.display();

        }
    return 0;
}

