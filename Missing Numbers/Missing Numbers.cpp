// Missing Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> &missingNumbers(vector<int> &A, vector<int> &B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> *resultptr = new vector<int>(1000010);

	auto it = set_difference(B.begin(), B.end(), A.begin(), A.end(), (*resultptr).begin());
	it = unique((*resultptr).begin(), it);
	resultptr->resize(distance((*resultptr).begin(), it));
	return *resultptr;
}

int main()
{
	int n, m, temp;
	vector<int>A, B, result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		A.push_back(temp);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	result = missingNumbers(A, B);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
;	}
    return 0;
}

