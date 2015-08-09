#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

char DIRTY = 'd';
char BOT = 'b';
int SIZE = 5;

float calcDist(int x1, int y1, int x2, int y2) {
  return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

void next_move(int bX, int bY, vector <string> grid) {

  int pX, pY;
  float distance = 999;

  for (vector<string>::size_type iY = 0; iY < grid.size(); iY++) {
    string line = grid[iY];

    for (int iX = 0; iX < SIZE; iX++) {
      char c = line[iX];

      if (c == DIRTY) {
        float tDist = calcDist(bX, bY, iX, iY);

        if (tDist < distance) {
          distance = tDist;
          pX = iX;
          pY = iY;
        }
      }
    }
  }

  int dX = bX - pX;
  int dY = bY - pY;

  if (dX == 0 && dY == 0) {
    cout << "CLEAN" << endl;
  } else if (dY > 0) {
    cout << "UP" << endl;
  } else if (dY < 0) {
    cout << "DOWN" << endl;
  } else if (dX > 0) {
    cout << "LEFT" << endl;
  } else {
    cout << "RIGHT" << endl;
  }
}

int main(void) {
  int pos[2];
  vector <string> board;
  cin >> pos[0] >> pos[1];

  for (int i = 0; i < 5; i++) {
    string s;cin >> s;
    board.push_back(s);
  }

  next_move(pos[1], pos[0], board);

  return 0;
}
