#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char stack_arr[100];
char infix[50];
char postfix[50];
char prefix[50];
int top = -1;
int top1 = -1;
int ans[50];
int push1(int i)
{
	ans[++top1] = i;
}
int pop1()
{
	if(top1==-1)
	return 0;
	return ans[top1--];
	
}
int push(char c)
{
	stack_arr[++top] = c;
}
char pop()
{
	if(top==-1)
	return ;
	return stack_arr[top--];
}
int instack_priority_postfix(char c)
{

	switch (c)
	{
	case '(':
		return 0;
	case '^':
		return 3;
	case '*':
	case '/':
	case '%':
		return 2;
	case '+':
	case '-':
		return 1;
	}
}
int incoming_priority_postfix(char c)
{

	switch (c)
	{
	case '^':
		return 4;
	case '*':
	case '/':
	case '%':
		return 2;
	case '+':
	case '-':
		return 1;
	}
}
int instack_priority_prefix(char c)
{

	switch (c)
	{
	case ')':
		return 0;
	case '^':
		return 4;
	case '*':
	case '/':
	case '%':
		return 2;
	case '+':
	case '-':
		return 1;
	}
}
int incoming_priority_prefix(char c)
{

	switch (c)
	{
	case '^':
		return 3;
	case '*':
	case '/':
	case '%':
		return 2;
	case '+':
	case '-':
		return 1;
	}
}

int postfixfun(char s[100])
{

	int p = 0;
	int i = 0;
	int l = strlen(s);

	char c, h;
	for (i = 0; i < l; i++)
	{

		c = s[i];
		switch (c)
		{
		case '(':
			push(c);
			break;
			// postfix[p++]=c;

		case ')':
			while ((h = pop()) != '(')
				postfix[p++] = h;
			break;
		case '^':
		case '+':
		case '*':
		case '-':
		case '/':
		case '%':
			while (instack_priority_postfix(stack_arr[top]) >= incoming_priority_postfix(c) && top != -1)
			{
				h = pop();
				postfix[p++] = h;
			}
			push(c);
			break;
		default:
			postfix[p++] = c;
		}
	}
	while (top != -1)
	{
		h = pop();
		postfix[p++] = h;
	}

	printf("%s", postfix);
}
int prefixfun(char s[100])
{
	int l = strlen(s);
	int i = l - 1;
	int p = 0;
	char c, h;
	while (i >= 0)
	{
		c = s[i];
		switch (c)
		{
		case ')':
			push(c);
			break;
		case '(':
			while ((h = pop()) != ')')
			{
				prefix[p++] = h;
			}
			break;
		case '^':
		case '+':
		case '*':
		case '-':
		case '/':
		case '%':
			while (instack_priority_prefix(stack_arr[top]) > incoming_priority_prefix(c) && top != -1)
			{
				h = pop();
				prefix[p++] = h;
			}
			push(c);
			break;
		default:
			prefix[p++] = c;
		}
		i--;
	}
	while (top != -1)
	{
		h = pop();
		prefix[p++] = h;
	}
	l = strlen(s);
	for (i = l - 1; i >= 0; i--)
		printf("%c", prefix[i]);
}

int postfixans(char s[100])
{
	int i;
	for (i = 0; i < strlen(s); i++)
	{
		if (isdigit(s[i]))
			push1(s[i] - '0');
		else if (s[i] == ' ')
			continue;
		else
		{
			int a = pop1();
			int b = pop1();
			if (s[i] == '+')
				push1(b + a);
			else if (s[i] == '-')
				push1(b - a);
			else if (s[i] == '*')
				push1(b * a);
			else if (s[i] == '/')
				push1(b / a);
			else if (s[i] == '^')
				push1(pow(b, a));
			else if (s[i] == '%')
				push1(b % a);
		}
	}
	return pop1();
}
int prefixans(char s[100])
{
	int i = strlen(s) - 1;
	for (; i >= 0; i--)
	{
		if (isdigit(s[i]))
			push1(s[i] - '0');
		else if(s[i]==' ')
		continue;
		else
		{
			int b = pop1();
			int a = pop1();
			if (s[i] == '+')
				push1(b + a);
			else if (s[i] == '-')
				push1(b - a);
			else if (s[i] == '*')
				push1(b * a);
			else if (s[i] == '/')
				push1(b / a);
			else if (s[i] == '^')
				push1(pow(b, a));
			else if (s[i] == '%')
				push1(b % a);
		}
	}
	return pop1();
}

int main()
{
	int n;
	while (1)
	{
		printf("\n1.Convert to postfix\n2.Convert to prefix\n3.Evaluation of postfix\n4.Evaluation of prefix\n5.Exit\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			printf("Enter infix expression\n");
			gets(infix);
			gets(infix);
			printf("Postfix Expression\n");
			postfixfun(infix);
			break;
		case 2:
			printf("Enter infix expression\n");
			gets(infix);
			gets(infix);
			printf("Prefix Expression\n");
			prefixfun(infix);
			break;
		case 3:
			top1 = -1;
			printf("Enter the postfix expression\n");
			gets(postfix);
			gets(postfix);
			printf("Answer=%d", postfixans(postfix));
			break;
		case 4:
			top1 = -1;
			printf("Enter the prefix expression\n");
			gets(postfix);
			gets(postfix);
			printf("Answer=%d", prefixans(postfix));
			break;
		case 5:
			exit(1);
		default:
		 printf("Wrong choice\n");	
		}
	}
}
