char check_line(char *board, char line, char reverse)
{
	char result;
	char i;

	result = 0;
	i = 0;
	while (i < 4)
	{

	}

}
char check_column(char *board, char column, char reverse);

char check_dupes(char *board, char index);

char check_rules(char *board, char *rules, char index);

char *get_rules(char *params);

void print_board(char *board);

void solve_board(char *board, char *rules, char index);

int main(int argc, char **argv)
{
	char test[] = {
		1, 2, 3, 4,
		2, 1, 3, 4,
		3, 2, 4, 4,
		4, 2, 3, 1,
	}
	// FREE THE RULES
}
