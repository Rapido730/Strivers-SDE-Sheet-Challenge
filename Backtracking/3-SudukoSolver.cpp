// Problem Link : https://www.codingninjas.com/studio/problems/valid-sudoku_8230704?challengeSlug=striver-sde-challenge&leftPanelTab=1

bool isSafe(int board[9][9], int row, int col, int c)
{

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == c)
            return false;

        if (board[row][i] == c)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool solve(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != 0)
                continue;

            for (int c = 1; c <= 9; c++)
            {
                if (isSafe(board, i, j, c))
                {
                    board[i][j] = c;

                    if (solve(board))
                    {
                        return true;
                    }
                    else
                    {
                        board[i][j] = 0;
                    }
                }
            }

            return false;
        }
    }
    return true;
}

bool isItSudoku(int matrix[9][9])
{
    return solve(matrix);
}
