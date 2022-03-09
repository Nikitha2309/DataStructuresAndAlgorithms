#include <iostream>
#include <queue>
using namespace std;

/**** Tree Node Struct *****/
struct Node {
    string val;
    Node* children[10];

    Node(): val(0) {
        for(int i=0; i<10; i++) children[i] = NULL;
    }
    Node(string x): val(x) {
        for(int i=0; i<10; i++) children[i] = NULL;
    }
};

// Function to Print
void print(Node* root) {
    if(!root)
        return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            Node* curr = q.front();
            q.pop();

            for(Node* nd: curr->children) {
                if(nd) {
                    q.push(nd);
                }
            }

            cout << curr->val << " ";                    
        }
        cout << "\n";
    }
}

/**** Main Function *****/
int main() {
    // root
    Node* root = new Node("IIT-G");

    // Departments
    root->children[0] = new Node("Electrical");
    root->children[1] = new Node("Mathematics");
    root->children[2] = new Node("Computer_Science");

    // Degrees
    root->children[0]->children[0] = new Node("EEE");
    root->children[0]->children[1] = new Node("ECE");
    root->children[1]->children[0] = new Node("MnC");
    root->children[2]->children[0] = new Node("CSE");
    Node* ece = root->children[0]->children[1];
	Node* eee = root->children[0]->children[0];

    // Students
    ece->children[0] = new Node("Neha");    
    ece->children[1] = new Node("Nikitha");
    ece->children[2] = new Node("Niharika");
	
    eee->children[0] = new Node("Preetham");
    eee->children[1] = new Node("Koushik");

    // Favourite subjects & topics
    ece->children[0]->children[0] = new Node("EE332");
    ece->children[0]->children[0]->children[0] = new Node("Source_coding");
    ece->children[0]->children[0]->children[1] = new Node("Huffman_Coding");
    ece->children[0]->children[1] = new Node("MA101");
    ece->children[0]->children[1]->children[0] = new Node("Convergence");
    ece->children[0]->children[1]->children[1] = new Node("Differentiability");

    ece->children[1]->children[0] = new Node("DSA");
    ece->children[1]->children[0]->children[0] = new Node("Array");
    ece->children[1]->children[0]->children[1] = new Node("Sorting");
    ece->children[1]->children[1] = new Node("CN");
    ece->children[1]->children[1]->children[0] = new Node("Application_Layer");
    ece->children[1]->children[1]->children[1] = new Node("Datalink_Layer");

    ece->children[2]->children[0] = new Node("DSA");
    ece->children[2]->children[0]->children[0] = new Node("Array");
    ece->children[2]->children[0]->children[1] = new Node("Pointer");
    ece->children[2]->children[1] = new Node("ACS");
    ece->children[2]->children[1]->children[0] = new Node("Routh_Array");
    ece->children[2]->children[1]->children[1] = new Node("Jury_Stability_Criteria");
    
    eee->children[0]->children[0] = new Node("DSA");
    eee->children[0]->children[0]->children[0] = new Node("HashTables");
    eee->children[0]->children[0]->children[1] = new Node("Trees");
    eee->children[0]->children[1] = new Node("CH419");
    eee->children[0]->children[1]->children[0] = new Node("Energy_Types");
    eee->children[0]->children[1]->children[1] = new Node("Organic_Compounds");

    eee->children[1]->children[0] = new Node("DSA");
    eee->children[1]->children[0]->children[0] = new Node("LinkedLists");
    eee->children[1]->children[0]->children[1] = new Node("Graphs");
    eee->children[1]->children[1] = new Node("Probability");
    eee->children[1]->children[1]->children[0] = new Node("Random Processes");
    eee->children[1]->children[1]->children[1] = new Node("Bayes Theorem");

    // Printing
    print(root);
}