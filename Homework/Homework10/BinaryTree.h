#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

using namespace std;

// Stack template
template <class T> class BinaryTree {
private:
    class TreeNode {
    public:
        T value;
        TreeNode* leftChild;
        TreeNode* rightChild;

        TreeNode() {
            leftChild = rightChild = nullptr;
        }
    };

    TreeNode* root;

    // Private member functions
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(T, TreeNode *&);
    void makeDeletion(TreeNode *&);

    void loadInOrderRec(TreeNode* nodePtr, T A[], int &pos) ;

    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
    void IndentBlock(int);
    void PrintTree(TreeNode *, int, int);
public:
    // Constructor
    BinaryTree() { root = nullptr; }

    // Destructor
    ~BinaryTree() { destroySubTree(root); }

    // Binary tree operations
    void insertNode(T);
    bool searchNode(T);
    void remove(T);

    void loadInOrder(T A[]);

    void displayInOrder() const { displayInOrder(root); }

    void displayPreOrder() const { displayPreOrder(root); }

    void displayPostOrder() const { displayPostOrder(root); }

    void PrintTree(int Indent = 4, int Level = 0);

};

template <class T>
void BinaryTree<T>::insert(TreeNode* & newNode, TreeNode* & nodePtr) {
    if (!nodePtr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(newNode, nodePtr->leftChild);
    else
        insert(newNode, nodePtr->rightChild);
}

template <class T>
void BinaryTree<T>::insertNode(T val) {
    TreeNode* newNode = nullptr;
    newNode = new TreeNode;
    newNode->value = val;
    newNode->leftChild = newNode->rightChild = nullptr;

    insert(newNode, root);

}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode * nodePtr) {
    if (nodePtr) {
        if (nodePtr->leftChild)
            destroySubTree(nodePtr->leftChild);
        if (nodePtr->rightChild)
            destroySubTree(nodePtr->rightChild);
        delete nodePtr;
    }
}
template <class T>
bool BinaryTree<T>::searchNode(T val) {
    TreeNode* nodePtr = root;

    while (nodePtr) {
        if (val == nodePtr->value)
            return true;
        else if (val < nodePtr->value)
            nodePtr = nodePtr->leftChild;
        else
            nodePtr = nodePtr->rightChild;
    }

    return false;
}

template <class T>
void BinaryTree<T>::remove(T val) {
    deleteNode(val, root);
}

template <class T>
void BinaryTree<T>::deleteNode(T val, TreeNode* & nodePtr) {
    if (!nodePtr)
        return;

    if (val < nodePtr->value)
        deleteNode(val, nodePtr->leftChild);
    if (val > nodePtr->value)
        deleteNode(val, nodePtr->rightChild);
    else
        makeDeletion(nodePtr);
}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode* & nodePtr) {
    TreeNode* temp = nullptr;

    if (!nodePtr)
        cout << "Cannot delete empty node..." << endl;
    else if (!nodePtr->rightChild) {
        temp = nodePtr;
        nodePtr = nodePtr->leftChild;
        delete temp;
    } else if (!nodePtr->leftChild) {
        temp = nodePtr;
        nodePtr = nodePtr->rightChild;
        delete temp;
    } else {
        temp = nodePtr->rightChild;

        while (temp->left)
            temp = temp->left;

        temp->left = nodePtr->leftChild;
        temp = nodePtr;
        nodePtr = nodePtr->rightChild;

        delete temp;
    }
}

template <class T>
void BinaryTree<T>::loadInOrder(T A[]) {

    TreeNode* nodePtr;
    nodePtr = root;
    int pos = 0;
    loadInOrderRec(nodePtr, A, pos);

}

template <class T>
void BinaryTree<T>::loadInOrderRec(TreeNode* nodePtr, T A[], int &pos) {
    if (nodePtr) {

            loadInOrderRec(nodePtr->leftChild, A, pos);

            A[pos] = nodePtr->value;
            pos++;

            loadInOrderRec(nodePtr->rightChild, A, pos);
    }
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        displayInOrder(nodePtr->leftChild);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->rightChild);
    }
}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->leftChild);
        displayPreOrder(nodePtr->rightChild);
    }
}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        displayPostOrder(nodePtr->leftChild);
        displayPostOrder(nodePtr->rightChild);
        cout << nodePtr->value << endl;
    }
}

template <class T> void BinaryTree<T>::IndentBlock(int num) {
  for (int i = 0; i < num; i++)
    cout << " ";
}

template <class T>
void BinaryTree<T>::PrintTree(TreeNode* t, int Indent, int Level) {
    if (t) {
        PrintTree(t->rightChild, Indent, Level + 1);
        IndentBlock(Indent * Level);
        cout << t->value << "\n";
        PrintTree(t->leftChild, Indent, Level + 1);
    }
}

template <class T>
void BinaryTree<T>::PrintTree(int Indent, int Level) {
    if (root)
        PrintTree(root, Indent, Level);
}

#endif // BINARYTREE_H
