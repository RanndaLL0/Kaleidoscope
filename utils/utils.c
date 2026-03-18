#include <string.h>
#include <stdlib.h>


/*
 * Esta funcao exige que a memoria seja limpa
 * */
char *concat_string(char *string, char character) {
        
        int len = strlen(string);

        char *new_string = realloc(string, (len + 2) * sizeof(char));
        if (new_string == NULL) {
                perror("Erro ao concatenar nova string");
        }

        new_string[len] = character;
        new_string[len + 1] = '\0';

        return new_string;
}
