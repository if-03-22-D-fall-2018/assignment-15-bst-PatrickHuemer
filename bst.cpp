/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdlib.h>
#include "bst.h"

struct Node{
  int element = 0;
  Node* left = 0;
  Node* right = 0;
};

Bst new_bst()
{
  return (struct Node*)malloc(sizeof(struct Node));
}

void delete_bst(Bst bst)
{

}

int get_depth(Bst bst)
{
  return 0;
}

void add(Bst* bst, int value)
{

}

int root_value(Bst bst)
{
  if (bst->value == 0) {
    return 0;
  }
  return
}

Bst left_subtree(Bst root)
{
  return root->left;
}

Bst right_subtree(Bst root)
{
  return root->right;
}

int traverse_pre_order(Bst bst, int *elements, int start)
{
  return 0;
}

int traverse_in_order(Bst bst, int *elements, int start)
{
  return 0;
}

int traverse_post_order(Bst bst, int *elements, int start)
{
  return 0;
}

bool are_equal(Bst bst1, Bst bst2)
{
  return false;
}

void most_left_longest_branch(Bst bst, Bst* branch)
{

}

int get_number_of_subtrees(Bst bst)
{
  return 0;
}
