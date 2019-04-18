//Author : Saloni Tyagi

//Problem Statement : You have an empty sequence, and you will be given  queries. Each query is one of these three types:
    // 1 x - Push the element x into the stack.
    // 2 - Delete the element present at the top of the stack.
    // 3 - Print the maximum element in the stack.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{

    long long int n, mx = 0, ele, type;
    cin >> n;

    stack<pair<long long int, long long int> > s; // Pair element and maximum Till that element
    while (n--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> ele;
            mx = max(mx, ele);
            s.push(make_pair(ele, mx));//Inserting element and maximum till now.
        }
        else if (type == 2)
        {
            s.pop();
            if (s.size() == 0)
                mx = 0; // if stack is empty , maximum is zero 
            else
                mx = s.top().second; 
        }
        else
            cout << mx << "\n";
    }
    return 0;
}
