//  Problem Link : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution
{
public:
    bool isSafe(int node, bool graph[101][101], vector<int> &color, int n, int col)
    {
        for (int i = 0; i < n; i++)
        {
            if (node != i && graph[node][i] == 1 && col == color[i])
                return false;
        }

        return true;
    }
    bool dfs(int node, bool graph[101][101], vector<int> &color, int m, int n)
    {

        if (node == n)
            return true;

        for (int col = 0; col < m; col++)
        {
            if (isSafe(node, graph, color, n, col))
            {
                color[node] = col;
                if (dfs(node + 1, graph, color, m, n))
                {
                    return true;
                }

                color[node] = -1;
            }
        }

        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> color(101, -1);
        // memset(color,-1,sizeof(color));

        return dfs(0, graph, color, m, n);

        // return true;
    }
};
