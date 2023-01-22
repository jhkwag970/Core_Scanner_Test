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

void tokenToEnum(){
    if(!strcmp(tokenString, "and")){
        token=0;
    }else if(!strcmp(tokenString, "begin")){
        token=0;
    }else if (!strcmp(tokenString, "do")){
        token=0;
    }else if (!strcmp(tokenString, "else")){
        token=0;
    }else if (!strcmp(tokenString, "end")){
        token=0;
    }else if (!strcmp(tokenString, "if")){
        token=0;
    }else if (!strcmp(tokenString, "in")){
        token=0;
    }else if (!strcmp(tokenString, ":=")){
        token=0;
    }else if (!strcmp(tokenString, "integer")){
        token=0;
    }else if (!strcmp(tokenString, "is")){
        token=0;
    }else if (!strcmp(tokenString, "new")){
        token=0;
    }else if (!strcmp(tokenString, "not")){
        token=0;
    }else if (!strcmp(tokenString, "or")){
        token=0;
    }else if (!strcmp(tokenString, "out")){
        token=0;
    }else if (!strcmp(tokenString, "procedure")){
        token=0;
    }else if (!strcmp(tokenString, "record")){
        token=0;
    }else if (!strcmp(tokenString, "then")){
        token=0;
    }else if (!strcmp(tokenString, "while")){
        token=0;
    }else if (!strcmp(tokenString, "+")){
        token=0;
    }else if (!strcmp(tokenString, "-")){
        token=0;
    }else if (!strcmp(tokenString, "*")){
        token=0;
    }else if (!strcmp(tokenString, "/")){
        token=0;
    }else if (!strcmp(tokenString, ":=")){
        token=0;
    }else if (!strcmp(tokenString, "=")){
        token=0;
    }else if (!strcmp(tokenString, "<")){
        token=0;
    }else if (!strcmp(tokenString, ":")){
        token=0;
    }else if (!strcmp(tokenString, ";")){
        token=0;
    }else if (!strcmp(tokenString, ".")){
        token=0;
    }else if (!strcmp(tokenString, ",")){
        token=0;
    }else if (!strcmp(tokenString, "(")){
        token=0;
    }else if (!strcmp(tokenString, ")")){
        token=0;
    }else if (!strcmp(tokenString, "[")){
        token=0;
    }else if (!strcmp(tokenString, "]")){
        token=0;
    }else{

    }

}

//keyword check
//symbol check
//else {
//  if (ASCII (not Symbol)) {ERROR}
//  else if(Number) {Const}
//  else if (EOS) {EOS}
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

    tokenString = calloc(20, sizeof(char));
    // tokenString[0]='8';
    // tokenString[1]='B';
    // int tmp = atoi(tokenString);
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