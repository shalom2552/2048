#include "inc/input.hpp"
#include "inc/menu/main_menu.hpp"

int main () {
    input_setup();

    MainMenu main_menu;
    main_menu.run_menu();

    cleanup();
    return 0;
}
