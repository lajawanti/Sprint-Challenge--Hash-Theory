#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

/*
  typedef struct Ticket {
    char *source;
    char *destination;
  } Ticket;
*/

char **reconstruct_trip(Ticket **tickets, int length)
{
      HashTable *ht = create_hash_table(16);
      char **route = malloc(length * sizeof(char *));

      // YOUR CODE HERE
      for(int i = 0; i < length; i++) {
          //void hash_table_insert(HashTable *ht, char *key, char *value)
          hash_table_insert(ht, tickets[i]->source, tickets[i]->destination);
          
          /* hash-table   :  key  : value
                             NONE : PDX
                             PDX  : DCA
                             DCA  : NONE */
      }
      char start_source = "NONE";
      for(int i = 0; i < length; i++) {
            route[i] = hash_table_retrieve(ht, start_source);
            //destination becomes source again..
            start_source = route[i];
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
  //tickets an array of Ticket struct type to hold 3 struct with source : desti..
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;   // NONE : PDX

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;   //PDX : DCA

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;   //DCA : NONE

  print_route(reconstruct_trip(tickets, 3), 3); // PDX, DCA, NONE

  return 0;
}
#endif
