# CP/M Screen Loader

This program allows you to display a ZX Spectrum screen file (e.g., a loading screen from a game) in Locomotive CP/M Plus for the ZX Spectrum +3. Note CP/M Plus on the ZX Specturm is usually text-only. To do this, the program bypasses the CP/M API and writes directly to screen memory.

## Building and using the program

To build the program you need to set up the [Z88DK development kit[(https://github.com/z88dk) and a copy of [Gnu Make](https://www.gnu.org/software/make/).

To build your custom binary:

1. Create a raw binary file, called "screen.bin", containing the screen you wish to use. For example, export the display buffer (starts at address 0x4000 and has length 0x1B00) from within a ZX Spectrum emulator. A sample "screen.bin" is distributed with the source code for testing purposes.

2. From the source code directory, type `make -f Makefile_scrload`.

A CP/M command file named "SCRLOAD.COM" is produced. This then needs to be added to a CP/M diskette image (.DSK file) using, for example, [CPCDiskXP](http://www.cpcmania.com/cpcdiskxp/cpcdiskxp.htm).

Boot your emulator into CP/M Plus, insert your new diskette image, and enter the command `SCRLOAD`. The screen should be displayed and the computer will pause, waiting for you to press any key.

Note: The screen to be displayed is assembled into the COM file that is created. This is to work around a possible bug in the Z88DK file-handling routines for CP/M. You need to build a new COM file for each screen you wish to display.
