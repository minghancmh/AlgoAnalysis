/*
PROJECT 1
This is a hybrid sort comprising of mergesort and insertion sort.
*/ 
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <limits.h>
using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;



unsigned long long counter = 0;
int THRESHOLD = 13;


int mergecomps = 0;
int hybridcomps = 0;
int compcounter = 0;



// HELPER FUNCTION PRINT ARR

void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

// INSERTION SORT

void insertionSort(int arr[], int upper, int lower) {
        
        int temp = 0;
        for(int i = lower + 1; i <= upper; i++) {
            temp = arr[i];
            int j = i-1;
            while (j >= lower && arr[j] > temp) {
                arr[j + 1] = arr[j];
                j--;
                hybridcomps++;
            }
            arr[j + 1] = temp;

            
        }

    }

// MERGE SORT

void merge(int arr[], int upper, int lower, int mid) {
        int s1 = mid - lower + 1;
        int s2 = upper - mid;
        compcounter = 0;
        int iteration = 0;

        int *arr1 = new int[s1];
        int *arr2 = new int[s2];

        for(int i = 0; i < s1; i++) {
            arr1[i] = arr[lower + i];
        }
        for(int i = 0; i < s2; i++) {
            arr2[i] = arr[mid + 1 + i];
        }

        int m = 0, n = 0;
        int i = lower;
        while(m < s1 && n < s2) {
            iteration++;
            if(arr1[m] <= arr2[n]) {
                arr[i] = arr1[m];
                m++;
            }
            else {
                arr[i] = arr2[n];
                n++;
            }
            i++;
        }

        while(m < s1) {
            arr[i] = arr1[m];
            i++;
            m++;
        }
        while(n < s2) {
            arr[i] = arr2[n];
            i++;
            n++;
        }
        compcounter += iteration;
    }

void mergesort(int arr[], int upper, int lower) {
        if(lower < upper) {
            int mid = lower + (upper - lower)/2;
            mergesort(arr,mid,lower);
            mergesort(arr,upper,mid+1);
            merge(arr,upper,lower,mid);
            mergecomps += compcounter;
        }
    }



// HYBRID ALGORITHM
void hybridSort(int arr[], int upper, int lower, int threshold) {
        if (upper - lower <= threshold) {
            insertionSort(arr, upper, lower);
        }
        else {
            
            int mid = lower + (upper - lower)/2;
            hybridSort(arr,mid,lower, threshold);
            hybridSort(arr,upper,mid+1, threshold);
            merge(arr,upper,lower,mid);
            hybridcomps += compcounter;
        }
    }




// GENERATE RANDOM NUMBERS
int* arrGenerator(int n){
    int *randArr = new int[n];
    for (int i=0; i<n; i++){
        randArr[i] = rand()%INT64_MAX;
    }
    return randArr;
}


// DRIVER CODE


int main(){
    srand(time(0)); // create a time seed so that the array of random numbers generated is different with each c++ run
    ofstream fout("YUFEIvariableS_1000000_newalgo(2)(s to 200).csv");
    fout << "s, hybridTime, \n";



    for (int s=0; s<=200; s+=1){
        int *arrIn = arrGenerator(1000000);
        auto t3 = high_resolution_clock::now();

        hybridSort(arrIn, 50000, 0, s);
        auto t4 = high_resolution_clock::now();
        duration<double, std::milli> ms_double2 = t4 - t3;


        fout<< s << "," << ms_double2.count()<<", \n";

        hybridcomps = 0;
        compcounter = 0;
        mergecomps = 0;


    }

        // auto t3 = high_resolution_clock::now();

        // hybridSort(arrH, 10-1,0);
        // cout<<"hybrid comps:" <<hybridcomps<<endl;
        // fout<<hybridcomps<<",";
        // hybridcomps=0;
        // mergecomps=0;
        // compcounter=0;
        // cout<<hybridcomps<<endl;
        // auto ms_int = duration_cast<milliseconds>(t4 - t3);
        // cout<<"Time for hybrid: "<< ms_double2.count()<<endl;
        // fout<<ms_double2.count()<<"\n";


}

