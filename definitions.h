#include <stdlib.h>

struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};


void print_list(struct song_node * start) {
  while (start) {
    //change to be more correct
    printf("%s\n", start -> i);
    start = start -> next;
  }
}

struct song_node * insert_front(struct song_node * start, char[] title, char[] artisto) {
  struct song_node * retNode = (struct song_node *) malloc(sizeof(struct song_node));
  strncpy(retNode -> name, title);
  strncpy(retNode -> artist, artisto);
  retNode -> next = start;
  return retNode;
}

struct song_node * free_list(struct song_node * start) {
  if (!start) {
    return 0;
  }
  free_list(start -> next);
  free(start);
  return 0;
}
