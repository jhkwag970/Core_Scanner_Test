#include<stdio.h>

enum core {
    // Keywords
    AND,
    BEGIN,
    DO,
    ELSE,
    END,
    IF,
    IN,
	INTEGER,
    IS,
    NEW,
    NOT,
    OR,
    OUT,
    PROCEDURE,
    RECORD,
    THEN,
    WHILE,
    // Symbols
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    ASSIGN,
    EQUAL,
    LESS,
    COLON,
    SEMICOLON,
    PERIOD,
	COMMA,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    // Others
    CONST,
    ID,
    EOS,
    ERROR
};
static FILE* fp;
int i = 0;

void nextToken(){
    int first=1;
    while(1){
        char ch = fgetc(fp);

        if(ch == EOF) break;
        if(ch == ' ' || ch =='\n'){
            if(first){
                continue;
            }else{
                break;
            }
        }
        first=0;

        //printf("<%d> %c\n",i, ch);
        printf("%c",ch);
        i++;

    }
    printf("\n");

}

int main(){

    fp = fopen ("1.1.code", "r");
    int s;
    for(s=0; s<12;s++){
        nextToken();
    }

   
    
}