#include <unistd.h>

void first_and_end_print(int inputX) { // it drows first and last col 
	int x = 1;
	while (x <= inputX) {
		if (x == 1 || x == inputX)
			write(1, "o", 1);
		else
			write(1, "-", 1);
		x++;
	}
	write(1, "\n", 1);
}

void middle_print(int inputX) {
	int x = 1;
	while (x <= inputX) {
		if (x == 1 || x == inputX)
			write(1, "|", 1);
		else
			write(1, " ", 1);
		x++;
	}
	write(1, "\n", 1);
}

void rush(int inputX, int inputY)
{
	int x = 1;
	int y = 1;
	
	while (y <= inputY) {
		if (y == 1 || y == inputY)
			first_and_end_print(inputX);
		else
			middle_print(inputX);
		y++;
	}
}

int main () {
	rush(5,3);
	return 0;
}

