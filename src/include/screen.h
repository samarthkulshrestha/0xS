#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"


int cursor_x = 0, cursor_y = 0;
const uint8 sw = 80, sh = 25, sd = 2;

void clear_line(uint8 from, uint8 to) {
    uint16 i = sw * from * sd;
    string vidmem = (string)0xB8000;

    for (i; i < (sw * (to + 1) * sd); i++) {
        vidmem[i] = 0x0;
    }
}

void update_cursor() {
    unsigned temp;
    temp = cursor_y * sw + cursor_x;            // position = (y * width) + x

    outportb(0x3D4, 14);                        // CRT control register: select cursor location
    outportb(0x3D5, temp >> 8);                 // send high byte across bus
    outportb(0x3D4, 15);                        // CRT cr: select send low byte
    outportb(0x3D5, temp);                      // send low byte of cursor location
}

void clear_screen() {
    clear_line(0, sh - 1);
    cursor_x = 0;
    cursor_y = 0;
    update_cursor;
}

void scroll_up(uint8 line_num) {
    string vidmem = (string)0xB8000;
    uint16 i = 0;

    for (i; i < sw * (sh - 1) * sd; i++) {
        vidmem[i] = vidmem[i + sw * sd * line_num];
    }

    clear_line(sh - 1 - line_num, sh - 1);

    if ((cursor_y - line_num) < 0) {
        cursor_x = 0;
        cursor_y = 0;
    } else {
        cursor_y -= line_num;
    }
    update_cursor();
}

void new_line_check() {
    if (cursor_y >= sh - 1) {
        scroll_up(1);
    }
}

void print_ch(char c) {
    string vidmem = (string)0xB8000;

    switch(c) {
        case (0x08):
            if (cursor_x > 0) {
                cursor_x--;
                vidmem[(cursor_y * sw + cursor_x) * sd] = 0x00;
            }
            break;
        case (0x09):
            cursor_x = (cursor_x + 8) & ~(8 - 1);
            break;
        case ('\r'):
            cursor_x = 0;
            break;
        case ('\n'):
            cursor_x = 0;
            cursor_y++;
            break;
        default:
            vidmem[((cursor_y * sw + cursor_x)) * sd] = c;
            vidmem[((cursor_y * sw + cursor_x)) * sd + 1] = 0x0F;
            cursor_x++;
            break;
    }

    if (cursor_x >= sw) {
        cursor_x = 0;
        cursor_y++;
    }
    new_line_check();
    update_cursor();
}

void print(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch) - 1;

    for (i; i < length; i++) {
        print_ch(ch[i]);
    }
}


#endif
