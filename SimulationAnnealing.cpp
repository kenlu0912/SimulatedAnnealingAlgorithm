/*
    > File name: SimulationAnnealing.cpp
    > Author: Ken
    > Created Time: 2020-03-14
*/

// This code is use the simulated annealing algorithm to solve the Knapsack
// problem. Each item has a weight and a value, and the constraint is that the
// sum of weight in the knapsack cannot exceed the half of the summation of
// weights of all items

#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <set>
#include <sstream>
#include <thread>
#include <vector>
using namespace std;

// Define the maximum weight of the knapsack
constexpr int MAX_WEIGHT = 245875;
constexpr int MAX_VALUE = 494725;
constexpr int ITEM_NUMBER = 10000;

// Data structure to store the item info
struct Item {
    int id;
    int weight;
    int value;

    bool operator<(const Item &item) const { return id < item.id; }
};

// Use mt19937 to create a random number generator
static std::mt19937 rng(std::random_device{}());
std::uniform_real_distribution<double> distribution(0.0, 1.0);

// Read the csv file and return a vector of items
std::vector<Item> readItem(const std::string fileName) {
    std::ifstream file(fileName);
    std::vector<Item> data;

    if (!file.is_open()) {
        std::cerr << "Error: file not found" << std::endl;
        return data;
    }

    std::string line;
    getline(file, line); // skip the first line

    std::stringstream ss;
    int id, weight, value;
    char comma;
    while (getline(file, line)) {
        ss << line;
        ss >> id >> comma >> weight >> comma >> value;

        data.push_back({id, weight, value});
    }

    return data;
}

// Print the items
void printItems(const std::set<Item> &items) {
    for (const auto &item : items) {
        std::cout << "id: " << item.id << ", weight: " << item.weight
                  << ", value: " << item.value << std::endl;
    }
}

// Determine if the new solution should be accepted
bool acceptance(int newValue, int currentValue, double temperature) {
    // If the new value is greater than the current value, accept the new
    if (newValue > currentValue) {
        return true;
    }

    // If probability is greater than a random number, accept the new solution
    // As newValue is less than currentValue, deltaV is negative
    // So e^(-deltaV / temperature) is less than 1
    int deltaV = newValue - currentValue;
    double probability = exp(deltaV / temperature);
    double random = distribution(rng);
    return random < probability;
}

// Select the items randomly to form the initial solution
void initial(vector<Item> &items, vector<bool> &currentItems, int &totalWeight,
             int &totalValue) {
    for (int i = 0; i < items.size(); i++) {
        if (totalWeight + items[i].weight <= MAX_WEIGHT &&
            distribution(rng) > 0.5) {
            currentItems[i] = true;
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }
}

// Check if the total weight is greater than the maximum weight
void checkMax(vector<Item> &items, vector<bool> &currentItems, int &totalWeight,
              int &totalValue) {
    // While the total weight is greater than the maximum weight, remove some
    // items randomly
    while (totalWeight > MAX_WEIGHT) {
        int select = distribution(rng) * ITEM_NUMBER;
        if (currentItems[select]) {
            currentItems[select] = false;
            totalWeight -= items[select].weight;
            totalValue -= items[select].value;
        }
    }
}

int simulatedAnnealing(vector<Item> &items, double initialTemperature,
                       double coolingRate, int iterations) {
    vector<bool> currentItems(ITEM_NUMBER, false);
    int currentWeight = 0;
    int currentValue = 0;

    vector<bool> newItems;
    int newWeight = 0;
    int newValue = 0;
    int select = 0;

    initial(items, currentItems, currentWeight, currentValue);

    for (int i = 0; i < iterations; i++) {
        newItems = currentItems;
        newWeight = currentWeight;
        newValue = currentValue;

        select = distribution(rng) * ITEM_NUMBER;

        // If the item is not in the knapsack, add it, otherwise remove it
        if (currentItems[select] == false) {
            newItems[select] = true;
            newWeight += items[select].weight;
            newValue += items[select].value;
        } else {
            newItems[select] = false;
            newWeight -= items[select].weight;
            newValue -= items[select].value;
        }

        // Check if the total weight is greater than the maximum weight
        checkMax(items, newItems, newWeight, newValue);

        // Determine if the new solution should be accepted
        // If accepted, update the current solution
        if (acceptance(newValue, currentValue, initialTemperature)) {
            currentItems = newItems;
            currentWeight = newWeight;
            currentValue = newValue;
        }

        // Reduce the temperature
        initialTemperature *= coolingRate;
    }

    stringstream ss;
    ss << std::time(0);

    ofstream logFile("./log.txt", ios::app);
    logFile << ss.str() << ",500,0.99995,100000000," << currentWeight << ","
            << currentValue << "\n";
    for (int i = 0; i < ITEM_NUMBER; i++) {
        if (currentItems[i]) {
            logFile << items[i].id << ",";
        }
    }
    logFile << "\n";

    logFile.close();

    return currentValue;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    std::vector<Item> items = readItem("data.csv");
    // printItems(items);

    while (true) {
        double initialTemperature = 500.0;
        double coolingRate = 0.99995;
        int iterations = 1e8;

        cout << simulatedAnnealing(items, initialTemperature, coolingRate,
                                   iterations)
             << "\n";
    }
}