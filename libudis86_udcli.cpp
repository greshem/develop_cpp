
// 2012_11_26   ÐÇÆÚÒ»   add by greshem
#include <stdio.h>
#include <udis86.h>

int
main() 
{
    //uint8_t raw[] = { 0xf0, 0x66, 0x36, 0x67, 0x65, 0x66, 0xf3, 0x67, 0xda };
    uint8_t raw[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
    uint8_t len = 9;
    ud_t ud_obj;
    ud_init(&ud_obj);
    ud_set_mode(&ud_obj, 16);
    ud_set_input_buffer(&ud_obj, raw, len);
    ud_set_syntax(&ud_obj, UD_SYN_INTEL);
    while (ud_disassemble(&ud_obj) != 0) 
	{
  		printf( "\t%s\n", ud_insn_asm( &ud_obj ) );
        //return 0;
    }
    return 1;
}

