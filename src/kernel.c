kmain() {
    char* vidmem = (char*)0xB8000;
    vidmem[0] = 'X';
    vidmem[1] = 0x02;
}
