void delay_ms(uint32_t ms) {
    volatile uint32_t *counter = (volatile uint32_t *)0xA0000000;
    uint32_t start = *counter;
    uint32_t ticks = ms * 192000;
    while ((*counter - start) < ticks);
}

int main()
{
    
}