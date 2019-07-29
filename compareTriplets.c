/*
Alice and Bob each created one problem for HackerRank. 
A reviewer rates the two challenges, awarding points on a scale from 1 to 100 for three categories: problem clarity, originality, and difficulty.

We define the rating for Alice's challenge to be the triplet a=(a[0],a[1],a[2]),
and the rating for Bob's challenge to be the triplet b=(b[0],b[1],b[2]).

Your task is to find their comparison points by comparing  with ,  with , and  with .

If a[i]>b[i], then Alice is awarded 1 point.
If a[i]<b[i], then Bob is awarded 1 point.
If a[i]==b[i], then neither person receives a point.
Comparison points is the total points a person earned.

Given a and b, determine their respective comparison points.

For example,a=[1,2,3] and b=[3,2,1]. 
For elements 0, Bob is awarded a point because a[0]<b[0].
For the equal elements 1,a[1] and b[1], no points are earned. 
Finally, for elements 2,a[2]>b[2],so Alice receives a point. 
Your return array would be [1,1] with Alice's score first and Bob's second.

Function Description

Complete the function compareTriplets in the editor below. It must return an array of two integers, the first being Alice's score and the second being Bob's.

compareTriplets has the following parameter(s):

a: an array of integers representing Alice's challenge rating
b: an array of integers representing Bob's challenge rating
Input Format

The first line contains 3 space-separated integers,a[0],a[1],a[2] describing the respective values in triplet . 
The second line contains 3 space-separated integers,b[0],b[1],b[2] describing the respective values in triplet .

Constraints
1<=a[i]<=100
1<=b[i]<=100

Output Format

Return an array of two integers denoting the respective comparison points earned by Alice and Bob.

Sample Input 0
5 6 7
3 6 10

Sample Output 0
1 1

Alice's comparison score is 1, and Bob's comparison score is 1.Thus, we return the array .

Sample Input 1

17 28 30
99 16 8
Sample Output 1

2 1
Explanation 1

Comparing the 0th elements,17<99 so Bob receives a point. 
Comparing the 1st and 2nd elements, 28<16  and 30>8 so Alice receives two points. 
The return array is [2,1].
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
char** split_string(char*);
 int temp[2];
 /*Main Logic of this program lies in compareTriplets function 
	The input to function are a_count array length of Alice and b_count is array length of Bob
	*a and *b are the two pointers pointing to the values passed as an array 
	temp is used to store two compare result that is if Alice wins then temp+0 is incremented by 1
	and if Bob wins then temp+1 is incremented by 1 */
	
 int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
  *result_count=2;
  int i;
  for(i=0;i<a_count && i<b_count;i++){
      if (*(a+i)==*(b+i)) {
          printf("both equal\n");
        }
      if (*(a+i)>*(b+i)){ 
          printf("Alice wins\n");
          *(temp+0)= *(temp+0)+1;
        }
      if (*(b+i)>*(a+i)){ 
          printf("Bob Wins\n");
          *(temp+1)= *(temp+1)+1;
        }
    }
	printf("\n%d %d",*(temp+0),*(temp+1));
    return temp;
}

int main()
{	int i=0;
	FILE* fptr = fopen("CompareTripletsOutput.txt", "w"); //You can see the file in the current directory
	//It will have the final result eg; 0,3 
	
    char** a_temp = split_string(rtrim(readline()));

    int* a = malloc(3 * sizeof(int));
	printf("Problem clarity, originality, and difficulty of Alice and Bob is:\n")
    for (i = 0; i < 3; i++) {
        char* a_item_endptr;
        char* a_item_str = *(a_temp + i);
		int a_item = strtol(a_item_str, &a_item_endptr, 10);

        if (a_item_endptr == a_item_str || *a_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(a + i) = a_item;
    }

    int a_count = 3;

    char** b_temp = split_string(rtrim(readline()));

    int* b = malloc(3 * sizeof(int));

    for (i = 0; i < 3; i++) {
        char* b_item_endptr;
        char* b_item_str = *(b_temp + i);
        int b_item = strtol(b_item_str, &b_item_endptr, 10);

        if (b_item_endptr == b_item_str || *b_item_endptr != '\0') { exit(EXIT_FAILURE); }
 
        *(b + i) = b_item;
    }

    int b_count = 3;

    int result_count;
    int* result = compareTriplets(a_count, a, b_count, b, &result_count);
	fprintf(fptr,"Alice  And  Bob:\n"); //This is commented by me 
    for (i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i)); //This is to print the final result array in the file 

        if (i != result_count - 1) {
            fprintf(fptr, "  \t");
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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}