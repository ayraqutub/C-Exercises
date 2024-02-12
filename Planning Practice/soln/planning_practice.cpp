#include <iostream>
using namespace std;

int main(){
	// Declare your variables
	int neighbours;
	int time;
	int hours=0;
	int days;
	bool at_home[24]={false}; // clock showing when someone is home

	// Read the input
	cin >> neighbours;
	cin >> time;
	int leave[neighbours];
	int arrive[neighbours];
	for (int i=0; i<neighbours; i++){
		cin >> leave[i];
		cin >> arrive[i];
	}

	// Solve the problem. Good luck! :)
	for (int i=0; i<neighbours; i++){
			if (leave[i]<arrive[i]){ 
			for (int j=0; j<leave[i]; j++){ // time before leaving home
				at_home[j]=true;
			}
			for (int j=arrive[i]; j<24; j++){ // time after coming back
				at_home[j]=true;
			}
		}
		if (arrive[i]<leave[i]){
			for (int j=arrive[i]; j<leave[i]; j++){ // time between coming back and leaving again
				at_home[j]=true;
			}
		}
	}

	// Output the answer
	for (int i=0; i<24; i++){
		if (at_home[i]==false){ // time that no one is home; can practice
			hours++;
		}
	}
	if (hours == 0){ // someone is always home; cannot practice
		cout << "IMPOSSIBLE"<< endl;
	}
	else{
	days = (time + hours -1)/hours; // round up to the next nearest day
	cout << days << endl;
	}
}