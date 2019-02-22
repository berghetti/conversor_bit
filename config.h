#ifndef __CONFIG_H__
#define __CONFIG_H__

#define PACKAGE "conv"
#define VERSION "1.0"
#define PACKAGE_NAME PACKAGE " " VERSION
#define BASE 10

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
float convertForBit(float valor, int unidade);

/*
func recebe o valor em bit e exibe,
caso a variavel verbose seja verdadeira (argumento -v)
a exibição com notação cientefica não é exibida,
mas sim o valor por extenso.
 */
void imprimir(float bit);


#endif // __CONFIG_H__