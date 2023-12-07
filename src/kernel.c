#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"


int kmain() {
    clear_screen();
    print("welcome to 0s!\n");

    while(1) {
        print("\nqc8x:  ");
        string ch = read_str();

        if (str_eql(ch, "cmd")) {
            print("\nyou're already in cmd.\n");
        }
        else if (str_eql(ch, "clear")) {
            clear_screen();
        }
        else {
            print("\ncommand not found.\n");
        }
        print("\n");
    }
}
