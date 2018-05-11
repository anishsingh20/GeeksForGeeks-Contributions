//CPP code to print BST keys in given Range in constant memory O(1) using Morris traversal. 
 
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
 
     
}
