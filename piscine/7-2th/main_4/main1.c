/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjoung <wjoung@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:52:31 by wjoung            #+#    #+#             */
/*   Updated: 2022/06/08 19:57:42 by donghki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "ex00/ft_strlen.c"
#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
//#include "ex05/ft_atoi_base.c"

int main(void)
{
    {
        printf("====ex00====\n");
        char str[6] = "HELLO", str2[1] = "";
        printf("mine: %d\toriginal: %lu\n", ft_strlen(str), strlen(str));
        printf("size 0 ->\n");
        printf("mine: %d\toriginal: %lu\n", ft_strlen(str2), strlen(str2));
    }
    {
        printf("====ex01====\n");
        char str[6] = "HELLO", str2[1] = "";
        ft_putstr(str);
        printf("\nsize 0 ->");
        ft_putstr(str2);
        printf("\n");
    }
    {
        printf("====ex02====\n");
        int t1 = 2147483647, t2 = -2147483648, t3 = -1050505, t4 = 0;
        ft_putnbr(t1);
        write(1, "\n", 1);
        ft_putnbr(t2);
        write(1, "\n", 1);
        ft_putnbr(t3);
		write(1, "\n", 1);
		ft_putnbr(t4);
		write(1, "\n", 1);
    }
    {
        printf("\n====ex03====\n");
        char t1[] = "\t2147483647", t2[] = "\r-2147483648", t3[] = "   00", t4[] = "", t5[] = "\v2147483648", t6[] = "-\n\r2147483649", t7[] = "\f1839021837901472947", t8[] = "--+++-123abc123", t9[] = "  ++--+-+-1451+a";
        printf("%d vs %d\n", ft_atoi(t1), atoi(t1));
        printf("%d vs %d\n", ft_atoi(t2), atoi(t2));
        printf("%d vs %d\n", ft_atoi(t3), atoi(t3));
        printf("%d vs %d\n", ft_atoi(t4), atoi(t4));
        printf("%d vs %d\n", ft_atoi(t5), atoi(t5));
        printf("%d vs %d\n", ft_atoi(t6), atoi(t6));
        printf("%d vs %d\n", ft_atoi(t7), atoi(t7));
        printf("%d vs %d\n", ft_atoi(t8), -123);
        printf("%d vs %d\n", ft_atoi(t9), 1451);
    }
    {
        printf("====ex04====\n");
        printf("answer1: \\\'\?\"\\\"\'\\\n");
        printf("answer2: rcrdmddd\n");
        printf("answer3: 1111111111111111111111111111111 (=1 * 31)\n");
        printf("answer4: -10000000000000000000000000000000 (=1 and 31 zeros)\n");
        printf("answer5 ~ 8: no output");
        char    base_sym[6] = {'\'', '\\', '"', '?', '!'};
        ft_putnbr_base(88926, base_sym);
        write(1, "\n", 1);
        ft_putnbr_base(145062, "mrdoc");
        write(1, "\n", 1);
        ft_putnbr_base(2147483647, "01");
        write(1, "\n", 1);
        ft_putnbr_base(-2147483648, "01");
        write(1, "\n", 1);
        ft_putnbr_base(0, "0123456789");
        write(1, "\n", 1);
        ft_putnbr_base(123, "0023456789");  //no output
        write(1, "\n", 1);
        ft_putnbr_base(123, "0123456789+"); //no output
        write(1, "\n", 1);
        ft_putnbr_base(123, "1");   //no output
        write(1, "\n", 1);
        ft_putnbr_base(123, "");    //no output
        write(1, "\n", 1);
    }
 /*   {
        printf("\n====ex05====\n");
        char    base_sym[6] = {'\'', '\\', '"', '?', '!'};
        printf("%d vs %d\n", 88926, ft_atoi_base("\n\\\'\?\"\\\"\'\\", base_sym));
        printf("%d vs %d\n", 145062, ft_atoi_base("\rrcrdmddd", "mrdoc"));
        printf("%d vs %d\n", 2147483647, ft_atoi_base("\v1111111111111111111111111111111", "01"));
        printf("%ld vs %d\n", -2147483648, ft_atoi_base("\f-10000000000000000000000000000000", "01"));
        printf("%d vs %d\n", 123, ft_atoi_base("      --+-+-123abc", "0123456789"));
        printf("%d vs %d\n", 0, ft_atoi_base("      --+-aa+-123abc", "0123456789"));
        printf("%d vs %d\n", 911058099, ft_atoi_base("1839021837901472947", "0123456789"));
    }*/
}
