//
// Created by jakea on 11/19/2018.
//




/*  BST312.h
  CS 312 Fall 2018

  a simple implementation of a binary search tree


*/

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;

template<class ItemType>
class BST_312 {
public:

    BST_312();

    //Copy constructor
    BST_312(const BST_312 & src);

    ~BST_312();

/****************************
makeEmpty

Function: Removes all the items from the BST.
Preconditions: BST has been initialized
Postconditions: All the items have been removed
*****************************/
    void makeEmpty();

/****************************
isEmpty

Function: Checks to see if there are any items in the BST.
Preconditions: BST has been initialized
Postconditions: Returns true if there are no items in the BST, else false.
*****************************/
    bool isEmpty() const;

/****************************
isFull

Function: Determines if you have any more room to add items to the BST
Preconditions: BST has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/
    bool isFull() const;

/****************************
insertItem

Function: Adds newItem to the BST.
Preconditions: BST has been initialized and is not full.
Postconditions: newItem is in the proper position for a BST.
*****************************/
    void insertItem(const ItemType &);

/****************************
deleteItem

Function: Removes target from BST.
Preconditions: BST has been initialized.
Postconditions: If found, element has been removed from BST.
*****************************/
    void deleteItem(const ItemType& newItem);

/****************************
countNodes

Function: Counts the number of nodes in the BST
Preconditions: BST has been initialized.
Postconditions: returns the number of nodes in the BST
*****************************/
    int countNodes();

/****************************
preOrderTraversal

Function: Returns the preOder (Node, Left, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> preOrderTraversal();

/****************************
inOrderTraversal

Function: Returns the inOder (Left, Node, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> inOrderTraversal();

/****************************
postOrderTraversal

Function: returns the postOder (Left, Right, Node) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> postOrderTraversal();

/********************
 isItemInTree

Function: Determines if a given Item is in tree.
Preconditions: BST has been initialized.
Postconditions: none
*****************************/

    bool isItemInTree(const ItemType& item);


private:
    struct TreeNode {
        ItemType data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode * root;


    void insertItem(TreeNode*& t, const ItemType& newItem);
    void inOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    int countNodes(TreeNode* t) const;
    void deleteNode(TreeNode*& node);
    void makeEmpty(TreeNode*& t);
    void deleteItem(TreeNode*& t, const ItemType& newItem);
    void getPredecessor(TreeNode* t, ItemType& data);
    void preOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void postOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void copyTree(TreeNode*& copy, const TreeNode *originalTree);


};

/*******************************
//Function implementations
********************************/

template<class ItemType>
BST_312<ItemType>::BST_312 ()
{
    root = NULL;
}

template<class ItemType>
BST_312<ItemType>::BST_312(const BST_312 & src)
{
    copyTree(root, src.root);
}

template<class ItemType>
BST_312<ItemType>::~BST_312()
{
    makeEmpty();

}


template<class ItemType>
void BST_312<ItemType>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->data = originalTree->data;

        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}


template<class ItemType>
void BST_312 <ItemType>::deleteNode(TreeNode*& t)
{
    ItemType info;
    TreeNode *tempPtr;

    tempPtr = t;

    if (t->left == NULL)
    {
        t = t->right;
        delete tempPtr;
    }
    else if (t->right == NULL)
    {
        t = t->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(t->left, info);
        t->data = info;
        deleteItem(t->left, info);
    }
}



//find largest in left subtree
template<class ItemType>
void BST_312 <ItemType>::getPredecessor(TreeNode* t, ItemType& data)
{

    while (t->right != NULL)
        t = t->right;

    data = t->data;

}


template<class ItemType>
void BST_312 <ItemType>::deleteItem(TreeNode*& t, const ItemType& newItem)
{
    if (t == NULL)
        return;
    else if (newItem < t->data)
        deleteItem(t->left, newItem);
    else if (newItem > t->data)
        deleteItem(t->right, newItem);
    else
        deleteNode(t);
}


template<class ItemType>
void BST_312 <ItemType>::deleteItem(const ItemType& newItem)
{
    deleteItem(root, newItem);

}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty(TreeNode*& t) //HELPER
{
    //YOUR CODE GOES HERE
    if(t!= NULL) //if data is found
    {
        makeEmpty(t->left); //empty each side
        makeEmpty(t->right);
        delete(t); //free
    }
}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty()
{
    makeEmpty(root);
    root = NULL;
}

