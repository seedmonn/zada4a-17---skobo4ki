#include <iostream>
//#include <stdbool.h>
#define N 100
using namespace std;
int cmp(char* i_ptr, int size)
{
	char c = ' ';
	bool disbalance = 0;
	int razmer_krug = 0; // ()
	int razmer_kvadrat = 0; // []
	int razmer_figur = 0;  // {}
	do {
		switch (*i_ptr)
		{
		case '(':
			c = *i_ptr++;
			razmer_krug++;
			break;
		case '[':
			c = *i_ptr++;
			razmer_kvadrat++;
			break;
		case '{':
			c = *i_ptr++;
			razmer_figur++;
			break;
		case ')':
			if ((c == ')' || c == ']' || c == '}' || c == '(') && (razmer_krug > 0))
			{
				razmer_krug--;
			}
			else
			{
				disbalance++;
			}
			c = *i_ptr++;
			break;
		case ']':
			if ((c == ')' || c == ']' || c == '}' || c == '[') && (razmer_kvadrat > 0))
			{
				razmer_kvadrat--;
			}
			else
			{
				disbalance++;
			}
			c = *i_ptr++;
			break;
		case '}':
			if ((c == ')' || c == ']' || c == '}' || c == '{') && (razmer_figur > 0)) 
			{
				razmer_figur--;
			}
			else 
			{
				disbalance++;
			}
			c = *i_ptr++;
			break;
		default:
			i_ptr++;
			break;
		}

	} while ((*i_ptr) && (disbalance == 0));

	size = (disbalance != 0) ? 1 : razmer_krug + razmer_kvadrat + razmer_figur;

	return size;
}

int main()
{
	int size = 0;
	char arr[N];
	char* i_ptr = arr;
	cout << "Enter a line: ";
	cin >> arr;
	size = cmp(i_ptr, size);
	cout << (size > 0 ? "Disbalance\n" : "Balance\n");
	system("pause");
	return 0;
}
