#include QMK_KEYBOARD_H
#include "stdio.h"
#include "config.h"
#include "debug.h"


void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable   = true;
    // debug_matrix   = true;
    // debug_keyboard = true;
}


enum combos {
    CTRL_S_SAVE_1,
    CTRL_S_SAVE_2,
    CTRL_X_CUT,
    CTRL_C_COPY,
    CTRL_V_PASTE,
};

const uint16_t PROGMEM ctrl_s_combo1[] = {KC_L, KC_S, COMBO_END};
const uint16_t PROGMEM ctrl_s_combo2[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ctrl_x_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM ctrl_c_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM ctrl_v_combo[] = {KC_C, KC_V, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [CTRL_S_SAVE_1] = COMBO_ACTION(ctrl_s_combo1),
  [CTRL_S_SAVE_2] = COMBO_ACTION(ctrl_s_combo2),
  [CTRL_X_CUT] = COMBO_ACTION(ctrl_x_combo),
  [CTRL_C_COPY] = COMBO_ACTION(ctrl_c_combo),
  [CTRL_V_PASTE] = COMBO_ACTION(ctrl_v_combo),
};


void process_combo_event(uint16_t combo_index, bool pressed){
    switch(combo_index) {
        case CTRL_S_SAVE_1:
        if (pressed)
        {
            tap_code16(LCTL(KC_S));
        }
        break;
         case CTRL_S_SAVE_2:
        if (pressed)
        {
            tap_code16(LCTL(KC_S));
        }
        break;
        case CTRL_X_CUT:
        if (pressed)
        {
            tap_code16(LCTL(KC_X));
        }
        break;
        case CTRL_C_COPY:
        if (pressed)
        {
            tap_code16(LCTL(KC_C));
        }
        break;
        case CTRL_V_PASTE:
        if (pressed)
        {
            tap_code16(LCTL(KC_V));
        }
        break;
   }

}

bool is_alt_tab_active = false;

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_B) {
        register_code(KC_LCTL);
        register_code(KC_B);
        unregister_code(KC_B);
        unregister_code(KC_LCTL);
    }
    // SEQ_TWO_KEYS(KC_D, KC_D) {
    //   SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    // }
    // SEQ_THREE_KEYS(KC_D, KC_D, KC_S) {
    //   SEND_STRING("https://start.duckduckgo.com\n");
    // }
    // SEQ_TWO_KEYS(KC_A, KC_S) {
    //   register_code(KC_LGUI);
    //   register_code(KC_S);
    //   unregister_code(KC_S);
    //   unregister_code(KC_LGUI);
    // }
  }


    if (is_alt_tab_active){
        //second part of prossesing Alt-Tab
    uint8_t r = get_highest_layer(layer_state);
    if (r==LIN) {
        is_alt_tab_active=false;
        unregister_code(KC_LALT);
    }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif

    switch (keycode)
    {
    case ALT_TAB:
   //first part of prossessing Alt-Tab.
        if (record->event.pressed) {
                if(!is_alt_tab_active){
                    is_alt_tab_active=true;
                    register_code(KC_LALT);
                }
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }
        break;
    default:
        break;
    }

    return true;
}

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    switch (get_highest_layer(layer_state)) {
        case LIN:
            oled_write_P(PSTR("Linux\n"), false);
            break;
        case LIN_SYM:
            oled_write_P(PSTR("Linux symbols\n"), false);
            break;
        case LIN_FN1:
            oled_write_P(PSTR("Linux FN 1\n"), false);
            break;
        case LIN_FN2:
            oled_write_P(PSTR("Linux FN 2\n"), false);
            break;
        case SPECIAL:
            oled_write_P(PSTR("SPECIAL\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

#endif

