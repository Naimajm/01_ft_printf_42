/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:07:22 by juagomez          #+#    #+#             */
/*   Updated: 2024/06/11 21:46:02 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Toma un carácter 'c' como entrada y lo escribe en la salida estándar 
(descriptor de archivo 1). Luego devuelve el valor 1 para indicar éxito, 
normalmente utilizado para la impresión de caracteres en programas. */

int ft_putchar(char character)
{
	write(1, &character, 1);
    return (1);
}
