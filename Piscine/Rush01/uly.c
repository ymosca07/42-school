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

char check_dupe(unsigned int *dupe, char c, char l, char s)
{
	if ((*dupe & (1 << (c - 1)) && c != 0) 
		|| (*dupe & (1 << (l + s - 1)) && l != 0))
		return (1);
	if (c != 0)
		*dupe |= 1 << (c - 1);
	if (l != 0)
		*dupe |= 1 << (l + s - 1);
	return (0);
}

char check_dupes(char *board, char index, char s)
{
	unsigned int dupe;
	int i;

	i = 0;
	dupe = 0;
	while (i < s)
	{
		if (check_dupe(&dupe, board[i * s + (index % s)], board[i + (index / s) * s], s))
		{
			// printf("dupe %i, %b, %i\n", index, dupe, board[index]);
			return (1);
		}
		i++;
	}
	return (0);
}

char col_full(char *board, char index)
{

}
char check_rule(char *board, char rules, char r_index)
{
	if (r_index > 8 && col_full(r_index))
	{
		if (check_column(board, r_index % 4, 0) != rules[r_index % 4])
		{
			return (0);
		}
	}
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

char	*get_rules(char *str)
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

	// if (j != 16)
	// 	return (0);

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

char get_valide(char *board, char *rules, char index, char size)
{
	char save;
	char i;
	int valide;

	valide = 0;
	save = board[index];
	i = 0;
	while (i < size)
	{
		board[index] = i + 1;
		if (check_rules(board, rules, index, size))
			valide |= 1 << i;
		i++;
	}
	board[index] = save;
	return valide;
}

char compare_valid(int a, int b)
{
	char ra;
	char rb;

	while (a > 0 || b > 0)
	{
		if (a % 2)
			ra++;
		if (b % 2)
			rb++;
		a /= 2;
		b  /= 2;
	}
	return (ra < rb);
}

char solve_less(char *board, char *rules, char size)
{
	char i;
	int min_valide;
	int min_index;
	int curr_valid;
	
	min_valide = 0x3F;
	min_index = -1;
	// print_board(board, size);
	while (i < size * size)
	{
		if (board[i])
		{
			i++;
			continue;
		}
		curr_valid = get_valide(board, rules, i, size);
		if (compare_valid(curr_valid, min_valide))
		{
			min_valide = curr_valid;
			min_index = i;
			if (min_valide == 0)
				return 0;
		}
		i++;
	}
	if (min_index == -1)
	{
		print_board(board, size);
		printf("Nice \n");
	}

	board[min_index] = 0;
	while(min_valide)
	{
		board[min_index] += 1;
		if (min_valide % 2)
			solve_less(board, rules, size);
		min_valide /= 2;
	}
	return (0);
}

char solve_board(char *board, char *rules, char index, char size, int *print)
{
	char i;
	char s;

	// printf("%i\n", index);
	
	if (*print % 1000000 == 0)
		print_board(board, size);
	*print += 1;
	s = size * size;
	if (index == s)
	{
		i = 0;
		// while (i < s)
		// {
		// 	if (check_rules(board, rules, i, size) == 0)
		// 		print_board(board, size);
		// 		// return (0);
		// 	i++;
		// }
		print_board(board, size);
		printf("Nice \n");
		return (1);
	}
	if (board[index] != 0)
		return solve_board(board, rules, index + 1, size, print);
	i = 1;
	while (i < size + 1)
	{
		board[index] = i;
		if (check_rules(board, rules, index, size))
		{
			if (solve_board(board, rules, index + 1, size, print))
				return (1);
		}
		i++;
	}
	board[index] = 0;
	return (0);
}



#include <stdio.h>
int main(int argc, char **argv)
{
	char test[81] = {
		// 3, 2, 0, 0, <- 1
		// 2, 3, 4, 0,
		// 2, 0, 0, 0,
		// 0, 0, 0, 0, 0, 2,
		// 0, 0, 0, 0, 3, 0,
		// 0, 0, 2, 0, 0, 0,
		// 0, 2, 0, 0, 0, 0,
		// 4, 0, 0, 0, 0, 0,
		// 0, 0, 0, 0, 0, 0,
		5, 6, 2, 3, 7, 9, 8, 4, 1,
		8, 2, 9, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 9, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		6, 9, 1, 7, 2, 8, 3, 5, 4, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		9, 5, 7, 4, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 
	};
	//
	// printf("%i\n", check_dupes(test, 2));
	// printf("%i\n", check_dupes(test, 4));
	// printf("%i\n", check_dupes(test, 8));
	// return 0;
	char i = 0;
	char *rules = get_rules(argv[1]);
	int p = 0;
	// while (i < 81)
	// {
	// 	test[i] = 0;
	// 	i++;
	// }
	
	// test[0] = 4;
	// test[17] = 2;
	// test[25] = 4;
	// test[28] = 1;
	// print_board(test);
	// print_board(rules);

	solve_board(test, rules, 10,  9, &p);

	// FREE THE RULES
}
