#include <bits/stdc++.h>
/*
Intuiton : 
Find the frequency of each number,if freq[num] > 1 then it is duplicate,
if freq[num] == 0 then it is missing.
TC : O(2n)
SC : O(n) 
*/
pair<int,int> bruteForce(vector<int> &arr,int n)
{
    unordered_map<int,int> freqMap;
    for(auto val : arr)
       ++freqMap[val];
    int missing,repeating;
    for(int i = 1; i<=n; ++i)
    {
        if(freqMap[i] > 1) repeating = i;
        else if(freqMap[i] == 0) missing = i;
    }
    return {missing,repeating};
}
/*
let x : repeating and y : duplicate.
IF subtract sum(arr) - sum(1-N) we get x - y.
if we subtract of squareSum(arr) - squareSum(1-N) we get x^2 - y2.
x^2 - y^2 = (x+y)(x-y).
We can get (x+y) from above equation. So we have x+y and x-y.
so we can get x and y.

NOTE : 
sum(1-N) - sum(arr) gives y-x similarly for square sum.
Be careful with the equations.

TC : O(n)
SC : O(1)
*/ 
pair<int,int> mathSolution(vector<int> &arr,int n)
{
   long long s = 0,sn = 0;
   long long s2 = 0,s2n = 0;
   sn = (1LL*n*(n+1))/2; /*sum of n numbers formula*/
   s2n = (1LL*n*(n+1)*(2*n+1))/6;  /*sum of n squares formula*/
   for(int i = 0; i<n; ++i)
   {
        s+=arr[i]; /*Calculating array sum*/
        s2+=(1LL*arr[i]*arr[i]); /*Calculating array square sum*/
   }
   long long val1 = s - sn; // x - y
   long long val2 = s2 - s2n; //x^2 - y^2
   val2 = val2/val1; /*(x+y)*/
   long long repeating = (val1 + val2)/2;   //x
   long long missing = (repeating - val1); //y = (x - val1)
   return {int(missing),int(repeating)};
} 
/*
Xor Solution
1.if we take xor(arr)^xor(1-N) we would get x^y.
2.The missing and repeating numbers are different,hence they must have 
one bit different.For the different bit xor comes out to be 1.
3.Find out the first bit which is different in two numbers.
4.Now from set1(arr) and set2(1-N) elements group them into two gropus,
numbers which contain 0,1 at differentiating bit.
5.As x and y has different bit values at differntiating bit,they move to 
different gropus.
6.Repeating number occurs 3 times in set = set1 + set2,and duplicate occurs
only once.
7.If we take the xor the groups we would get x and y.
8. Among x and y we don't know which is repeating and duplicate,so iterate 
over the arr, if we found one number in array then it is repeating rest 
is missing

TC : O(n)
SC : O(1)
*/ 
pair<int,int> xorSolution(vector<int> &arr,int n)
{
    int xr = 0;
    for(int i = 0; i<n; ++i)
    {
        xr^=arr[i];
        xr^=(i+1);
    }
    int number = (xr&~(xr-1)); /*This is used to find the first 
    differentitaing bit in two numbers.
    We can also run a loop and find the first differentiating bit
    number denotes the 2th power of differntiating bit*/
    int zero = 0,one = 0;
    for(int i = 0; i<n; ++i)
    {  
        /*If differntBit is set in arr[i] then it is in gropu one else zero*/
        if(arr[i]&(number)) one^=arr[i];
        else zero^=arr[i];
        if((i+1)&(number)) one^=(i+1);
        else zero^=(i+1);
    }
    /*Now one among zero or one is repeating and other is missing*/
    for(auto val : arr)
    {
        if(val == zero) return {one,zero};
        else if(val == one) return {zero,one};
    }
    return {-1,-1};
}
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// return bruteForce(arr,n);
    // return mathSolution(arr,n);
    return xorSolution(arr,n);
} 