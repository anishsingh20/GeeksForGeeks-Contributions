* CPP program to convert a Binary tree to BST 
   using sets as containers. */
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    struct Node *left, *right;
};
 
// function to store the nodes in set while
// doing inorder traversal.
void storeinorderInSet(Node* root, set<int>& s)
{
    if (!root)
        return;
 
    // visit the left subtree first
    storeinorderInSet(root->left, s);
 
    // insertion takes order of O(logn) for sets
    s.insert(root->data); 
 
    // visit the right subtree
    storeinorderInSet(root->right, s);
 
} // Time complexity  = O(nlogn)
 
// function to copy items of set one by one 
// to the tree while doing inorder traversal
void setToBST(set<int>& s, Node* root)
{
    // base condition
    if (!root)
        return;
 
    // first move to the left subtree and 
    // update items
    setToBST(s, root->left);
 
    // iterator initially pointing to the
    // beginning of set
    auto it = s.begin();
 
    // copying the item at beginning of 
    // set(sorted) to the tree.
    root->data = *it; 
 
    // now erasing the beginning item from set.
    s.erase(it);
 
    // now move to right subtree and update items
    setToBST(s, root->right);
 
} // T(n) = O(nlogn) time
 
// Converts Binary tree to BST.
void binaryTreeToBST(Node* root)
{
    set<int> s;
 
    // populating the set with the tree's 
    // inorder traversal data
    storeinorderInSet(root, s);
 
    // now sets are by default sorted as
    // they are implemented using self-
    // balancing BST
 
    // copying items from set to the tree 
    // while inorder traversal which makes a BST
    setToBST(s, root);
 
} // Time complexity  =  O(nlogn), 
  // Auxiliary Space = O(n) for set.
 
// helper function to create a node
Node* newNode(int data)
{
    // dynamically allocating memory
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// function to do inorder traversal
void inorder(Node* root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
int main()
{
    Node* root = newNode(5);
    root->left = newNode(7);
    root->right = newNode(9);
    root->right->left = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(11);
 
    /* Constructing tree given in the above figure
           5
         /   \
        7     9
       /\    / \
      1  6   10 11   */
 
    // converting the above Binary tree to BST
    binaryTreeToBST(root);
    cout << "Inorder traversal of BST is: " << endl;
    inorder(root);
    return 0;
}
