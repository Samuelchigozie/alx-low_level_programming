#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

/* Function prototypes for binary manipulation functions */
unsigned int binary_to_uint(const char *binary_str);
void print_binary(unsigned long int number);
int _putchar(char character);
int get_bit(unsigned long int number, unsigned int index);
int set_bit(unsigned long int *number, unsigned int index);
int clear_bit(unsigned long int *number, unsigned int index);
unsigned int flip_bits(unsigned long int number1, unsigned long int number2);

/* Function prototype for system endianness detection */
int get_endianness(void);

#endif /* MAIN_H */
