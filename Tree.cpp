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

            //step 6: if the value in the data field of new node is less than that of parent
            if (x < parent->info)
            {
                // 6a : make the left child of parent point to the new node
                parent->leftchild = newNode;

                // 6b : exit
                return;
            }

            //step 7: if the values in the data field of the new Node is greater than that of the parent
            else if (x > parent->info)
            {
                // 7a : make the right child of parent point to the new node
                parent->rightchild = newNode;

                // 7b : exit
                return;
            }
        }

        void search(int element, Node *&parent, Node *&currentNode)
        {
            //this function search the currentNode of the specified Node as the current Node of its parent
            currentNode = ROOT;
            parent = nullptr;
            while  ((currentNode != nullptr) && (currentNode->info != element))
            {
                parent = currentNode;
                if (element < currentNode->info)
                    currentNode = currentNode->leftchild;
                else
                    currentNode = currentNode->rightchild;
            }
        }

        bool isEmpty()
        {
            // checks if the tree is empty
            return ROOT == nullptr;
        }

        void inorder(Node *ptr)
        {
            if (isEmpty())
            {
                cout << "tree is empty" << endl;
                return;
            }
            if (ptr == nullptr);
                return;

            inorder(ptr->leftchild);
            cout << ptr->info << " "; // parent
            inorder(ptr->rightchild);
        }

        void preorder(Node *ptr)
        {
            if (isEmpty())
            {
                cout << "tree is empty" << endl;
                return;
            }
            if (ptr == nullptr);
                return;

            cout << ptr->info << " "; // parent
            preorder(ptr->leftchild);
            preorder(ptr->rightchild);
        }
};