#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayChoices()
{
    cout << "Choose one of the following:\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
}

string getChoiceName(int choice)
{
    switch (choice)
    {
    case 1:
        return "Rock";
    case 2:
        return "Paper";
    case 3:
        return "Scissors";
    default:
        return "Invalid";
    }
}

int determineWinner(int playerChoice, int computerChoice)
{
    if (playerChoice == computerChoice)
    {
        return 0;
    }
    else if ((playerChoice == 1 && computerChoice == 3) ||
             (playerChoice == 2 && computerChoice == 1) ||
             (playerChoice == 3 && computerChoice == 2))
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    srand(time(0));

    int playerChoice, computerChoice;

    displayChoices();
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> playerChoice;

    if (playerChoice < 1 || playerChoice > 3)
    {
        cout << "Invalid choice! Please run the game again and select 1, 2, or 3.\n";
        return 1;
    }

    computerChoice = (rand() % 3) + 1;

    cout << "You chose: " << getChoiceName(playerChoice) << endl;
    cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

    int result = determineWinner(playerChoice, computerChoice);

    if (result == 0)
    {
        cout << "It's a draw!\n";
    }
    else if (result == 1)
    {
        cout << "You win!\n";
    }
    else
    {
        cout << "Computer wins!\n";
    }

    return 0;
}
