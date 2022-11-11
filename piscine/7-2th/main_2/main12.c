/* ************************************************************************** */
/*                                                                            */
/*                                                       ::     :::::::   */
/*   main.c                                            +:     +:   +:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghki2 <donghki2@student.42seoul:        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:27:15 by donghki2          #+#    #+#             */
/*   Updated: 2022/06/06 16:30:11 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "./ex12/ft_print_memory.c"

int main(void)
{
	char testStr11[200] = "aaaaaaaaaaaabbbbbbbbbbbbbbbccccccccccccccddddddddddddddeeeeeeeeeeeeeee";
	char testStr12[200] = "Hi Hellow?";
	char testStr13[200] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";

	ft_print_memory (testStr12, 200);
	printf ("\n\n");

	ft_print_memory (testStr13, 200);
	printf ("\n\n");

	ft_print_memory (testStr13, 50);
	printf ("\n\n");

	ft_print_memory (testStr11, 200);
	return 0;
}
