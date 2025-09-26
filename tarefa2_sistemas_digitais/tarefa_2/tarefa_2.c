#include "pico/stdlib.h"
#include "oledLIB/oled.h"
#include "joyLIB/joyLIB.h"
#include "logicaLIB/logica.h"
#include "menuLIB/menu.h"

int main() {
    stdio_init_all();
    init_oled();    
    init_logic_components();
    setup_joystick();

    Menu menu;
    menu_init(&menu);
    
    
    // Loop principal
    while (1) {
        // Atualiza posição
        menu.posicao_atual = joystick_handle_movement(menu.posicao_atual, MENU_ITEMS);
        // lógica selecionada e atualiza o display
        menu_update(&menu);
        // delay para evitar leituras rapidass
        sleep_ms(100);
    }
}