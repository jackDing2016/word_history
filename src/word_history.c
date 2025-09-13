#include "word_history.h"

#include <stdbool.h>
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
    bool isstore = true;
    while ((c = fgetc(f)) != EOF) {
	if (c == ' ') {
	    *p = '\0';
	    char *wordtosave = calloc(30, sizeof(char));
	    strcpy(wordtosave, word);
	    arraylist_add(al, wordtosave);
	    p = word;
	    isstore = false;
	}
	if (c == '\n') isstore = true;

	if (isstore && (c != '\n')) {
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

