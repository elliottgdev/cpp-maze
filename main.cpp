#include <iostream>
#include <vector>

int playerX = 1, playerY = 1;
std::vector<std::string> level = {
    "############",
    "#          #",
    "#     #    #", 
    "# &   #    #",
    "#     ##   #", 
    "#          #",
    "#      # $ #", 
    "############",
};
char input;
bool running = true;
bool coin = false;

void update() {
  for (int i = 0; i < level.size(); i++) {
    std::string line = level[i];
    for (int x = 0; x < line.size(); x++) {
      if (line[x] == '$' && coin) {
        line[x] = ' ';
      }
      if (playerY == i) {
        if (playerX == x) {
          if (line[x] == '#') {
            line = "game over";
            running = false;
            break;
          }
          if (line[x] == '$') {
            coin = true;
          }
          if (line[x] == '&') {
            if (coin) {
              line = "you win";
              running = false;
              break;
            }
          }
          line[x] = '@';
        }
      }
    };
    std::cout << line << "\n";
  }
}

int main() {
  std::cout << "Hello World!\n";
  update();
  while (running) {
    std::cin >> input;
    switch (input) {
    case 'w':
      playerY--;
      break;
    case 's':
      playerY++;
      break;
    case 'a':
      playerX--;
      break;
    case 'd':
      playerX++;
      break;
    default:
      std::cout << "invalid input\n";
      break;
    }
    std::cout<<"\e[1;1H\e[2J";
    update();
  }
}
