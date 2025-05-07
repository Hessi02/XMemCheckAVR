#ifndef __USART_HPP__
#define __USART_HPP__
    
#include <avr/io.h>

namespace USART 
{
    __attribute__((naked, section(".init4")))
    void init(void);

    void write(const char* str);
}

#endif //__USART_HPP__
