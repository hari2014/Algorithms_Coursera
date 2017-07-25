#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long count_split_sort(vector<long long> &numbers, vector<long long> &tmp, long low, long mid, long high) {
	long i = low, j = mid + 1, k = 0;
	long long count = 0;
	while(i <= mid && j <= high) {
		if(numbers[i] < numbers[j]) {
			tmp[k++] = move(numbers[i++]);
		} else {
			tmp[k++] = move(numbers[j++]);
			count += (mid - i + 1);
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
	return count;
}

long long sort_count(vector<long long> &numbers, vector<long long>  &tmp, long low, long high) {
	long long count = 0;
	if(high > low) {
		long mid = low + ((high-low) >> 1);
		count = sort_count(numbers, tmp, low, mid);
		count += sort_count(numbers, tmp, mid + 1, high);
		count += count_split_sort(numbers, tmp, low, mid, high);
	}
	return count;
}

long long inversion_count(vector<long long> &numbers, long low, long high) {
	vector<long long> tmp(high - low + 1);
	return sort_count(numbers, tmp, low, high);
}

int main() {
	// your code goes here
	long n;
	cin>>n;
	vector <long long> numbers(n);
	for(long j = 0; j < n; j++) {
		cin>>numbers[j];
	}
	cout<<inversion_count(numbers, 0, numbers.size() - 1)<<endl;
	return 0;
}