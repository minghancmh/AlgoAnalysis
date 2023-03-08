/*
PROJECT 1
This is a hybrid sort comprising of mergesort and insertion sort.
*/ 
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;



unsigned long long counter = 0;



// HELPER FUNCTION PRINT ARR

void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

// INSERTION SORT

void insertionSort(int arr[], int start, int end){ // n is the number of elements in the list

    int i,j,key;
    // unsigned long long count = 0;

    for (i=start+1; i<=end; i++){
        key = arr[i];
        j = i-1;

        while(j>=start && arr[j]>key){ // add in counter variable count to determine number of comparisons
            counter++;
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }


    // return count;

}

// unsigned long long insertionSortCaller(int arr[], int n){
    
//     unsigned long long count = insertionSort(arr, n);
//     cout<<"==========INSERTION SORT==============="<<endl;
//     cout<<"Size of array: "<< n<<endl;
//     cout<<"Number of Comparisons: "<< count << endl;
//     return count;
// }

// MERGE SORT

void merge(int arr[], int start, int end){ // will increment global counter
    int mid = (start + end) / 2;
    int a = start;
    int b = mid+1;
    int i, tmp;


    if (end-start <=0){
        return;
    }

    while(a<=mid && b<=end){
        counter++;
        if (arr[a] > arr[b]){
            tmp = arr[b++];
            for (i=++mid; i>a; i--){
                arr[i] = arr[i-1];
            }
            arr[a++] = tmp;
        }
        else if (arr[a] < arr[b]){
            a++;
        }
        else{
            if (a==mid && b==end){
                break;
            }
            tmp = arr[b++];
            a++;
            for (i=++mid; i>a; i--){
                arr[i] = arr[i-1];
            }
            arr[a++] = tmp;
        }
    }
}

void mergeSort(int arr[], int start, int end){
    int mid = (start+end)/2;


    if (end-start <=0){
        return;
    }
    else if (end-start>1){

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        // printArr(arr, 10);
        // cout<<""<<endl;
        
    }
    merge(arr, start, end);


}

unsigned long long mergeSortCaller(int arr[], int n){ // n is the number of elements in the unsorted list
    mergeSort(arr, 0, n-1);
    cout<<"==========MERGE SORT==============="<<endl;
    cout<<"Size of array: "<< n <<endl;
    cout<<"Number of Comparisons: "<< counter << endl;
    return counter;
    counter = 0; // we reset global counter to 0 when we finish sorting the list

}

// HYBRID ALGORITHM
void hybridSort(int arr[], int start, int end){

    // int size = end+1-start;


    if (end-start<=15){

        insertionSort(arr, start, end);
        // return;
    }

    // if (end-start<=0){
    //     return;
    // }
    // else{


    else {
        int mid = (start + end)/2;
        hybridSort(arr, start, mid);
        hybridSort(arr, mid+1, end);
        // printArr(arr, 10);
        // cout<<""<<endl;
        merge(arr, start, end);

    }
        



    // }

}

unsigned long long hybridSortCaller(int arr[], int n){ // n is the number of elements in the unsorted list

    hybridSort(arr,0,n-1);


    cout<<"==========HYBRID SORT==============="<<endl;
    cout<<"Size of array: "<< n <<endl;
    cout<<"Number of Comparisons: "<< counter << endl;
    return counter;
    counter =0; // reset the global counter to 0;


}

// GENERATE RANDOM NUMBERS
int* arrGenerator(int n){
    int *randArr = new int[n];
    for (int i=0; i<n; i++){
        randArr[i] = rand()%99999;
    }
    return randArr;
}


// DRIVER CODE


int main(){
    srand(time(0)); // create a time seed so that the array of random numbers generated is different with each c++ run
    ofstream fout("hybridSortComparison_s100_1kto10m.csv");
    // fout<<"n, HybridSort\n";
    fout<<"n, Insertion Sort, Merge Sort, Hybrid Sort\n";



    for (int i=10000; i<=10000000; i*=10){
    // copying the arrays twice, and then running these 3 arrays through insertion sort, merge sort, hybrid sort respectively
        int *arrI = arrGenerator(i);
        int *arrM = new int[i];
        int *arrH = new int[i];
        for (int s=0; s<i; s++){
            arrM[s] = arrI[s];
            arrH[s] = arrI[s];
        }

        fout<<i<<",";
        // fout<<insertionSortCaller(arrI, i)<<",";
        // counter=0;
        fout<<mergeSortCaller(arrM, i)<<",";
        printArr(arrM, 1000);
        counter=0;
        fout<<hybridSortCaller(arrI, i)<<"\n";
        printArr(arrI, 1000);
        counter=0;
    }


}

