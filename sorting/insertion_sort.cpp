//Insertion Sort
//Inplace sorting(addition memory not required)
//stable sorting
//Worst-Case Complexity = N^2 


#include<iostream>

using namespace std ;

int main() {

    int n ;
    cout << "Enter the size\n" ;
    cin >> n ;
    cout << "Enter the elements\n" ;

    int arr[n] , key, j ;
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
    }

    for(int i = 2 ; i < n ; i++) {
        key = arr[i] ;
        j = i-1 ;
        while(j >= 0 && key < arr[j]) {
            arr[j+1] = arr[j] ;
            j-- ;
        }
        arr[j+1] = key ;
    }

    cout << "Sorted Array : \n" ;
    
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << " " ;
}
