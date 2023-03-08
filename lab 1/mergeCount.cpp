#include <iostream>
using namespace std;
int counter = 0;;

// MERGE SORT

void merge(int arr[], int start, int end){ // returns the number of key comparisons
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

int mergeSort(int arr[], int start, int end){
    int mid = (start+end)/2;

    if (end-start <=0){
        return 0;
    }
    else if (end-start>1){
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
    }
    merge(arr, start, end);
    return 0;
}

void mergeSortCaller(int arr[], int n){ // n is the number of elements in the unsorted list
    mergeSort(arr, 0, n-1);
    cout<<"==========MERGE SORT==============="<<endl;
    cout<<"Size of array: "<< n <<endl;
    cout<<"Number of Comparisons: "<< counter << endl;
    counter = 0;
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



    for (int i=10; i<1000000; i*=10){
        
        int* arrIn = arrGenerator(i);
        mergeSortCaller(arrIn, i);
    }

    // for (int i=10; i<1000000; i*=10){
        
    //     int* arrIn = arrGenerator(i);
    //     insertionSortCaller(arrIn, i);
    // }

    // for (int i=10; i<1000000; i*=10){
        
    //     int* arrIn = arrGenerator(i);
    //     hybridSortCaller(arrIn, i);
    // }

    // int arr[] = {10,9,8,7,6,5,4,3,2,1};
        int arrM[] = {5,1,7,3,6,2,8,4};
    // insertionSortCaller(arr, 10);
    // hybridSortCaller(arr, 10);
    mergeSortCaller(arrM, 8);

    // int arrM[] = {5,1,7,3,6,2,8,4};

    // int arrI[] = {8,7,6,5,4,3,2,1};
    // int* arrIn = arrGenerator(5);
    // insertionSort(arrI, 8);
    // printArr(arrIn,5);
    // cout<<""<<endl;
    // mergeSortCaller(arrM, 8);
    // mergeSort(arrT, 0, 7);
    // printArr(arrIn,100);
}

