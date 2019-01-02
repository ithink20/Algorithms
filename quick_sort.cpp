/*
    author: @vikasc
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <fstream>


using namespace std;

const int MAX = 10e5;

typedef long long int lint;

lint first_comparison = 0;
lint last_comparison = 0;
lint mid_comparison = 0;

int partition_first(int *A, int start, int end) {
    int i = start + 1;
    int piv = A[start];             // taking 1st element as pivot
    for (int j = start + 1; j <= end; ++j) {
        if (A[j] < piv) {
            first_comparison += 1;
            swap(A[i], A[j]);
            ++i;
        }
    }
    swap(A[start], A[i - 1]);
    return i - 1;       // return pivot_position
}

void quick_sort_first(int *A, int start, int end) {
    if (start < end) {
        int piv = partition_first(A, start, end);
        quick_sort_first(A, start, piv - 1);
        quick_sort_first(A, piv + 1, end);
    }
}

int partition_last(int *A, int start, int end) {
    int i = start;
    int piv = A[end];           // taking last element as pivot
    for (int j = start; j < end; ++j) {
        if (A[j] <= piv) {
            last_comparison += 1;
            swap(A[j], A[i]);
            ++i;
        }
    }
    swap(A[i], piv);
    return i;
}

void quick_sort_last(int *A, int start, int end) {
    if (start < end) {
        int piv = partition_last(A, start, end);
        quick_sort_last(A, start, piv - 1);
        quick_sort_last(A, piv + 1, end);
    }
}

void quick_sort_mid(int *A, int start, int end) {
    if (start < end) {
        int pivot = A[(start + end) / 2];
        int i = start, j = end;
        while (i <= j) {
            while (A[i] < pivot) {
                mid_comparison += 1;
                i += 1;
            }
            while (A[j] > pivot) {
                mid_comparison += 1;
                j -= 1;
            }
            if (i <= j) {
                swap(A[i], A[j]);
                i += 1;
                j -= 1;
            }
        }
        quick_sort_mid(A, start, j);
        quick_sort_mid(A, i, end);
    }
}

int main() {
    int size = 0, N, A[MAX];
    fstream myfile("IntegerArray.txt"); // read integer text file.
    while (myfile >> N) {
        A[size] = N;
        size += 1;
    }
    quick_sort_first(A, 0, N - 1);
    // for (int i = 0; i < N; ++i) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    cout << "first_comparison : " << first_comparison << endl;
    quick_sort_last(A, 0, N - 1);
    // for (int i = 0; i < N; ++i) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    cout << "last_comparison : " << last_comparison << endl;
    quick_sort_mid(A, 0, N - 1);
    // for (int i = 0; i < N; ++i) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    cout << "mid_comparison : " << mid_comparison << endl;
    // for (int i = 0; i < N; ++i) {
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    return 0;
}
