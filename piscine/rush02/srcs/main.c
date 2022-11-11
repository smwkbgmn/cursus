#include "rush.h"

int main(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return (0);

	if (ac == 2)
	    print(get_dict("numbers.dict"), av[1]);
	else
	    print(get_dict(av[1]), av[2]);

    return (0);
}