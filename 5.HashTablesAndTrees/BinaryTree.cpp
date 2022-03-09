#include <iostream>
#include <queue>
using namespace std;

/**** Node Struct *****/
struct Node {
    int val;
    Node* left, *right;

    Node(): val(0), left(nullptr), right(nullptr) {}
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

/**** Binary Search Tree Class *****/
class BST {
    Node* root;
public:
    BST(): root(nullptr) {}

    // Insert an element
    Node* insertHelper(int x, Node* curr) {
        if(curr == NULL)
            return new Node(x);
        
        if(x < curr->val) {
            curr->left = insertHelper(x, curr->left);
        }
        else {
            curr->right = insertHelper(x, curr->right);
        }
        return curr;
    }
    
    void insert(int x) {
        root = insertHelper(x, root);
    }

    // Print Tree
    void print() {
        if(!root)
            return;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                Node* curr = q.front();
                q.pop();

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);

                cout << curr->val << " ";                    
            }
            cout << "\n";
        }
    }
};

int main() {
    int arr[] = {27, 32, 56, 12, 45, 81, 23, 16, 72, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    BST my_bst = BST();

    for(int i=0; i<size; i++) {
        my_bst.insert(arr[i]);
    }

    my_bst.print();
	
}

