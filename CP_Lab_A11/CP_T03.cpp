#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    int jerseyNumber;
    int runsScored;
};

int main() {
    Player team[4];
    int totalRuns = 0;

    for (int i = 0; i < 4; i++) {
        cout << "Enter details for Player " << i + 1 << ":" << endl;
        cout << "Player Name: ";
        cin >> team[i].name;
        cout << "Jersey Number: ";
        cin >> team[i].jerseyNumber;
        cout << "Runs Scored: ";
        cin >> team[i].runsScored;
        cout << endl;
        
        totalRuns += team[i].runsScored;
    }

    cout << "--- All Player Details ---" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Name: " << team[i].name 
             << ", Jersey No: " << team[i].jerseyNumber 
             << ", Runs: " << team[i].runsScored << endl;
    }
    cout << endl;

    int highestIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (team[i].runsScored > team[highestIndex].runsScored) {
            highestIndex = i;
        }
    }
    cout << "Player with Highest Runs: " << team[highestIndex].name 
         << " (Runs: " << team[highestIndex].runsScored << ")" << endl;

    cout << "Team's Total Runs: " << totalRuns << endl;
    cout << endl;
    
    cout << "--- Players with More Than 50 Runs ---" << endl;
    bool foundBonus = false;
    for (int i = 0; i < 4; i++) {
        if (team[i].runsScored > 50) {
            cout << "Name: " << team[i].name << " | Runs: " << team[i].runsScored << endl;
            foundBonus = true;
        }
    }
    if (!foundBonus) {
        cout << "No players scored more than 50 runs." << endl;
    }

    return 0;
}