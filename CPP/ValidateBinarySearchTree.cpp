#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
int isBSTUtil(struct node* node, int min, int max);
 
/* Returns true if the given tree is a binary search tree(efficient version). */
int isBST(struct node* node)
{
  return(isBSTUtil(node, INT_MIN, INT_MAX));
} 
 
/* Returns true if the given tree is a BST and its values are >= min and <= max. */

int isBSTUtil(struct node* node, int min, int max)
{ 
 
  if (node==NULL)
     return 1;
 
  if (node->data < min || node->data > max)
     return 0; 
 
  /* otherwise check the subtrees recursively,
   tightening the min or max constraint */
  return
    isBSTUtil(node->left, min, node->data-1) &&
    isBSTUtil(node->right, node->data+1, max);
} 
 
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 

int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(6);
  root->left->left  = newNode(1);
  root->left->right = newNode(3); 
  root->right->left = newNode(5);
  root->right->right= newNode(7);

 
  if(isBST(root))
    printf("Is BST");
  else
    printf("Not a BST");
 
  getchar();
  return 0;
}