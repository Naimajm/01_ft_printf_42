/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:28 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/22 18:12:02 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* diseñada para convertir e imprimir un 'entero largo sin signo' como un número
hexadecimal en la salida estándar (stdout). Admite formato tanto en minúsculas
como en mayúsculas según el carácter de formato proporcionado. */

int	ft_puthexa(unsigned long num, char specifier_format)
{
	unsigned long	chars_number;
	char			*base_hexa;

	chars_number = 0;
	if (num == 0)
		return (ft_putstr("(nil)"));
	if (specifier_format == 'X')
		base_hexa = "0123456789ABCDEF";
	else
		base_hexa = "0123456789abcdef";
	if (num >= 16)
		chars_number += ft_puthexa(num / 16, specifier_format);
	chars_number += ft_putchar(base_hexa[num % 16]);
	return (chars_number);
}

/* int	main(void)
{
	unsigned int arg_num0 = 0;

	unsigned int num_hexa_X = ft_puthexa(arg_num0, 'X');
	printf("\n argumentos -> unsigned int '%X' \n", arg_num0);
	printf("num caracteres impresos: %d \n",num_hexa_X);
	
	unsigned int num_hexa_x = ft_puthexa(arg_num0, 'x');
	printf("\n argumentos -> unsigned int '%x' \n", arg_num0);
	printf("num caracteres impresos: %d \n",num_hexa_x);

	unsigned int arg_num = 2547;
	
	num_hexa_X = ft_puthexa(arg_num, 'X');
	printf("\n argumentos -> unsigned int '%X' \n", arg_num);
	printf("num caracteres impresos: %d \n",num_hexa_X);
	
	num_hexa_x = ft_puthexa(arg_num, 'x');
	printf("\n argumentos -> unsigned int '%x' \n", arg_num);
	printf("num caracteres impresos: %d \n",num_hexa_x);
	
	return (0);
} */