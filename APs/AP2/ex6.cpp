#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Adivinhe o número
int main() {
    int  number, attempt;
    int wb = 1;
    long sec;
    time( &sec);
    srand((unsigned)sec);
    while( wb == 1) {
        cout << "Choose a number between 1 and 15 \n"
        << "You have three chances to guess correctly!\n"
        << "\n";
        number = (rand() % 15) + 1;
        bool found = false;
        int count = 0;
        while( !found  && count < 3 ) {
            cin.sync();
            cin.clear();
            cout << ++count << ". attempt: ";
            cin >> attempt;
            if(attempt < number){
                cout << "too small!"<< endl;
            } else if(attempt > number){
                cout <<"too big!"<< endl;
            } else {
                found = true;
            }
        }
        if( !found) {
            cout << "\nI won!"
            << " The number in question was: "
            << number << endl;
        } else {
            cout << "\nCongratulations! You won!" << endl;
        }
        cout << "Repeat —> < 1 > || Finish —> < 0 >\n";
        do {
            cin >> wb;
        } while( wb != 1 &&  wb != 0);
    }
    return 0;
}
