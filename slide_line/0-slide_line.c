#include "slide_line.h"

int slide_line(int* line, size_t size, int direction)
{
	switch (direction)
	{
	case SLIDE_LEFT:
		slide_left(line, size);
		return 1;
	case SLIDE_RIGHT:
		slide_right(line, size);
		return 1;
	default:
		return 0;
	}
}
void slide_right(int* line, size_t size)
{
	int mx = size;
	int i, j;
	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			for (j = i; j < (int)size - 1; j++)
			{
				i = j;
				if (line[j + 1] != 0)
					break;

				line[j + 1] = line[j];
				line[j] = 0;
			}
			if (line[i] == line[i + 1] && i + 1 < mx)
			{
				line[i] = 0;
				line[i + 1] *= 2;
				mx = i + 1;
			}
		}
	}
}
void slide_left(int* line, size_t size)
{
	int mn = -1;
	int i, j;
	for (i = 1; i < (int)size; i++)
	{
		if (line[i] != 0)
		{
			for (j = i; j >= 0; j--)
			{
				i = j;
				if (line[j - 1] != 0)
					break;

				line[j - 1] = line[j];
				line[j] = 0;
			}
			if (line[i] == line[i - 1] && i - 1 > mn)
			{
				line[i] = 0;
				line[i - 1] *= 2;
				mn = i - 1;
			}
		}
	}
}