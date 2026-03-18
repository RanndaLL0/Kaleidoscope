
#include "lexer.h"
#include "../utils/utils.h"
#include "../token/token.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Lexer lexer_constructor() {

        struct Lexer lexer;
        lexer.identifier_string = NULL;

        return lexer;
}


Token get_tok(struct Lexer *lexer) {
        int last_character = ' ';
        enum Token token;

        while(isspace(last_character)) {
                last_character = getchar();
        }


        if(isalpha(last_character)) {
                lexer->identifier_string = concat_string(lexer->identifier_string, (char)last_character); 
                while (isalpha(last_character = getchar())) {
                        lexer->identifier_string = concat_string(lexer->identifier_string, (char)last_character);
                }

                if (strcmp(lexer->identifier_string, "def") == 0) {
                        return TOK_DEF;
                }
                if (lexer->identifier_string == "extern") {
                        return TOK_EXTERN;
                }
                return TOK_IDENTIFIER;
        }
}
