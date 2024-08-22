/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:18:36 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/22 13:35:37 by juagomez         ###   ########.fr       */
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
	size_t	char_number;

	char_number = 0;
	char_number += write (1, "0x", 2);
	char_number += ft_puthexa(ptr_address, 'x');
	return (char_number);
}

/* int	ft_putaddress( ptr_address)
{
    char    string[25];
    int index;
    char    *base_hexa;
    int char_number;

    base_hexa = "0123456789abcdef";
    index = 0;
    ft_putchar('0');
    ft_putchar('x');
    if (ptr_address == 0)
    {
        ft_putchar('0');
        return (1);
    }
    while (ptr_address != 0)
    {
        string[index] = base_hexa[ptr_address % 16];
        ptr_address = ptr_address / 16;
        index++;
    }
    char_number = index + 2;
    while (index >= 0)
    {
        ft_putchar(string[index]);
        index--;
    }
    return (char_number);  
} */

/* static  int ft_length_adress(char *ptr_address)
{
    int count;

    while(ptr_address[count] != '0')
        count++;

    count = count + 2;
    return (count);
} */

/* int main(void)
{   
    size_t ptr_address = 452397;
    char *str = NULL;

    int num_ptraddress = ft_putaddress(ptr_address);

    printf("\n argumentos -> void * '%p' \n", str);
    printf("num caracteres impresos: %d \n", num_ptraddress);
    return (0);
} */