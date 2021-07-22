#include<stdio.h>
void string_longestCommonPrefix(char **arr)
{
	int n = 0;
	int i = 0;
	while (*(*(arr + 0) + i) == *(*(arr + 1) + i)
		&& *(*(arr + 1) + i) == *(*(arr + 2) + i)
		&& *(*(arr + 2) + i) == *(*(arr + 3) + i)
		&& *(*(arr + 3) + i) == *(*(arr + 4) + i))
		i++;
	for (n = 0; n < i; n++)
	{
		printf("%c", arr[0][n]);
	}
}
int main()
{
	char* arr[5] = { "abca","abc","abca","abc","abcc" };
	string_longestCommonPrefix(arr);
	return 0;
}