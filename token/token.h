#ifndef TOKEN_H 
#define TOKEN_H

        typedef enum Token {
                TOK_EOF = -1,
                TOK_DEF = -2,
                TOK_EXTERN = -3,
                TOK_IDENTIFIER = -4,
                TOK_NUMBER = -5,
                TOK_ANY = -6 
        };


#endif // !TOKEN_H
