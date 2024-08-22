/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:18:36 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/22 18:05:59 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Útil para mostrar direcciones de memoria en un formato hexadecimal estándar
y legible con el prefijo “0x”. Proporciona una interfaz fácil de usar para 
imprimir direcciones de memoria en la salida estándar y se puede utilizar en 
diversos contextos, como la depuración o la visualización de información 
sobre la memoria asignada. */

int	ft_putaddress(size_t ptr_address)
{
	size_t	chars_number;

	chars_number = 0;
	if (ptr_address == 0)
		return (ft_putstr("(nil)"));
	chars_number += ft_putstr("0x");
	chars_number += ft_puthexa(ptr_address, 'x');
	return (chars_number);
}

/* int main(void)
{   
    size_t ptr_address = 452397;
    char *str = NULL;

    int num_ptraddress = ft_putaddress(ptr_address);

    printf("\n argumentos -> void * '%p' \n", str);
    printf("num caracteres impresos: %d \n", num_ptraddress);
    return (0);
} */