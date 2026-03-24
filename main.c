#include <stdio.h>
#include <stdlib.h>


struct dinamic_vector {
	int capacity;
	int size;
	int *arr;

	void (* push)(struct dinamic_vector *vector, int item);
	struct dinamic_vector *vector_constructor(int initial_capacity);
};

void *push(struct dinamic_vector *vector, int item) {
	
	if (vector->capacity == vector->size) {
		vector->capacity = vector->capacity ==  0 ? 2 : vector->capacity * 2;
		int *temp = realloc(vector->arr, vector->capacity * sizeof(int));

		if (temp == NULL) {
			perror("Erro ao realocar o vetor");
			exit(EXIT_FAILURE);
		}
	}

	vector->arr[size++] = item;
}


struct dinamic_vector vector_constructor(int initial_capacity) {

	struct dinamic_vector vector;
	vector.arr = (struct dinamic_vector *)malloc(initial_capacity * sizeof(int));

	if(vector == NULL) {
		perror("Erro ao alocar memoria para o vetor");
		exit(EXIT_FAILURE); 
	}
	
	vector.capacity = initial_capacity;
	vector.size = 0;
	return vector;
}
