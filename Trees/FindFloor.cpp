int findFloor(Node* root, int key)
{
    Node *curr = root, *ans = NULL;
 
    // traverse in the tree
    while (curr) {
 
        // if the node is smaller than N,
        // move right.
        if (curr->key > key) {
            ans = curr;
            curr = curr->left;
        }       
             
         
        // if it is equal to N, then it will be
        // the answer
        else if (curr->key == key) {
            ans = curr;
            break;
        }
             
        else // move to the right of the tree
            curr = curr->right;
    }
     
    if (ans != NULL)
       return ans->key;
     
    return -1;
}
