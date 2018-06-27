#include<iostream>
using namespace std;

struct node {
	int data;
	struct node *left,*right;
};

node* newNode(int item)
{
    node* temp = new node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}

int SumKLargestUsingReverseMorrisTraversal(node *root,int k)
{
	node *curr = root;
	int sum = 0 ;
	int count = 0;
	//while doing reverse inorder traversal keep track of visited nodes
	
	while(curr)
	{
		if(curr->right==NULL)
		{
		
			if( ++count <= k)
			{
				sum += curr->data;
			}
			
			curr = curr->left;
		}
		
		else
		{
			//finding the inorder successor node
			//inorder successor is the left most in right subtree
			node *succ = curr->right;
			while(succ->left && succ->left!=curr)
				succ = succ->left;
				
			if(succ->left==NULL)
			{
				succ->left = curr;
				
				curr =  curr->right;
			}
			
                        //if the threaded link already exists then simply 
                        //revert back the tree to original form.
			else
			{
				succ->left = NULL;
				
				
				if(++count <= k)
					sum += curr->data;
					
				curr = curr->left;
						
			}
			
		}
	}
	
	return sum;
}
//T(n) = O(n) and extra space  - O(1)

int main()
{
 /* Constructed binary tree is
          8
        /   \
       7     10
     /      /  \
    2      9    13 
*/

        struct node *root = newNode(8);
	
	root->right = newNode(10);
	root->left = newNode(7);
	root->left->left = newNode(2);
	
        root->right->left = newNode(9);
	root->right->right = newNode(13);

cout<<SumKLargestUsingReverseMorrisTraversal(root,3);

return 0;
}
