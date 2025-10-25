#include <time.h>

#include "/home/jack/develop/c/lib/string.h"
struct wordrecord {
    struct string *name;
    struct tm *createtime;
    time_t createtime_t;
};

/* struct wordrecord { */
/*     struct string name; */
/*     struct tm createtime; */
/*     time_t createtime_t; */
/* }; */

struct wordrecord *newwordrecord(char *name, struct tm t);

void newwordrecord_version2(struct wordrecord *wr, char *name, struct tm t);

struct wordrecord newwordrecord_version3(char *name);

struct wordrecord newwordrecord_version5(char *name);

struct wordrecord newwordrecord_version6(char *name, struct tm t);

