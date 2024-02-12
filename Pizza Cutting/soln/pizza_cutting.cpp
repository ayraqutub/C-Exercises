#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	// declare your variables
	double n;
	double m;
	double x;
	// read the input
	cin >> n;
	cin >> m;
	// solve, good luck!
	x = log(m) / log(n);
	if (int(x) == x){
		cout << "GOOD" << "\n" ;
	}
	else {
		cout << "BAD" << "\n" ;
	}
	return 0;
}
