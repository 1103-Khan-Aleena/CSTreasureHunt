#include "helpers.h"
#include <dirent.h>

int generateRandomInt(){
    int generatedNumber = (rand() % 4) + 1; //Because i want an interval between 0 and 4, using the remainder limits its range
    return generatedNumber;
}

bool checkGameStatus(Player& player){
    if(player.getHealth()<=0){
        cout << endl << "Game Over! You Died!\n" << endl;
        return true;//ends the game
    }
    if(player.getHealth()>=1 && player.getTreasures()==3){
        cout << endl << "Congratulations! You colllected 3 treaures" << endl << "You Won!" << endl;
        return true;
    }
    return false;// continues the game 
}
//extra credit idk if this will even work directly copied and pasted from PA2 
int loadLeaderboardFromUserFiles(string names[], int wins[]) {
    DIR *directoryPtr = opendir(".");
    struct dirent *directoryEntry;
    int numPlayers = 0;
    
    if (directoryPtr) {
        while ((directoryEntry = readdir(directoryPtr)) != NULL && numPlayers < 10) {
            string filename = directoryEntry->d_name;
            if (filename.size() >= 4 && filename.substr(filename.size() - 4) == ".txt") {
                if (filename != "leaderboard.txt") {
                    // remove ".txt" extension
                    string username = filename.substr(0, filename.size() - 4);
                    
                    // open the file
                    ifstream file(filename);
                    string line, lastLine;
                    while (getline(file, line)) {
                        lastLine = line; // keep updating until we reach last line
                    }
                    file.close();
                    
                    int userWins = 0;
                    if (!lastLine.empty()) {
                    bool isValidNumber = true;
                    userWins = 0;

                // Loop through each character of the string and convert it to an integer
                    for (int i = 0; i < lastLine.length(); i++) {
                        if (lastLine[i] < '0' || lastLine[i] > '9') {
                            isValidNumber = false;
                            break;
                        }

        // Update the number by multiplying the current result by 10 and adding the digit
        userWins = userWins * 10 + (lastLine[i] - '0');
    }

    // If the string was invalid (non-digit characters), set userWins to 0
    if (!isValidNumber) {
        userWins = 0;
    }
}
        names[numPlayers] = username;
        wins[numPlayers] = userWins;
        numPlayers++;
                }
            }
        }
        closedir(directoryPtr);
    }
    
    // sort leaderboard
    for (int i = 0; i < numPlayers - 1; i++) {
    for (int j = i + 1; j < numPlayers; j++) {
        if (wins[j] > wins[i]) {
            // Swap wins[i] and wins[j] manually
            int tempWins = wins[i];
            wins[i] = wins[j];
            wins[j] = tempWins;

            // Swap names[i] and names[j] manually
            string tempName = names[i];
            names[i] = names[j];
            names[j] = tempName;
        }
    }
}
return numPlayers;
}




