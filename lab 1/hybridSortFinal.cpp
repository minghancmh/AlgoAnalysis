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
#include <chrono>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;



unsigned long long counter = 0;
int THRESHOLD = 4;


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
void hybridSort(int arr[], int upper, int lower) {
        if (upper - lower <= THRESHOLD) {
            insertionSort(arr, upper, lower);
        }
        else {
            
            int mid = lower + (upper - lower)/2;
            hybridSort(arr,mid,lower);
            hybridSort(arr,upper,mid+1);
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
    ofstream fout("hybridSortComparison_newest.csv");

    // fout<<"n,Merge Sort, Merge Time,Hybrid Sort, Hybrid Time\n";

        int arrH[] = {12, 13, 14, 5, 6, 7 , 18, 1293, 3248, 234};

        // auto t3 = high_resolution_clock::now();

        hybridSort(arrH, 10-1,0);
        cout<<"hybrid comps:" <<hybridcomps<<endl;
        fout<<hybridcomps<<",";
        hybridcomps=0;
        mergecomps=0;
        compcounter=0;
        // cout<<hybridcomps<<endl;
        // auto t4 = high_resolution_clock::now();
        // auto ms_int = duration_cast<milliseconds>(t4 - t3);
        // duration<double, std::milli> ms_double2 = t4 - t3;
        // cout<<"Time for hybrid: "<< ms_double2.count()<<endl;
        // fout<<ms_double2.count()<<"\n";



    // for (int i=1000; i<=1100000; i+=10000){
    // // copying the arrays twice, and then running these 3 arrays through insertion sort, merge sort, hybrid sort respectively
    //     int *arrI = arrGenerator(i);
    //     int *arrM = new int[i];
    //     int *arrH = new int[i];
    //     for (int s=0; s<i; s++){
    //         arrM[s] = arrI[s];
    //         arrH[s] = arrI[s];
    //     }

    //     fout<<i<<",";
    //     cout<<"=====Size of Array = "<<i<<"====="<<endl;

    //     // insertionSort(arrI, i-1,0);
    //     // cout<<"insertion comps:" <<hybridcomps<<endl;
    //     // hybridcomps=0;
    //     // mergecomps=0;
    //     // compcounter=0;
    //     // fout<<insertionSortCaller(arrI, i)<<",";
    //     // counter=0;
    //     auto t1 = high_resolution_clock::now();

    //     mergesort(arrM, i-1,0);
    //     cout<<"merge comps:" <<mergecomps<<endl;
    //     fout<<mergecomps<<",";
    //     hybridcomps=0;
    //     mergecomps=0;
    //     compcounter=0;
    //     auto t2 = high_resolution_clock::now();
    //     auto ms_int = duration_cast<milliseconds>(t2 - t1);
    //     duration<double, std::milli> ms_double = t2 - t1;
    //     cout<<"Time for merge: "<< ms_double.count()<<endl;
    //     fout<<ms_double.count()<<",";
    //     // printArr(arrI, 10000000);


    //     auto t3 = high_resolution_clock::now();

    //     hybridSort(arrH, i-1,0);
    //     cout<<"hybrid comps:" <<hybridcomps<<endl;
    //     fout<<hybridcomps<<",";
    //     hybridcomps=0;
    //     mergecomps=0;
    //     compcounter=0;
    //     auto t4 = high_resolution_clock::now();
    //     // auto ms_int = duration_cast<milliseconds>(t4 - t3);
    //     duration<double, std::milli> ms_double2 = t4 - t3;
    //     cout<<"Time for hybrid: "<< ms_double2.count()<<endl;
    //     fout<<ms_double2.count()<<"\n";





    //     // cout<<"time for hybrid: "<< fixed<< diff <<setprecision(5)<<endl;
    //     // printArr(arrM, 10000000);
    //     // hybridcomps=0;
    // }


}

