#include "parser.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        new_expr->as.call.call = call;
        new_expr->as.call.args = vector_constructor();

        return new_expr;
}

expr_ast *binary_constructor_expr_ast(char op, expr_ast *left_node, expr_ast *right_node) {

        expr_ast *new_expr = (expr_ast *)malloc(sizeof(expr_ast));
        
        if (new_expr == NULL) {
                perror("Erro ao alocar espaco de memoria para a expressao do tipo operador");
        }

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
}

void free_expr_ast(expr_ast *ast) {
        
        if (ast == NULL) {
                perror("Erro ao realizar desalocacao de memoria da expressao");
        }

        switch (ast->type) {
                case AST_NUMBER:
                        break;
                case AST_BINARY:
                        free(ast->as.binary.left_node);
                        free(ast->as.binary.right_node);
                        break;
                case AST_CALL:
                        free(ast->as.call.call);
                        break;
        }

        free(ast);
}

