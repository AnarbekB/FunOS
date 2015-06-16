#include "user_program.h"
#include "tty.h"
#include "stdlib.h"

#define OS_NAME "FunOS Education" 
#define VERSION_OS "0.0.1"

void reboot(){
	asm("int $0x16");
}

void version(){
	printf("%s ", OS_NAME);
	printf("%s\n", VERSION_OS);
}

void help_sh(){
	printf(" Help:\n");
	printf("  clear - clear screen:\n");
	printf("  version - the kernel version:\n");
	
}

void sh(){
	set_text_attr(10);
	printf("Shell 0.1\n");
	printf("Enter help for help\n");
	//out_char('# ');
	char com_name[50];
	while((compstr(com_name, "quit") != 0)){
		out_char('#');
		out_char(' ');
		in_string(com_name, strlen(com_name));

		if (compstr(com_name, "clear") == 0)
			clear_screen();
		if (compstr(com_name, "version") == 0)
			version();
		if (compstr(com_name, "help") == 0)
			help_sh();
	}
	set_text_attr(15);
	clear_screen();
}

