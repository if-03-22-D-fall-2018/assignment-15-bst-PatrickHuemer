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
#include "general.h"
#include "bst.h"

struct Node{
  int value = 0;
  Node* left = 0;
  Node* right = 0;
};

Bst new_bst()
{
  return 0;
}

void delete_bst(Bst bst)
{
  if(bst == 0) return;
  delete_bst(bst->right);
  delete_bst(bst->left);
  sfree(bst);
}

int get_depth(Bst bst)
{
  if (bst == 0) return 0;

  if(bst->right == 0 && bst->left == 0) return 1;

  if(get_depth(right_subtree(bst)) >  get_depth(left_subtree(bst))) return 1 + get_depth(right_subtree(bst));

  return 1 + get_depth(left_subtree(bst));
}

Node* node(int value);

void add(Bst* bst, int value)
{
  if ((*bst) == 0)
  {
    Node* newNode = node(value);
    (*bst) = newNode;
    return;
  }
  if ((*bst)->value >= value)
  {
    if ((*bst)->left == 0)
    {
      Node* newNode = node(value);
      (*bst)->left = newNode;
    }
    else
    {
      Node* toAdd = (*bst)->left;
      add(&toAdd, value);
    }
  }
  else
  {
    if ((*bst)->right == 0)
    {
      Node* newNode = node(value);
      (*bst)->right = newNode;
    }
    else
    {
      Node* toAdd = (*bst)->right;
      add(&toAdd, value);
    }
  }
}

Node* node(int value)
{
  Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->right = 0;
  newNode->left = 0;
  newNode->value = value;
  return newNode;
}

int root_value(Bst bst)
{
  if (bst != 0)
  {
    return bst->value;
  }
  return 0;
}

Bst left_subtree(Bst root)
{
  if (root != 0)
  {
    return root->left;
  }
  return 0;
}

Bst right_subtree(Bst root)
{
  if (root != 0)
  {
    return root->right;
  }
  return 0;
}

int traverse_pre_order(Bst bst, int *elements, int start)
{
  if(bst != 0)
  {
    elements[start] = bst->value;
    start++;
    start = traverse_pre_order(bst->left, elements, start);
    start = traverse_pre_order(bst->right, elements, start);
  }
  return start;
}

int traverse_in_order(Bst bst, int *elements, int start)
{
  if(bst != 0)
  {
    start = traverse_in_order(bst->left, elements, start);
    elements[start] = bst->value;
    start++;
    start = traverse_in_order(bst->right, elements, start);
  }
  return start;
}

int traverse_post_order(Bst bst, int *elements, int start)
{
  if (bst != 0)
  {
    start = traverse_post_order(bst->left, elements, start);
    start = traverse_post_order(bst->right, elements, start);
    elements[start] = bst->value;
    start++;
  }
  return start;
}

bool are_equal(Bst bst1, Bst bst2)
{
  if(bst1 == 0)
  {
      return bst2 == 0;
    }else if(get_depth(bst1) == get_depth(bst2)){
      if(bst1->value == bst2->value){
        return are_equal(bst1->left, bst2->left) && are_equal(bst1->right, bst2->right);
      }
    }
    return false;
}

void most_left_longest_branch(Bst bst, Bst* branch)
{
  if(bst != 0)
  {
    if(get_depth(bst->left) < get_depth(bst->right))
    {
      add(branch, bst->value);
      most_left_longest_branch(&(*bst->right), branch);
    }
    else if(get_depth(bst->left) >= get_depth(bst->right))
    {
      add(branch, bst->value);
      most_left_longest_branch(&(*bst->left), branch);
    }
  }

}

int get_number_of_subtrees(Bst bst)
{
  if (bst != 0)
  {
    int *elements = new int[get_depth(bst)];
    return traverse_pre_order(bst, elements, 0) -1;
  }
  return -1;
}
