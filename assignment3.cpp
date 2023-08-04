#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

// func to get user's choice
char getUserChoice() {
    char userChoice;
    cout << "Choose one of the (r/ p/ s): r for rock, p for paper, s for scissors): ";
    cin >> userChoice;
    return userChoice;
}

// func to get/ generate computer's choice
char getComputerChoice() {
    char possibleChoices[] = { ROCK, PAPER, SCISSORS };
    int randomIndex = rand() % 3;
    return possibleChoices[randomIndex];
}

// func to display user's and computer's choices
void displayChoices(char userChoice, char computerChoice) {
    cout << "User chose: " << userChoice << endl;
    cout << "Computer chose: " << computerChoice << endl;
}

// func to determine who win
char determineWinner(char userChoice, char computerChoice) {

    if ((userChoice == ROCK && computerChoice == SCISSORS) || (userChoice == PAPER && computerChoice == ROCK) || (userChoice == SCISSORS && computerChoice == PAPER)) {
        return 'u'; // User wins
    } else if ((computerChoice == ROCK && userChoice == SCISSORS) || (computerChoice == PAPER && userChoice == ROCK) || (computerChoice == SCISSORS && userChoice == PAPER)) {
        return 'c'; // Computer wins
    } else {
        return 't'; // It's a tie
    }
}

int main() {
    // variables for storing winsCounts of user and computer
    int userWinsCount = 0;
    int computerWinsCount = 0;

    // while loop to keep the game going until a winner is born
    while (userWinsCount < 3 && computerWinsCount < 3) {
        char userChoice = getUserChoice();
        char computerChoice = getComputerChoice();

        displayChoices(userChoice, computerChoice);

        char winner = determineWinner(userChoice, computerChoice);

        if (winner == 'u') {
            cout << "User wins this round!" << endl;
            userWinsCount++;
        } else if (winner == 'c') {
            cout << "Computer wins this round!" << endl;
            computerWinsCount++;
        } else {
            cout << "It's a tie this round!" << endl;
        }

        cout << "User scored " << userWinsCount << " while Computer scored " << computerWinsCount << endl;
    }

    // Announce who wins the game
    if (userWinsCount == 3) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }

    return 0;
}
