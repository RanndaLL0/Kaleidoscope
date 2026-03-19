#ifndef LEXER_H
#define LEXER_H
        
        struct Lexer {

                char* identifier_string;
                double number_value;
                int last_character;

                int (*get_tok)(struct Lexer lexer);
        };

        struct Lexer lexer_constructor();

#endif // !LEXER_H
