/*
 * Filename: traveling.cpp
 * Jinghui Tian
 * Date: 5.4.2021
 */


#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#include "middleearth.h"
/**
 * @brief travelling salesman problem
 *
 * @return distance and path
 * @todo Need to write acceptance tests for this function
 * @author Jinghui Tian
 * @file traveling.cpp
 */

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    float min_dist = 0.0;
    float curr = 0.0;
    vector<string> min_path = dests;
    
    sort(dests.begin() + 1,dests.end());
    min_dist = computeDistance(me, dests[0], dests);
    while(next_permutation(dests.begin() + 1,dests.end()) == true){
        curr = computeDistance(me, dests[0], dests);
        if (curr < min_dist){
            min_dist = curr;
            min_path = dests;
        }
    }
    cout << "Minimum path has distance " << min_dist << ": ";
    printRoute(min_path[0], min_path);
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth &me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
    float distance = 0.0;
    string startt = start;
    for (int i = 0; i < dests.size(); i++){
        distance += me.getDistance(startt, dests[i]);
        startt = dests[i];
     }
    distance += me.getDistance(dests[dests.size()-1], start);
    return distance;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
   for (auto i = dests.begin(); i != dests.end(); ++i){
        cout << *i << " -> ";
    }
    cout << start << endl;
}
