/*Finding kth largest node using Morris traversal in constant space O(1) in a BST.-ASKED IN SAMSUNG
ALGORITHM-

1) Initialize Current as root.

2) Initialize a count variable to 0.

3) While current is not NULL :

  3.1) If current has no right child
   a) Increment count and check if count is equal to K.
      1)If count is equal to K, simply return current node as it is the Kth largest node.

   b)Otherwise, Move to the left child of current.

  3.2) Else, here we have 2 cases:
   a) Find the inorder successor of current node. 
      Inorder successor is the left most node 
      in the right subtree or right child itself.
   b) If the left child of the inorder successor is NULL:
      1) Set current as the left child of its inorder successor.
      2) Move current node to its right.
   c) Else, if the threaded link between the current node 
      and it's inorder successor already exists :
      1) Set left pointer of the inorder successor as NULL.
      2) Increment count and check if count is equal to K.
           a)If count is equal to K, simply return current node as it is the Kth largest node.

      3)Otherwise, Move current to it's left child.
*/



//CPP code for finding K-th largest node using O(1) extra memory and reverse Morris
//traversal.
#include<iostream>
 
 
using namespace std;
 
 
struct node{
     
    int data;   
    struct node *left,*right;
};
 
// helper function to create a new node
node *newNode(int data)
{
    node *temp = new node;
      
    temp->data = data;
    temp->right = temp->left = NULL;
  
    return temp;
}
 
 
node *KthLargestUsingMorrisTraversal(node *root,int k)
{
 
     
    node *curr  = root;
    node *Klargest= NULL;
        //count variable to keep count of visited nodes
    int count = 0;
     
    while(curr!=NULL)
    {
                //if right child is NULL
        if(curr->right==NULL)
        {
            //first increment count and check if count = k
            if(++count==k)
                Klargest  = curr;
             
            //otherwise move to the left child
            curr = curr->left;
                 
        }
         
     
        else
        {
            //find inorder successor of current node
            node *succ  = curr->right;
             
            while(succ->left != NULL && succ->left != curr)
                succ=succ->left;
 
            if(succ->left==NULL)
            {
                //set left child of successor to the current node
                succ->left = curr;
                 
                //move current to its right
                curr = curr->right;
            }
             
                  //restoring the tree back to original binary search tree
                      //removing threaded links
            else
            {
                 
                succ->left = NULL;
             
                if(++count==k)
                    Klargest = curr;
                     
                //move current to its left child
                curr = curr->left;
            }
             
        }
    }
     
    return Klargest;
}
//TIME COMPLEXITY = O(n) and SPACE COMPLEXITY = O(1)
 
 
int main()
{
  // Your C++ Code
/* Constructed binary tree is
          4
        /   \
       2     7
     /  \   /  \
    1    3  6    10
*/
  
node *root = newNode(4);
root->left = newNode(2);
root->right = newNode(7);
root->left->left = newNode(1);
root->left->right = newNode(3);
root->right->left = newNode(6);
root->right->right = newNode(10);
 
cout<<"Finding K-th largest node in BST :"<<endl;
 
 
cout<<KthLargestUsingMorrisTraversal(root,2)->data;
 
  return 0;
} 
