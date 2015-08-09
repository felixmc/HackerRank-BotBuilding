#include <iostream>
#include <vector>

using namespace std;

const char PRINCESS = 'p';
const char MARIO = 'm';

void displayPathtoPrincess(int n, vector <string> grid) {

  int pX, pY;
  int mX, mY;

  for (vector<string>::size_type iY = 0; iY < grid.size(); iY++) {
    string line = grid[iY];

    for (int iX = 0; iX < n; iX++) {
      char c = line[iX];

      if (c == PRINCESS) {
        pX = iX;
        pY = iY;
      } else if (c == MARIO) {
        mX = iX;
        mY = iY;
      }
    }
  }

  // cout << "Princess position: [" << pX << ", " << pY << "]" << endl;
  // cout << "Mario position:    [" << mX << ", " << mY << "]" << endl;
  //
  // cout << endl << endl;

  int dX = mX - pX;
  int dY = mY - pY;

  // move over Y
  for (int start = mY; start != pY; dY < 0 ? start++ : start--) {
    if (dY > 0) {
      cout << "UP" << endl;
    } else {
      cout << "DOWN" << endl;
    }
  }

  // move over X
  for (int start = mX; start != pX; dX < 0 ? start++ : start--) {
    if (dX > 0) {
      cout << "LEFT" << endl;
    } else {
      cout << "RIGHT" << endl;
    }
  }

}

int main(void) {

  // cout << endl;

  int m;
  vector <string> grid;

  cin >> m;

  for (int i = 0; i < m; i++) {
    string s; cin >> s;
    grid.push_back(s);
    // cout << s << endl;
  }

  // cout << endl << endl;

  displayPathtoPrincess(m, grid);

  return 0;
}
