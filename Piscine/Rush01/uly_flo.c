#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char indexer(int i, int reverse)
{
	if (reverse)
		return (3 - i);
	return i;
}
char check_line(char *board, char line, char reverse)
{
	char result;
	char i;
	char max;

	result = 0;
	i = 0;
	max = 0;
	while (i < 4)
	{
		if (max < board[line * 4 + indexer(i, reverse)])
		{
			result++;
			max = board[line * 4 + indexer(i, reverse)];
		}
		i++;
	}
	printf("Line %i, ret: %i, rev : %i\n", line, result, reverse);
	return (result);

}
char check_column(char *board, char column, char reverse)
{
	char result;
	char i;
	char max;

	result = 0;
	i = 0;
	max = 0;
	while (i < 4)
	{
		if (max < board[column + 4 * indexer(i, reverse)])
		{
			result++;
			max = board[column +  4 * indexer(i, reverse)];
		}
		i++;
	}
	printf("Conlun %i, ret: %i, rev : %i\n", column, result, reverse);
	return (result);
}

char	check_dupes(char *board, char index)
{
	int	i;
	int	row;
	int	col;
	char	value;

	row = index / 4;
	col = index % 4;
	i = 0;
	value = board[index];
	while (i < 4)
	{
		if (i != col && (value != 0) && board[row * 4 + i] == value)
			return (1);
		i++;
	}

	i = 0;
	while (i < 4)
	{
		if (i != row && (value != 0) && board[i * 4 + col] == value)
			return (1);
		i++;
	}
	return (0);
}

char index_full(char *board, char index)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (board[(index / 4) * 4 + i] == 0
				|| board[(index % 4) + i * 4] == 0)
			return 0;
		i++;
	}
	return (1);
}

char check_rules(char *board, char *rules, char index)
{
	if (check_dupes(board, index) || (index_full(board, index) && (
		rules[index % 4] < check_column(board, index % 4, 0)
		|| rules[index % 4 + 4] < check_column(board, index % 4, 1)
		|| rules[index / 4 + 8] < check_line(board, index / 4, 0)
		|| rules[index / 4 + 12] < check_line(board, index / 4, 1)))
	)
		return (0);
	return (1);
}

int	count_numbers(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
			j++;
		i++;
	}
	return (j);
}

char	*get_rules(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = count_numbers(str);
	if (!(*str))
		return (0);
	if (j != 16)
		return (0);
	res = (char *)malloc(j + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			res[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (res);
}

void print_board(char *board)
{
	char i;
	char c;

	i = 0;
	while (i < 16)
	{
		c = '0' + board[i];
		write(1, &c, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

char solve_board(char *board, char *rules, char index)
{
	char i;

	print_board(board);
	if (index == 16)
	{
		print_board(board);
		printf("Nice");
		return (1);
	}
	i = 1;
	while (i < 5)
	{
		board[index] = i;
		if (check_rules(board, rules, index))
		{
			if (solve_board(board, rules, index + 1))
				return (1);
		}
		i ++;
	}
	board[index] = 0;
	return (0);
}



#include <stdio.h>
int main(int argc, char **argv)
{
	char test[16] = {
		// 1, 2, 3, 4,
		// 2, 3, 4, 1,
		// 3, 4, 1, 2,
		// 0, 0, 0, 0
	};
	//
	// printf("%i\n", check_dupes(test, 2));
	// printf("%i\n", check_dupes(test, 4));
	// printf("%i\n", check_dupes(test, 8));
	// return 0;
	char i = 4;
	char *rules = get_rules(argv[1]);
	while (i < 16)
	{
		test[i] = 0;
		i++;
	}
	
	print_board(test);
	print_board(rules);

	solve_board(test, rules, 0);

	// FREE THE RULES
}
