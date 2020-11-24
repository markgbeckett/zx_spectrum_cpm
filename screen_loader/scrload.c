#include <stdio.h>
#include <stdlib.h>

void showScrFromRam3() __naked;

int main(){
  showScrFromRam3(); /* copy screen from RAM3 into display buffer */

  getchar(); /* wait for keypress */
  

  return 0;
}

void showScrFromRam3() __naked
{
  __asm
    di
    /* Copy loader and screen to RAM3, so not lost when we 
       switch to different memory configuration */
    ld hl, scrLoader
    ld de, 0xCE00 /* Space in RAM3 between 0xCE00 and 0xE900 is enough
		     to hold data */
    ld bc, scrLoader_End - scrLoader
    ldir

    /* Jump to new copy of code in RAM3 */
    jp 0xCe00
scrLoader:
    /* Switch to RAM4-RAM5-RAM6-RAM3 */
    ld a, %00000101
    ld bc, 0x1FFD
    out (c), a     

    /* Copy screen from RAM3 to RAM5 */
    ld hl, 0xCE00 + scrLoader_data - scrLoader
    ld de, 0x4000
    ld bc, 0x1B00
    ldir

    /* Switch back to RAM0-RAM1-RAM2-RAM3 */
    ld a, %00000001 
    ld bc, 0x1FFD
    out (c), a                           
    jp scrLoader_End /* Return to original code in TPA */

scrLoader_data:
    BINARY "screen.bin"

scrLoader_End:            
    ei

  __endasm;            
}
