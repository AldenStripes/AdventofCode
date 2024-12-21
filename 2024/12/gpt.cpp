#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Region {
    int area;
    int sides;
};

// Directions for neighbors (up, down, left, right)
const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Function to check if a cell is within bounds
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Flood fill to calculate area and sides of a region
Region floodFill(int x, int y, vector<string>& grid, vector<vector<bool>>& visited) {
    char plantType = grid[x][y];
    int rows = grid.size();
    int cols = grid[0].size();
    int area = 0;
    int sides = 0;

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        area++;

        for (const auto& [dx, dy] : directions) {
            int nx = cx + dx, ny = cy + dy;

            if (isValid(nx, ny, rows, cols)) {
                if (grid[nx][ny] == plantType && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                } else if (grid[nx][ny] != plantType) {
                    sides++; // Border with a different plant type
                }
            } else {
                sides++; // Border with the edge of the map
            }
        }
    }

    return {area, sides};
}

int calculateTotalPrice(vector<string>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    int totalPrice = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j]) {
                // Perform flood fill for each unvisited region
                Region region = floodFill(i, j, grid, visited);
                totalPrice += region.area * region.sides;
            }
        }
    }

    return totalPrice;
}

int main() {
    // Example input map
    vector<string> inputMap = {
        "RRRRIICCFF",
        "RRRRIICCCF",
        "VVRRRCCFFF",
        "VVRCCCJFFF",
        "VVVVCJJCFE",
        "VVIVCCJJEE",
        "VVIIICJJEE",
        "MIIIIIJJEE",
        "MIIISIJEEE",
        "MMMISSJEEE",
    };

    int totalPrice = calculateTotalPrice(inputMap);
    cout << "Total Price: " << totalPrice << endl;

    return 0;
}
