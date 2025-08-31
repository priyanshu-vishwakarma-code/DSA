#include<iostream>
#include<vector>

using namespace std;

void descending_bubble_sort(vector<int>arr,int n){
    for(int i = 0 ; i<n-1 ; i++){
        bool swapped = false;
        for(int j = 0 ; j<n-i-1 ;j++){
            if(arr[j]<arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }

    cout<<"bubble sorted descending array : "<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return;
}


void descending_selection_sort(vector<int>arr,int n){
    int index = 0;
    for(int i = 0; i<n-1 ; i++){
        int current = i;
        for(int j = i+1 ; j<n ; j++){
            if(arr[j]>arr[current]) current = j;
        }
        swap(arr[i],arr[current]);
    }

    cout<<"selection sorted descending array : "<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return;
}


void descending_insertion_sort(vector<int>arr,int n){
    for(int i = 1 ; i<n ; i++){
        int current = arr[i] , previous = i-1;
        while(previous>=0 && current>arr[previous]){
            arr[previous+1] = arr[previous];
            previous--;
        }
        arr[previous+1] = current;
    }


    cout<<"insertion sorted descending array : "<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    return;
}


int main(){

    vector<int>arr = {2,5,7,6,1,3,9,0,8,4};
    int n = arr.size();

    cout<<"original array : "<<endl;
    for(int i : arr){
        cout<<i<<" ";
    }
    cout<<endl;

    descending_bubble_sort(arr,n);
    descending_selection_sort(arr,n);
    descending_insertion_sort(arr,n);

    return 0;
}
