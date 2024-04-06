#include <stdio.h>
#include <stdlib.h>

int strcp(char* src,char* dest);

typedef struct Book {
    long id;
    char name[10];
    int copies;

} Book;

typedef struct BooksVector{
    Book books[4];
    int size;
    int currentIdx;
} BooksVector;

int getBooksVectorSize(Book * booksVector){
    return sizeof booksVector / sizeof booksVector[0];
}

// int duplicateArray(Book * orig, Book * dest){
//     Book * destPointer = dest;
//     Book * origPointer = orig;
//     for(int i=0;i< sizeof(orig);i++){
//         destPointer = origPointer;
//         origPointer++;
//         destPointer++;
//     }
// }

int pushBook(BooksVector* lib,Book* newBookPointer){
    if(getBooksVectorSize(lib->books)+1>=lib->size) {
        int newSize = lib->size*2;
        realloc(lib->books,newSize);
    }
        lib->books[lib->currentIdx] = *newBookPointer;
        lib->currentIdx++;
}

int getBookFromClient(Book * bookPointer){
    
    char bookName[10];
    printf("type a book to add: ");
    fgets(bookName,sizeof(bookName),stdin);    
    strcp(bookName,bookPointer->name);

    printf("type number of copies: ");
    scanf(" %d",&(bookPointer->copies));
    
    printf("Id: ");
    scanf(" %s",&(bookPointer->id));
    return 0;
}
void initLib(BooksVector* lib){
    lib->size = 4;
    lib->currentIdx = 0;
}
int strcp(char* src,char* dest){
    char * srcPointer = src;
    char * destPointer = dest;
    while(*srcPointer != '\0'){
        *destPointer = *srcPointer;
        srcPointer++;
        destPointer++;
    }
    *destPointer = "\0";
    return 0;
}
int main(void) {
    BooksVector* lib = malloc(sizeof(BooksVector));
    initLib(lib);
    while(1){
        Book* b = malloc(sizeof(Book));
        getBookFromClient(b);
        pushBook(lib,b);
    }
    return 0;
}

// }
// void convertTime(int seconds, int* sp, int* mp, int* hp)
// {
//     *hp = seconds/3600;
//     *mp = seconds/60;
//     *sp = seconds;
// }