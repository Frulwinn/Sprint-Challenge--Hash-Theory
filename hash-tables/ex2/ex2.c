#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *ht = create_hash_table(length);
  char **route = malloc(length * sizeof(char *));

  /* YOUR CODE HERE 
  Understanding the problem ---------------
  one-way flight trip
  unscramble your flight tickets by reconstructing trip func

  each ticket is represented as a struct
  typedef struct Ticket {
  char *source; //represents starting airport
  char *destination; //represents next aiport
} Ticket;

  first flight has destination source of none
  final flight has destination source of none
  */

  //SOLUTION
  //create hash table keys and values
  for (int i = 0; i < length; i++) {

    //insert tickets to the hash table, key: location, value destination
    hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
  }
  //the first index should have a source of NONE
  char *current_location = hash_table_retrieve(ht, "NONE");

  //loop through each ticket in the hash table
  for (int i = 0; i < length; i++) {
    //add current location to the route array
    route[i] = current_location;
    //get the next location that has the source/key that matches current ticket destination
    //returns value/destination of that ticket
    current_location = hash_table_retrieve(ht, current_location);
  }
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}



#ifndef TESTING
int main(void)
{
  // Short test
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  for (int i = 0; i < 3; i++) {
    free(tickets[i]);
  }

  free(tickets);

  return 0;
}
#endif
