#include<iostream>
#include<string.h>
#include<vector>
using namespace std ;

int main() {
	int n ;
	cin >> n ;
	int a[n] , lis[n];
	vector<int>seq ;
	int index[n] ; //to store the index which resulted in lis at position i ;
	
	for(int i=0 ; i < n; i++) {
		cin >> a[i] ;
		lis[i]=1 ;
		index[i] = i ;
	}

	for(int i=1 ; i < n ;i++) {
		for(int j = 0 ; j < i ; j++) {
			if(a[i] > a[j]) {
				if(lis[j]+1 > lis[i]) {
					lis[i] = max(lis[i], lis[j]+1) ;
					index[i] = j ;
				}
			}
		}
	}
	cout << "LIS is : " ;
	cout << lis[n-1] << "\n" ;
	cout << "Sequence is " ;
	int k = n-1;
	
	while(index[k] != k) {
		seq.push_back(a[k]) ;
		k = index[k] ;
	}
	seq.push_back(a[k]);

	for(int i = seq.size()-1 ; i >= 0 ; i--) {
		cout << seq[i] << " " ;
	}
	return 0;
}
