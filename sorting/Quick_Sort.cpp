//AUTHOR : SALONI TYAGI
//QUICK SORT
//INPLACE SORTING

#include <iostream>

using namespace std;

int partition(int a[] , int l , int r) { // this function takes last element as pivot
    int pivot = a[r] ;
    int i = l - 1 ;

    for(int j = l ; j <= r ; j++) {
        if(a[j] < pivot) {
            i++ ;
            swap(a[i] , a[j]) ;
        }
    }

    swap(a[i+1] , a[r]) ;
    return i+1 ;
}


void quick_sort(int a[] ,int l , int r) {
    int q ;
    if(l < r) {
        q =  partition(a , l , r) ;
        quick_sort(a , l , q-1) ;
        quick_sort(a , q+1 , r) ;
    }
}

int main()
{

    int n;
    cout << "Enter the size\n";
    cin >> n;
    cout << "Enter the elements\n";

    int a[n], key, j;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    quick_sort(a , 0 , n-1) ;

    cout << "Sorted Array : \n";

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}