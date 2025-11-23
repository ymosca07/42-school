char check_line(char *board, char line, char reverse)
{
	int i = 0;

	char max_line = 0;

	char max_int = 0;

	char point_view = 0;

	if (reverse == 0)
	{
		i = line * 4 + i;

		max_line = line * 4 + 4;

		max_int = 0;

		point_view = 0;

		while (i < max_line)
		{
			if (board[i] == 4)
				return (point_view + 1);

			if (i == line * 4 + 0)
			{
				point_view++;
				max_int = board[i];
			}

			if (max_int < board[i])
			{
				point_view++;
				max_int = board[i];
			}

			i++;
		}
	}

	else
	{
		i = line * 4 + 3;

		max_line = line * 4;

		max_int = 0;

		point_view = 0;

		while (i >= max_line)
		{
			if (board[i] == 4)
				return (point_view + 1);

			if (i == line * 4 + 3)
			{
				point_view++;
				max_int = board[i];
			}

			if (max_int < board[i])
			{
				point_view++;
				max_int = board[i];
			}

			i--;
		}
	}
	return (0);
}

#include <stdio.h>

int main()
{
	char tab[] = {
	4, 1, 3, 2,
	2, 1, 3, 4,
	2, 1, 3, 4,
	4, 3, 1, 2,
	};
	
	printf("--> %d  |", check_line(tab, 0, 0));
	printf("  %d <--\n", check_line(tab, 0, 1));	
	printf("--> %d  |", check_line(tab, 1, 0));
	printf("  %d <--\n", check_line(tab, 1, 1));
	printf("--> %d  |", check_line(tab, 2, 0));
	printf("  %d <--\n", check_line(tab, 2, 1));
	printf("--> %d  |", check_line(tab, 3, 0));
	printf("  %d <--\n", check_line(tab, 3, 1));
}
