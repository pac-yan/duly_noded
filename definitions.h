#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};


void print_list(struct song_node * start) {
  while (start) {
    //change to be more correct
    printf("Song name: %s\tArtist name: %s\n", start -> name, start -> artist);
    start = start -> next;
  }
}

struct song_node * insert_front(struct song_node * start, char* title, char* artisto) {
  struct song_node * retNode = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(retNode -> name, strlwr(title));
  strcpy(retNode -> artist, strlwr(artisto));
  retNode -> next = start;
  return retNode;
}

struct song_node * insert_order(struct song_node * start, char* title, char* artisto) {
  struct song_node * retNode = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(retNode -> name, strlwr(title));
  strcpy(retNode -> artist, strlwr(artisto));
  if (strcmp(start -> artist, retNode -> artist) <= 0) {
    while (strcmp(start -> next -> artist, retNode -> artist) < 0) {
      start = start -> next;
    }
    if (!strcmp(start -> next -> artist, retNode -> artist)) {
      while (strcmp(start -> next -> name, retNode -> name) < 0) {
	    start = start -> next;
      }
    }
  }
  retNode -> next = start -> next;
  start -> next = retNode;
}

struct song_node * find_song(struct song_node * start, char* title, char* artisto) {
  struct song_node * retNode = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(retNode -> name, strlwr(title));
  strcpy(retNode -> artist, strlwr(artisto));
  while (strcmp(start -> artist, retNode -> artist) < 0) {
    if (!(start -> next)) {
      return 0;
    }
    start = start -> next;
  }
  if (!strcmp(start -> artist, retNode -> artist)) {
    while (strcmp(start -> name, retNode -> name) < 0) {
      if (!(start -> next)) {
	return 0;
      }
      else if(!strcmp(start -> artist, retNode -> artist)){
	return 0;//song is not here
      }
      else{
	start = start -> next;
      }
    }
    if (!strcmp(start -> artist, retNode -> artist) * !strcmp(start -> name, retNode -> name)) {
      return start;
    }
  }
  return 0;
}

struct song_node * find_artist(struct song_node * start, char* artisto) {
  while (strcmp(start -> artist, retNode -> artist) < 0) {
    if (!(start -> next)) {
      return 0;
    }
    start = start -> next;
  }
  if (!strcmp(start -> artist, retNode -> artist)) {
    return start;
  }
  return 0;
}

struct song_node * random_song(struct song_node * start){
  int len = 0;
  struct song_node * start0 = start;
  while(!(start0 -> next)){
    len ++;
    start0 = start0 -> next;
  }
  srand(time(NULL));
  int randIndex = rand() % len;
  while(len) {
    start = start -> next;
    len--;
  }
  return start;
}

struct song_node * remove_song(struct song_node * start, char* title, char* artisto){
  struct song_node * begin = start;
  struct song_node * start0;
  if (!strcmp(start -> name, title ) * !strcmp(start -> artist, artisto)) {
    start0 = start -> next;
    free(start);
    return start0;
  }
  while (!strcmp(start -> name, title) * !strcmp(start -> artist, artisto)) {
    if (!start) {
      return 0;
    }
    start0 = start;
    start = start -> next;
  }
  start0 -> next = start -> next;
  free(start);
  return start;
}

struct song_node * free_list(struct song_node * start) {
  if (!start) {
    return 0;
  }
  free_list(start -> next);
  free(start);
  return 0;
}
