/*
Morris traversal is based on Threaded Binary trees which makes use of NULL pointers in a tree to make them point to some successor or predecessor nodes. 
As in a binary tree with n nodes, n+1 NULL pointers waste memory.
*/

#include<iostream>
#include<limits.h>


using namespace std;

struct node {
	
	int data;
	node *left,*right;
};

node *newNode(int data)
{
	node *temp = new node();
	
	temp->data = data;
	
	temp->left = temp->right = NULL;
	
	return temp;
}

node* ClosestNodeUsingMorrisTraversal(node *root,int key)
{
	int diff = INT_MAX;
	node *curr = root;
	node *closest ;
	
	while(curr)
	{
		if(curr->left==NULL)
		{
			//updating diff if the current diff is smaller than prev difference
			if(diff > abs(curr->data-key))
			{
				diff = abs(curr->data-key);
				closest = curr;
				
				
			}
				
			curr = curr->right;
		}
		
		
		else{
			//finding the inorder predecessor
                        node *pre = curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
				pre = pre->right;
				
			if(pre->right==NULL)
			{
				pre->right = curr;
				
				curr = curr->left;
			}
			
			//threaded link between curr and its predecessor already exists
			else
			{
				pre->right = NULL;
			//if a closer node found, then update the diff and set closest to current
				if(diff > abs(curr->data-key))
				{
					diff = abs(curr->data-key);
					closest = curr;
					
				
				}
				//moving to the right child
				curr = curr->right;
				
				
			}
		}
		
		
	}
	
	return closest;
	
}


int main()
{
/* Constructed binary tree is
          5
        /   \
       3     9
     /  \   /  \
    1    2  8    12 

*/

    node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(9);
    root->left->left = newNode(1);
    root->left->right = newNode(2);
    root->right->left = newNode(8);
    root->right->right = newNode(12);

   cout<<ClosestNodeUsingMorrisTraversal(root,10)->data;


return 0;
}
