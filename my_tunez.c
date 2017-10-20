#include <stdlib.h>
#include <stdio.h>
#include <time.h>
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
  struct song_node * addedSong = insert_order(table[strlwr(artisto)[0]-61], strlwn(title), strlwr(artisto));
  table[strlwr(artisto)[0]-61] = addedSong;
  return addedSong;  
}

struct song_node * find_a_song(char[] title, char[] artisto) {
  return find_song(table[strlwr(artisto)[0]-61], strlwr(title), strlwr(artisto));
}

struct song_node * find_an_artist(char[] artisto) {
  return find_artist(table[strlwr(artisto)[0]-61], strlwr(artisto));
}

void print_letter(char letter) {
  struct song_node * start = table[strlwr(letter)-61];
  while (start) {
    printf("%s - %s\n", start -> name, start -> artist);
  }
  return 0;
}

void print_artist(char[] artisto) {
  struct song_node * start = find_artist(table[strlwr(artisto)[0]], strlwr(artisto));
  while (start) {
    printf(""%s - %s\n", start -> name, start -> artist);
  }
  return 0;
}

void print_all() {
  int count = 0;
  while (count < 26) {
    print_letter(count+61);
	count++;
  }
  return 0;
}

void print_shuffle() {
  int count = 0;
  struct song_node * start;
  while (count < 5) {
    srand(time(NULL));
    int randIndex = rand() % 26;
	start = random_song(table[randIndex]);
	printf(""%s - %s\n", start -> name, start -> artist);
	count++;
  }
  return 0;
}

void delete_song(char[] title, char[] artisto) {
  char letter = strlwr(artisto)[0];
  table[letter-61] = remove_song(table[letter-61], strlwr(title), strlwr(artisto));
  return 0;  
}

void delete_all() {
  int index = 0;
  while (index < 26) {
	table[index] = free_list(table[index]);
  }
  return 0;  
}






















