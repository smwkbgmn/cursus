#include "rush.h"

void free_dict(char **dict, int idx)
{
	if (idx == -1)
	{
		while (dict[++idx])
			free(dict[idx]);
	}
	else
	{
		while (idx >= 0)
			free(dict[idx--]);
	}
	free(dict);
}