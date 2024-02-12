#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initialize variables
    char ferry_direction = 'W';
    int num_west, num_east, arrival_time;
	int current_time = 0;

    // Read input values
    cin >> num_west >> num_east;

    // Store the arrival times and positions of the vehicles in a vector of pairs
    vector<pair<int, char>> arrivals;
    for (int i = 0; i < num_west; ++i) {
        cin >> arrival_time;
        arrivals.push_back(make_pair(arrival_time, 'W'));
    }
    for (int i = 0; i < num_east; ++i) {
        cin >> arrival_time;
        arrivals.push_back(make_pair(arrival_time, 'E'));
    }

    // Sort the arrival times in non-descending order
    sort(arrivals.begin(), arrivals.end());

    // Process each arrival in order
    for (const auto& arrival : arrivals) {
        const auto arrival_time = arrival.first;
        const auto position = arrival.second;

        // Wait until the arrival time before proceeding
        if (current_time < arrival_time) {
            current_time = arrival_time;
        }

        // Update the time and ferry direction based on the vehicle's position
        if (position == ferry_direction) {
            current_time += 100;
            ferry_direction = (ferry_direction == 'E') ? 'W' : 'E'; // toggle direction
        } else {
            current_time += 200;
        }
    }

    // Output the final time
    cout << current_time << endl;

    return 0;
}
