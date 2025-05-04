#include "helpers.h"
#include <dirent.h>

int generateRandomInt(){
    int generatedNumber = (rand() % 4) + 1; // Because I want an interval between 0 and 4, using the remainder limits its range
    return generatedNumber;
}

bool checkGameStatus(Player& player){
    if (player.getHealth() <= 0){
        cout << endl << "Game Over! You Died!\n" << endl;
        return true; // Ends the game
    }
    if (player.getHealth() >= 1 && player.getTreasures() == 3){
        cout << endl << "Congratulations! You collected 3 treasures" << endl << "You Won!" << endl;
        return true;
    }
    return false; // Continues the game 
}

// Extra credit idk if this will even work copied directly from PA2!!
#include "helpers.h"
#include <dirent.h>

int loadLeaderboardFromUserFiles(string names[], int wins[]) {
    DIR *directoryPtr = opendir(".");
    struct dirent *directoryEntry;
    int numPlayers = 0;

    if (directoryPtr) {
        while ((directoryEntry = readdir(directoryPtr)) != NULL && numPlayers < 10) {
            string filename = directoryEntry->d_name;

            // Manually check if filename ends with ".txt" not using substr
            bool isTxtFile = true;
            int filenameLength = 0;
            while (filename[filenameLength] != '\0') {
                filenameLength++;
            }

            if (filenameLength >= 4) {
                for (int i = 0; i < 4; i++) {
                    if (filename[filenameLength - 4 + i] != ".txt"[i]) {
                        isTxtFile = false;
                        break;
                    }
                }
            } 
            else {
                isTxtFile = false;//is this a text file or no
            }

            if (isTxtFile && filename != "leaderboard.txt") {
                // Manually remove ".txt" from the filename
                string username = "";
                for (int i = 0; i < filenameLength - 4; i++) {
                    username += filename[i];
                }

                // Open the file
                ifstream file(filename);
                string line, lastLine;
                while (getline(file, line)) {
                    lastLine = line; // Keep updating until we reach the last line
                }
                file.close();

                int userWins = 0;
                // Check if lastLine is not empty 
                bool isValidNumber = true;
                if (lastLine[0] != '\0') { // Check if it's not empty
                    userWins = 0;
                    for (int i = 0; lastLine[i] != '\0'; i++) {
                        if (lastLine[i] < '0' || lastLine[i] > '9') {
                            isValidNumber = false;
                            break;
                        }
                        userWins = userWins * 10 + (lastLine[i] - '0');
                    }
                }

                // If the string was invalid (non-digit characters), set userWins to 0
                if (!isValidNumber) {
                    userWins = 0;
                }

                names[numPlayers] = username;
                wins[numPlayers] = userWins;
                numPlayers++;
            }
        }
        closedir(directoryPtr);
    }

    // Sort leaderboard from the highest nunber to the then the lowest
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = i + 1; j < numPlayers; j++) {
            if (wins[j] > wins[i]) {
                //Swap wins[i] and wins[j] manually
                int tempWins = wins[i];
                wins[i] = wins[j];
                wins[j] = tempWins;

                //Swap names[i] and names[j] manually
                string tempName = names[i];
                names[i] = names[j];
                names[j] = tempName;
            }
        }
    }

    return numPlayers;
}
