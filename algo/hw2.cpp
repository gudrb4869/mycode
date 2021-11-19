#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
using namespace std;

int input1[3], input2[3]; //sorted, random input
double result1[2][3], result2[8][3]; // sorted, random data result
char sr[] = "sorted";
char rd[] = "random";
char sp[] = " ";
char ms[] = "Merge Sort";
char qs[] = "Quick Sort";
char d1[] = "data 1";
char d2[] = "data 2";
char d3[] = "data 3";
char av[] = "average";

void merge(int arr[], int l, int m, int r){
    int i = l, j = m + 1, k = l;
    int *brr = new int [r + 1];
    while(i <= m && j <= r){
        if(arr[i] < arr[j]){
            brr[k++] = arr[i++];
        }
        else{
            brr[k++] = arr[j++];
        }
    }
    if(i > m)
        while(j <= r)
            brr[k++] = arr[j++];
    else
        while(i <= m)
            brr[k++] = arr[i++];

    for(int i = l; i <= r; i++){
        arr[i] = brr[i];
    }
    delete[] brr;
}

void mergesort(int arr[], int l, int r){
    int m;
    if(l < r){
        m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int l, int r){
    int i= l + 1, j = l, pivot = arr[l];
    while(i <= r){
        if(arr[i] < pivot){
            j++;
            swap(arr[i], arr[j]);
        }
        i++;
    }
    swap(arr[l], arr[j]);
    return j;
}

void quicksort(int arr[], int l, int r){
    int p;
    if(l < r){
        p = partition(arr, l, r);
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, r);
    }
}

int main(){
    srand((unsigned int)time(NULL));
    ifstream fin("input.txt");
    
    if(!fin){
        printf("File can't open.\n");
        return 0;
    }

    for(int i = 0; i < 3; i++){
        fin >> input1[i];

        int *m = new int[input1[i]];
        int *q = new int[input1[i]];
        
        for(int j = 0; j < input1[i]; j++){
            m[j] = q[j] = j;
        }

        clock_t s = clock();
        mergesort(m, 0, input1[i] - 1);
        clock_t e = clock();
        clock_t d = e - s;
        result1[0][i] = (double)(d) / CLOCKS_PER_SEC;
        
        s = clock();
        quicksort(q, 0, input1[i] - 1);
        e = clock();
        d = e - s;
        result1[1][i] = (double)(d) / CLOCKS_PER_SEC;

        delete[] m, q;
    }
    
    for(int i = 0; i < 3; i++){
        fin >> input2[i];

        int* m = new int[input2[i]];
        int* q = new int[input2[i]];
        
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < input2[i]; k++){
                int val = (rand() << 15 | rand());
                m[k] = q[k] = val;
            }

            clock_t s = clock();
            mergesort(m, 0, input2[i] - 1);
            clock_t e = clock();
            clock_t d = e - s;
            result2[0 + j][i] = (double)(d) / CLOCKS_PER_SEC;
            result2[3][i] += result2[0 + j][i];
            
            s = clock();
            quicksort(q, 0, input2[i] - 1);
            e = clock();
            d = e - s;
            result2[4 + j][i] = (double)(d) / CLOCKS_PER_SEC;
            result2[7][i] += result2[4 + j][i];
        }
        result2[3][i] /= 3.0;
        result2[7][i] /= 3.0;
        delete[] m, q;
    }

    printf("%10s\t N=%-7d\t N=%-7d\t N=%-7d\n", sr, input1[0], input1[1], input1[2]);
    printf("%10s\t %-.6lf\t %-.6lf\t %-.6lf\n", ms, result1[0][0], result1[0][1], result1[0][2]);
    printf("%10s\t %-.6lf\t %-.6lf\t %-.6lf\n", qs, result1[1][0], result1[1][1], result1[1][2]);

    printf("\n\n");

    printf("%10s\t %8s\t N=%-7d\t N=%-7d\t N=%-7d\n", rd, sp, input2[0], input2[1], input2[2]);
    printf("%10s\t %8s\t %-.6lf\t %-.6lf\t %-.6lf\n", sp, d1, result2[0][0], result2[0][1], result2[0][2]);
    printf("%10s\t %8s\t %-.6lf\t %-.6lf\t %-.6lf\n", ms, d2, result2[1][0], result2[1][1], result2[1][2]);
    printf("%10s\t %8s\t %-.6lf\t %-.6lf\t %-.6lf\n", sp, d3, result2[2][0], result2[2][1], result2[2][2]);
    printf("%10s\t %8s\t %-.6lf\t %-.6lf\t %-.6lf\n", sp, av, result2[3][0], result2[3][1], result2[3][2]);
    printf("%10s\t %8s\t %-.6lf\t %-.6lf\t %-.6lf\n", sp, d1, result2[4][0], result2[4][1], result2[4][2]);
    printf("%10s\t %8s\t %-.6lf\t %-.6lf\t %-.6lf\n", qs, d2, result2[5][0], result2[5][1], result2[5][2]);
    printf("%10s\t %8s\t %-.6lf\t %-.6lf\t %-.6lf\n", sp, d3, result2[6][0], result2[6][1], result2[6][2]);
    printf("%10s\t %8s\t %-.6lf\t %-.6lf\t %-.6lf\n", sp, av, result2[7][0], result2[7][1], result2[7][2]);
    return 0;
}
