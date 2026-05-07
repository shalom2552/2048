#include "inc/terminal.hpp"
#include "inc/menu/main_menu.hpp"

int main () {
    Terminal terminal;

    MainMenu main_menu;
    main_menu.run_menu();

    return 0;
}
