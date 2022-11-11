/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongble <jeongble@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:15:53 by jeongble          #+#    #+#             */
/*   Updated: 2022/06/08 18:53:54 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex00/ft.h"
#include "ex01/ft_boolean.h"
#include "ex02/ft_abs.h"
#include "ex03/ft_point.h"
#include "ex04/ft_strs_to_tab.c"
#include "ex05/ft_show_tab.c"
#include <stdio.h>

int	main(void)
{
	{
		printf("\n===============EX01===============\n\n");
		printf("TRUE is %d\n", TRUE);
		printf("FALSE is %d\n\n", FALSE);
		printf("DO YOU HAVE EVEN NUMBER?\n%s\n\n", EVEN_MSG);
		printf("DO YOU HAVE ODD NUMBER?\n%s\n\n", ODD_MSG);
		printf("SUCCESS : %d\n\n", SUCCESS);
		printf("42 IS ");
		if (EVEN(42))
			printf("EVEN NUMBER\n");
		else
			printf("ODD NUMBER\n");
	}
	{
		printf("\n===============EX02===============\n\n");
		printf("ABSOLUTE VALUE OF  42 IS %d\n", ABS(42));
		printf("ABSOLUTE VALUE OF -42 IS %d\n", ABS(-42));
		printf("ABSOLUTE VALUE OF   0 IS %d\n", ABS(0));
	}
	{
		printf("\n===============EX03===============\n\n");
		t_point	point;
		point.x = 42;
		point.y = 21;
		printf("POINT X IS 42 : %d\n", point.x);
		printf("POINT Y IS 21 : %d\n", point.y);
	}
/*	{
		printf("\n============EX04, EX05============\n\n");
		t_stock_str	*strts;
		char	*av[3];

		*(av + 0) = "JEONGBLE";	
		*(av + 1) = "IS";
		*(av + 2) = "BABO";
		strts = ft_strs_to_tab(3, av);
		printf("--------- output ---------\n");
		printf("JEONGBLE\n8\nJEONGBLE\nIS\n2\nIS\nBABO\n4\nBABO\n");
		printf("------ user  output ------\n");
		ft_show_tab(strts);
		printf("\n===============FIN===============\n\n");
	}*/
	return (0);
}	
