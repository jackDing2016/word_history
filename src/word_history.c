#include "word_history.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "/home/jack/develop/c/lib/dateutil.h"
#include "/home/jack/develop/c/lib/fileutil.h"
#include "/home/jack/develop/c/lib/string.h"
#include "/home/jack/develop/c/lib/stringutil.h"
#include "/home/jack/develop/c/word_parse/temp/wordutil_v_2.h"
#include "wordrecord.h"
arraylist *generaterandomsorthistory() {
    // the total size of generated list decided to be 300
    int maxsize = 300;
    // get word which you have known and which is used to be excluded in the
    // result
    arraylist *knowwordlist = getknownwordlist();

    arraylist *l = getallhistory();
    int totalsize = arraylist_size(l);
    srand(time(NULL));
    int currentsize = totalsize;
    arraylist *reslist = arraylist_create();
    for (int i = 0; i < totalsize; i++) {
	int index = rand() % (currentsize);
	/* printf("rand index is %d\n", index); */
	char *a = arraylist_remove(l, index);
	if (strlen(a) > 0) {
	    // filter the word which you know
	    if (!iscontainelement(knowwordlist, a)) {
		arraylist_add(reslist, a);
	    }
	}
	if ((totalsize - currentsize) > 300) break;
	/* printf("%s ", a); */
	currentsize--;
    }
    printf("\n");
    return reslist;
}

void writehistory(arraylist *l) {
    FILE *f = fopen(
	"/home/jack/develop/c/word_history/data/randomsorthistory.txt", "wb");
    time_t now = time(NULL);
    char *fileforback = concat(itoc(now), "wordhistory.txt");
    char *filepath =
	concat("/home/jack/develop/c/word_history/data/", fileforback);
    FILE *ff = fopen(filepath, "wb");
    int size = arraylist_size(l);
    for (int i = 0; i < size; i++) {
	char *c = arraylist_get(l, i);
	struct string *s = newstr(c);
	writestring(s, f);
	writestring(s, ff);
    }
}

arraylist *loadrandomsorthistory() {
    FILE *f = fopen(
	"/home/jack/develop/c/word_history/data/randomsorthistory.txt", "rb");
    arraylist *l = arraylist_create();
    while (!feof(f)) {
	struct string *s = readstring(f);
	arraylist_add(l, s);
    }
    return l;
}

arraylist *getallhistory_version2() {
    /* FILE *f = fopen("/home/jack/wordhistory_test.txt", "rb"); */
    arraylist *res = arraylist_create();
    FILE *f = fopen("/home/jack/wordhistory.txt", "rb");
    printf("read line start\n");
    char **linearr = readline(f);
    free(f);
    printf("read line end\n");
    char *line;
    while ((line = *linearr++) != NULL) {
	int *count = malloc(sizeof(int));
	char **strarr = splitstr(line, " ", count);
	/* printf("new count is %d\n", *count); */
	free(count);
	char *word = *strarr;
	char *datestr = *(strarr + 1);

	/* free(word); */
	/* printf("wordis aaaaa %s\n", word); */
	/* printf("word is %s, datestr is %s\n", word, datestr); */

	// do that date str to date
	/* struct tm wordcreatetime = strtodate(datestr); */
	struct tm wordcreatetime;
	/* free(datestr); */

	/* struct wordrecord *wr = newwordrecord(word, wordcreatetime); */
	struct wordrecord *wr = malloc(sizeof(struct wordrecord));
	wr->name = malloc(sizeof(struct string));
	int wordlen = strlen(word);
	wr->name->value = calloc(wordlen, sizeof(char));
	strcpy(wr->name->value, word);
	wr->name->length = wordlen;
	/* free(word); */
	wr->createtime = malloc(sizeof(struct tm));
	/* wr->createtime->tm_year = 2025; */
	/* struct tm wordcreatetime = strtodate(datestr); */
	/* free(datestr); */
	free(*(strarr + 1));
	free(*strarr);
	free(strarr);

	/* free(word); */
	/* free(datestr); */
	arraylist_add(res, wr);

	/* free(wr->name->value); */
	/* free(wr->createtime); */
	/* free(wr); */

	/* struct wordrecord *wr = malloc(sizeof(struct wordrecord)); */
	/* newwordrecord_version2(wr, word, wordcreatetime); */
	/* free(word); */

	/* struct wordrecord wr2 = newwordrecord_version6(word, wordcreatetime);
	 */
	/* printf("word is %s,date is %d-%d-%d\n", (&wr2)->name.value, */
	/* (&wr2)->createtime.tm_year, (&wr2)->createtime.tm_mon, */
	/* (&wr2)->createtime.tm_mday); */
	/* free(wr); */
	/* free(word); */
	/* arraylist_add(res, wr2); */
    }
    return res;
}

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

