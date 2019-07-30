/*
Sam's house has an apple tree and an orange tree that yield an abundance of fruit. In the diagram below, the red region denotes his house, where  is the start point, and  is the endpoint. The apple tree is to the left of his house, and the orange tree is to its right. You can assume the trees are located on a single point, where the apple tree is at point , and the orange tree is at point .

Apple and orange(2).png

When a fruit falls from its tree, it lands  units of distance from its tree of origin along the -axis. A negative value of  means the fruit fell  units to the tree's left, and a positive value of  means it falls  units to the tree's right.

Given the value of  for  apples and  oranges, determine how many apples and oranges will fall on Sam's house (i.e., in the inclusive range )?

For example, Sam's house is between s=7 and t=10. 
The apple tree is located at a=4 and the orange at t=10.
There are m=3 apples and n=3 oranges.
Apples are thrown apples=[2,3,-4] units distance from a, and oranges=[3,-2,-4] units distance.
Adding each apple distance to the position of the tree, they land at[4+2,4+3,4+-4]=[6,7,0].
Oranges land at [12+3,12+-2,12+-4]=[15,10,8]. 
One apple and two oranges land in the inclusive range 7-10 so we print

1
2

Function Description
Complete the countApplesAndOranges function in the editor below.
It should print the number of apples and oranges that land on Sam's house, each on a separate line.

countApplesAndOranges has the following parameter(s):

s: integer, starting point of Sam's house location.
t: integer, ending location of Sam's house location.
a: integer, location of the Apple tree.
b: integer, location of the Orange tree.
apples: integer array, distances at which each apple falls from the tree.
oranges: integer array, distances at which each orange falls from the tree.
Input Format

The first line contains two space-separated integers denoting the respective values of s and t. 
The second line contains two space-separated integers denoting the respective values of a and b. 
The third line contains two space-separated integers denoting the respective values of m and n. 
The fourth line contains m space-separated integers denoting the respective distances that each apple falls from point . 
The fifth line contains n space-separated integers denoting the respective distances that each orange falls from point .

Constraints
1<=s,t,a,b,m,n<=10000
-100000<d<100000
a<s<t<b

Output Format
Print two integers on two different lines:
The first integer: the number of apples that fall on Sam's house.
The second integer: the number of oranges that fall on Sam's house.

Sample Input 0
7 11
5 15
3 2
-2 2 1
5 -6

Sample Output 0
1
1

Explanation 0

The first apple falls at position 5-2=3. 
The second apple falls at position 5+2=7. 
The third apple falls at position 5+1=6. 
The first orange falls at position 15+5=20. 
The second orange falls at position 15-6=9. 
Only one fruit (the second apple) falls within the region between 7 and 11, so we print 1 as our first line of output. 
Only the second orange falls within the region between 7 and 11, so we print 1 as our second line of output.
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);


//countApplesAndOranges is the main logic behind the problem. Only bother about this function
void countApplesAndOranges(int s, int t, int a, int b, int apples_count, int* apples, int oranges_count, int* oranges) {
    int i,count=0;
    for(i=0;i<apples_count;i++){
        if(a+*(apples+i)>=s && a+*(apples+i)<=t){
            ++count;
        }
    }
    printf("%d\n",count);
    
    count=0;
    for(i=0;i<oranges_count;i++){
        if(b+*(oranges+i)<=t && b+*(oranges+i)>=s){
            ++count;
        }
    }
    printf("%d",count);
}

int main()
{
	int i=0;
    char** st = split_string(readline());

    char* s_endptr;
    char* s_str = st[0];
    int s = strtol(s_str, &s_endptr, 10);

    if (s_endptr == s_str || *s_endptr != '\0') { exit(EXIT_FAILURE); }

    char* t_endptr;
    char* t_str = st[1];
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    char** ab = split_string(readline());

    char* a_endptr;
    char* a_str = ab[0];
    int a = strtol(a_str, &a_endptr, 10);

    if (a_endptr == a_str || *a_endptr != '\0') { exit(EXIT_FAILURE); }

    char* b_endptr;
    char* b_str = ab[1];
    int b = strtol(b_str, &b_endptr, 10);

    if (b_endptr == b_str || *b_endptr != '\0') { exit(EXIT_FAILURE); }

    char** mn = split_string(readline());

    char* m_endptr;
    char* m_str = mn[0];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n_endptr;
    char* n_str = mn[1];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** apples_temp = split_string(readline());

    int* apples = malloc(m * sizeof(int));

    for (i = 0; i < m; i++) {
        char* apples_item_endptr;
        char* apples_item_str = *(apples_temp + i);
        int apples_item = strtol(apples_item_str, &apples_item_endptr, 10);

        if (apples_item_endptr == apples_item_str || *apples_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(apples + i) = apples_item;
    }

    int apples_count = m;

    char** oranges_temp = split_string(readline());

    int* oranges = malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        char* oranges_item_endptr;
        char* oranges_item_str = *(oranges_temp + i);
        int oranges_item = strtol(oranges_item_str, &oranges_item_endptr, 10);

        if (oranges_item_endptr == oranges_item_str || *oranges_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(oranges + i) = oranges_item;
    }

    int oranges_count = n;

    countApplesAndOranges(s, t, a, b, apples_count, apples, oranges_count, oranges);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
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
