/*
iven five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated long integers.

Example

The minimum sum is  and the maximum sum is . The function prints

16 24
Function Description

Complete the miniMaxSum function in the editor below.

miniMaxSum has the following parameter(s):

arr: an array of  integers
Print

Print two space-separated integers on one line: the minimum sum and the maximum sum of  of  elements.

Input Format

A single line of five space-separated integers.

Constraints


Output Format

Print two space-separated long integers denoting the respective minimum and maximum values that can be calculated by summing exactly four of the five integers. (The output can be greater than a 32 bit integer.)

Sample Input

1 2 3 4 5
Sample Output

10 14
Explanation

The numbers are , , , , and . Calculate the following sums using four of the five integers:

Sum everything except , the sum is .
Sum everything except , the sum is .
Sum everything except , the sum is .
Sum everything except , the sum is .
Sum everything except , the sum is .
Hints: Beware of integer overflow! Use 64-bit Integer.

Need help to get started? Try the Solve Me First problem


/*

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
struct Pair 
{
    long long int min;
    long long int max;
}; 
 
struct Pair getMinMax(vector<long long int> arr, int n)
{
    struct Pair minmax;     
    int i;
     
    // If there is only one element 
    // then return it as min and max both
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];     
        return minmax;
    } 
     
    // If there are more than one elements,
    // then initialize min and max
    if (arr[0] > arr[1]) 
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    } 
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    } 
     
    for(i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)     
            minmax.max = arr[i];
             
        else if (arr[i] < minmax.min)     
            minmax.min = arr[i];
    }
    return minmax;
}
// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
    int tamanho = arr.size();
    vector< long long int> aux(tamanho);
    
    for(int i=0;i<tamanho;i++){
        long long int contador = 0;
        for(int j=0; j < tamanho; j++){
          if(i==j)continue;
          contador += arr[j];  
        }  
        aux[i] = contador;
    }
    int min = 0;
    int max = 0;
    
    
    Pair minmax = getMinMax(aux,aux.size());
    printf("%lli %lli" ,minmax.min,minmax.max);

}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}



