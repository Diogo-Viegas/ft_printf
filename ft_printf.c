/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dviegas <dviegas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:02:20 by dviegas           #+#    #+#             */
/*   Updated: 2025/04/30 16:26:21 by dviegas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		print_len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_len += ft_printpercent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;
	int		i;

	print_len = 0;
	if (!str || *str == '\0')
		return (0);
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

// int	main(void)
// {
// 	int				n;
// 	unsigned int	unum;
// 	void			*ptr;
// 	char			c;
// 	char			*str;

// 	n = 42;
// 	unum = 323423423;
// 	ptr = &n;
// 	c = '@';
// 	str = "Diogo";
// 	ft_printf("================TESTES================\n");
// 	ft_printf("POINTERS\n");
// 	ft_printf("Hello World %p \n", ptr);
// 	printf("Hello World %p \n", ptr);
// 	ft_printf("NUMBERS\n");
// 	ft_printf("Hello World %d \n", n);
// 	printf("Hello World %d \n", n);
// 	ft_printf("CHARS\n");
// 	ft_printf("Hello World %c \n", c);
// 	printf("Hello World %c \n", c);
// 	ft_printf("STRINGS\n");
// 	ft_printf("Hello World %s \n", str);
// 	printf("Hello World %s \n", str);
// 	ft_printf("UNSIGNED\n");
// 	ft_printf("Hello World %u \n", unum);
// 	printf("Hello World %u \n", unum);
// 	ft_printf("HEXADECIMAL\n");
// 	ft_printf("Hello World %x            Hello World %X\n", unum, unum);
// 	printf("Hello World %x            Hello World %X \n", unum, unum);
// 	ft_printf("PERCENT\n");
// 	ft_printf("Hello World %% \n");
// 	printf("Hello World %% \n");
// }
