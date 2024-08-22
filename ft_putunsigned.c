/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:58:05 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/22 17:56:28 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Útil para convertir e imprimir números enteros largos sin signo en formato 
decimal. Utiliza recursividad para manejar cada dígito de la representación 
decimal, proporcionando una solución flexible y extensible para mostrar valores
enteros sin signo. */

int	ft_putunsigned(unsigned int num)
{
	int	chars_number;

	chars_number = 0;
	if (num > 9)
	{
		chars_number += ft_putunsigned(num / 10);
		ft_putunsigned(num % 10);
	}
	else
		chars_number += ft_putchar(num + '0');
	return (chars_number);
}

/* int	main(void)
{	
	unsigned int arg_num = 214748364;
	int num = ft_putunsigned(arg_num);
	
	printf("\n argumentos -> unsigned int '%d' \n", arg_num);
	printf("num caracteres impresos: %d \n",num);
	return (0);
} */