#include "Player.h"
#include <iostream>

int main() {
    // Create Player object using the default constructor
    Player player1;
    
    // Display initial stats of player1
    std::cout << "Player 1 Initial Stats:" << std::endl;
    player1.displayStats();

    // Create Player object using parameterized constructor
    Player player2(2, 3, 80, 5);  // Player at position (2,3) with health 80 and 5 treasures
    std::cout << "\nPlayer 2 Initial Stats:" << std::endl;
    player2.displayStats();

    // Test setter methods
    player1.setPosition(4, 4);
    player1.setHealth(90);
    player1.collectTreasure();  // Collect one treasure

    std::cout << "\nPlayer 1 Updated Stats:" << std::endl;
    player1.displayStats();

    // Test health change (damage or healing)
    player1.changeHealth(-10);  // Decrease health by 10 (damage)
    std::cout << "\nPlayer 1 After Taking Damage:" << std::endl;
    player1.displayStats();

    // Test copy constructor
    Player player3 = player2;  // Copy player2 to player3
    std::cout << "\nPlayer 3 (Copied from Player 2) Stats:" << std::endl;
    player3.displayStats();

    return 0;
}
