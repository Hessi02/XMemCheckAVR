#include "usart.hpp"

void USART::init(void) {
    constexpr unsigned short ubrr = (F_CPU + BAUD * 8) / (BAUD * 16) - 1;
    UBRR0H = static_cast<unsigned char>(ubrr >> 8);
    UBRR0L = static_cast<unsigned char>(ubrr & 0xff);
    UCSR0B = (1 << TXEN);
}      

void USART::write(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        while (!( UCSR0A & (1 << UDRE)));
        UDR0 = str[i];
    }
}
