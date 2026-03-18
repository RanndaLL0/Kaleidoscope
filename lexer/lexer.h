#ifndef LEXER_H
#define LEXER_H
        
        #define "../token/token.h"

        struct Lexer {

                char* identifier_string;
                double number_value;
                int last_character;

                Token (*get_tok)(struct Lexer lexer);
        };

        struct Lexer lexer_constructor();

#endif // !LEXER_H
