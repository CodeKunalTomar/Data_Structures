/*You’re given a board of N * M size.
Each element of this board is
represented by either 0 or 1, where
0 means ‘dead’ and 1 means ‘live’.
Each element can interact with all
of its eight neighbors using the
following four rules.

If any live cell has less
than two live neighbors,
then it dies.

If any live cell has two
or three live neighbors,
then it lives onto the
next generation.

If any live cell has more
than three live neighbors,
then it dies.

A dead element with
exactly three live
neighbors becomes a live
element.

Your task is to print the
next state of this board
using these four rules.

Sample Input 1 :
1
2 2
1 0
0 1
Sample Output 1 :
 0 0
 0 0

Explanation For Sample Input 1 :

The first element(0,0) and the fourth element(1,1) are ‘live’ and have one live and two dead neighbors. Hence they both will die and become 0 in the next state. The second element(0,1) and the third element(1,0) are ‘dead’ and have one dead and two live neighbors. Hence they will also die and become 0 in the next state.

Sample Input 2 :
1
3 3
0 0 1
0 0 0
1 0 1
Sample Output 2 :
0 0 0
0 1 0
0 0 0
*/
vector<vector<int>> gameOfLife(vector<vector<int>>& board, int n, int m)
{
	// Write your code here
	int liveNeighbours = 0;

	vector<vector<int>> new_board = board;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			for(int x = max(i - 1, 0); x <= min(i + 1, n - 1); x++)
			{
				for(int y = max(j - 1, 0); y <= min(j + 1, m - 1); y++)
				{
					if(x == i && y == j)
					{
						continue;
					}

					if(board[x][y] == 1)
					{
						liveNeighbours++;
					}
				}
			}
			if(board[i][j] == 1 && (liveNeighbours < 2 || liveNeighbours > 3))
			{
				new_board[i][j] = 0;
			}

			else if(board[i][j] == 0 && liveNeighbours == 3)
			{
				new_board[i][j] = 1;
			}

			else
			{
				new_board[i][j] = board[i][j];
			}
			liveNeighbours = 0;
		}
	}
	return new_board;
}
