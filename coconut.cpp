#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Class to represent a Coconut Tree
class CoconutTree {
private:
    int age;           // Age in years
    int coconuts;      // Number of coconuts currently on the tree
    bool isHealthy;    // Tree health status

public:
    CoconutTree() {
        age = 0;
        coconuts = 0;
        isHealthy = true;
        cout << "A new coconut tree sprouts in the grove!\n";
    }

    void grow() {
        if (isHealthy) {
            age++;
            coconuts += rand() % 5 + 1; // Produces 1-5 coconuts per year
            cout << "Tree (Age: " << age << ") now has " << coconuts << " coconuts.\n";
            if (age > 10 && rand() % 100 < 20) { // 20% chance to get sick after 10 years
                isHealthy = false;
                cout << "Oh no! The tree has fallen ill!\n";
            }
        }
    }

    int harvest() {
        if (isHealthy) {
            int harvested = coconuts;
            coconuts = 0;
            cout << "Harvested " << harvested << " coconuts!\n";
            return harvested;
        } else {
            cout << "This tree is too sick to harvest.\n";
            return 0;
        }
    }

    void waterTree() {
        if (!isHealthy) {
            isHealthy = true;
            cout << "The tree has been nursed back to health with water!\n";
        } else {
            cout << "The tree is already thriving!\n";
        }
    }
};

// Class to manage the Coconut Grove
class CoconutGrove {
private:
    vector<CoconutTree> trees;
    int coconutStock; // Stockpile of harvested coconuts
    int coconutMilk;  // Processed coconut milk (in imaginary liters)

public:
    CoconutGrove() : coconutStock(0), coconutMilk(0) {
        trees.push_back(CoconutTree()); // Start with one tree
    }

    void addTree() {
        trees.push_back(CoconutTree());
    }

    void simulateYear() {
        cout << "\n--- A New Year in the Grove ---\n";
        for (int i = 0; i < trees.size(); i++) {
            cout << "Tree " << i + 1 << ": ";
            trees[i].grow();
        }
    }

    void harvestAll() {
        cout << "\n--- Harvesting Season ---\n";
        for (int i = 0; i < trees.size(); i++) {
            cout << "Tree " << i + 1 << ": ";
            coconutStock += trees[i].harvest();
        }
        cout << "Total coconut stock: " << coconutStock << "\n";
    }

    void processCoconuts() {
        if (coconutStock > 0) {
            int processed = coconutStock / 2; // 2 coconuts = 1 liter of milk
            coconutMilk += processed;
            coconutStock -= processed * 2;
            cout << "\nProcessed " << processed << " liters of coconut milk!\n";
            cout << "Remaining stock: " << coconutStock << " coconuts\n";
            cout << "Total coconut milk: " << coconutMilk << " liters\n";
        } else {
            cout << "\nNo coconuts to process!\n";
        }
    }

    void waterAllTrees() {
        cout << "\n--- Watering the Grove ---\n";
        for (int i = 0; i < trees.size(); i++) {
            cout << "Tree " << i + 1 << ": ";
            trees[i].waterTree();
        }
    }
};

int main() {
    srand(time(0)); // Seed random number generator
    cout << "Welcome to Coconut Grove Simulator!\n";

    CoconutGrove grove;

    // Simulate a few years of grove management
    grove.addTree(); // Add a second tree
    for (int year = 1; year <= 3; year++) {
        grove.simulateYear();
        grove.harvestAll();
        grove.processCoconuts();
        if (year == 2) {
            grove.waterAllTrees(); // Water trees in year 2
        }
    }

    cout << "\nThanks for tending the Coconut Grove!\n";
    return 0;
}