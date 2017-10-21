#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "definitions.h"

int songcmp(struct song_node * song1, struct song_node * song2){
  if(strcmp(song1 -> artist, song2 -> artist)){
    return strcmp(song1 -> artist, song2 -> artist);
  }
  else{
    return strcmp(song1 -> name, song2 -> name);
  }
}


void print_list(struct song_node * start) {
  while (start) {
    printf("%s - %s\n", start -> name, start -> artist);
	start = start -> next;
  }
  return;
}

struct song_node * insert_front(struct song_node * start, char* title, char* artisto) {
  struct song_node * retNode = (struct song_node *) malloc(sizeof(struct song_node));
  //title = strlwr(title);
  //artisto = strlwr(artisto);
  strcpy(retNode -> name, title);
  strcpy(retNode -> artist, artisto);
  retNode -> next = start;
  return retNode;
}

struct song_node * insert_order(struct song_node * start, char* title, char* artisto) {
  if (!start) {
	return insert_front(start, title, artisto);
  }
  struct song_node * begin = start;
  struct song_node * after_start = start -> next;
  struct song_node * retNode = (struct song_node *) malloc(sizeof(struct song_node));
  //title = strlwr(title);
  //artisto = strlwr(artisto);
  strcpy(retNode -> name, title);
  strcpy(retNode -> artist, artisto);
  if (songcmp(start, retNode) > 0) {
	retNode -> next = start;
	return retNode;
  }
	  
  while (after_start && (songcmp(after_start, retNode) < 0)) {
	start = start -> next;
	after_start = after_start -> next;
  }
  
  retNode -> next = after_start;
  start -> next = retNode;
  return begin;
}


struct song_node * find_song(struct song_node * start, char* title, char* artisto) {
  struct song_node * retNode = (struct song_node *) malloc(sizeof(struct song_node));
  //title = strlwr(title);
  //artisto = strlwr(artisto);
  strcpy(retNode -> name, title);
  strcpy(retNode -> artist, artisto);
  while (start && songcmp(start, retNode)) {
	start = start -> next;
  }
  return start;
}

struct song_node * find_artist(struct song_node * start, char * artisto) {
  while (strcmp(start -> artist, artisto) < 0) {
    if (!(start -> next)) {
      return 0;
    }
    start = start -> next;
  }
  if (!strcmp(start -> artist, artisto)) {
    return start;
  }
  return 0;
}

struct song_node * random_song(struct song_node * start){
  int len = 1;
  struct song_node * start0 = start;
  while(start0 -> next){
    len++;
    start0 = start0 -> next;
  }
  //srand(time(NULL));
  int randIndex = rand() % len;
  //printf("len: %d\n", len);
  //printf("randIndex: %d\n", randIndex);
  while(randIndex > 0) {
    start = start -> next;
    randIndex--;
  }
  return start;
}

struct song_node * remove_song(struct song_node * start, char * title, char * artisto){	
  struct song_node * retNode = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(retNode -> name, title);
  strcpy(retNode -> artist, artisto);
  struct song_node * begin = start;	
  if (!songcmp(begin, retNode)){
    begin = begin -> next;
    free(start);
    return begin;
  }
  while (begin && (songcmp(begin, retNode))) {
	begin = begin -> next;
  }  
  if (!begin){
    return start;
  }   
  struct song_node * song1 = start;
  while(song1 -> next && (song1 -> next != begin)){
    song1 = song1 -> next;
  }
  song1 -> next = song1 -> next -> next;
  free(begin);
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
