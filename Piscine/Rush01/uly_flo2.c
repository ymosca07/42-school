#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void print_board(char *board, char size)
{
	char i;
	char c;

	i = 0;
	while (i < size * size)
	{
		c = '0' + board[i];
		write(1, &c, 1);
		if (i % size == size - 1)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

char indexer(char i, char reverse, char s)
{
	if (reverse)
		return (s - i - 1);
	return i;
}

char check_line(char *board, char line, char reverse, char s)
{
	char result;
	char i;
	char max;

	result = 0;
	i = 0;
	max = 0;
	while (i < s)
	{
		if (max < board[line * s + indexer(i, reverse, s)])
		{
			result++;
			max = board[line * s + indexer(i, reverse, s)];
		}
		i++;
	}
	// printf("Line %i, ret: %i, rev : %i\n", line, result, reverse);
	return (result);

}

char check_column(char *board, char column, char reverse, char s)
{
	char result;
	char i;
	char max;

	result = 0;
	i = 0;
	max = 0;
	while (i < s)
	{
		if (max < board[column + s * indexer(i, reverse, s)])
		{
			result++;
			max = board[column +  s * indexer(i, reverse, s)];
		}
		i++;
	}
	// printf("Conlun %i, ret: %i, rev : %i\n", column, result, reverse);
	return (result);
}

char	check_dupes(char *board, char index, char size)
{
	int		i;
	int		row;
	int		col;
	char	value;

	row = index / size;
	col = index % size;
	i = 0;
	value = board[index];
	while (i < size)
	{
		if (i != col && (value != 0) && board[row * size + i] == value)
			return (1);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (i != row && (value != 0) && board[i * size + col] == value)
			return (1);
		i++;
	}
	return (0);
}

char index_full(char *board, char index, char s)
{
	int i;

	i = 0;
	while (i < s)
	{
		if (board[(index / s) * s + i] == 0
				|| board[(index % s) + i * s] == 0)
			return 0;
		i++;
	}
	return (1);
}

char check_rule(char *board, char *rules, char r_index, char size)
{
	char i;
	char empty;
	char see;
	char max;
	char curr;
	char off;

	i = 0;
	empty = 0;
	max = 0;
	see = 0;
	// print_board(board, size);
	if (rules[r_index] == 0)
		return (0);
	while (i < size)
	{
		if (r_index / (size * 2) == 0)
		{
			if (r_index / size == 0)
				curr = board[i * size + (r_index % size)];
			else
				curr = board[(size - i - 1)  * size + (r_index % size)];
		}
		else 
		{
			if (r_index / size == 2)
				curr = board[i + size * (r_index % size)];
			else
				curr = board[size - i - 1 + size * (r_index % size)];
		}
		if (curr > max)
		{
			max = curr;
			see += 1;
		}
		if (curr == 0)
			empty++;
		// printf("Cuur %i, i: %i\n", curr, i);
		i++;
	}
	// printf("Check rule %i e; %i s: %i\n", r_index, empty, see);
	return empty == 0 && rules[r_index] != see;
}


char check_rules(char *board, char *rules, char index, char size)
{
	// if (check_dupes(board, index, size) || (index_full(board, index, size) && (
	// 	rules[index % size] != check_column(board, index % size, 0, size)
	// 	|| rules[index % size + siz1 * 1] != check_column(board, index % size, 1, size)
	// 	|| rules[index / size + size * 2] != check_line(board, index / size, 0, size)
	// 	|| rules[index / size + size * 3] != check_line(board, index / size, 1, size)))
	// )
	// 	return (0);
 
	if ( check_dupes(board, index, size) 
			|| check_rule(board, rules, index % size, size)
			|| check_rule(board, rules, size + index % size, size)
			|| check_rule(board, rules, 2 * size + index / size, size)
			|| check_rule(board, rules, 3 * size + index / size, size))
	{
		// printf("Board off\n");
		return (0);
	}
	return (1);
}

//TODO: Prendre pointeur et renvoyer la size du tableau
char	*get_rules(char *str, char *size)
{
	int	i;
	int	j;
	char	*res;

	i = 0;
	j = 0;
	if (!(*str))
		return (0);

	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			j++;
		i++;
	}

	if (j < 16 || j % 4 != 0)
	 	return (0);

	*size = j / 4;

	res = (char *)malloc(j);

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res[j] = str[i] - '0';
			j++;
		}
		i++;
	}

	return (res);
}

char	solve_board(char *board, char *rules, char size)
{
	char i;
	char tab_size;

	tab_size = size * size;
	i = 0;
	while (i < tab_size)
	{
		if (i < 0)
			return (0);
		if (board[i] == size)
		{
			board[i] = 0;
			i -= 1;
			continue;
		}
		board[i] += 1;
		if (check_rules(board, rules, i, size))
			i++;
	}
	print_board(board, size);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	char test[81] = {
		0, 0, 3, 0, 0, 0, 0, 6, 2, 
		0, 0, 9, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 7, 0, 9, 0, 0, 0, 0, 0, 
		0, 4, 0, 2, 8, 7, 0, 0, 0, 
		0, 3, 5, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 3, 2, 4, 6
	};
	char i = 0;
	char size;
	char *rules = get_rules(argv[1], &size);
	if (rules == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (i < 81)
	{
	 	test[i] = 0;
	 	i++;
	}

	printf("Tab size : %i\n", size);
	solve_board(test, rules, size);

	// FREE THE RULES
}

