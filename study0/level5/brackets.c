#include <unistd.h>

static int is_start(char c)
{
	return (c == '(' || c == '[' || c == '{');
}

static int is_end(char c)
{
	return (c == ')' || c == ']' || c == '}');
}

static void push(char *stack, int *top, char content)
{
	stack[*top] = content;
	*top += 1;
}

static void pop(int *top)
{
	*top -= 1;
}

static int is_current_bracket(char *stack, int *top, char target)
{
	if (stack[*top - 1] == '(' && target == ')')
		return (1);
	else if (stack[*top - 1] == '[' && target == ']')
		return (1);
	else if (stack[*top - 1] == '{' && target == '}')
		return (1);
	return (0);
}

static void bracket(char *stack, char *word)
{
	int top;
	int error;

	top = 0;
	error = 0;
	while (*word)
	{
		if (is_end(*word))
		{
			if (!is_current_bracket(stack, &top, *word))
			{
				error = 1;
				break ;
			}
			pop(&top);
		}
		else
		{
			if (is_start(*word))
				push(stack, &top, *word);
		}
		word++;
	}
	if (top == 0 && error == 0)
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
}

int main(int argc, char **argv)
{
	char stack[4096];
	int i = 1;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (argv[i])
	{
		bracket(stack, argv[i]);
		i++;
	}
	return (1);
}
