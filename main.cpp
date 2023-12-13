#include<iostream>
#include <string>
using namespace std;

//idea put already used coords in an arrau so canot use again during current game

//function signatures
string** createEmptyBoard();
void displayBoard(string** board);
bool turns(string ** board);
bool checkIfWinnerOrFull(string** board);
void gameLoop();
void deleteBoard(string** board);


int main() {
    gameLoop();
    cout << "\nEnd of play, Goodbye :)";
    return 0;
}

bool turns(string ** board) {
    string p1_play; string p2_play; bool gameWon = false;
    cout << "\nPlayer 1, pick a coodrinate [ex. (0,0)] to place your 'X'\n->";
    cin >> p1_play;
    board[stoi(p1_play.substr(1,1))-1][stoi(p1_play.substr(3,1))-1] = "X";
    displayBoard(board);
    if(checkIfWinnerOrFull(board) == true) {return true;}

    cout << "\nPlayer 2, pick a coodrinate [ex. (0,0)] to place your 'O'\n->";
    cin >> p2_play;
    board[stoi(p2_play.substr(1,1))-1][stoi(p2_play.substr(3,1))-1] = "O";
    displayBoard(board);
    if(checkIfWinnerOrFull(board) == true) {return true;}

    return false;

}

bool checkIfWinnerOrFull(string** board) {
    for(int i =0;i<3;i++) {
        if(board[i][1] == board[i][1-1] && board[i][1] == board[i][1+1] && board[i][1] != "_" && board[i][1] != " ") {
            cout << "\nGAME OVER: " << board[i][1] << "'s has won!!";
            return true;
        }
    }
    for(int j =0;j<3;j++) {
        if(board[1][j] == board[1-1][j] && board[1][j] == board[1+1][j] && board[1][j] != "_" && board[1][j] != " ") {
            cout << "\nGAME OVER:  " << board[1][j] << "'s has won!!";
            return true;
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        cout << "\nGAME OVER:  " << board[1][1] << "'s has won!!";
        return true;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        cout << "\nGAME OVER:  " << board[1][1] << "'s has won!!";
        return true;
    }

    //if board full, end game, no winners
    bool stillRoom = false;
    for(int i =0;i<3;i++) {
        for(int j =0;j<3;j++) {
            if(board[i][j] == "_" || board[i][j] == " ") { stillRoom = true;}
        }
    }
    if(stillRoom == false) {
        cout << "\nGAME OVER:  -No Winner- ";
        return true;
    }

    return false;
}

void gameLoop() {
    string answer="y";
    while(answer != "no") {
        string ** board = createEmptyBoard();
        std::cout << "\n\tWelcome to TIC-TAC-TOE\n\n";
        displayBoard(board);
        bool gameWon =false;
        while(gameWon == false) {
            gameWon = turns(board);
        };

        cout << "\nWould you like to replay? (yes/no):\n->";
        cin >> answer;
        if(answer != "no"){
            cout << "\nResetting Game...\n---------------------------------------------------------\n\n";
        }
        deleteBoard(board);
    };
}

void deleteBoard(string** board){
    //delete board
    for (int i = 0; i < 3; ++i)
        delete [] board[i];
    delete [] board;
}

string** createEmptyBoard() {
    string ** brd = new string*[3];
    for(int i =0;i<3;i++) {
        brd[i] = new string[3];
        for(int j =0; j<3;j++) {
            if(i==2){brd[i][j]= " ";}
            else {brd[i][j] = "_";}
        }
    }
    return brd;
}


void displayBoard(string** board) {

    std::string row_1 = "\t      _" + board[0][0] + "_|_" + board[0][1] + "_|_" + board[0][2] + "_";
    std::string row_2 = "\t      _" + board[1][0] + "_|_" + board[1][1] + "_|_" + board[1][2] + "_";
    std::string row_3 = "\t       " + board[2][0] + " | " + board[2][1] + " | " + board[2][2] + " ";

    cout << row_1 << endl;
    cout << row_2 << endl;
    cout << row_3 << endl;
}

// To Compile: g++ sourcefile_name.c -o outputfile.exe