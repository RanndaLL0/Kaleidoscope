#include "parser.h"
#include <complex.h>
#include <linux/limits.h>
#include "../token/token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CURRENT_TOKEN = 0;

void free_prototype(struct prototype_ast *prototype) {
        
        for(int i = 0; i < prototype->args.size; i++) {
                free(prototype->args.arr[i]);
        }
        free(prototype->function_name);
        free(prototype);
}

expr_ast *number_constructor_ExprAST(double value) {

        expr_ast *new_expr = (expr_ast *)malloc(sizeof(expr_ast));

        if (new_expr == NULL) {
                perror("Erro ao alocar espaco de memoria para a expressao do tipo double");
        }

        new_expr->type = AST_NUMBER;
        new_expr->as.number.value = value;

        return new_expr;
}


expr_ast *call_constructor_expr_ast(char *call) {
        
        expr_ast *new_expr = (expr_ast *)malloc(sizeof(expr_ast));

        if (new_expr == NULL) {
                perror("Erro ao alocar espaco de memoria para a expressao do tipo call");
                exit(EXIT_FAILURE);
        }
        
        new_expr->type = AST_CALL;
        new_expr->as.call.call = call;
        new_expr->as.call.args = vector_constructor();

        return new_expr;
}

expr_ast *binary_constructor_expr_ast(char op, expr_ast *left_node, expr_ast *right_node) {

        expr_ast *new_expr = (expr_ast *)malloc(sizeof(expr_ast));
        
        if (new_expr == NULL) {
                perror("Erro ao alocar espaco de memoria para a expressao do tipo operador");
        }

        new_expr->type = AST_BINARY;
        new_expr->as.binary.left_node = left_node;
        new_expr->as.binary.right_node = right_node;
        new_expr->as.binary.op = op;
        return new_expr;
}

struct prototype_ast *prototype_ast_constructor(char *name, struct vector args) {
        
        struct prototype_ast *prototype = (struct prototype_ast *)malloc(sizeof(struct prototype_ast));

        if (prototype == NULL) {
                perror("Erro ao alocar espaco de memoria para a prototipo da funcao");
                exit(EXIT_FAILURE);
        } 

        prototype->function_name = strdup(name);
        prototype->args = vector_constructor();
        prototype->free_prototype = free_prototype;
        return prototype;
}

void free_expr_ast(expr_ast *ast) {
        
        if (ast == NULL) {
                perror("Erro ao realizar desalocacao de memoria da expressao");
        }

        switch (ast->type) {
                case AST_NUMBER:
                        break;
                case AST_BINARY:
                        free_expr_ast(ast->as.binary.left_node);
                        free_expr_ast(ast->as.binary.right_node);
                        break;
                case AST_CALL:
                        free(ast->as.call.call);
                        break;
        }

        free(ast);
}

int get_next_token(struct Lexer *lexer) {
        return CURRENT_TOKEN = get_tok(lexer);
}

void log_error(char *str) {
        fprintf(stderr, "Error: %s\n", str);
        return;
}

void log_error_p (char *str) {
        log_error(str);
        return; 
}

struct expr_ast *parse_number_expr(struct Lexer *lexer) {

        struct expr_ast *result = (struct expr_ast *)malloc(sizeof(struct expr_ast));

        if (result == NULL) {
                return NULL;
        }

        result->type = AST_NUMBER;
        result->as.number.value = lexer->number_value;

        get_next_token(lexer);
        return result;
}

// Consume a expressao ( ... )
struct expr_ast *parse_paren_expr(struct Lexer *lexer) {

        get_next_token(lexer);

        struct expr_ast *v = parse_expression(lexer);

        if (!v) {
                return NULL;
        }

        if (CURRENT_TOKEN != ')') {
                log_error("Expected ')'");
                exit(EXIT_FAILURE);
        }

        get_next_token(lexer);
        return v;
}


struct expr_ast *parse_identifier_expr(struct Lexer *lexer) {

        char *id_name = lexer->identifier_string;

        get_next_token(lexer);


        if (CURRENT_TOKEN != '(') {
                struct expr_ast *name_expr = malloc(sizeof(struct expr_ast));
                name_expr->type = AST_VARIABLE;
                name_expr->as.variable.name = id_name;
                return name_expr;
        }

        get_next_token(lexer);

        struct expr_ast *call_expr = malloc(sizeof(struct expr_ast));
        call_expr->type = AST_CALL;
        call_expr->as.call.call = id_name;
        call_expr->as.call.args = vector_constructor();

        if (CURRENT_TOKEN != ')') {
                while (1) {

                        struct expr_ast *arg = parse_expression(lexer);
                        if (!arg) return NULL;

                        call_expr->as.call.args.push(&call_expr->as.call.args, arg);

                        if (CURRENT_TOKEN == ')')
                                break;

                        if (CURRENT_TOKEN != ',') {
                                log_error("Expected ')' or ',' in argument list");
                                return NULL;
                        }

                        get_next_token(lexer);
                }
           }

        get_next_token(lexer);

        return call_expr;
}

struct expr_ast *parse_primary(struct Lexer *lexer) {
        
        switch(CURRENT_TOKEN) {
                case TOK_IDENTIFIER:
                        return parse_identifier_expr(lexer);
                case TOK_NUMBER:
                        return parse_number_expr(lexer);
                case '(':
                        return parse_paren_expr(lexer);
                default:
                        log_error("Token desconhecido quando se espera uma expressão");
                        return NULL;
        }
}

