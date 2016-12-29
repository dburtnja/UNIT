
#include "../libft.h"
#define N 30

int		is_safe(int board[N][N], int row, int col)
{
	int i;
	int j;

	i = 0;
	while (i < col)
	{
		if (board[row][i])
			return (0);
		i++;
	}
	i = row;
	j = col;
	while (i >= 0 && j >= 0)
	{
		if (board[i][j])
			return (0);
		i--;
		j--;
	}
	i = row;
	j = col;
	while (i >= 0 && i < N)
	{
		if (board[i][j])
			return (0);
		i++;
		j--;
	}
	return (1);
}

int		solveNQUntil(int board[N][N], int col)
{
	int	i;

	i = 0;
	if (col >= N)
		return (1);
	while (i < N)
	{
		if (is_safe(board, i, col))
		{
			board[i][col] = 1;
			if (solveNQUntil(board, col + 1))
				return (1);
			board[i][col] = 0;
		}
		i++;
	}
	return (0);
}

void	ft_putint_array(int board[N][N], int r, int c)
{
	int i;
	int j;

	i = 0;
	while (i < r)
	{
		j = 0;
		while (j < c)
		{
			ft_putnbr(board[i][j]);
			ft_putchar('\t');
			j++;
		}
		i++;
		ft_putendl("");
	}
}

void	solveNQ(void)
{
	int	board[N][N] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
	if (solveNQUntil(board, 0) == 0)
		ft_putendl("Solution does not exist");
	ft_putint_array(board, N, N);
}

int		main(void)
{
	solveNQ();
	return (0);
}
