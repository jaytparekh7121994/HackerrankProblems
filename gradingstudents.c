
/*
HackerLand University has the following grading policy:

Every student receives a grade in the inclusive range from 0 to 100.
Any grade less than 40 is a failing grade.
Sam is a professor at the university and likes to round each student's grade according to these rules:

If the difference between the grade and the next multiple of 5 is less than 3, round grade up to the next multiple of 5.
If the value of grade is less than 40, no rounding occurs as the result will still be a failing grade.
For example, grade=84  will be rounded to 85 but grade=29 will not be rounded because the rounding would result in a number that is less than 40.

Given the initial value of grading for each of Sam's n students, write code to automate the rounding process.

Function Description

Complete the function gradingStudents in the editor below. It should return an integer array consisting of rounded grades.

gradingStudents has the following parameter(s):

grades: an array of integers representing grades before rounding

Input Format

The first line contains a single integer, , the number of students. 
Each line i of the n subsequent lines contains a single integer,grades[i], denoting student i's grade.

Constraints

Output Format

For each grades[i], print the rounded grade on a new line.

Sample Input 0

4
73
67
38
33
Sample Output 0

75
67
40
33
Explanation 0



Student 1 received a 73, and the next multiple of 5 from 73 is 75. Since 75-73=2<3, the student's grade is rounded to 75.
Student 2 received a 67, and the next multiple of 5 from 67 is 70. Since 70-67=3, the grade will not be modified and the student's final grade is 67.
Student 3 received a 38, and the next multiple of 5 from 38 is 40. Since 40-38=2<3, the student's grade will be rounded to 40.
Student 4 received a grade below 38 ie; 33, so the grade will not be modified and the student's final grade is 33 .
*/


#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'gradingStudents' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY grades as parameter.
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 *
 * For example,
 * int* return_integer_array_using_static_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     static int a[5] = {1, 2, 3, 4, 5};
 *
 *     return a;
 * }
 *
 * int* return_integer_array_using_dynamic_allocation(int* result_count) {
 *     *result_count = 5;
 *
 *     int *a = malloc(5 * sizeof(int));
 *
 *     for (int i = 0; i < 5; i++) {
 *         *(a + i) = i + 1;
 *     }
 *
 *     return a;
 * }
 *
 */

int* gradingStudents(int grades_count, int* grades, int* result_count) {
    
    *result_count=grades_count;

    int i=0,temp=0,tempten=0;
    if (grades_count>=1 && grades_count<=60){
        for(i=0;i<grades_count;i++){
        temp=*(grades+i)%5;
        tempten=*(grades+i)%10;
        
            if(*(grades+i)>37 &&*(grades+i)<=100 ){
                if(temp==0){
                    *(grades+i)=*(grades+i);
                }
                else if(temp>2 && tempten<=4){
                    *(grades+i)=*(grades+i)+(5-temp);
                }
                else if (temp>2 && tempten>7){
                    *(grades+i)=*(grades+i)+(10-tempten);
                }
        
            }
            else {
                *(grades+i)=*(grades+i);
            }
        }
    }
    return grades;
}

int main()
{
	int i=0;
    FILE* fptr = fopen("gradingStudentsMarks.txt", "w");

    int grades_count = parse_int(ltrim(rtrim(readline())));

    int* grades = malloc(grades_count * sizeof(int));

    for ( i = 0; i < grades_count; i++) {
        int grades_item = parse_int(ltrim(rtrim(readline())));

        *(grades + i) = grades_item;
    }

    int result_count;
    int* result = gradingStudents(grades_count, grades, &result_count);

    for ( i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}




/* Must Try This outputs 
Inputs 
44
84    
94
21
0
18
100
18
62
30
61
53
0
43
2
29
53
61
40
14
4
29
98
37
23
46
9
79
62
20
38
51
99
59
47
4
86
61
68
17
45
6
1
95
95

Expected Outputs
85
95
21
0
18
100
18
62
30
61
55
0
45
2
29
55
61
40
14
4
29
100
37
23
46
9
80
62
20
40
51
100
60
47
4
86
61
70
17
45
6
1
95
95
*/
