#ifndef PARSER_H 
#define PARSER_H

        #include <stdlib.h>
        #include "../utils/utils.h"
        #include "../lexer/lexer.h"

        typedef enum {
                AST_NUMBER,
                AST_BINARY,
                AST_CALL,
                AST_VARIABLE
        } expr_type;

        typedef struct expr_ast{
                expr_type type;

                union {
                       
                        struct {
                                char *name;
                        } variable;

                        struct {
                                double value;
                        } number;

                        struct {
                                char op;
                                struct expr_ast *left_node;
                                struct expr_ast *right_node;
                        } binary;

                        struct {
                                char *call;
                                struct vector args;
                        } call;

                } as;

        } expr_ast;

        struct prototype_ast {
                char *function_name;
                struct vector args;

                void (* free_prototype)(struct prototype_ast *prototype);
        };

        struct function_ast {
                struct prototype_ast *prototype;
                struct expr_ast *body;
        };

        expr_ast *number_constructor_ExprAST(double value);
        expr_ast *binary_constructor_expr_ast(char op, expr_ast *left_node, expr_ast *right_node);
        expr_ast *call_constructor_expr_ast(char *call);


        struct prototype_ast *prototype_ast_constructor(char *name, struct vector args);
        void free_expr_ast(struct expr_ast *ast);

        int get_next_token(struct Lexer *lexer);

#endif // !PARSER_H
