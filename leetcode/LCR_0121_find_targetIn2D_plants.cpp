#include <vector>
using namespace std;

bool findTargetIn2DPlants(vector<vector<int>>& plants, int target)
{
    if (plants.empty() || plants[0].empty())return false;
    size_t row = plants.size();
    size_t col = plants[0].size();
    for (size_t i = 0;i < row;i++) {
        if (plants[i][0] <= target && plants[i][col - 1] >= target) {
            int left = -1, right = col;
            while (left + 1 != right) {
                int mid = (left + right) / 2;
                if (plants[i][mid] > target)right = mid;
                else if (plants[i][mid] < target)left = mid;
                else return true;
            }
        }
    }
    return false;
}

bool findTargetIn2DPlants(vector<vector<int>>& plants, int target)
{
    if (plants.empty() || plants[0].empty())return false;
    size_t row = plants.size();
    size_t col = plants[0].size();
    int i = 0, j = col - 1;
    while (i < row && j >= 0) {
        if (plants[i][j] > target) j--;
        else if (plants[i][j] < target) i++;
        else return true;
    }
    return false;
}