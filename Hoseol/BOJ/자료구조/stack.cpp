#include <stdio.h>
#include <string.h>
#include <algorithm>


using namespace std;

int s[10101];
int top;
char buf[111];
int dat;
int t;

int main()
{
	int i, j, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", buf);
		if (strcmp(buf, "push") == 0)
		{
			scanf("%d", &dat);
			s[top] = dat;
			top++;
		}
		if (strcmp(buf, "pop") == 0)
		{
			if (top == 0)
			{
				printf("-1\n");
			}
			else {
				printf("%d\n", s[top - 1]);
				top--;
			}
		}
		if (strcmp(buf, "size") == 0)
		{
			printf("%d\n", top);
		}
		if (strcmp(buf, "empty") == 0)
		{
			if (top == 0)
			{
				printf("1\n");
			}
			else printf("0\n");
		}
		if (strcmp(buf, "top") == 0)
		{
			if (top == 0)
			{
				printf("-1\n");
			}
			else printf("%d\n", s[top - 1]);
		}
	}
	return 0;
}