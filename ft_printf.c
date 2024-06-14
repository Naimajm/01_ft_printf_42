/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:51:11 by juagomez          #+#    #+#             */
/*   Updated: 2024/06/11 22:13:36 by juagomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include "ft_printf.h"

// https://42-cursus.gitbook.io/guide/rank-01/ft_printf/variadic-functions
// https://42.nauman.cc/2023/08/16/ft-printf-ft-printf/

/* implementación personalizada de la función printf en C, que proporciona 
un subconjunto simplificado de opciones de formato para cadenas de caracteres. 
Toma una cadena de formato como entrada y, cuando encuentra un carácter % de 
marcador de posición seguido de un especificador de conversión, procesa e 
imprime los valores correspondientes. */

//PROCESO
/* Procesa el especificador de formato y los argumentos correspondientes e 
imprime la salida formateada en la salida estándar utilizando el descriptor de 
archivo especificado. Devuelve el número total de caracteres escritos en la 
salida estándar. */
/* Para cada especificador de conversión válido, la función llama a la función
auxiliar estática ft_format para manejar la lógica de formato e impresión 
específica.  */
/* Los especificadores de conversión no admitidos o no válidos provocan que
se devuelva un error (-1). */

static void	ft_format(char specifier_format, va_list args_list);

int	ft_printf(const char *format, ...)
{
	va_list	args_list;
	unsigned int	chr_numbers;
	unsigned int	index;
	char	specifier_format;

	index = 0;
	chr_numbers = 0;
	va_start(args_list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			specifier_format = format[index];
			ft_format(specifier_format, args_list);
		}
		else
		{
			ft_putchar(format[index]);
			chr_numbers += 1;
		}
		index++;
	}
	va_end(args_list);
	return (chr_numbers);
}

/** 
* @brief Maneja la lógica de formato e impresión específica. Responsable de 
formatear e imprimir valores según el especificador de conversión. 
Utiliza la macro 'va_arg' para recuperar el argumento correspondiente de la
lista de argumentos variables. devuelve numero caracteres impresos.
* @param especifier_format: Especificador de conversión de formato.
* @param args_list: Lista de argumentos variables (va_list).
* @returns void -> 
*/
static void	ft_format(char specifier_format, va_list args_list)
{
	//int chr_numbers;

	if (specifier_format == 'c')
	{
		ft_putchar(va_arg(args_list, int));
	}
	else if (specifier_format == 's')
	{
		ft_putstr(va_arg(args_list, char *));
	}
	else if (specifier_format == 'd' || specifier_format == 'i')
	{
		ft_putnbr(va_arg(args_list, int));
	}
	else if (specifier_format == '%')
		ft_putchar('%');
	//else
		//return (-1);
		
	//return (chr_numbers);
}

int	main(void)
{
	//TESTEO FUNCION PROTOTIPO PRINTF
	char str[] = "Ho%l%a";
	printf("Frase testeo: \n");
	int resultado = ft_printf(str);
	printf("\n");
	printf("%d numero caracteres imprimidos -> printf \n\n", resultado);

	// CARACTERES CHAR -> especificador de formato %c
	printf("caracteres char 'c' -> printf \n");
	char chr1 = 'a'; 
	resultado = ft_printf("%c\n", chr1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	// STRINGS CHAR * -> especificador de formato %S
	printf("Strings char* 's' -> printf \n");
	char str1[] = "Hola";
	resultado = ft_printf("%s\n", str1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);
	
	// NUMEROS ENTEROS INT o DECIMALES -> especificador de formato %d
	printf("numero enteros int 'd' -> printf \n");
	int int1 = 12345;
	resultado = ft_printf("%d\n", int1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	// NUMEROS ENTEROS INT o DECIMALES -> especificador de formato %d
	printf("caracter '%%' -> printf \n");
	char str2[] = "Ho%%la";
	resultado = ft_printf("%s\n", str2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	return (0);
}