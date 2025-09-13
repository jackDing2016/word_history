#include "word_history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
arraylist *getallhistory() {
    arraylist *al = arraylist_create();
    FILE *f = fopen("/home/jack/wordhistory.txt", "r");
    char *word = calloc(30, sizeof(char));
    char *p;
    p = word;
    char c;
    while ((c = fgetc(f)) != EOF) {
	if (c == '\n') {
	    *p = '\0';
	    char *wordtosave = calloc(30, sizeof(char));
	    strcpy(wordtosave, word);
	    arraylist_add(al, wordtosave);
	    p = word;
	} else {
	    *p++ = c;
	}
    }
    return al;
}

/* int main() { */
/*     arraylist *wl = getallhistory(); */
/*     printf("word of number one is %s\n", arraylist_get(wl, 1)); */
/*     printf("word of number one is %s\n", arraylist_get(wl, 2)); */
/* } */

