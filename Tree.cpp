//BinarySearchTree_4nimbelakang
//15 commit

#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    //constructor for the node class
    Node()
    {
        leftchild = nullptr; // initialize left child to null
        rightchild = nullptr; // initialize right child to null
    }
};

class BinaryTree
{
    public:
        Node *ROOT;

        BinaryTree()
        {
            ROOT = nullptr; // initializing ROOT to null
        }

        void insert()
        {
            int x;
            cout << "masukkan nilai : ";
            cin >> x;

            //step 1: alocate memory for the new node
            Node *newNode = new Node();

            //step 2: assign value to the data field of new node 
            newNode->info = x;

            //step 3: make the left and right child of the new Node point to NULL
            newNode->leftchild = nullptr;
            newNode->rightchild = nullptr;

            //step 4: locate the node which will be the parent of the node to be inserted
            Node *parent = nullptr;
            Node *curentNode = nullptr;
            search(x, parent, curentNode);

            //step 5: if parent is NULL (Tree is empty)
            if (parent == nullptr)
            {
                // 5a : mark the new Node as ROOT
                ROOT = newNode;

                // 5b : exit
                return;
            }

        }
};