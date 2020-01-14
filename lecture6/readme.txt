
UART configuration:

BaudRate			115200
Word Length		8 Bits
Stop Bit			One Stop bit
Parity				None
Hardware flow control disabled (RTS and CTS signals)

Conection is implemented via virtual com port (USART1, RX - PC5, TX - PC4)

The board waits until receives the message (20 bytes), then sends it back.
UART works repeatedly, first using  Interrupts  then  DMA.
