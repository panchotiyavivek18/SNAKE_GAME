#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class SnakeGame {
private:
    bool gameOver;
    const int width;
    const int height;
    int x, y, foodX, foodY, score;
    int speed; // Adjustable game speed
    Direction dir;
    vector<pair<int, int>> snake; // Snake body

public:
    SnakeGame(int w, int h, int spd) : width(w), height(h), gameOver(false), score(0), speed(spd), dir(STOP) {
        resetGame();
    }

    void resetGame() {
        gameOver = false;
        score = 0;
        dir = STOP;
        x = width / 2;
        y = height / 2;
        snake.clear();
        snake.push_back({x, y});
        foodX = rand() % width;
        foodY = rand() % height;
    }

    void draw() {
        vector<string> buffer(height + 2, string(width + 2, ' '));

        // Draw top and bottom borders
        for (int i = 0; i < width + 2; i++) {
            buffer[0][i] = '-';
            buffer[height + 1][i] = '-';
        }

        // Draw left and right borders
        for (int i = 1; i <= height; i++) {
            buffer[i][0] = '|';
            buffer[i][width + 1] = '|';
        }

        // Draw snake
        for (auto part : snake) {
            buffer[part.second + 1][part.first + 1] = 'o';
        }

        // Draw snake head
        buffer[y + 1][x + 1] = 'O';

        // Draw food
        buffer[foodY + 1][foodX + 1] = 'F';

        // Output the buffer*/
        system("cls");
        for (const auto& line : buffer) {
            cout << line << endl;
        }

        cout << "Score: " << score << endl;
    }

    void input() {
        if (_kbhit()) {
            Direction olddir = dir;
            switch (_getch()) {
                case 75: dir = LEFT; break;
                case 77: dir = RIGHT; break;
                case 72: dir = UP; break;
                case 80: dir = DOWN; break;
                case 'a':dir = LEFT; break;
                case 's': dir=DOWN;break;
                case 'd': dir=RIGHT;break;
                case 'w' : dir=UP;break;
                case '0': gameOver = true; break;
            }

            if (olddir == UP && dir == DOWN) dir = olddir;
            else if (olddir == DOWN && dir == UP) dir = olddir;
            else if (olddir == LEFT && dir == RIGHT) dir = olddir;
            else if (olddir == RIGHT && dir == LEFT) dir = olddir;
        }
    }

    void logic() {
        // Update tail
        snake.insert(snake.begin(), {x, y});
        if (x == foodX && y == foodY) {
            score += 10;
            foodX = rand() % width;
            foodY = rand() % height;
        } else {
            snake.pop_back();
        }

        switch (dir) {
            case LEFT: x--; break;
            case RIGHT: x++; break;
            case UP: y--; break;
            case DOWN: y++; break;
            default: break;
        }

        // Check collisions with boundaries
        if (x < 0 || x >= width || y < 0 || y >= height)
            gameOver = true;

        // Check collisions with itself
        for (int i = 1; i < snake.size(); i++) {
            if (snake[i].first == x && snake[i].second == y) {
                gameOver = true;
                break;
            }
        }
    }

    void run() {
        int maxx = 0;
        while (true) {
            while (!gameOver) {
                draw();
                input();
                logic();
                Sleep(speed); // Adjustable game speed
            }

            maxx = max(maxx, score);
            cout << "Game Over!" << endl;
            cout << "Your score: " << score << endl;
            cout << "Maximum Score: " << maxx << endl;
            
            char choice;
            cout << "Press 'R' to restart or any other key to exit: ";
            cin >> choice;
            if (choice == 'R' || choice == 'r') {
                resetGame();
            } else {
                break;
            }
        }
    }
};

int main() {
    srand (static_cast<unsigned>(time(0)));
    int gridWidth = 50;
    int gridHeight = 20;
    int gameSpeed = 200; // Adjustable game speed (ms) to 100 for a normal game speed, 1 for a very slow game speed, etc. 1000ms = 1 second. 100ms = 0.1 second. 1ms = 1000000 microseconds. 1000000 / 100 = 1000ms. 1000000 / 1 = 1 second. 1000000 / 10 = 100000 milliseconds. 1000000 / 1000 = 1000 milliseconds. 1000000 / 1000000 = 1 second. 1000000 / 100000000

    SnakeGame game(gridWidth, gridHeight, gameSpeed);

    string n;
    cout<<"if you want to play snake game type 'YES' ";
    cin>>n;

    if(n=="YES") game.run();
    else cout<<"please experience our game one time";
    return 0;
}
