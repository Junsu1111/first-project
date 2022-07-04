#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#define SIZE 6
#define TIME_LIMIT 5
void show_string(char[]);
int main(void)
{
	char input[SIZE];
	char ch;
	char word[SIZE];
	int s_time=time(0);
	int j=0;
	srand((unsigned int)time(NULL));
	while (1)
	{
		if (time(0) >= s_time + TIME_LIMIT)
		{
			system("cls");
			show_string(word);
			s_time = time(0);
			j = 0;
		}
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 27)
				break;
			printf("%c", ch);
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				input[j] = ch;
				j++;
			}
		}
		if (j >= SIZE - 1)
		{
			input[SIZE - 1] = 0;
			if (!strcmp(word, input))
			{
				printf("\n축하합니다.\n");
				Sleep(1000);
			}
			system("cls");
			show_string(word);
			s_time = time(0);
		}
	}


	return 0;
}

void show_string(char w[])
{
	int i;
	for (i = 0; i < SIZE - 1; i++)
	{
		w[i] = 'a' + rand() % ('z' - 'a' + 1);
		printf("%c", w[i]);
	}
	w[i] = '\0';
}