/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: mucelep <celepm82@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:01:03 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/10 21:01:03 by mucelep          ###   ########.fr       */
=======
/*   By: mucelep <mucelep@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:58:33 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/14 03:26:49 by mucelep          ###   ########.fr       */
>>>>>>> cbdd5f8 (hersey tamam)
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

<<<<<<< HEAD
static int ft_format(char format, va_list vargs)
=======
static int	ft_format(char format, va_list vargs)
>>>>>>> cbdd5f8 (hersey tamam)
{
	if (format == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	if (format == 's')
<<<<<<< HEAD
		return(ft_putstr(va_arg(vargs, char*)));
	if (format == 'p')
		return(ft_address(va_arg(vargs, void *)));
	if (format == 'd' || format == 'i')
		return(ft_putnbr(va_arg(vargs, int)));
	if (format == 'u')
		return(ft_unputnbr(va_arg(vargs, unsigned int)));
	if (format == 'x')
		return(ft_hexa(va_arg(vargs, unsigned int),"0123456789abcdef"));
	if (format == 'X')
		return(ft_hexa(va_arg(vargs, unsigned int),"0123456789ABCDEF"));
	if (format == '%')
		return(ft_putchar('%'));
	return(-1);
}

int ft_printf(const char *format, ...)
{
	va_list vargs;
	int count;
	int check;

	count = 0;
	va_start(vargs,format);
	while (*format)
	{
		if(*format == '%' && *(format + 1) != '\0')
		{
			check = ft_format(*(++format),vargs);
			if (check == -1)
				return (-1);
			count += check;
		}
		else
			count += ft_putchar(*format);
=======
		return (ft_putstr(va_arg(vargs, char *)));
	if (format == 'p')
		return (ft_address(va_arg(vargs, void *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(vargs, int)));
	if (format == 'u')
		return (ft_unputnbr(va_arg(vargs, unsigned int)));
	if (format == 'x')
		return (ft_hexa(va_arg(vargs, unsigned int), "0123456789abcdef"));
	if (format == 'X')
		return (ft_hexa(va_arg(vargs, unsigned int), "0123456789ABCDEF"));
	if (format == '%')
		return (ft_putchar('%'));
	return (-2);
}

int	ft_printf(const char *format, ...)
{
	va_list	vargs;
	int		count;
	int		controller;

	count = 0;
	va_start(vargs, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			controller = ft_format(*(++format), vargs);
			if (controller == -2)
				controller = ft_putchar(*(--format));
		}
		else
			controller = ft_putchar(*format);
		if (controller == -1)
			return (-1);
		count += controller;
>>>>>>> cbdd5f8 (hersey tamam)
		format++;
	}
	va_end(vargs);
	return (count);
}
<<<<<<< HEAD
#include <stdio.h>
int main ()
{
	ft_printf("%%\n");
	printf("%%");
}
=======
>>>>>>> cbdd5f8 (hersey tamam)
