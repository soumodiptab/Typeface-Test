#include <bits/stdc++.h>
using namespace std;
// min-row/max-row/min-col/max-col

void dfs(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &vis, vector<int> &s)
{
    int rows = mat.size();
    int cols = mat[0].size();
    if (i < 0 || i >= rows || j < 0 || j >= cols || vis[i][j] || !mat[i][j])
        return;
    vis[i][j] = 1;
    s[0] = min(i, s[0]);
    s[1] = max(i, s[1]);
    s[2] = min(j, s[2]);
    s[3] = max(j, s[3]);
    dfs(mat, i - 1, j, vis, s);
    dfs(mat, i, j - 1, vis, s);
    dfs(mat, i + 1, j, vis, s);
    dfs(mat, i, j + 1, vis, s);
}

vector<vector<int>> getboundingbox(vector<vector<int>> &mat)
{
    vector<vector<int>> sol;
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!visited[i][j] && mat[i][j])
            {
                vector<int> s = {i, i, j, j};
                dfs(mat, i, j, visited, s);
                int width = s[3] - s[2] + 1;
                int height = s[1] - s[0] + 1;
                int cx = (s[3] + s[2]) / 2;
                int cy = (s[1] + s[0]) / 2;
                sol.push_back({cx,
                               cy,
                               width,
                               height});
            }
        }
    }
    return sol;
}

int main()
{
    int m, n;
    // input matrix of image
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> sol = getboundingbox(mat);
    // output : centerx,centery,width,height
    for (auto &v : sol)
    {
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    }
    return 0;
}