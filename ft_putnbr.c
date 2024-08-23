/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:41:47 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/23 20:31:44 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Diseñada para escribir un número entero en la salida estándar (stdout) usando
la función ft_putnbr_fd. Además, devuelve la longitud (número de dígitos) del
número entero impreso. La función auxiliar estática ft_nbrlen se utiliza 
internamente para calcular la longitud del número entero. */

int	ft_putnbr(int num)
{
	int	chars_number;

	chars_number = 0;
	if (num == -2147483648)
		chars_number += ft_putstr("-2147483648");
	else if (num < 0)
	{
		chars_number += ft_putchar('-');
		num = num * -1;
		chars_number += ft_putnbr(num);
	}
	else if (num > 9)
	{
		chars_number += ft_putnbr(num / 10);
		chars_number += ft_putnbr(num % 10);
	}
	else
		chars_number += ft_putchar(num + '0');
	return (chars_number);
}

/* int	main(void)
{	
	int arg_num = -2147483648;
	int num = ft_putnbr(arg_num);

	printf("\n argumentos -> int '%d' \n", arg_num);
	printf("num caracteres impresos: %d \n",ft_number_len(arg_num));
	
	printf("\n argumentos -> int '%d' \n", arg_num);
	printf("num caracteres impresos: %d \n",num);
	return (0);
} */
