
#include "lexer.h"
#include "../token/token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#define MAX_ID_LEN 256

struct Lexer lexer_constructor() {

        struct Lexer lexer;
        lexer.identifier_string = NULL;

        return lexer;
}


int get_tok(struct Lexer *lexer) {

        enum Token token;

        while(isspace(lexer->last_character)) {
                lexer->last_character = getchar();
        }


        if(isalpha(lexer->last_character)) {

                char buffer[MAX_ID_LEN];
                int i = 0;

                buffer[i++] = lexer->last_character;

                lexer->last_character = getchar();

                while (isalnum(lexer->last_character) && i <  MAX_ID_LEN - 1){
                        buffer[i++]= lexer->last_character;
                        lexer->last_character = getchar();
                }

                buffer[i] = '\0';

                if (lexer->identifier_string != NULL) {
                        free(lexer->identifier_string);
                }

                lexer->identifier_string = malloc(strlen(buffer) + 1);
                strcpy(lexer->identifier_string, buffer);

                if (strcmp(lexer->identifier_string, "def") == 0) {
                        return TOK_DEF;
                }
                if (strcmp(lexer->identifier_string,"extern") == 0) {
                        return TOK_EXTERN;
                }
                return TOK_IDENTIFIER;
        }


        if (isdigit(lexer->last_character) || lexer->last_character == '.') {
                
                char buffer[MAX_ID_LEN];
                int i = 0;
                
                do { 
                       buffer[i++] = lexer->last_character;
                       lexer->last_character = getchar();

                } while (isdigit(lexer->last_character) || lexer->last_character == '.');

                buffer[i] = '\0';

                lexer->number_value = strtod(buffer, NULL);

                return TOK_NUMBER;
        }

        if (lexer->last_character == '#') {
               
                do {
                        lexer->last_character = getchar();
                } while(lexer->last_character != EOF && lexer->last_character != '\n' && lexer->last_character != '\r');

                if (lexer->last_character != EOF) {
                        return get_tok(lexer);
                }
        } 

        if (lexer->last_character == EOF) {
                return TOK_EOF;
        }

        lexer->last_character = getchar();
        return TOK_ANY;
}
