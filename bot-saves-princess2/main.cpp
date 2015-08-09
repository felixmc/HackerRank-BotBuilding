#include <iostream>
#include <vector>

using namespace std;

const char PRINCESS = 'p';

void nextMove(int n, int mX, int mY, vector <string> grid) {

  int pX, pY;

  for (vector<string>::size_type iY = 0; iY < grid.size(); iY++) {
    string line = grid[iY];

    for (int iX = 0; iX < n; iX++) {
      char c = line[iX];

      if (c == PRINCESS) {
        pX = iX;
        pY = iY;
      }
    }
  }


  int dX = mX - pX;
  int dY = mY - pY;

  if (dY > 0) {
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

  int n, mX, mY;
  vector <string> grid;

  cin >> n;
  cin >> mY;
  cin >> mX;

  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    grid.push_back(s);
  }

  nextMove(n, mX, mY, grid);

  return 0;
}
