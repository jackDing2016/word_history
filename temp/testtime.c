#include <stdio.h>
#include <time.h>
int main() {
    time_t now = time(NULL);

    int c = 87123;

    int a = c % 10;

    printf("a is %d\n", a);
    printf("%jd\n", now);
}
