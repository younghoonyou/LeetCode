#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
    struct document ans;
    ans.paragraph_count = 0;
    ans.data = malloc(5*sizeof(struct paragraph));//least 5 paragraph array
    for(int i=0;i<5;++i){
        ans.data[i].sentence_count = 0;//init
        ans.data[i].data = malloc(16*(sizeof(struct sentence)));//least 5 sentence arrary
        for(int j=0;j<16;++j){
            ans.data[i].data[j].word_count = 0;//init
            ans.data[i].data[j].data = malloc(128*sizeof(struct word));//least 128 word array
            for(int k=0;k<128;++k){
                ans.data[i].data[j].data[k].data = malloc(sizeof(char)*256);//least word length
            }
        }
    }
    int p = 0, s = 0, w = 0, c = 0;//position
    for(int i=0;i<strlen(text);++i){
        if(text[i] == '\n'){//paragraph
            ans.paragraph_count++;
            c = w = s = 0;
            p++;
            continue;
        }
        if(text[i] == '.'){//sentence
            ans.data[p].data[s].data[w].data[c] = '\0';
            ans.data[p].data[s].word_count++;
            ans.data[p].sentence_count++;//increase sentence
            c = w = 0;
            s++;//increase sentence
            continue;
        }
        if(text[i] == ' '){//word
            ans.data[p].data[s].data[w].data[c] = '\0';//
            ans.data[p].data[s].word_count++;//increase cnt
            c = 0;
            w++;
            continue;
        }
        ans.data[p].data[s].data[w].data[c++] = text[i];//make word
    }
    return ans;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n-1].data[m-1].data[k-1];//return word
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m-1].data[k-1];//return sentence
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k-1];//return paragraph
}

