#include <stdio.h>
int main() {
    int marks[10];  // Array to store marks of 10 students
    int sum = 0, highest, lowest, aboveAverageCount = 0;
    float average;

    // Input marks for 10 students
    printf("Enter marks for 10 students:\n");
    for(int i = 0; i < 10; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];  // Accumulate sum of marks
    }

    // Calculate average marks
    average = sum / 10.0;

    // Find highest and lowest marks
    highest = marks[0];
    lowest = marks[0];
    
    for(int i = 1; i < 10; i++) {
        if(marks[i] > highest) {
            highest = marks[i];
        }
        if(marks[i] < lowest) {
            lowest = marks[i];
        }
    }

    // Count how many students scored above average
    for(int i = 0; i < 10; i++) {
        if(marks[i] > average) {
            aboveAverageCount++;
        }
    }

    // Output results
    printf("\nAverage Marks: %.2f\n", average);
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks: %d\n", lowest);
    printf("Number of students who scored above average: %d\n", aboveAverageCount);

    return 0;
}