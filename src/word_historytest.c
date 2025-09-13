#include "word_history.h"


int main(){
    arraylist *wl = getallhistory();
    printf("word of number one is %s\n", arraylist_get(wl, 1));
    printf("word of number one is %s\n", arraylist_get(wl, 2));

}
