#ifndef __CONFIG_H__
#define __CONFIG_H__

#define PACKAGE "conv"
#define VERSION "1.0"
#define PACKAGE_NAME PACKAGE " " VERSION
#define BASE_10 10
#define BASE_2  2

extern bool verbose;

/*
func utilizada para mostrar exemplo de uso
do programa e sai com erro
*/
void usage(void);

/*
func recebe o valor informado junto com a unidade, ex: 100Mb,
então retorna o valor convertiro em bit(s).
 */
float convertForBit(float valor, char *unidade);

/*
func recebe o valor em bit e exibe os valores convertidos em outras unidades,
caso a variavel verbose seja verdadeira (argumento -v)
a exibição com notação cientefica não é exibida,
mas sim o valor por extenso.
 */
void imprimir(float bit);


#endif // __CONFIG_H__