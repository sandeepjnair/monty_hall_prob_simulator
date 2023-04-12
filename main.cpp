#include <iostream>
#include <cstdlib>
#include <ctime> //For random seed generation

using namespace std;

int main() {
    /* 
    code to simulate monty hall problem and generate probability of winning if the contestant switches or doesn't
    switch doors after host reveal. The number of sim runs are hardcoded in the variable "N"
    */

    srand(time(NULL)); // To initialize random seed differently each run

    const int N = 1000000; // hardcoded number of sim runs
    int switch_wins = 0;
    int stay_wins = 0;

    for (int i = 0; i < N; i++) {
        
        int doors[3] = {0, 0, 0};
        doors[rand() % 3] = 1;   // Initialize doors with a car behind one of them, represented by 1 

        int choice = rand() % 3; // Contestant chooses a door

        // Host reveals a door without a car behind it
        int reveal;
        do {
            reveal = rand() % 3;
        } while (doors[reveal] == 1 || reveal == choice);

        // at this point the contestant can stick with his choice or switch to the other door
        // if the contestant would've won by sticking to his choice we increment stay_wins else we increment switch_wins
        if (doors[choice] == 1) {
            stay_wins++;
        }
        else{
            switch_wins++;
        }
    }

    cout << "Switching wins: " << switch_wins << " out of " << N << " times (" << ((double)switch_wins)*100 / N << "%)\n";
    cout << "Staying wins: " << stay_wins << " out of " << N << " times (" << ((double)stay_wins)*100 / N << "%)\n";

    return 0;
}
