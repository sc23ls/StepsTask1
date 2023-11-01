#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

FILE *open_file(char FitnessData_2023[], char mode[]) {
    FILE *file = fopen(FitnessData_2023, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}


// Complete the main function
int main() {
    FITNESS_DATA data[250];
    char FitnessData_2023 [] = "FitnessData_2023.csv";
    FILE *file = open_file(FitnessData_2023, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    int i=0;
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        tokeniseRecord(put stuff here);
        printf("%s", line_buffer);
    }

    fclose(file);
    return 0;
}


