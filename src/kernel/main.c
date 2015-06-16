#include "stdlib.h"
#include "interrupts.h"
#include "tty.h"
#include "user_program.h"

typedef struct {
	uint64 base;
	uint64 size;
} BootModuleInfo;

void kernel_main(uint8 boot_disk_id, void *memory_map, BootModuleInfo *boot_module_list) 
{
	init_interrupts();
	init_tty();
	set_text_attr(15);

/*
		TODO:

		- sleep();
		- user login
		- shell
		- strlen();
*/
//	move_cursor(959);
//	asm("cli \n Hlt");
//	int i, j;
/*	for (i= 1; i < 100000; ++i){
		for (j = 0; j < 79; ++j)
		{
			move_cursor(880 + j);
			if (i % 100 != 0)
				printf("/");
			else
				printf("|");
		}
	}
*/
//	clear_screen();
    move_cursor(910); 
	printf("Welcome to FunOS!\n\n");
	//printf("You load in disk number %d\n", boot_disk_id);
	//printf("Memory map at 0x%x\n", memory_map);
	//printf("Boot module list at 0x%x\n", boot_module_list);
	//printf("String is %s, char is %c, number is %d, hex number is 0x%x", __DATE__, 'A', 1234, 0x1234);
	//char mode;

	//printf("%s",__DATE__);
	printf("The shell: sh\n");
	printf("Reboot: reboot\n");
	char select[256];

	//asm("int $0x1A");

	while (true){		
		in_string(select, strlen(select));
		
		if (compstr(select, "sh") == 0)
			sh();
		if (compstr(select, "reboot") == 0)
			reboot();
		if (compstr(select, "version") == 0)
			version();
        else
            printf("Unknown command\n");
	}
} 
