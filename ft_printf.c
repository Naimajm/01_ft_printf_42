/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juagomez <juagomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:40:59 by juagomez          #+#    #+#             */
/*   Updated: 2024/08/21 12:09:18 by juagomez         ###   ########.fr       */
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

static int	ft_format_print(char specifier_format, va_list args_list);

int	ft_printf(char const *format, ...)
{
	va_list			args_list;
	unsigned int	chr_numbers;
	unsigned int	index;
	char			specifier_format;

	index = 0;
	chr_numbers = 0;
	va_start(args_list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			specifier_format = format[index + 1];
			chr_numbers = ft_format_print(specifier_format, args_list);
			index++;
		}
		else
		{
			ft_putchar(format[index]);
			chr_numbers++;
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
static int	ft_format_print(char specifier_format, va_list args_list)
{
	int	chr_numbers;
	
	if (specifier_format == 'c') 
		chr_numbers = ft_putchar(va_arg(args_list, int));
	else if (specifier_format == 's')
		chr_numbers = ft_putstr(va_arg(args_list, char *));
	else if (specifier_format == 'x' || specifier_format == 'X')
		chr_numbers = ft_puthexadecimal(va_arg(args_list, unsigned long), specifier_format);
	else if (specifier_format == 'p')
		chr_numbers = ft_putaddress(va_arg(args_list, size_t));
	else if (specifier_format == 'u')
		chr_numbers = ft_putunsigned(va_arg(args_list, unsigned int));
	else if (specifier_format == 'd' || specifier_format == 'i')
		chr_numbers = ft_putnbr(va_arg(args_list, int));
	else if (specifier_format == '%')
		chr_numbers = ft_putchar('%');
	else
		chr_numbers = -1;
	return (chr_numbers);
}

/* int	main(void)
{
	//TESTEO FUNCION PROTOTIPO PRINTF
	char str[] = "Ho%l%a";
	printf("Frase testeo: \n");	
	int resultado1 = printf("%s\n", str);
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	int resultado = ft_printf("%s\n",str);
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	// CARACTERES CHAR -> especificador de formato %c
	printf("caracteres char 'c' \n");
	char chr1 = 'a'; 
	resultado1 = printf("%c\n", chr1);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	resultado = ft_printf("%c\n", chr1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	// STRINGS CHAR * -> especificador de formato %S
	printf("Strings char* 's' \n");
	char str1[] = "Hola";
	resultado1 = printf("%s\n", str1);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	resultado = ft_printf("%s\n", str1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	// NUMEROS EN HEXADECIMAL 'UNSIGNED int' -> especificador de formato %X o %x
	printf("numero enteros SIN SIGNO unsigned long 'x o X' \n");
	unsigned int unsig_int2 = 567845;
	resultado1 = printf("%x\n", unsig_int2);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	resultado1 = printf("%X\n", unsig_int2);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	resultado = ft_printf("%x\n", unsig_int2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n", resultado);
	resultado = ft_printf("%X\n", unsig_int2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);		

	// NUMEROS ENTEROS SIN SIGNO 'UNSIGNED INT' -> especificador de formato %u
	printf("numero enteros SIN SIGNO unsigned int 'u' \n");
	unsigned int unsig_int1 = 567845;
	resultado1 = printf("%i\n", unsig_int1);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	resultado = ft_printf("%i\n", unsig_int1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);
	
	// NUMEROS ENTEROS INT -> especificador de formato %d
	printf("numero enteros int 'd' \n");
	int int1 = 12345;
	resultado1 = printf("%i\n", int1);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	resultado = ft_printf("%i\n", int1);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	// NUMEROS DECIMALES -> especificador de formato %
	printf("numero decimales int 'i' \n");
	int int2 = 5678;
	resultado1 = printf("%d\n", int2);	
	printf("%d numero caracteres imprimidos -> printf \n", resultado1);
	resultado = ft_printf("%d\n", int2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);

	// DOBLE CARACTER '%' -> especificador de formato %%
	printf("caracter '%%' -> printf \n");
	char str2[] = "Ho%%la";
	resultado1 = printf("%s\n", str2);	
	printf("%d numero caracteres imprimidos \n", resultado1);
	resultado = ft_printf("%s\n", str2);	
	printf("%d numero caracteres imprimidos -> ft_printf \n\n", resultado);



	return (0);
} */
