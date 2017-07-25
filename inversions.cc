#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long split(vector<long long> &numbers, vector<long long> &tmp, long low, long mid, long high) {
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

long long sort(vector<long long> &numbers, vector<long long>  &tmp, long low, long high) {
	long long c = 0;
	if(high > low) {
		long mid = low + ((high-low) >> 1);
		c = sort(numbers, tmp, low, mid);
		c += sort(numbers, tmp, mid + 1, high);
		c += split(numbers, tmp, low, mid, high);
	}
	return c;
}

long long inversion(vector<long long> &numbers, long low, long high) {
	vector<long long> tmp(high - low + 1);
	return sort(numbers, tmp, low, high);
}

int main() {

	long n;
	cin>>n;
	vector <long long> numbers(n);
	for(long j = 0; j < n; j++) {
		cin>>numbers[j];
	}
	cout<<inversion(numbers, 0, numbers.size() - 1)<<endl;
	return 0;
}
