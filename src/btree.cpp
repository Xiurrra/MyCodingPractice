#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};  
class BTree {
private:
    Node* root;
public:
    BTree() {
        root = NULL;
    }
    void insert(int val) {
        if (root == NULL) {
            root = new Node(val);
            return;
        }
        Node* curr = root;
        while (true) {
            if (val < curr->data) {
                if (curr->left == NULL) {
                    curr->left = new Node(val);
                    break;
                }
                curr = curr->left;
            }
            else {
                if (curr->right == NULL) {
                    curr->right = new Node(val);
                    break;
                }
                curr = curr->right;
            }
        }
    }

    void print() {
        printHelper(root);
    }
    void printHelper(Node* curr) {
        if (curr == NULL) {
            return;
        }
        printHelper(curr->left);
        cout << curr->data << " ";
        printHelper(curr->right);
    }

    void inorder() {
        inorderHelper(root);
    }
    void inorderHelper(Node* curr) {
        if (curr == NULL) {
            return;
        }
        inorderHelper(curr->left);
        cout << curr->data << " ";
        inorderHelper(curr->right);
    }
    void preorder() {
        preorderHelper(root);
    }
    void preorderHelper(Node* curr) {
        if (curr == NULL) {
            return;
        }
        cout << curr->data << " ";
        preorderHelper(curr->left);
        preorderHelper(curr->right);
    }
    void postorder() {
        postorderHelper(root);
    }
    void postorderHelper(Node* curr) {
        if (curr == NULL) {
            return;
        }
        postorderHelper(curr->left);
        postorderHelper(curr->right);
        cout << curr->data << " ";
    }
    void inorderUnCur(){
        stack<Node*> s;
        Node* curr = root;
        while(curr != NULL || !s.empty()){
            if(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            else{
                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    void preorderUnCur(){
        stack<Node*> s;
        Node* curr = root;
        if(curr != NULL){
            s.push(curr);
            while(!s.empty()){
                curr = s.top();
                s.pop();
                cout << curr->data << " ";
                if(curr->right != NULL){
                    s.push(curr->right);
                }
                if(curr->left != NULL){
                    s.push(curr->left);
                }
            }
        }
    }

    void TreeDepthUnCur(int& depth){
        if(root == NULL){
            return;
        }
        stack<Node*> s;
        Node* curr = root;
        int maxDepth = 0;
        int curDepth = 0;
        s.push(curr);
        while (!s.empty() || curr != NULL) {
        if (curr != NULL) {
            s.push(curr);
            curDepth++;
            maxDepth = max(maxDepth, curDepth);
            curr = curr->left;
        } else {
            curr = s.top();
            s.pop();
            curDepth--;  
            curr = curr->right;
        }
    }
        depth = maxDepth;
    }
       

    void postorderUnCur(){
        stack<Node*> s1, s2;
        Node* curr = root;
        if(curr != NULL){
            s1.push(curr);
            while (!s1.empty()) {
                curr = s1.top();
                s1.pop();
                s2.push(curr);
                if(curr->left != NULL){
                    s1.push(curr->left);
                }
                if(curr->right != NULL){
                    s1.push(curr->right);
                }
            }
            while (!s2.empty()) {
                cout << s2.top()->data << " ";
                s2.pop();
            }
        }
    }
};

int main() {
    BTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.insert(80);
    int depth = 0;
    queue<Node*> q;

    tree.TreeDepthUnCur(depth);
    cout << "Depth of the tree is: " << depth << endl;
    cout << "Inorder traversal of the tree is: ";
    tree.inorderUnCur();
    cout << endl;
    cout << "Preorder traversal of the tree is: ";
    tree.preorderUnCur();
    cout << endl;
    cout << "Postorder traversal of the tree is: ";
    tree.postorderUnCur();
    cout << endl; 
    return 0;
}