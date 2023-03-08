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

unsigned long long insertionSort(int arr[], int n){ // n is the number of elements in the list

    int i,j,key;
    unsigned long long count = 0;

    for (i=1; i<n; i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key){ // add in counter variable count to determine number of comparisons
            count++;
            arr[j+1] = arr[j];
            j=j-1;
        }

        arr[j+1] = key;
    }


    return count;

}

void insertionSortCaller(int arr[], int n){
    
    unsigned long long count = insertionSort(arr, n);
    cout<<"==========INSERTION SORT==============="<<endl;
    cout<<"Size of array: "<< n<<endl;
    cout<<"Number of Comparisons: "<< count << endl;
}

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
    }
    merge(arr, start, end);

}

void mergeSortCaller(int arr[], int n){ // n is the number of elements in the unsorted list
    mergeSort(arr, 0, n-1);
    cout<<"==========MERGE SORT==============="<<endl;
    cout<<"Size of array: "<< n <<endl;
    cout<<"Number of Comparisons: "<< counter << endl;
    counter = 0; // we reset global counter to 0 when we finish sorting the list

}


void hybridSort(int arr[], int start, int end){
    int mid = (start + end)/2;
    int size = end+1-start;
    int insertionSorted = 0;

    if (size<=50){

        counter += insertionSort(arr, size);
        return;
    }

    if (end-start<=0){
        return;
    }
    // else{


    else if (end-start>1){
        hybridSort(arr, start, mid);
        hybridSort(arr, mid+1, end);
        // printArr(arr, 10);
        // cout<<""<<endl;

    }
        merge(arr, start, end);



    // }

}
// HYBRID ALGORITHM
void hybridSort(int arr[], int start, int end, int threshold){
    int mid = (start + end)/2;
    int size = end+1-start;
    int insertionSorted = 0;
    
    if (size<=threshold){

        counter += insertionSort(arr, size);
        return;
    }
    if (end-start<=0){
        return;
    }

    else if (end-start>1){
        hybridSort(arr, start, mid, threshold);
        hybridSort(arr, mid+1, end, threshold);
    }

    merge(arr, start, end);

}



unsigned long long hybridSortCaller(int arr[], int n, int threshold){ // n is the number of elements in the unsorted list
    hybridSort(arr,0,n-1, threshold);
    cout<<"==========HYBRID SORT==============="<<endl;
    cout<<"Size of array: "<< n <<endl;
    cout<<"Number of Comparisons: "<< counter << endl;
    return counter;
    // counter =0; // reset the global counter to 0;


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

    // ofstream fout("dataset1000.csv");
    // fout<<"s, minComparisons\n";
    

    // for (int i=0; i<100; i++){
    //     unsigned long long minNum = 999999999999999;
    //     int s_val;
    //     for (int s=0; s<=500; s+=1){
    //         int *arrIn = arrGenerator(1000);
    //         unsigned long long num = hybridSortCaller(arrIn, 1000, s);
    //         if (num<minNum){
    //             minNum=num;
    //             s_val = s;
    //         }
    //         counter = 0;
    //         // fout<< s << "," << num<<", \n";

    //     }
    //     fout<<s_val<<","<<minNum<<", \n";



    // }


    ofstream fout("variableS_50000(s to 2000).csv");
    fout << "s, numComparisons, \n";



    for (int s=0; s<=2000; s+=20){
        int *arrIn = arrGenerator(50000);
        unsigned long long num = hybridSortCaller(arrIn, 50000, s);
        counter = 0;
        fout<< s << "," << num<<", \n";

    }


}

