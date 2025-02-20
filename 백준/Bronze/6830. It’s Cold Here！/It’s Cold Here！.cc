#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int minTemp = 201;
  string coldestCity;
  while (true) {
    string city; int temp; cin >> city >> temp;

    if (temp < minTemp) {
      minTemp = temp;
      coldestCity = city;
    }

    if (city == "Waterloo") break ;
  }

  cout << coldestCity << "\n";

  return 0;
}