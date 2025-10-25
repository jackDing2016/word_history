#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {
    /* struct tm tm_info; */

    /* strftime("2024-10-10", 100, "yyyy-MM-dd", &tm_info); */

    /* time_t localtime = mktime(&tm_info); */
    /* localtime */

    struct tm *tm = malloc(sizeof(struct tm));
    tm->tm_year = 2025;
    tm->tm_mon = 10;
    tm->tm_mday = 12;

    struct tm *tm2 = malloc(sizeof(struct tm));
    tm2->tm_year = 2025;
    tm2->tm_mon = 10;
    tm2->tm_mday = 19;

    time_t t = mktime(tm);
    time_t t2=mktime(tm2);
    double d=difftime(t,t2);
    printf("diff is %e\n",d);
}
