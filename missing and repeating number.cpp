/*
You are given a vector of n integers from 1 to n.

Each integer appears exactly once except M which is missing and R which appears twice.
Return M and R.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output M should precede R.
*/

#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n1)
{
	// Write your code here 
    long long int n = n1;
    long long int sum = 0, s = 0, sum2 = 0, s2 = 0;
    for(int i = 0; i < n; i++){
        s += arr[i];
        s2 += arr[i]*arr[i];
    }
    sum = (n*(n+1))/2;
    sum2 = (n*(n+1)*(2*n+1))/6;
    long long int mminusr = sum - s;
    long long int m2minusr2 = sum2 - s2;
    long long int mplusr = m2minusr2/mminusr;
    int m = (mplusr + mminusr)/2;
    int r = (mplusr - mminusr)/2;
    pair<int, int> p = {m,r};
    return p;
	
}
