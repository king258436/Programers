#include <string>
#include <vector>

using namespace std;

typedef struct {
    int y;
    int x;
} Po;

vector<int> solution(vector<string> wallpaper)
{
    vector<int> answer(4);
    Po L, H;
    L = { 100, 100 };
    H = { 0, 0 };
    int wall_length = wallpaper[0].length();
    int wall_hight = wallpaper.size();
    for (int i = 0; i < wall_hight; i++) {
        for (int j = 0; j < wall_length; j++) {
            if (wallpaper[i][j] == '#') {
                L.x = min(L.x, j);
                L.y = min(L.y, i);
                H.x = max(H.x, j);
                H.y = max(H.y, i);
            }
        }
    }
    H.x++;
    H.y++;
    answer[0] = L.y;
    answer[1] = L.x;
    answer[2] = H.y;
    answer[3] = H.x;
    return answer;
}