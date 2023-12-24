#include <iostream>
using namespace std;

class Node {
public:
    Node *right;
    int data;
    Node *left;

    Node(int key) {
        data = key;
        right = NULL;
        left = NULL;
    }
};

class linkedQueue;

class BinaryTree {
public:
    Node *root;

    BinaryTree() {}

    void inoder(Node *root) {
        if (root != NULL) {
            inoder(root->left);
            cout << root->data << " ";
            inoder(root->right);
        }
    }

    void preoder(Node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            preoder(root->left);
            preoder(root->right);
        }
    }

    void postoder(Node *root) {
        if (root != NULL) {
            postoder(root->left);
            postoder(root->right);
            cout << root->data << " ";
        }
    }

    void Leveloderprint(Node *root);
};

class Nodeforqueuelinklist {
public:
    int data;
    Nodeforqueuelinklist *next;

    Nodeforqueuelinklist(int value) {
        data = value;
        next = NULL;
    }
};

class linkedQueue {
private:
    Nodeforqueuelinklist *front;
    Nodeforqueuelinklist *rear;

public:
    linkedQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(Node *node) {
        Nodeforqueuelinklist *newNode = new Nodeforqueuelinklist(node->data);
        if (rear == NULL) {
            rear = front = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue already empty" << endl;
            return;
        }
        Nodeforqueuelinklist *t = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete t;
    }

    Node *getFront() {
        if (front == NULL) {
            cout << "Queue empty";
            return NULL;
        } else {
            return new Node(front->data);
        }
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void display() {
        Nodeforqueuelinklist *t = front;
        if (t == NULL) {
            cout << "Nothing in the queue" << endl;
        } else {
            while (t != NULL) {
                cout << t->data << " ";
                t = t->next;
            }
            cout << endl;
        }
    }
};

void BinaryTree::Leveloderprint(Node *root) {
    if (root == NULL) {
        return;
    }
    linkedQueue q;
    q.enqueue(root);
    while (q.isEmpty() == false) {
        Node *curr = q.getFront();
        q.dequeue();
        cout << curr->data << " ";
        if (curr->left != NULL) {
            q.enqueue(curr->left);
        }
        if (curr->right != NULL) {
            q.enqueue(curr->right);
        }
    }
}

int main() {
    BinaryTree bt;
    bt.root = new Node(10);
    bt.root->left = new Node(20);
    bt.root->right = new Node(30);
    bt.root->left->left = new Node(40);
    bt.root->left->right = new Node(50);
    bt.inoder(bt.root);
    cout << endl;
    bt.postoder(bt.root);
    cout << endl;
    bt.preoder(bt.root);
    cout << endl;
    bt.Leveloderprint(bt.root);
    return 0;
}

