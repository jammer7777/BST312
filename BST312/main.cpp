//
// Created by jakea on 11/19/2018.
//

#include <iostream>
#include <fstream>
#include "BST312.h"

using namespace std;

template <class Print>
void print(vector<Print> printVec)
{
    for(int i = 0 ; i < printVec.size() ; i++)
    {
        cout << printVec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("tester.txt");

    BST_312<string> sampleTree;

    string sample;
    inFile >> sample;
    while (inFile) {;
        cout << "inserting ... " << sample << endl;
        sampleTree.insertItem(sample);
        inFile >> sample;
    }

    cout << "The postorder traversal is " << endl;
    print(sampleTree.postOrderTraversal());
    cout << endl;

    cout << "The preorder traversal is " << endl;
    print(sampleTree.preOrderTraversal());
    cout << endl;

    cout << "The inorder traversal is " << endl;
    print(sampleTree.inOrderTraversal());
    cout << endl;

    cout << "Is there an a in the tree???" << endl;
    if(sampleTree.isItemInTree("a") == true){
        cout << "YES" <<endl;
    }
    else{
        cout << "NO!!!!" << endl;
    }
    cout << endl;
    cout << "The number of nodes in the tree is  " << sampleTree.countNodes() << endl;
    cout << endl;

    cout << "Remove items " << endl;
    //sampleTree.deleteItem()
    //sample = "tree";
    //sampleTree.deleteItem(sample);
    sampleTree.makeEmpty();
    print(sampleTree.postOrderTraversal());
    print(sampleTree.preOrderTraversal());
    print(sampleTree.inOrderTraversal());
    cout << "The number of nodes in the tree is  " << sampleTree.countNodes() << endl;




}
