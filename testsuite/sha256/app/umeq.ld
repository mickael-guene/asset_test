OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm",
              "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY
{
 flash (rx)         : ORIGIN = 0x08000000, LENGTH = 16M
 sram (rw)          : ORIGIN = 0x20000000, LENGTH = 16M
}

SECTIONS
{
  .text             :
    {
        *(.text)
        *(*code_asset)
    } > flash
  .rodata           :
    {
        *(.rodata)
        *(*rodata)
        KEEP (*(SORT_NONE(.init)))
        KEEP (*(SORT_NONE(.fini)))
        KEEP (*(.eh_frame))
    } > flash
  __exidx_start = .;
  .ARM.exidx        :
    {
        *(.ARM.exidx*)
    } > flash
  __exidx_end = .;
  __data_load_start__ = .;
  .data             :
    {
        __data_start__ = .;
        __init_array_start = .;
        KEEP (*(SORT(.init_array.*)))
        KEEP (*(.init_array ))
        __init_array_end = .;
        KEEP (*(SORT(.fini_array.*)))
        KEEP (*(.fini_array ))
        KEEP (*(.jcr))
        *(.data*)
        *(*data_asset)
        __data_end__ = .;
    } > sram AT > flash
  __bss_start__ = .;
  .bss             :
    {
    } > sram
  __bss_end__ = . ;
  __end__ = . ;
  PROVIDE (end = .);
}
