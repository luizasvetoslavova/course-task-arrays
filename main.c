#include <stdio.h>
#include <stdlib.h>

double get_element(int i, int j);
int is_numeric(const char input[]);
int get_array_size();
int is_positive_integer(const char input[]);
void show_instructions();

int main(int argc, char *argv[]) {
	show_instructions();
	int size = get_array_size();
	double array[size][size];
	
	int i, j;
	//get array values
	for(i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		for(j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); j++) {
			array[i][j] = get_element(i, j);
		}
	}
	
	printf("\nMatrix:\n");
	//show matrix
	for(i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		printf("{ ");
		for(j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); j++) {
			printf("%lf ", array[i][j]);
		}
		printf("}\n");
	}
	printf("\n");
	
	double mean_values[sizeof(array) / sizeof(array[0])];
	//calculate arithmetic mean values
	for(i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		int count = 0;
		double sum = 0;
		for(j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); j++) {
			count++;
			sum += array[i][j];
		}
		double mean_value = sum / count;
		mean_values[i] = mean_value;
	}
	
	printf("Arithmetic mean values of each row:\n");
	//show mean values
	for(i = 0; i < sizeof(mean_values) / sizeof(mean_values[0]); i++) {
		printf("%lf\n", mean_values[i]);
	}
	
	//sort mean values by ascening order
	for(i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
		for(j = 0; j < sizeof(array[0]) / sizeof(array[0][0]); j++) {
			double temp;
			if(mean_values[j] > mean_values[i]) {
				temp = mean_values[i];
				mean_values[i] = mean_values[j];
				mean_values[j] = temp;
			}
		}
	}
	
	printf("\nSorted by ascending order:\n");
	//show sorted values
	for(i = 0; i < sizeof(mean_values) / sizeof(mean_values[0]); i++) {
		printf("%lf\n", mean_values[i]);
	}
	
	return 0;
}

double get_element(int i, int j) {
	double value;
	char value_input[50];
	
	printf("Enter value of row %d, column %d: ", i + 1, j + 1);
	scanf("%49s", &value_input);	
	while(is_numeric(value_input) || atof(value_input) < -1000 || atof(value_input) > 1000) {
		printf("Wrong value! Try again: ");
		scanf("%49s", &value_input);	
	}
	return atof(value_input);
}

int is_numeric(const char input[]) {
    //0=true, 1=false
    if (input[0] == '\0') return 1;

    int has_minus = 0;
    int has_dot = 0;
    int has_digit = 0;
    int i = 0;

    if (input[0] == '-') {
        has_minus = 1;
        i = 1;
        if (input[1] == '\0') return 1;
    } else if (input[0] == '.') {
        return 1; 
    }

    while (input[i] != '\0') {
        if (input[i] >= '0' && input[i] <= '9') {
            has_digit = 1;
        } else if (input[i] == '.') {
            if (has_dot) return 1;
            has_dot = 1;
        } else if (input[i] == '-') {
            return 1;
        } else {
            return 1;
        }
        i++;
    }

    if (has_dot && input[i - 1] == '.') return 1;
    if (!has_digit) return 1;
    return 0;
}

int get_array_size() {
	int size;
	char size_input[50];
	scanf("%49s", &size_input);	
	while(is_positive_integer(size_input)) {
		printf("Wrong value! Try again: ");
		scanf("%49s", &size_input);	
	}
	return atoi(size_input);
}

int is_positive_integer(const char input[]) {
    //0=true, 1=false
    if (input[0] == '\0') return 1;

    int i = 0;
    while (input[i] != '\0') {
        if (input[i] < '1' || input[i] > '9') {
            return 1;
        }
        i++;
    }
    return 0;
}

void show_instructions() {
	printf("Write a program to process a two-dimensional array, A[N][N], containing real numbers within the range[-1000, 1000].\nSolution author: Luiza Svetoslavova\n\n");
	printf("Enter matrix size: ");
}
