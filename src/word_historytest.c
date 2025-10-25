#include <string.h>

#include "/home/jack/develop/c/lib/string.h"
#include "word_history.h"
#include "wordrecord.h"
void getallhistorytest();
void writehistorytest();
void loadrandomsorthistorytest();
void generaterandomsorthistorytest();
void getallhistory_version2test();
int main() {
    /* getallhistorytest(); */
    /* generaterandomsorthistorytest(); */
    /* writehistorytest(); */
    /* loadrandomsorthistorytest(); */
    getallhistory_version2test();
}
void getallhistory_version2test() {
    arraylist *l = getallhistory_version2();
    for (int i = 0; i < arraylist_size(l); i++) {
	struct wordrecord *wr = arraylist_get(l, i);
	printf("word ddd is %s\n", wr->name->value);
    }
}
void writehistorytest() {
    arraylist *l = generaterandomsorthistory();
    writehistory(l);
}

void loadrandomsorthistorytest() {
    arraylist *l = loadrandomsorthistory();
    for (int i = 0; i < arraylist_size(l); i++) {
	struct string *s = arraylist_get(l, i);
	printf("word is %s\n", s->value);
    }
}

void getallhistorytest() {
    arraylist *wl = getallhistory();
    printf("word of number one is %s\n", arraylist_get(wl, 493));
    printf("word of number one is %s\n", arraylist_get(wl, 2));
}

void generaterandomsorthistorytest() {
    arraylist *l = generaterandomsorthistory();

    for (int i = 0; i < arraylist_size(l); i++) {
	char *c = arraylist_get(l, i);
	printf("size of %s: %d\n", c, strlen(c));
    }
}
