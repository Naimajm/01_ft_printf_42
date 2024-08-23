/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:19:52 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/23 13:40:05 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

/* Toma un puntero a una cadena 's' terminada en nulo como entrada. Si 's' es 
NULL, escribe la cadena “(nulo)” en la salida estándar (descriptor de archivo 1)
y devuelve 6 (el número de caracteres escritos). De lo contrario, escribe el 
contenido de 's' en la salida estándar usando la función "escribir" y devuelve
el número de caracteres escritos, calculado por "ft_strlen(s)". Esta función 
se utiliza para imprimir cadenas en la consola. */

int	ft_putstr(char *str)
{
	int	index;
	int	chars_number;

	index = 0;
	chars_number = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[index] != '\0')
	{
		chars_number += ft_putchar(str[index]);
		index++;
	}
	return (chars_number);
}

/* int	main(int argn, char **argv)
{
	int num = ft_putstr(argv[1]);
	if (argn > 1)
		printf("\n num caracteres impresos: %d \n",num);
	return (0);
} */
