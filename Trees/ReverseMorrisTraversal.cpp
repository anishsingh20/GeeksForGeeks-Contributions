/*ALGORITHM-
1) Initialize Current as root.

2) While current is not NULL :

  2.1) If current has no right child
   a) Visit the current node.
   b) Move to the left child of current.

  2.2) Else, here we have 2 cases:
   a) Find the inorder successor of current node. 
      Inorder successor is the left most node 
      in the right subtree or right child itself.
   b) If the left child of the inorder successor is NULL:
      1) Set current as the left child of its inorder successor.
      2) Move current node to its right.
   c) Else, if the threaded link between the current node 
      and it's inorder successor already exists :
      1) Set left pointer of the inorder successor as NULL.
      2) Visit Current node.
      3) Move current to it's left child.
*/

#include<bits/stdc++.h>
 
using namespace std;
 
// Node structure
struct Node {
    int data;
    Node *left, *right;
};
 
// helper function to create a new node
Node *newNode(int data){
    Node *temp = new Node;
     
    temp->data = data;
    temp->right = temp->left = NULL;
 
    return temp;
}
 
// function for reverse inorder traversal
void MorrisReverseInorder(Node *root)
{
     
    if(!root) 
        return ;
     
    // Auxiliary node pointers
    Node *curr, *successor;
     
    // initialize current as root
    curr = root;
     
    while(curr)
    {
        // case-1, if curr has no right child then 
        // visit current and move to left child
        if(curr -> right == NULL)
        {
            cout << curr->data << " ";
            curr = curr->left;
        }
         
        // case-2
        else
        {
            // find the inorder successor of
            // current node i.e left most node in 
            // right subtree or right child itself
            successor = curr->right;
             
            // finding left most in right subtree
            while(successor->left != NULL && 
                  successor->left != curr)
                    successor = successor->left;
                 
            // if the left of inorder successor is NULL
            if(successor->left == NULL)
            {
                // then connect left link to current node
                successor->left = curr;
                 
                // move current to right child
                curr = curr->right;
            }
             
            // otherwise inorder successor's left is
            // not NULL and already left is linked 
            // with current node
            else
            {
                successor->left = NULL;
                 
                // visiting the current node
                cout << curr->data << " ";
 
                // move current to its left child 
                curr = curr->left;
            }
        }
    }
}
 
// Driver code
int main()
{
 
/* Constructed binary tree is
          1
        /   \
       2     3
     /  \   /  \
    4    5  6    7
*/
 
Node *root = newNode(1);
root->left = newNode(2);
root->right = newNode(3);
root->left->left = newNode(4);
root->left->right = newNode(5);
root->right->left = newNode(6);
root->right->right = newNode(7);
 
//reverse inorder traversal.
MorrisReverseInorder(root);
 
return 0;
}
