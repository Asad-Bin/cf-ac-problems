//...Bismillahir Rahmanir Rahim...
// Code by    Asad Bin Saber
// 11 04 2020

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>
#include <iostream>

using namespace std;

#define    ll   long long

void task()
{
    char str[201], output[201];

    scanf(" %[^\n]", str);

    int len = strlen(str), i=0;

    for(int K=0; K<len; K++){
        if(str[K]=='W' && str[K+1]=='U' && str[K+2]=='B'){
            K+=2;
        }
        else{
            output[i] = str[K];
            i++;
            if(K<len-3 && str[K+1]=='W' && str[K+2]=='U' && str[K+3]=='B'){
                output[i] = ' ';
                i++;

                K+=3;
            }
        }
    }
    output[i] = '\0';

    cout << output << endl;
}

int main()
{
    //clock_t tStart = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    task();

    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    return 0;
}
