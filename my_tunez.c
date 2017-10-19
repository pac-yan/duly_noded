#include <stdlib.h>
#include <stdio.h>
#include "defintions.h"

struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node * next;
};

struct song_node * table[26];
int index = 0;
while (index < 26) {
  table[index] = 0;
  index++;
}

struct song_node * addSong(char[] title, char[] artisto) {
  struct song_node * addedSong = insert_order(table[artisto[0]-61], title, artisto);
  table[artisto[0]-61] = addedSong;
  return addedSong;  
}