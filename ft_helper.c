/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucelep <celepm82@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 23:53:44 by mucelep           #+#    #+#             */
/*   Updated: 2026/02/10 23:53:44 by mucelep          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
	return(write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int	i;

	i = 0;
	if(!s)
	{
		if(write(1, "(null)",6) == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (ft_putchar(s[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int ft_putnbr(long n)
{
	int	len;
	int check;

	len = 0;
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len += 1;
		n *= -1;
	}
	if (n >= 10)
	{
		check = ft_putnbr(n / 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	check = ft_putchar((n % 10) + '0');
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}

int ft_unputnbr(unsigned int nb)
{
	int	len;
	int check;

	len = 0;
	if (nb >= 10)
	{
		check = ft_unputnbr(nb / 10);
		if (check == -1)
			return (-1);
		len += check;
	}
	check = ft_putchar((nb % 10) + '0');
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}

int ft_hexa(unsigned long nb, char *base)
{
	int	len;
	int check;

	len = 0;
	if (nb >= 16)
	{
		check = ft_hexa(nb / 16, base);
		if (check == -1)
			return (-1);
		len += check;
	}
	check = ft_putchar((base[nb % 16]));
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}

int ft_address(void *p)
{
	int	len;
	int check;

	len = 0;
	if (!p)
	{
		check = ft_putstr("(nil)");
		if (check == -1)
			return (-1);
		len += check;
		return (len);
	}
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	check = ft_hexa((unsigned long)p, "0123456789abcdef");
	if (check == -1)
		return (-1);
	len += check;
	return (len);
}
