#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  /* YOUR CODE HERE 
  Understanding the problem --------------
  merging two packages
  A package is given WITH (limit and weights)
  weight limit = limit
  list = weights of item weights
  FIND two items whose sum of weights == weight limit
  index_1 + index_2 == weight limit
  return instance of answer struct

  typdef struct Answer { //represents item weights of two packages
  int index_1; //place higher value weight
  int index_2; //place smaller value weight
} Answer;

  If such a pair doesn’t exist for the given inputs, 
  your function should return `NULL`.

  When calling `hash_table_retrieve` with a key that doesn't exist 
  in the hash table, `hash_table_retrieve` will return -1. 

  Example:
  ```
  input: int *weights = { 4, 6, 10, 15, 16 }, 
  int length = 5, int limit = 21
  output: Answer{ index_1: 3, index_2: 1 }  
  # since these are the indices of weights 15 and 6 whose sum equals 21
  ```
  */
  //SOLUTION
  //loop through the items in the weight list

  //check if the needed key is in the hash table
  //return the index value of the key for that weights array
  //calculate the two weight number needed to equal the limit

  //if the key is not in the hash table make one
  //create the key value pairs that are inserted into the hash table

  //if a key equal to the (limit - weight) exists
  //create an instance of the answer truct

  //set the index of the weight started with

  //store the value(index) that matches

  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}

#ifndef TESTING
int main(void)
{
  // TEST 1
  int weights_1 = {9};
  Answer *answer_1 = get_indices_of_item_weights(&weights_1, 1, 9);
  print_answer(answer_1);  // NULL

  // TEST 2
  int weights_2[] = {4, 4};
  Answer* answer_2 = get_indices_of_item_weights(weights_2, 2, 8);
  print_answer(answer_2);  // {1, 0}

  // TEST 3
  int weights_3[] = {4, 6, 10, 15, 16};
  Answer* answer_3 = get_indices_of_item_weights(weights_3, 5, 21);
  print_answer(answer_3);  // {3, 1}

  // TEST 4
  int weights_4[] = {12, 6, 7, 14, 19, 3, 0, 25, 40};
  Answer* answer_4 = get_indices_of_item_weights(weights_4, 9, 7);
  print_answer(answer_4);  // {6, 2}

  return 0;
}

#endif
