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
static int token;

void tokenizer(){
    int first=1;
    int tokenSize=0;
    int numChecker=0;
    tokenString = calloc(20, sizeof(char));
    while(1){
        char ch = fgetc(fp);

        if(ch == EOF){
            if(first){
                tokenString[0]='E';
                tokenString[1]='O';
                tokenString[2]='S';
                tokenString[3]='\0';
            }
            break;
        } 
        if(ch == ' ' || ch =='\n' || ch == '\t' || ch == '\r'){
            if(first){
                continue;
            }else{
                break;
            }
        }
        first=0;

        tokenString[tokenSize]=ch;
        tokenSize++;
        
        //Switch and Case to check it is sysmbol
        //If symbol than assign the symbol to the tokenString and break the while loop;
        //If there are something in token break; mark?
        if (ch == '+'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == '-'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == '*'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == '/'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == '='){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == '<'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == ':'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            char next = fgetc(fp);
            if(next == '='){
                tokenString[tokenSize]=next;
                tokenSize++;
            }else{
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == ';'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == '.'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == ','){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == '('){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == ')'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == '['){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }else if(ch == ']'){
            if(tokenSize!=1){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
            }
            break;
        }
        
        int tmp = tokenSize-1;
        if(tokenSize != 1){
            if((numChecker==tmp) &&!(tokenString[tmp]>=48 && tokenString[tmp]<=57)){
                tokenSize--;
                tokenString[tokenSize]='\0';
                fseek( fp, -1, SEEK_CUR);
                break;
            }
        }

        if((tokenString[tmp]>=48 && tokenString[tmp]<=57)){
            numChecker++;
        }

    }
    printf("%s\n", tokenString);
    free(tokenString);
}

int errorChecker(){
    int idx=0;
    int error=0;
    while(tokenString[idx] != '\0'){
        char ch = tokenString[idx];
        if((ch>=33 && ch <= 39) || (ch >=62 && ch<=64) || (ch==92) || (ch>= 94 && ch <= 96) || (ch >=123 && ch<=126) ){
            error=1;
            break;
        }
        idx++;
    }
    return error;
}

int numberChecker(){
    int idx=0;
    int isNumber=1;
    while(tokenString[idx] != '\0'){
        char ch = tokenString[idx];
        if(!(ch>=48 && ch<=57)){
            isNumber=0;
            break;
        }
        idx++;
    }
    return isNumber;

}

void tokenToEnum(){
    if(!strcmp(tokenString, "and")){ //keyword
        token=0;
    }else if(!strcmp(tokenString, "begin")){
        token=1;
    }else if (!strcmp(tokenString, "do")){
        token=2;
    }else if (!strcmp(tokenString, "else")){
        token=3;
    }else if (!strcmp(tokenString, "end")){
        token=4;
    }else if (!strcmp(tokenString, "if")){
        token=5;
    }else if (!strcmp(tokenString, "in")){
        token=6;
    }else if (!strcmp(tokenString, "integer")){
        token=7;
    }else if (!strcmp(tokenString, "is")){
        token=8;
    }else if (!strcmp(tokenString, "new")){
        token=9;
    }else if (!strcmp(tokenString, "not")){
        token=10;
    }else if (!strcmp(tokenString, "or")){
        token=11;
    }else if (!strcmp(tokenString, "out")){
        token=12;
    }else if (!strcmp(tokenString, "procedure")){
        token=13;
    }else if (!strcmp(tokenString, "record")){
        token=14;
    }else if (!strcmp(tokenString, "then")){
        token=15;
    }else if (!strcmp(tokenString, "while")){
        token=16;
    }else if (!strcmp(tokenString, "+")){//symbol
        token=17;
    }else if (!strcmp(tokenString, "-")){
        token=18;
    }else if (!strcmp(tokenString, "*")){
        token=19;
    }else if (!strcmp(tokenString, "/")){
        token=20;
    }else if (!strcmp(tokenString, ":=")){
        token=21;
    }else if (!strcmp(tokenString, "=")){
        token=22;
    }else if (!strcmp(tokenString, "<")){
        token=23;
    }else if (!strcmp(tokenString, ":")){
        token=24;
    }else if (!strcmp(tokenString, ";")){
        token=25;
    }else if (!strcmp(tokenString, ".")){
        token=26;
    }else if (!strcmp(tokenString, ",")){
        token=27;
    }else if (!strcmp(tokenString, "(")){
        token=28;
    }else if (!strcmp(tokenString, ")")){
        token=29;
    }else if (!strcmp(tokenString, "[")){
        token=30;
    }else if (!strcmp(tokenString, "]")){
        token=31;
    }else if (!strcmp(tokenString, "EOS")){//other
        token=34;
    }else{
        if (errorChecker()){
            token=35;
        }else if(numberChecker()){
            token=32;
        }else{
            token=33;
        }
    }
}

//keyword check
//symbol check
//else {
//  if (ASCII (not Symbol)) {ERROR} (x)
//  else if(Number) {Const} (x)
//  else {ID}    
//}



int main(){

    fp = fopen ("Correct/1.code", "r");
    //fp = fopen ("Correct/2.code", "r");
    //fp = fopen ("Correct/3.code", "r");
    //fp = fopen ("Correct/4.code", "r");
    //fp = fopen ("Correct/5.code", "r");
    //fp = fopen ("Correct/6.code", "r");
    //fp = fopen ("Correct/7.code", "r");
    //fp = fopen ("Correct/8.code", "r");
    //fp = fopen ("Correct/9.code", "r");
    //fp = fopen ("Correct/10.code", "r");
    //fp = fopen ("Correct/11.code", "r");
    //fp = fopen ("Correct/12.code", "r");
    //fp = fopen ("Correct/13.code", "r");
    //fp = fopen ("test.code", "r");
    int s;

    
    // for(s=0; s<200;s++){
    //     tokenizer();
    // }


    //----------------------------

    int tmp = 88;
    tokenString = calloc(20, sizeof(char));
    tokenString[0]='1';
    tokenString[1]='8';
    printf("%d\n", numberChecker());
    // printf("%d\n",tmp);
    // printf("%s\n", tokenString);

    char a = 'A';
    char z = 'Z';
    char a2 = 'a';
    char z2 = 'z';
    //printf("A: %d\nZ: %d\na: %d\nz: %d\n", a,z,a2,z2);
    // if(a==tmp){
    //     printf("Same\n");
    // }


    
}