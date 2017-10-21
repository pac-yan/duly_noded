#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "definitions.h"
#include "my_tunez.h"

int main(){
    struct song_node * head = insert_front(0, "gorgeous", "taylor swift");
    
	srand(time(NULL));
    printf("definitions tests:\n");
    printf("============================\n");
    printf("print_list() Tests:\n");
    printf("\n");
    printf("print current list:\n");
    print_list(head);
    
    printf("============================\n");
    printf("insert_front() Tests:\n");
    printf("\n");
    printf("insert let you down in front of gorgeous:\n");
    head = insert_order(head, "let you down", "nf");
    print_list(head);
    
    printf("============================\n");
    printf("\n");
    printf("insert_order() Tests:\n");
    printf("insert a bunch of songs ordered:\n");
    head = insert_order(head,"rockstar","post malone");
    head = insert_order(head,"bad at love","halsey");
    head = insert_order(head,"what lovers do","maroon five");
    print_list(head);
    

    printf("============================\n");
    printf("\n");
    printf("now testing find\n");
    printf("find rockstar by post malone\n");
    struct song_node* rockstar = find_song(head,"rockstar","post malone");
    printf("%s - %s\n",rockstar->name, rockstar->artist);

    printf("============================\n");
    printf("\n");
    printf("now testing find_artist\n");
    printf("find the first piece by nf\n");
    struct song_node* nf = find_artist(head,"nf");
    printf("%s - %s\n",nf -> name, nf -> artist);   
    
    printf("============================\n");
    printf("\n");
    printf("random_song() tests:\n");
    printf("random song from list:\n");
    struct song_node * random = random_song(head);
	printf("test\n");
    printf("%s - %s\n", random -> artist, random -> name);
    
    printf("============================\n");
    printf("\n");
    printf("remove_song() tests:\n");
    printf("remove let you down - nf  from list:\n");
    remove_song(head, "let you down", "nf");
    print_list(head);
    
    printf("============================\n");
    printf("\n");
    printf("free_list() tests:\n");
    printf("deleted list:\n");
    head = free_list(head);
    print_list(head);
    
    printf("my_tunez tests:\n");
    printf("============================\n");
    printf("print current list:\n");
    delete_all();
    add_song("havana", "camilla cabello");
    print_all();
	
    printf("============================\n");
    printf("add_song() tests:\n");
    printf("\n");
    printf("Add a bunch of songs:\n");
    add_song("bedroom floor", "liam payne");
    add_song("meant to be","bebe rexha");
    add_song("i fall apart","post malone");
    add_song("new","daya");
    add_song("feel it still", "portugal");
    add_song("homemade dynamite", "lorde");
    add_song("dusk till dawn", "zayn");
    add_song("rockstar","post malone");
    printf("it should print out 8 entries in order:\n");
    print_all();
    
    printf("============================\n");
    printf("print_artist() tests:\n");
    printf("\n");
    printf("print out everything by post malone: \n");
    print_artist("post malone");
    
    printf("============================\n");
    printf("print_shuffle() tests:\n");
    printf("\n");
    printf("print_shuffle: \n");
    print_shuffle();
    
    printf("============================\n");
    printf("delete_song() tests:\n");
    printf("\n");
    printf("delete i fall apart\n");
    delete_song("i fall apart", "post malone");
    printf("print out everything by post malone:\n");
    print_artist("post malone");
    

    printf("\nprint all\n");
    print_all();

    printf("\ntest search for rockstar\n");
    struct song_node * search_test = find_a_song("rockstar","post malone");
    printf("%s - %s\n",search_test -> artist, search_test -> name);
    
    return 0;
}