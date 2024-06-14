/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:51:02 by juagomez          #+#    #+#             */
/*   Updated: 2024/06/11 22:15:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Diseñada para escribir un número entero en la salida estándar (stdout) usando
la función ft_putnbr_fd. Además, devuelve la longitud (número de dígitos) del
número entero impreso. La función auxiliar estática ft_nbrlen se utiliza 
internamente para calcular la longitud del número entero. */

int	ft_putnbr(int num)
{
	int	count;
	
	count = 0;
	if (num == -2147483648)
	{
		ft_putstr("-2147483648");
		count = 11;
	}		
	else if (num < 0)
	{
		ft_putchar('-');
		num = num * -1;
		ft_putnbr(num);
		count++;
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
		count++; 
	}
	return (count);		
}
