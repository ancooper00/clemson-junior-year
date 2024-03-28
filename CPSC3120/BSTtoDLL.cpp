#include <iostream>
using namespace std;
//* A binary tree node has data, and left and right pointers */
struct node
{
    int data;
    node* left;
    node* right;
};

/* Function to print nodes in a given doubly linked list */
void printList(node *node)
{
    while (node!=NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
node* newNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}

//function to turn a BST into a doubly linked list staying inorder 
//r is the root of the BST
//head is the pointer of the head node of the DLL
void BSTtoDoublyLL(node *r, node **head){
  //base case where the tree is empty (root is null)
  if(r == NULL) return;
  //make previously visited node null. (static to be reachable by all recursive calls)
  static node *p = NULL;
  //convert left subtree to DLL recursivly
  BSTtoDoublyLL(r->left, head);
  //convert current visited node to head of list
  if(p == NULL){
    *head = r;
  }
  else{
    //go to left side
    r->left = p;
    //right side set as root
    p->right = r;
  }
  p = r;
  //recursively convert the right subtree
  BSTtoDoublyLL(r->right, head);
}








/* Driver program to test above functions*/
int main()
{
    // Let us create the tree shown in above diagram
    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    // Convert to DLL
    node *head = NULL;
    BSTtoDoublyLL(root, &head);

    // Print the converted list
    printList(head);

    return 0;
}
