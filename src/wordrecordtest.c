#include <stdlib.h>

#include "wordrecord.h"
void wordrecordnewtest();
void wordrecordnew_version6test();
void wordrecoredatecomparetest();
void wordrecordnew_version6test() {
    struct tm t;
    struct wordrecord wr = newwordrecord_version6("monkey", t);
    /* printf("word is %s\n", (&wr)->name.value); */
}
void wordrecoredatecomparetest() {
    /* struct tm *tm = malloc(sizeof(struct tm)); */
    /* struct tm tm; */
    /* (&tm)->tm_year = (2025 - 1900); */
    /* (&tm)->tm_mon = 9; */
    /* (&tm)->tm_mday = 2; */
    /* struct wordrecord *wr = newwordrecord("monkey", tm); */
    /* struct tm tm2; */
    /* (&tm2)->tm_year = (2025 - 1900); */
    /* (&tm2)->tm_mon = 9; */
    /* (&tm2)->tm_mday = 8; */
    /* struct wordrecord *wr2 = newwordrecord("fierce", tm); */

    /* double res = difftime(wr->createtime_t, wr2->createtime_t); */
    /* printf("compare result is %f\n", res); */
}

void wordrecordnewtest() {
    /* time_t t = time(NULL); */

    /* struct tm *tm = malloc(sizeof(struct tm)); */
    /* struct tm tm; */
    /* (&tm)->tm_year = (2025 - 1900); */
    /* (&tm)->tm_mon = 9; */
    /* (&tm)->tm_mday = 2; */

    /* time_t t = mktime(tm); */

    /* struct wordrecord *wr = newwordrecord("monkey", tm); */
    /* printf("name is %s\n", wr->name->value); */
    /* char formatted_time[80];  // Buffer to store the formatted string */
    /* strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d", */
    /* localtime(wr->createtime)); */
    /* strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d", tm); */

    /* strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d", */
    /* wr->createtime); */
    /* printf("Formatted local time: %s\n", formatted_time); */
}

int main() {
    wordrecordnewtest();
    /* wordrecoredatecomparetest(); */
    /* wordrecordnew_version6test(); */
}
