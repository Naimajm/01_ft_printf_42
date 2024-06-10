
#include "libftprintf.h"

// https://42-cursus.gitbook.io/guide/rank-01/ft_printf/variadic-functions
// https://42.nauman.cc/2023/08/16/ft-printf-ft-printf/

/* implementación personalizada de la función printf en C, que proporciona 
un subconjunto simplificado de opciones de formato para cadenas de caracteres. 
Toma una cadena de formato como entrada y, cuando encuentra un carácter % de 
marcador de posición seguido de un especificador de conversión, procesa e 
imprime los valores correspondientes. */

int	ft_printf(const char *format, ...)
{
	va_list	args_list;
	int	chr_numbers;
	int	index;
	//char	special_character;

	index = 0;
	chr_numbers = 0;
	va_start(args_list, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			//special_character = format[index];
		}
		else
		{
			write(1, &format[index], 1);
			chr_numbers += 1;
		}
		index++;
	}
	va_end(args_list);
	return (chr_numbers);
}

int	main(void)
{
	//TESTEO FUNCION PROTOTIPO PRINTF
	char str[] = "Ho%l%aj";
	printf("Frase testeo: \n");
	int resultado = ft_printf("%s", str);
	printf("\n");
	printf("%d numero caracteres imprimidos -> printf \n", resultado);

	return (0);
}