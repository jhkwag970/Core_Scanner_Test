#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 


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
static char* tokenString;
static int i = 0;
static int eof=0;

void nextToken(){
    int first=1;
    int tokenSize=0;
    tokenString = calloc(20, sizeof(char));
    while(1){
        char ch = fgetc(fp);

        if(ch == EOF){
            if(first){
                tokenString[0]='E';
                tokenString[1]='O';
                tokenString[2]='S';
            }
            break;
        } 
        if(ch == ' ' || ch =='\n'){
            if(first){
                continue;
            }else{
                break;
            }
        }
        first=0;


        tokenString[tokenSize]=ch;
        tokenSize++;
        i++;

    }
    printf("%s\n", tokenString);
    free(tokenString);

}

int main(){

    fp = fopen ("Correct/1.code", "r");
    int s;
    for(s=0; s<14;s++){
        nextToken();
    }

   
    
}