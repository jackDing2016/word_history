#include "wordrecord.h"

#include <stdlib.h>

/* struct wordrecord newwordrecord_version6(char *name, struct tm t) { */
/*     struct wordrecord wr; */
/*     (&wr)->name = newstr_version2(name); */
/*     (&wr)->createtime = t; */
/*     return wr; */
/* } */
/* struct wordrecord newwordrecord_version5(char *name) { */
/*     struct wordrecord wr; */
/*     (&wr)->name = newstr_version2(name); */
/*     return wr; */
/* } */

/* struct wordrecord newwordrecord_version3(char *name) { */
/*     struct wordrecord wr; */
/*     (&wr)->name = newstr(name); */
/*     return wr; */
/* } */

struct wordrecord *newwordrecord(char *name, struct tm t) {
    struct wordrecord *wr = malloc(sizeof(struct wordrecord));
    struct string *n = newstr(name);
    wr->name = n;
    wr->createtime = malloc(sizeof(struct tm));
    /* wr->createtime->tm_year = (&t)->tm_year; */
    /* wr->createtime->tm_mon = (&t)->tm_mon; */
    /* wr->createtime->tm_mday = (&t)->tm_mday; */

    /* wr->createtime_t = mktime(wr->createtime); */

    /* memcpy(createtime, wr->createtime, sizeof(sizeof(time_t))); */
    /* struct tm *t = malloc(sizeof(struct tm)); */
    /* wr->createtime = createtime; */
    return wr;
}

void newwordrecord_version2(struct wordrecord *wr, char *name, struct tm t) {
    /* struct wordrecord *wr = malloc(sizeof(struct wordrecord)); */
    /* struct string *n = newstr(name); */

    struct string *n = malloc(sizeof(struct string));
    /* newstr_version3(name, n); */

    /* wr->name = n; */
    /* wr->createtime = malloc(sizeof(struct tm)); */
    /* wr->createtime->tm_year = (&t)->tm_year; */
    /* wr->createtime->tm_mon = (&t)->tm_mon; */
    /* wr->createtime->tm_mday = (&t)->tm_mday; */

    /* wr->createtime_t = mktime(wr->createtime); */
}
