/* 
Given two values n1 and n2 (where n1 < n2) and a root pointer to a Binary Search Tree. Print all the keys of tree in range n1 to n2. i.e. print all nodes n such that n1<=n<=n2 and n is a key of given BST. Print all the keys in increasing order.

Now, to print keys of a BST within a range is quiet simple, by using a logic similar to inorder tree traversal which is demonstrated in Print BST keys in the given range. This technique uses recursion. Now recursion consumes O(n) extra space to maintain a recursion call stack. Hence this is where a technique which uses no Recursion or any stack or queue would be efficient memory wise.

Inorder traversal uses recursion or stack/queue which consumes O(n) space. But there is one efficient way to do inorder tree traversal using Morris Traversal which is based in Threaded Binary trees.Morris traversal uses no recursion or stack/queue and simply stores some important information in the wasted NULL pointers. Morris traversal consumes constant extra memory O(1) as it uses no recursion or stack/queue. Hence we will use Morris traversal to do inorder traversal in the algorithm presented in this tutorial to print keys of a BST in a given range, which is efficient memory wise.

The concept of Threaded Binary trees is simple that they store some useful information in the wasted NULL pointers. In a normal binary tree with n nodes, n+1 NULL pointers waste memory.
*/
#include<iostream>
 
using namespace std;
  
struct node{
      
    int data;   
    struct node *left,*right;
};
 
void RangePrintMorrisTraversal(node *root,int n1,int n2)
{
    if(!root) return;
     
    node *curr = root;
 
    while(curr)
    {
         
        if(curr->left==NULL)
        {
      //check if current node lies between n1 and n2 
            if(curr->data <= n2 && curr->data >= n1)
            {
                cout<<curr->data<<" ";
            }
                 
                        curr = curr->right;
        }
         
        else
        {
            node *pre = curr->left;
            //finding the inorder predecessor-
            //inorder predecessor is the right most in left subtree or the left child, i.e in BST
            //it is the maximum(right most) in left subtree. 
 
            while(pre->right!=NULL && pre->right!=curr)
                    pre = pre->right;
                 
            if(pre->right==NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
             
            else
            {
                pre->right  = NULL;
                 
              //check if current node lies between n1 and n2
                if(curr->data <= n2 && curr->data >= n1)
                {
                     
                    cout<<curr->data<<" ";
                         
                }
                 
                curr = curr->right;                      
                     
            }
        }
 
    } //end while
     
}
//efficient solution- Time complexity = O(n), Space complexity = O(1)
 
 
// helper function to create a new node
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->right = temp->left = NULL;
   
    return temp;
}
 
int main()
{
 
 
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
 
RangePrintMorrisTraversal(root,4,9);
return 0;
//outputs : 4 6 7 
     
}
