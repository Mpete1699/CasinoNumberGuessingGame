#include <iostream>
#include <string> 
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
void rules();
/**
 * The program asks for a betting amount and then asks the user to guess a number on rolling.
 * If the random number generated matches the user input, he wins, else money is deducted. 
 * The user can keep playing until he loses all the amount he put in initially.
 */

int main(){

string userName;
int balance; 
int bet;
int guess;
int dice;
bool gameOver = false;
//Setting Random Number 
srand(time(0));

//User Information
cout << "Enter your username" << endl;
cin >> userName;
cout << "Enter how much you want to be your balence : $";
cin >> balance;
do{
    rules();
    cout << "\n Hi "<< userName << ", Your current balance is $ " << balance << endl;
    //Enter bet
    do
    {
        cout << "Please Enter the amount you want to bet with" << endl;
        cin >> bet;
        if(bet > balance){
            cout << "Your bet cannot be greater than your balance!" << endl;
            cout << "Re-enter your bet";
        }
    } while (bet > balance);
    //Getting guess
     do
    {
        cout << "Please enter a guess between 1 and 10" << endl;
        cin >> guess;
        if(guess <= 0 || guess > 10){
            cout << "You need to enter a guess between 1 and 10!" << endl;
            cout << "Re-enter your guess";
        }
    } while (guess <= 0 || guess > 10);

    dice = rand()%10 + 1;

    if(guess == dice){
        cout << "Congrats you win" << endl;
        balance = balance + (bet*10);
    }
    else{
        cout << "You Lose!" << endl;
        balance = balance - bet;
    }
    if(balance == 0){
        cout << "You have run out of Money!" << endl;
        break;
    }
    cout << "\nEnter 0 to continue 1 to end your game" << endl;
    cin >> gameOver;
}while(!gameOver);
 cout << "\nGoodbye "<< userName << ", Your finishing balance was $ " << balance << endl;
cout << "Thanks for Playing!" << endl;
}


void rules()
{
    system("cls");
    cout << "CASINO NUMBER GUESSING RULES!" << endl;
    cout << "Choose a number between 1 to 10"<< endl;
    cout << "Winner gets 10 times of the money bet"<< endl;
    cout << "Wrong bet, and you lose the amount you bet"<< endl;
}
