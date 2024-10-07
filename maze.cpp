#include <iostream>
#include <vector>
#include <conio.h> // For _getch()

using namespace std;

// Define the maze
const vector<string> maze = {
    "#########",
    "#       #",
    "# ### # #",
    "# #   # #",
    "# ### # #",
    "#       #",
    "#########"
};

// Player's starting position
pair<int, int> playerPos = {1, 1};

void printMaze() {
    system("cls"); // Clear the console (Windows)
    for (int y = 0; y < maze.size(); ++y) {
        for (int x = 0; x < maze[y].size(); ++x) {
            if (playerPos.first == y && playerPos.second == x) {
                cout << "P"; // Player's position
            } else {
                cout << maze[y][x];
            }
        }
        cout << endl;
    }
}

void movePlayer(int dx, int dy) {
    int newX = playerPos.second + dx;
    int newY = playerPos.first + dy;

    // Check for wall or boundary
    if (maze[newY][newX] != '#') {
        playerPos = {newY, newX};
    }
}

int main() {
    printMaze();
    while (true) {
        char move = _getch(); // Get user input
        switch (move) {
            case 'w':
            case 'W':
                movePlayer(0, -1);
                break;
            case 'a':
            case 'A':
                movePlayer(-1, 0);
                break;
            case 's':
            case 'S':
                movePlayer(0, 1);
                break;
            case 'd':
            case 'D':
                movePlayer(1, 0);
                break;
            case 'q':
            case 'Q':
                cout << "Thanks for playing!" << endl;
                return 0;
            default:
                cout << "Invalid input. Use W, A, S, D to move, or Q to quit." << endl;
                continue;
        }
        printMaze();
    }

    return 0;
}
