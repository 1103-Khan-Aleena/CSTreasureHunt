#include "helpers.h"
#include <dirent.h>

int generateRandomInt() {
    int generatedNumber = (rand() % 4) + 1; // Because I want an interval between 0 and 4, using the remainder limits its range
    return generatedNumber;
}

bool checkGameStatus(Player& player) {
    if (player.getHealth() <= 0) {
        cout << endl << "Game Over! You Died!\n" << endl;
        return true; // Ends the game
    }
    if (player.getHealth() >= 1 && player.getTreasures() == 3) {
        cout << endl << "Congratulations! You collected 3 treasures" << endl << "You Won!" << endl;
        return true;
    }
    return false; // Continues the game 
}

// Extra credit idk if this will even work copied directly from PA2!!
int loadLeaderboardFromUserFiles(string names[], int wins[]) {
    DIR* directoryPtr = opendir("."); // open the current directory
    struct dirent* directoryEntry; // ptr to hold each file
    int numPlayers = 0;

    if (directoryPtr) {
        while ((directoryEntry = readdir(directoryPtr)) != NULL) {// keeps looping through all files in directory
            string filename = directoryEntry->d_name;

            // Manually check if filename ends with ".txt" not using substr
            bool isTxtFile = true;
            int filenameLength = 0;
            while (filename[filenameLength] != '\0') {
                filenameLength++;
            }

            if (filenameLength >= 4) { // check extension if filename is more than 4 chars long
                for (int i = 0; i < 4; i++) {
                    if (filename[filenameLength - 4 + i] != ".txt"[i]) {
                        isTxtFile = false;
                        break;
                    }
                }
            } else {
                isTxtFile = false; // if filename is shorter than 4 its not a txt file
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
                file.close(); // close the file

                int userWins = 0;
                // Check if lastLine is not empty 
                bool isValidNumber = true; // assume valid until its not
                if (lastLine[0] != '\0') { // Check if it's not empty
                    userWins = 0;
                    for (int i = 0; lastLine[i] != '\0'; i++) {
                        if (lastLine[i] < '0' || lastLine[i] > '9') { // if any char is not a num digit
                            isValidNumber = false;
                            break;
                        }
                    }

                    // If the string was invalid (nondigit characters), set userWins to 0
                    if (isValidNumber) {
                        userWins = stoi(lastLine); // to convert to int
                    } else {
                        userWins = 0; // fallback if the last line isn't a valid number
                    }
                }

                names[numPlayers] = username; // store into names array
                wins[numPlayers] = userWins; // store into wins array
                numPlayers++; // increment num of players found
            }
        }
        closedir(directoryPtr);
    }

    // Sort leaderboard from the highest number to the then the lowest
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

    return numPlayers; // return how many players were loaded
}

//Displays main menu and creates a file for new players, otherwise it tells the main that the user already exists
void displayMainMenu(string *userName){
    cout << "Enter Your Name: ";
    cin >> *userName;
    int s[50];
    string currPlayers[50], existingFile[200];
    int numPlayersSaved = loadLeaderboardFromUserFiles(currPlayers, s);
    bool playerExists = false;
    if(numPlayersSaved == 0){
        cout << endl << "Welcome " << *userName << "!" << endl;
        showLeaderBoard();
        createFile(*userName);
        return;
    }
    for(int i = 0; i < numPlayersSaved; i++){
        if(currPlayers[i] == *userName){
            playerExists = true;
            break;
        }
    }
    if(playerExists == true){
        string filename = *userName + ".txt";
        ifstream fin(filename);
        int linesInFile;
            if(fin.is_open()){
                linesInFile = readEntireFile(fin, existingFile);
            }
            cout << endl <<  "Welcome Back " << *userName << "!" << endl;
            showLeaderBoard();
            for(int i = 1; i < linesInFile - 1; i++){
                cout << existingFile[i] << endl;
            }
            cout << "Current Winning Streak: " << existingFile[linesInFile - 1] << endl;
            return;
        }
    else{
        cout << endl << "Welcome " << *userName << "!" << endl;
        showLeaderBoard();
        createFile(*userName);
        return;
        
    }
    
}

//Creates new file and writes user's name at the top
void createFile(string name){
    string filename = name + ".txt";
    ofstream toFile(filename);
    if(!toFile.is_open()){
        cout << "Unable to create file." << endl;
    }
    else{
        toFile << name << endl << endl << 0;
    }
    toFile.close(); //make sure to close file
}

//File reading function
int readEntireFile(ifstream& fin, string sentences[]){
    int row = 0, col = 0;
    while(getline(fin, sentences[row]) && row < 200){ //Reads each line into its own row
        row++;
    }
   return row;
}

void appendStatsToFile(Player& player, string name){
    string filename = name + ".txt";
    ifstream fin(filename);
    string fileArray[200];
    int lines, streak;

    //Start reading from file
    if(!fin.is_open()){
        cout << "File could not be open" << endl;
    }
    else{
        lines = readEntireFile(fin, fileArray); //reads entire file and saves to 2D array, and lines will be used to figure out how many games have been saved, by subtracting 1 and dividing by 4
        fin.close(); //Make sure to close file
    }
    
    //Opens file again and writes contents of 2D array to file
    ofstream fout(filename);
    if(!fout.is_open()){ //reopen file to append to it
        cout << "File could not be open" << endl;
    }
    else{
        for(int i = 0; i < lines - 1; i ++){
            fout << fileArray[i] << endl;
        }
        fout.close(); //close the file
    }

    //Modifies Win Streak
    string streakString = fileArray[lines - 1];
    int streakInt = stoi(streakString);
    if(player.getHealth() <= 0){
        streakInt = 0;
    }
    if(player.getHealth() >= 1 && player.getTreasures() == 3){

        streakInt++; 
    }
    fileArray[lines - 1] = to_string(streakInt);

    //Reopen file in append mode
    fout.open(filename, ios::app);

    //Append current game to file
    fout << "Game " << ((lines - (lines % 5) - 3) / 5) + 1 << endl << "Final Health: " << player.getHealth() << endl << "Treasures Collected: " << player.getTreasures() << "/3" << endl;
    if(player.getHealth() <= 0){
        fout << "Game Lost 🎮 ❌" << endl;
        fout << endl << fileArray[lines - 1]; //Write streak to file
    }
    if(player.getHealth() >= 1 && player.getTreasures() == 3){
        fout << "Game Won! 🎮 🏆" << endl;
        fout << endl << fileArray[lines - 1]; //write streak to file 
    }
    fout.close(); //close the file
}
void showLeaderBoard() {
    string names[50]; // array to store up to 50 useranmesOr [10] if you want strictly 10
    int wins[50];// array to store up to 50 wins

    int numPlayers = loadLeaderboardFromUserFiles(names, wins);

    char choice;
    cout<<"View leaderboard? (y/n):"; //gives the user the choice to view the leaderbaord or not
    cin>>choice;
    if (choice == 'y' || choice == 'Y') {
    
    //display leaderboard 
    cout << "Top " << 10 << " players:\n";

    // Loop through each player and print their rank, name, and win count
        for (int i = 0; i <10; i++) {
            cout << (i + 1) << ". " << names[i] << " - " << wins[i] << " wins\n";
            }
        }
    // Write leaderboard to file
    ofstream outFile("leaderboard.txt");// Open a file called "leaderboard.txt" for writing
    for (int i = 0; i < 10; i++) {
        outFile << (i + 1) << ". " << names[i] << " - " << wins[i] << " wins\n"; // Write same output 
    }
    outFile.close();
}
