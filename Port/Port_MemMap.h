#ifndef PORT_MEMMAP_H
#define PORT_MEMMAP_H

#define REG(R1, R2)		*((volatile uint32_t *)(R1 + R2))

#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
	
#define GPIODATA_OFFSET		0x3FC
#define GPIODIR_OFFSET 		0x400
#define GPIOAFSEL_OFFSET	0x420
#define GPIOPUR_OFFSET		0x510
#define GPIOPDR_OFFSET		0x514
#define GPIOSLR_OFFSET		0x518
#define GPIODEN_OFFSET		0x51C
#define GPIOLOCK_OFFSET		0x520
#define GPIOAMSEL_OFFSET	0x528
#define GPIOPCTL_OFSSET		0x52C
#define GPIOICR_OFFSET		0x524



#endif
