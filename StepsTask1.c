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
    if (token != NULL) { 
       strcpy(date, token);
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

FILE *open_file(char fileName[], char mode[]) {
    FILE *file = fopen(fileName, mode);
    if (file == NULL) {
        perror("");
        exit(1);
    }
    return file;
}


// Complete the main function
int main() {
    FITNESS_DATA data[128];
    char FitnessData_2023 [] = "FitnessData_2023.csv";
    FILE *file = open_file(FitnessData_2023, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    char *delimeter = ", ";
    int i=0;
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        char *stepsTemp = (char *) malloc(6);
        char *dateTemp = (char *) malloc(11);
        char *timeTemp = (char *) malloc(6);
        tokeniseRecord(line_buffer, delimeter, dateTemp, timeTemp, stepsTemp);

        strcpy(data[i].date, dateTemp);
        strcpy(data[i].time, timeTemp);
        data[i].steps = atoi(stepsTemp);

        i++;
    }
    
    printf("number of records in file: %d \n", i);
    printf("%s/%s/%d \n",data[0].date,data[0].time,data[0].steps);
    printf("%s/%s/%d \n",data[1].date,data[1].time,data[1].steps);
    printf("%s/%s/%d \n",data[2].date,data[2].time,data[2].steps);

    fclose(file);
    return 0;
}