template<class ItemType>
bool BST_312 <ItemType>::isEmpty() const
{
    return root == NULL;
}



template<class ItemType>
bool BST_312 <ItemType>::isFull() const
{
    try
    {
        TreeNode *temp = new TreeNode;
        delete temp;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }

}


template<class ItemType>
void BST_312 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem) {
    if (t == NULL)       //tree is empty new node must be made
    {
        t = new TreeNode; //create new node and fill with data (root node)
        t->data = newItem;
        t->left = NULL;
        t->right = NULL;
        return;
    }

    if ( t != NULL) { //data is present

        if (newItem < t->data)
        {
                return insertItem(t->left, newItem); //already data, if new is less insert on left branch
        }
        else if (newItem > t->data)
        {
                return insertItem(t->right, newItem);  //already data, if new is greater insert on right branch
        }


        //YOUR CODE GOES HERE

    }

}

template<class ItemType>
void BST_312 <ItemType>::insertItem(const ItemType& newItem)
{

        insertItem(root, newItem); //already data, not root node

    //YOUR CODE GOES HERE
}



template<class ItemType>
int BST_312 <ItemType>::countNodes(TreeNode* t) const
{

    int Nodes =0; //at least one node

    if(t == NULL)
    {
        Nodes = 0;
    }
    else
    {
        Nodes = countNodes(t->left) + countNodes(t->right) + 1;
    }

    return Nodes;
    //YOUR CODE GOES HERE

}


template<class ItemType>
int BST_312 <ItemType>::countNodes() //HELPER
{

    return countNodes(root); //count em up
    //YOUR CODE GOES HERE
}

template<class ItemType>
void BST_312 <ItemType>::preOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    result.push_back(t->data); //push data first (pre)

    if(t->left != NULL)
    {
        preOrderTraversal(t->left, result); //check left, trav
    }

    if(t->right != NULL)
    {
        preOrderTraversal(t->right, result); //check right, trav
    }
    //YOUR CODE GOES HERE
}


template<class ItemType>
vector<ItemType> BST_312 <ItemType>::preOrderTraversal() //HELPER
{
    vector<ItemType> values; //values for storing tree data
    if(isEmpty() == true) //quit when list is empty, checks for base case
    {
        return values;
    }
    preOrderTraversal(root, values); //keep traversing
    return values;
    //YOUR CODE GOES HERE

}

template<class ItemType>
void BST_312 <ItemType>::inOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    if(t->left != NULL)
    {
        inOrderTraversal(t->left, result); //check left, trav
    }

    result.push_back(t->data); //push put data in between (in order)

    if(t->right != NULL)
    {
        inOrderTraversal(t->right, result); //check right, trav
    }
    //YOUR CODE GOES HERE

}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::inOrderTraversal() //HELPER
{
    vector<ItemType> values; //values for storing tree data
    if(isEmpty() == true) //quit when list is empty, checks for base case
    {
        return values;
    }
    inOrderTraversal(root, values); //keep traversing
    return values;
    //YOUR CODE GOES HERE
}

template<class ItemType>
void BST_312 <ItemType>::postOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{

    if(t->left != NULL)
    {
        postOrderTraversal(t->left, result); //check left, trav
    }

    if(t->right != NULL)
    {
        postOrderTraversal(t->right, result); //check right, trav
    }

    result.push_back(t->data); //push at end so post order
    //YOUR CODE GOES HERE
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::postOrderTraversal()
{
    vector<ItemType> values; //values for storing tree data
    if(isEmpty() == true) //quit when list is empty, checks for base case
    {
        return values;
    }
    postOrderTraversal(root, values); //keep trav if not empty
    return values;
    //YOUR CODE GOES HERE
}


template <class ItemType>
bool BST_312 <ItemType>::isItemInTree(const ItemType& item)
{
    TreeNode *t = root;
    while(t != NULL)  //loops through ALL data
    {
        if(item == t->data) //has the data
        {
            return true;
        }

        if (item < t->data)  //next right has
        {
            t = t->left;
        }

        else
        {
            //next left has
            t = t->right;
        }

    }
    return false; //none found
}


#endif
