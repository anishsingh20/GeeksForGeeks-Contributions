  #include<iostream>
#include<math.h>

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

node *SmallestNumGreaterThanNUsingMorris(node *root,int n)
{
	if(!root) return NULL;
	
	node *curr = root;
	node *small;
	
	int diff = INT_MAX;
	while(curr)
	{
		if(!curr->left)
		{
			if(curr->data >= n)
			{
				if(diff  < abs(curr->data-n))
				{
					diff = abs(curr->data - n );
					small=curr;
				}
			}
			
			curr = curr->right;
		}
		
		else
		{
			//finding the inorder predecessor
			node *pre = curr->left;
			
			while(pre->right!=NULL && pre->right!=curr)
			{
				pre = pre->right;
			}
			
			//building thread
			if(pre->right==NULL)
			{
				pre->right = curr;
				curr = curr->left;
			}
			
			//if thraded link already exists,we break the threads and 
                        //change the tree to the original tree.
			else
			{
				pre->right = NULL;
				if(curr->data >= n)
				{
					if(diff  > abs(curr->data-n))
					{
						diff = abs(curr->data - n );
						small=curr;
					}
				}
				
				curr = curr->right;
				
			}
		}
	}
	
	
	return small;
}
//Time complexity = O(n), Space complexity = O(1)

int main()
{
  // Your C++ Code
        struct node *root = newNode(8);
	
	root->left = newNode(7);
	root->right = newNode(10);
        root->left->left = newNode(2);
        root->right->right = newNode(13);
        root->right->left = newNode(9);

        cout<<SmallestNumGreaterThanNUsingMorris(root,5)->data;

  return 0;
} 
