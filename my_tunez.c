#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "definitions.h"
#include "my_tunez.h"

void initialize() {
  int index = 0;
  while (index < 26) {
    table[index] = 0;
    index++;
  }
}

struct song_node * add_song(char * title, char * artisto) {
  //title = strlwr(title);
  //artisto = strlwr(artisto);
  //printf("%d\n", artisto[0]-97);
  struct song_node * added_song = insert_order(table[artisto[0]-97], title, artisto);
  table[artisto[0]-97] = added_song;
  return added_song;  
}

struct song_node * find_a_song(char * title, char * artisto) {
  //title = strlwr(title);
  //artisto = strlwr(artisto);
  return find_song(table[artisto[0]-97], title, artisto);
}

struct song_node * find_an_artist(char * artisto) {
  //artisto = strlwr(artisto);
  return find_artist(table[artisto[0]-97], artisto);
}

void print_letter(char letter) {
  struct song_node * start = table[letter-97];
  while (start) {
    printf("%s - %s\n", start -> name, start -> artist);
	start = start -> next;
  }
  return;
}

void print_artist(char * artisto) {
  //artisto = strlwr(artisto);
  struct song_node * start = find_artist(table[artisto[0]-97], artisto);
  while (start) {
    printf("%s - %s\n", start -> name, start -> artist);
	start = start -> next;
  }
  return;
}

void print_all() {
  int count = 0;
  while (count < 26) {
	//printf("%d\n", count);
    print_list(table[count]);
	count++;
  }
  return;
}

void print_shuffle() {
  int count = 0;
  struct song_node * start;
  srand(time(NULL));
  while (count < 5) {
    int randIndex = rand() % 26;
    //printf("randIndex: %d\n", randIndex%26);
	if (table[randIndex]) {
	  //printf("random achieved\n");
	  start = random_song(table[randIndex]);
	  printf("%s - %s\n", start -> name, start -> artist);
	  count++;
	}
  }
  return;
}

void delete_song(char * title, char * artisto) {
  //title = strlwr(title);
  //artisto = strlwr(artisto);
  char letter = artisto[0];
  table[letter-97] = remove_song(table[letter-97], title, artisto);
}

void delete_all() {
  int index = 0;
  while (index < 26) {
	table[index] = free_list(table[index]);
	index++;
  }
  return;
}





















