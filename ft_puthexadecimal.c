/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:28:28 by juagomez          #+#    #+#             */
/*   Updated: 2024/06/19 19:29:21 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* diseñada para convertir e imprimir un 'entero largo sin signo' como un número
hexadecimal en la salida estándar (stdout). Admite formato tanto en minúsculas
como en mayúsculas según el carácter de formato proporcionado. */

int	ft_puthexadecimal(unsigned int num, char specifier_format)
{
	//unsigned int	int_num;
	int				count;
	char			*base_hexa;

	//int_num = (unsigned int) num;
	count = 0;
	if (specifier_format == 'X')
		base_hexa = "0123456789ABCDEF";
	else
		base_hexa = "0123456789abcdef";		
	if (num > (16 - 1))
		count = count + ft_puthexadecimal(num / 16, specifier_format);
	count = count + ft_putchar(base_hexa[num % 16]);
	return (count);
}

/* int	main(void)
{	
	unsigned int arg_num = 2547;

	int num_hexa_X = ft_puthexadecimal(arg_num, 'X');
	printf("\n argumentos -> unsigned int '%X' \n", arg_num);
	printf("num caracteres impresos: %d \n",num_hexa_X);
	
	int num_hexa_x = ft_puthexadecimal(arg_num, 'x');
	printf("\n argumentos -> unsigned int '%x' \n", arg_num);
	printf("num caracteres impresos: %d \n",num_hexa_x);
	
	return (0);
} */
