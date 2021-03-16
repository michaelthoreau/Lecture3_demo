#include <mbed.h>
#include <USBSerial.h>

USBSerial serial;

extern "C" uint32_t is_0(uint32_t a);

//https://www.st.com/resource/en/reference_manual/dm00031020-stm32f405-415-stm32f407-417-stm32f427-437-and-stm32f429-439-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf
//https://azeria-labs.com/assembly-basics-cheatsheet/


#define GPIOD_MODER 0x40020c00
int main() {

  /* setup output */
  DigitalOut led1(LED1);
  led1 = 1;

  
  while (1) {
    uint32_t tmp = *(uint32_t*)GPIOD_MODER;
    serial.printf("%08X\n\r", tmp);
  }
  
  
  while(1) {

    serial.printf(is_0(0) ? "a == 0\n\r" : "a != 0\n\r");
    serial.printf(is_0(1) ? "a == 0\n\r" : "a != 0\n\r");

    wait_ms(500);


  }
}




