#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<long long> &numbers, vector<long long> &tmp, long low, long mid, long high) {
	long i = low, j = mid + 1, k = 0;
	while(i <= mid && j <= high) {
		if(numbers[i] < numbers[j]) {
			tmp[k++] = move(numbers[i++]);
		} else {
			tmp[k++] = move(numbers[j++]);
		}
	}
	while(i <= mid) {
		tmp[k++] = move(numbers[i++]);
	}
	while(j <= high) {
		tmp[k++] = move(numbers[j++]);
	}
	for(i = low, k = 0; i <= high; i++, k++) {
		numbers[i] = move(tmp[k]);
	}
}

void msort(vector<long long> &numbers, vector<long long>  &tmp, long low, long high) {
	if(high > low) {
		long mid = low + ((high-low) >> 1);
		msort(numbers, tmp, low, mid);
		msort(numbers, tmp, mid + 1, high);
		merge(numbers, tmp, low, mid, high);
	}
}

void mergesort(vector<long long> &numbers, long low, long high) {
	vector<long long> tmp(high - low + 1);
	msort(numbers, tmp, low, high);
}

int main() {
	// your code goes here
	long n;
	cin>>n;
	vector <long long> numbers(n);
	for(long j = 0; j < n; j++) {
		cin>>numbers[j];
	}
	mergesort(numbers, 0, numbers.size() - 1);
	for(int i: numbers) {
		cout<<i<<endl;
	}
	return 0;
}