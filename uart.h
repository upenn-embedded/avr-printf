#ifndef UART_H
#define UART_H

#include <stdio.h>

/***************************************/
/* USER CONFIG */
/***************************************/

/**
 * Line termination type that your terminal emulator follows
 *      \r  :   #define CR
 *      \n  :   #define LF
 *      \r\n:   #define CRLF
 * For example, PuTTY and MobaXTerm end a line with only \r (CR)
 * Arduino IDE supports termination with \r\n (CRLF)
 * VSCode serial monitor extension supports all three.
 * 
 * Call determine_line_ending() in your code to see which one your terminal supports.
 */
#define CRLF

/**
 * Maximum length of input string
 */
#define MAX_STRING_LENGTH   100

/**
 * Set UART baud rate
 * This has been tested to work fine with 9600
 * 
 * If using other baud rates, slight adjustments may need to be made
 * to the UART_BAUD_PRESCALER macro (add or subtract a few counts)
 * due to baud rate error
 */
#define UART_BAUD_RATE      9600

/***************************************/
/* MACROS AND FUNCTION DECLARATIONS */
/***************************************/

#ifndef F_CPU
    #warning "F_CPU not defined. Defaulting to 16MHz"
    #define F_CPU 16000000UL
#endif

#define UART_BAUD_PRESCALER (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)

void uart_init(void);

int uart_send(char data, FILE* stream);

int uart_receive(FILE* stream);

void uart_scanf(const char* format, ...);

void determine_line_ending(void);

#endif // UART_H