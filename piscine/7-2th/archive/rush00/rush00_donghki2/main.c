#include <unistd.h>
#include <stdio.h>

void rush(int x, int y);

int main(void)
{
	rush(10, 7);
}

void rush(int x, int y)
{
	int xidx, yidx, sidx;

	xidx = x;
	yidx = y;
	sidx = xidx;

	while( y >= 1 )
	{
		while ( y == yidx | y == 1 ) // it drows first and last col  
		{
			write(1, &"o", 1); // drow first 'o'
			x--;

			while( x > 1 ) // drow '-' to rest of the lines 
			{
				write(1, &"-", 1);
				x--;
			}

			if( xidx != 1 )
			{
				write(1, &"o", 1); // drow last 'o'
			}
			write(1, &"\n", 1);

			x--;
			y--; // it says it just draw first & last line  
		}

		while( y > 1 ) // it drows rest of the lines 
		{
			write(1, &"|", 1);

			if( xidx != 1 )
			{
				while( sidx-1 > 1 )
				{
					write(1, &" ", 1);
					sidx--;
				}
				write(1, &"|", 1);
			}

			write(1, &"\n", 1);
			
			sidx = xidx; // it keeps the number of space 
			y--;
		}
		x = xidx; // for drowing the last col, give x's default value that is equal to begining of first line 
	}
}
