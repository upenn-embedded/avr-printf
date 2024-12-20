# Printf and Scanf for the ATMega328PB (MPLAB X IDE) 

Quality of life improvement. Gives you the ```printf()``` and ```uart_scanf()``` functions, which you would use exactly like the regular ```printf()``` and ```scanf()```. No more unwieldy buffer creation, ```sprintf()```, or ```UART_putstring()``` in your code.

## Usage notes [IMPORTANT]

In uart.h, there are two macros at the top that you **must configure** for this library to work.

The instructions on how to configure that can be found in the uart.h file, in the "USER CONFIG" section.

## APIs

- ```printf("<format string>", arg1, arg2, ...)```: works just like the native ```printf()```
- ```uart_scanf("<format string>", &arg1, &arg2, ...)```: works just like the native ```scanf()```

For ```uart_scanf()```, only three format specifiers have been implemented:
- ```%d```: integer
- ```%s```: string
- ```%c```: character

You might ask why we can use the standard printf, but not the standard scanf. Well, the native printf works just fine by piping stdout to the UART interface. The native scanf also technically can work the same way - however, that has double buffering issues with UART, and apparently you can't disable those on the XC8 compiler (if you're curious about what that means, change uart_scanf to scanf in one of the examples in examples_main.c). So I implemented my own version and called it uart_scanf.

## Examples

The examples_main.c file has some example code that you can selectively enable or disable at the top of that file.
