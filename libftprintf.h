#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// LIBRERIAS EXTERNAS -----------------------------------
// ----------------------------------------------------

# include <stdio.h>
# include <stdarg.h>

// INCLUSION ARCHIVO ENCABEZADO LIBRERIA "LIBFT.H"
# include "../LIBFT/libft.h"

// FUNCIONES PRINT  -----------------------------------
// ----------------------------------------------------

/** 
* @brief Imita la funcionalidad de la función estándar "printf", permitiendo
salida formateada. Admite varios marcadores de posición como “%c” 
para caracteres, “%s” para cadenas y maneja conversiones de números, 
lo que facilita la personalización de la salida para los programadores.
* @param format: puntero a una cadena terminada en nulo que contiene la 
cadena de control de formato. Esta cadena puede contener caracteres 
comunes y especificaciones de formato.
* @param ...: número variable de argumentos que corresponden a los valores
que se formatearán e imprimirán en función de los marcadores de posición
en la cadena de formato.
* @returns int -> número total de caracteres impresos, excluido el byte
que termina en nulo. Si se produce un error o se encuentra un especificador
de conversión no compatible, devuelve -1.
*/
int	ft_printf(const char *format, ...);


# endif