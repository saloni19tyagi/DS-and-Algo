//AUTHOR : SALONI TYAGI
//HEAP SORT
//COMPLEXITY : nlogn


#include<iostream>

using namespace std ;

void min_heapify(int a[], int index, int heap_size)
{
    int l = 2 * index + 1; // left child
    int r = 2 * index + 2; // right child
    int largest ;

    if (l < heap_size && a[index] > a[l]) // comparison with left child
    {
        largest = l ;
    }
    else
    {
        largest = index;
    }
    if (r < heap_size && a[largest] > a[r])
    {
        largest = r;
    }

    if (largest != index)
    {
        swap(a[index], a[largest]);
        min_heapify(a, largest, heap_size);
    }
}

void build_min_heap(int a[], int heap_size)
{
    for (int i = (heap_size/2) - 1; i >= 0; i--)
    {
        min_heapify(a, i, heap_size);
    }
}

void heapsort(int a[] , int heap_size , int ans[]) {
    build_min_heap(a, heap_size) ;
    int length = heap_size ;
    for(int i = 0 ; i < length ; i++) {
        ans[i] = a[0] ;
        swap(a[0] , a[heap_size-1]) ;
        heap_size-- ;
        min_heapify(a , 0 , heap_size) ;
    }
}


int main() {

    int heap_size ;
    cout << "Enter the size\n";
    cin >> heap_size ;
    cout << "Enter the elements\n";

    int a[heap_size] , ans[heap_size] ;
    for (int i = 0; i < heap_size; i++)
    {
        cin >> a[i];
    }

    heapsort(a , heap_size , ans) ;

    cout << "Sorted Array\n" ;
    for(int i = 0 ; i < heap_size ; i++) {
        cout << ans[i] << " " ;
    }
}