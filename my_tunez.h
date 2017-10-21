struct song_node * table[26];

void initialize();
struct song_node * add_song(char*, char*);
struct song_node * find_a_song(char *, char *);
struct song_node * find_an_artist(char *);
void print_letter(char);
void print_artist(char *);
void print_all();
void print_shuffle();
void delete_song(char *, char *);
void delete_all();