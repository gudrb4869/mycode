/*
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

Node* insert(Node* node, int val){
    if(node == NULL){
        node = new Node();  // 기본 생성자
        node->key = val;
        node->left = node->right = NULL;
    }
    else if(val <= node->key){
        node->left = insert(node->left, val);
    }
    else{
        node->right = insert(node->right, val);
    }
    return node;
}

void postorder(Node* node){
    if(node->left != NULL) postorder(node->left);
    if(node->right != NULL) postorder(node->right);
    cout << node->key << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* root = NULL;
    int val;
    while(cin>>val){
        if(val == EOF) break;
        root = insert(root, val);
    }
    postorder(root);
    return 0;
}
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int value, depth;
    Node *left, *right;
    Node(const int& _value) : value(_value), depth(0), left(NULL), right(NULL) { }
    void Setleft(Node* newleft) { left = newleft; }
    void Setright(Node* newright) { right = newright; }
};

Node* insert(Node* root, Node* node){
    if(root == NULL) return node;
    if(node->value < root->value)
        root->Setleft(insert(root->left, node));
    else
        root->Setright(insert(root->right, node));
    return root;
}

void printNode(Node* node){
    if(node->left != NULL)
        printNode(node->left);
    if(node->right != NULL)
        printNode(node->right);
    cout << node->value << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int data;
    Node* Nodes = NULL;
    while(cin>>data){
        if(cin.eof()) break;
        Nodes = insert(Nodes, new Node(data));
    }
    printNode(Nodes);
    return 0;
}