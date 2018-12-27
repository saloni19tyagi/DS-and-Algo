//Merge Sort
//Complexity : nlogn 
//Stable sort


#include<iostream>
#include<climits>

using namespace std ;

void merge(int a[] , int p , int q , int r) {
    int n1 = q-p+1 , n2 = r-q ;
    int L[n1+1] , R[n2+1] ;

    for(int i = 0 ; i < n1 ; i++)
      L[i] = a[i+p] ;

    for(int i = 0 ; i < n2 ; i++)
      R[i] = a[i+q+1] ;

    int i = 0 , j = 0 , k = p ;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i] ;
            i++ ;
            k++ ;
        }
        else {
            a[k] = R[j] ;
            k++ ;
            j++ ;
        }
    }

    while(i < n1) {
        a[k] = L[i] ;
        k++ ;
        i++ ;
    }

    while(j < n2) {
        a[k] = R[j] ;
        k++ ;
        j++ ;
    }
    

}


void merge_sort(int a[] , int p , int r) {
    if(p < r) {
        int q = p + (r-p)/2 ;
        merge_sort(a , p , q) ;
        merge_sort(a , q+1 , r) ;
        merge(a , p , q , r) ;
    }
}

int main() {

    int n;
    cout << "Enter the size\n";
    cin >> n;
    cout << "Enter the elements\n";

    int a[n] ;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    merge_sort(a , 0 , n-1) ;

    for(int i = 0 ; i < n ; i++) {
        cout << a[i] << " " ;
    }

}