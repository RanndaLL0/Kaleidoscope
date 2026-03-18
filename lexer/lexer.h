#ifndef LEXER_H
#define LEXER_H

        struct Lexer {

                char* identifier_string;
                double number_value;
        };

        struct Lexer lexer_constructor();

#endif // !LEXER_H
