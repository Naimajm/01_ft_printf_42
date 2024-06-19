/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:58:05 by juagomez          #+#    #+#             */
/*   Updated: 2024/06/19 21:06:55 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Útil para convertir e imprimir números enteros largos sin signo en formato 
decimal. Utiliza recursividad para manejar cada dígito de la representación 
decimal, proporcionando una solución flexible y extensible para mostrar valores
enteros sin signo. */

static int	ft_unsigned_number_len(unsigned int num);

int	ft_putunsigned(unsigned int num)
{
	int	count;

	count = ft_unsigned_number_len(num);
	if (num > 9)
	{
		ft_putunsigned(num / 10);
		ft_putunsigned(num % 10);
	}
	else
		ft_putchar(num + '0');
	return (count);
}

/** 
* @brief Devuelve numero de digitos de un número.
* @param num: Número entero a determinar.
* @returns int -> número total de digitos.
*/
static int	ft_unsigned_number_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return (len + 1);
}

/* int	main(void)
{	
	unsigned int arg_num = 214748364;
	int num = ft_putunsigned(arg_num);
	
	printf("\n argumentos -> unsigned int '%d' \n", arg_num);
	printf("num caracteres impresos: %d \n",num);
	return (0);
} */