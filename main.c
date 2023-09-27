#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

struct Word {  
    char word[128];  
    char meaning[256];  
};

struct Word words[1000];  
int word_count = 0;
void add_word() {  
    struct Word new_word;  
    printf("------WordNewNew------\n");
    printf("Please key in word:");  
    scanf("%s", new_word.word);  
    printf("Please key in meaning:");  
    scanf("%s", new_word.meaning);  
    //在word_count位置存入单词，而后word_count自增
    words[word_count++] = new_word;  
    printf("OK!\n");  
}
void list_words() {  
    printf("------WordNewNew------\n");
    printf("Word List:\n");  
    for (int i = 0; i < word_count; i++) {  
        printf("%s means %s\n", words[i].word, words[i].meaning);  
    }  
}
void review_word() {  
    if (word_count == 0) {  
        printf("Get impact but NO GIRL\n");  
        return;  
   }  
    int word_index = rand() % word_count;
    //给释义或者给单词
    int model = rand() % 2;  
    struct Word word = words[word_index];  
    printf("------WordNewNew------\n");
    if (model) {
        printf("What is----%s\n", word.word);  
        printf(">>");  
        char input[256];  
        scanf("%s", input);  
        if (strcmp(word.meaning, input) == 0) {  
            printf("Great!\n");  
        } else {  
            printf("Not this,but:%s\n", word.meaning);  
        }
    } else {
        printf("What is----%s\n", word.meaning);  
        printf(">>");  
        char input[256];  
        scanf("%s", input);  
        if (strcmp(word.word, input) == 0) {  
            printf("Great!\n");  
        } else {  
            printf("Not this,but:%s\n", word.word);  
        }
    }
      
}
int main() {  
    int choice;  
    do {  
        printf("------WordNewNew------\n");
        printf("Choose one of them:\n");  
        printf("1. Add\n");  
        printf("2. Examine\n");  
        printf("3. Review\n");  
        printf("4. Quit\n");  
        printf(">>"); 
        scanf("%d", &choice);  
        switch (choice) {  
            case 1:  
                add_word();  
                break;  
            case 2:  
                list_words();  
                break;  
            case 3:  
                review_word();  
                break;  
            case 4:  
                return 0;  
            default:  
                //如果输入纯数字以外的形式，\n将会留在缓存区内，导致无线循环，在此插个眼
                printf("What?\n");  
       }  
   } while (choice!= 4);  
   return 0;  
}
