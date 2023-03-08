#include <iostream>
using namespace std;

int arr[] = {5,4,3,2,1};

void merge(int start, int end){
    int mid = (start + end) / 2;
    int a = start;
    int b = mid+1;
    int i, tmp;

    if (end-start <=0){
        return;
    }

    while(a<=mid && b<=end){
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

void mergeSort(int start, int end){
    int mid = (start+end)/2;
    if (end-start <=0){
        return;
    }
    else if (end-start>1){
        mergeSort(start, mid);
        mergeSort(mid+1, end);
    }
    merge(start, end);

}

void printArr(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    mergeSort(0,4);
    printArr(arr,5);
}