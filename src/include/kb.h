#ifndef KB_H
#define KB_H

#include "screen.h"
#include "system.h"
#include "types.h"

string read_str() {
    char buff;
    string buffstr;
    uint8 i = 0;
    uint8 reading = 1;

    while (reading) {
        if (inportb(0x64) & 0x1) {
            switch(inportb(0x60)) {
                // case 1:
                //     print_ch('(char)27);
                //     buffstr[i] = (char)27;
                //     i++;
                //     break;
                case 2:
                    print_ch('1');
                    buffstr[i] = '1';
                    i++;
                    break;
                case 3:
                    print_ch('2');
                    buffstr[i] = '2';
                    i++;
                    break;
                case 4:
                    print_ch('3');
                    buffstr[i] = '3';
                    i++;
                    break;
                case 5:
                    print_ch('4');
                    buffstr[i] = '4';
                    i++;
                    break;
                case 6:
                    print_ch('5');
                    buffstr[i] = '5';
                    i++;
                    break;
                case 7:
                    print_ch('6');
                    buffstr[i] = '6';
                    i++;
                    break;
                case 8:
                    print_ch('7');
                    buffstr[i] = '7';
                    i++;
                    break;
                case 9:
                    print_ch('8');
                    buffstr[i] = '8';
                    i++;
                    break;
                case 10:
                    print_ch('9');
                    buffstr[i] = '9';
                    i++;
                    break;
                case 11:
                    print_ch('0');
                    buffstr[i] = '0';
                    i++;
                    break;
                case 12:
                    print_ch('-');
                    buffstr[i] = '-';
                    i++;
                    break;
                case 13:
                    print_ch('=');
                    buffstr[i] = '=';
                    i++;
                    break;
                case 14:
                    print_ch('\b');
                    i--;
                    buffstr[i] = 0;
                    break;
                // case 15:
                //     print_ch('\t');                   // tab button
                //         buffstr[i] = '\t';
                //     i++;
                //     break;
                case 16:
                    print_ch('q');
                    buffstr[i] = 'q';
                    i++;
                    break;
                case 17:
                    print_ch('w');
                    buffstr[i] = 'w';
                    i++;
                    break;
                case 18:
                    print_ch('e');
                    buffstr[i] = 'e';
                    i++;
                    break;
                case 19:
                    print_ch('r');
                    buffstr[i] = 'r';
                    i++;
                    break;
                case 20:
                    print_ch('t');
                    buffstr[i] = 't';
                    i++;
                    break;
                case 21:
                    print_ch('y');
                    buffstr[i] = 'y';
                    i++;
                    break;
                case 22:
                    print_ch('u');
                    buffstr[i] = 'u';
                    i++;
                    break;
                case 23:
                    print_ch('i');
                    buffstr[i] = 'i';
                    i++;
                    break;
                case 24:
                    print_ch('o');
                    buffstr[i] = 'o';
                    i++;
                    break;
                case 25:
                    print_ch('p');
                    buffstr[i] = 'p';
                    i++;
                    break;
                case 26:
                    print_ch('[');
                    buffstr[i] = '[';
                    i++;
                    break;
                case 27:
                    print_ch(']');
                    buffstr[i] = ']';
                    i++;
                    break;
                case 28:
                    // print_ch('\n');
                    // buffstr[i] = '\n';
                    i++;
                    reading = 0;
                    break;
                // case 29:
                //     print_ch('q');               // left control
                //     buffstr[i] = 'q';
                //     i++;
                //     break;
                case 30:
                    print_ch('a');
                    buffstr[i] = 'a';
                    i++;
                    break;
                case 31:
                    print_ch('s');
                    buffstr[i] = 's';
                    i++;
                    break;
                case 32:
                    print_ch('d');
                    buffstr[i] = 'd';
                    i++;
                    break;
                case 33:
                    print_ch('f');
                    buffstr[i] = 'f';
                    i++;
                    break;
                case 34:
                    print_ch('g');
                    buffstr[i] = 'g';
                    i++;
                    break;
                case 35:
                    print_ch('h');
                    buffstr[i] = 'h';
                    i++;
                    break;
                case 36:
                    print_ch('j');
                    buffstr[i] = 'j';
                    i++;
                    break;
                case 37:
                    print_ch('k');
                    buffstr[i] = 'k';
                    i++;
                    break;
                case 38:
                    print_ch('l');
                    buffstr[i] = 'l';
                    i++;
                    break;
                case 39:
                    print_ch(';');
                    buffstr[i] = ';';
                    i++;
                    break;
                case 40:
                    print_ch((char)44);              // single quote
                    buffstr[i] = (char)44;
                    i++;
                    break;
                case 41:
                    print_ch((char)44);              // Back tick (`)
                    buffstr[i] = (char)44;
                    i++;
                    break;
                // case 42:                            // left shift 
                //     print_ch('q');
                //     buffstr[i] = 'q';
                //     i++;
                //     break;
                // case 43:                           // \ (< for somekeyboards)
                //     print_ch((char)92);
                //     buffstr[i] = 'q';
                //     i++;
                //     break;
                case 44:
                    print_ch('z');
                    buffstr[i] = 'z';
                    i++;
                    break;
                case 45:
                    print_ch('x');
                    buffstr[i] = 'x';
                    i++;
                    break;
                case 46:
                    print_ch('c');
                    buffstr[i] = 'c';
                    i++;
                    break;
                case 47:
                    print_ch('v');
                    buffstr[i] = 'v';
                    i++;
                    break;
                case 48:
                    print_ch('b');
                    buffstr[i] = 'b';
                    i++;
                    break;
                case 49:
                    print_ch('n');
                    buffstr[i] = 'n';
                    i++;
                    break;
                case 50:
                    print_ch('m');
                    buffstr[i] = 'm';
                    i++;
                    break;
                case 51:
                    print_ch(',');
                    buffstr[i] = ',';
                    i++;
                    break;
                case 52:
                    print_ch('.');
                    buffstr[i] = '.';
                    i++;
                    break;
                case 53:
                    print_ch('/');
                    buffstr[i] = '/';
                    i++;
                    break;
                case 54:
                    print_ch('.');
                    buffstr[i] = '.';
                    i++;
                    break;
                case 55:
                    print_ch('/');
                    buffstr[i] = '/';
                    i++;
                    break;
                // case 56:
                //     print_ch(' ');                 // right shift
                //     buffstr[i] = ' ';
                //     i++;
                //     break;
                case 57:
                    print_ch(' ');
                    buffstr[i] = ' ';
                    i++;
                    break;
            }
        }
    }
    buffstr[i] = 0;
    return buffstr;
}

#endif
