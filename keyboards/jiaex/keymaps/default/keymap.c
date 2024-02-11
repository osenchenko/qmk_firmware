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
    // CTRL_S_SAVE_2,
    COPY_COMBO,
    CUT_COMBO,
    ENTER_COMBO,
    LANG_SW_COMBO,
    ESCAPE_COMBO,
    PASTE_COMBO,
    COMMA_WITH_SPACE,
    PRINT_SCR_COMBO,
    CTRL_BSPACE_COMBO,
    MAC_SW_LANG_ENG_COMBO
};

const uint16_t PROGMEM ctrl_s_combo1[] = {KC_W, KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM ctrl_s_combo2[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM comma_with_space_combo[] = {KC_Z, KC_SLASH, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_S,KC_E, KC_F, COMBO_END};
const uint16_t PROGMEM cut_combo[] = {KC_W, KC_E, KC_F, COMBO_END};
const uint16_t PROGMEM enter_combo[] = {KC_S, KC_F, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM lang_sw_combo[] = {KC_S, KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM mac_lang_sw_eng_combo[] = {KC_S, KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM print_scr_combo[] = {KC_S, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM escape_combo[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM ctrl_bspace_combo[] = {KC_S, KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM _combo[] = {, COMBO_END};
// const uint16_t PROGMEM _combo[] = {, COMBO_END};
// const uint16_t PROGMEM _combo[] = {, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  [CTRL_S_SAVE_1] = COMBO_ACTION(ctrl_s_combo1),
//   [CTRL_S_SAVE_2] = COMBO_ACTION(ctrl_s_combo2),
  [COMMA_WITH_SPACE] = COMBO_ACTION(comma_with_space_combo),
  [COPY_COMBO] = COMBO_ACTION(copy_combo),
  [CUT_COMBO] = COMBO_ACTION(cut_combo),
  [PASTE_COMBO] = COMBO_ACTION(paste_combo),
  [ESCAPE_COMBO] = COMBO_ACTION(escape_combo),
  [PRINT_SCR_COMBO] = COMBO_ACTION(print_scr_combo),
  [CTRL_BSPACE_COMBO] = COMBO_ACTION(ctrl_bspace_combo),
  [LANG_SW_COMBO] = COMBO_ACTION(lang_sw_combo),
  [ENTER_COMBO] = COMBO_ACTION(enter_combo),
  [MAC_SW_LANG_ENG_COMBO] = COMBO_ACTION(mac_lang_sw_eng_combo),
//   [_COMBO] = COMBO_ACTION(),
//   [_COMBO] = COMBO_ACTION(),
//   [_COMBO] = COMBO_ACTION(),


};


void process_combo_event(uint16_t combo_index, bool pressed){
    switch(combo_index) {
        case CTRL_S_SAVE_1:
            if (pressed) {
               if (IS_LAYER_ON_STATE(default_layer_state,MAC)) {
                    tap_code16(LGUI(KC_S));
                    return;
               }
                tap_code16(LCTL(KC_S));
            }
            return;
            break;
        case COMMA_WITH_SPACE:
            if (pressed) {
                SEND_STRING(", ");
            }
            break;
        case PASTE_COMBO:
            if (pressed) {
               if (IS_LAYER_ON_STATE(default_layer_state,MAC)) {
                    tap_code16(LGUI(KC_V));
                    return;
               }
                tap_code16(LCTL(KC_V));
            }
            return;
            break;
        case COPY_COMBO:
            if (pressed) {
               if (IS_LAYER_ON_STATE(default_layer_state,MAC)) {
                    tap_code16(LGUI(KC_C));
                    return;
               }
                tap_code16(LCTL(KC_C));
            }
            return;
            break;
        case CUT_COMBO:
            if (pressed) {
               if (IS_LAYER_ON_STATE(default_layer_state,MAC)) {
                    tap_code16(LGUI(KC_X));
                    return;
               }
                tap_code16(LCTL(KC_X));
            }
            return;
            break;
        case ESCAPE_COMBO:
            if (pressed) {
                tap_code16(KC_ESCAPE);
            }
            return;
            break;
        case PRINT_SCR_COMBO:
            if (pressed) {
               if (IS_LAYER_ON_STATE(default_layer_state,MAC)) {
                    tap_code16(LCTL(LSFT(KC_1)));
                    return;
               }
                tap_code16(KC_PSCREEN);
            }
            return;
            break;
        case CTRL_BSPACE_COMBO:
            if (pressed) {
               if (IS_LAYER_ON_STATE(default_layer_state,MAC)) {
                    tap_code16(LALT(KC_BSPACE));
                    return;
               }
                tap_code16(LCTL(KC_BSPACE));
            }
            return;
            break;
        case MAC_SW_LANG_ENG_COMBO:
            if (pressed) {
                if (IS_LAYER_ON_STATE(default_layer_state,LIN)) {
                    tap_code16(HYPR(KC_E));
                    return;
               }
               if (IS_LAYER_ON_STATE(default_layer_state,MAC)) {
                    tap_code16(LGUI(KC_RGUI));
               }
            }
            return;
            break;
        case LANG_SW_COMBO:
            if (pressed) {
               if (IS_LAYER_ON_STATE(default_layer_state,LIN)) {
                    tap_code16(HYPR(KC_R));
                    return;
               }
               if (IS_LAYER_ON_STATE(default_layer_state,WIN)) {
                    tap_code16(LALT(KC_LSHIFT));
                    return;
               }
               if (IS_LAYER_ON_STATE(default_layer_state,MAC)) {
                    tap_code16(LSFT(KC_RSFT));
                    return;
               }
            }
            return;
            break;
        case ENTER_COMBO:
            if (pressed)
            {
                tap_code16(KC_ENTER);
            }
            break;
        // case _COMBO:
        //     if (pressed)
        //     {
        //         tap_code16();
        //     }
        //     break;
        default:
            break;
   }

}

bool is_alt_tab_active = false;
bool is_vscode_ctrl_tab_active=false;
bool is_mac_cmd_tab_active=false;
bool is_switch_windows_on_active_ws_active = false;  //cmd+alt+' 
bool is_switch_only_active_app_windows = false;  //ctrl+'
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
        if (r==LIN || r ==WIN) {
            is_alt_tab_active=false;
            unregister_code(KC_LALT);
        }
    }
    if (is_vscode_ctrl_tab_active){
        //second part of prossesing Alt-Tab
        uint8_t r = get_highest_layer(layer_state);
        if (r==LIN || r ==WIN) {
            is_vscode_ctrl_tab_active=false;
            unregister_code(KC_LCTRL);
        }
    }
    if (is_mac_cmd_tab_active){
        //second part of prossesing Alt-Tab
        uint8_t r = get_highest_layer(layer_state);
        if (r==LIN || r ==WIN || r==MAC) {
            is_mac_cmd_tab_active=false;
            unregister_code(KC_LGUI);
        }
    }
    
    if (is_switch_windows_on_active_ws_active){
        //second part of prossesing Alt-Tab
        uint8_t r = get_highest_layer(layer_state);
        if (r==LIN || r ==WIN || r==MAC) {
            is_switch_windows_on_active_ws_active=false;
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
        }
    }
    
    if (is_switch_only_active_app_windows){
        //second part of prossesing Alt-Tab
        uint8_t r = get_highest_layer(layer_state);
        if (r==LIN || r ==WIN || r==MAC) {
            is_switch_only_active_app_windows=false;
            unregister_code(KC_LCTRL);
        }
    }
}

uint16_t key_timer;

// char r_arrow[1]=">";

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
    case MAC_CMD_TAB:
        //first part of prossessing Alt-Tab.
        if (record->event.pressed) {
                if(!is_mac_cmd_tab_active){
                    is_mac_cmd_tab_active=true;
                    register_code(KC_LGUI);
                }
            register_code(KC_ESC);
        } else {
            unregister_code(KC_ESC);
        }
        break;
    case VSCODE_CTRL_TAB:
        //first part of prossessing Alt-Tab.
        if (record->event.pressed) {
                if(!is_vscode_ctrl_tab_active){
                    is_vscode_ctrl_tab_active=true;
                    register_code(KC_LCTRL);
                }
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }
        break;

    case SW_ACTIVE_APP_WNDWS:
        //first part of prossessing SW_ACTIVE_APP_WNDWS.
        if (record->event.pressed) {
                if(!is_switch_only_active_app_windows){
                    is_switch_only_active_app_windows=true;
                    register_code(KC_LCTRL);
                }
            register_code(KC_GRAVE);
        } else {
            unregister_code(KC_GRAVE);
        }
        break;

    case SW_WNDWS_ACTIVE_WS:
        //first part of prossessing SW_ACTIVE_APP_WNDWS.
        if (record->event.pressed) {
                if(!is_switch_windows_on_active_ws_active){
                    is_switch_windows_on_active_ws_active=true;
                    register_code(KC_LGUI);
                    register_code(KC_LALT);
                }
            register_code(KC_GRAVE);
        } else {
            unregister_code(KC_GRAVE);
        }
        break;


    


    case PROG_RIGHT_ARROW:
        if (record->event.pressed)
        {
            tap_code(KC_MINUS);
            tap_code16(RALT(KC_DOT));
        }
        break;
    case PROG_FAT_RIGHT_ARROW:
        if (record->event.pressed)
        {
            tap_code(KC_EQUAL);
            tap_code16(RALT(KC_DOT));
        }
        break;
    case COPY_URL_IN_BROWSER:
        if  (record->event.pressed){
            tap_code16(KC_F6);
            tap_code16(LCTL(KC_C));
        }
        break;
   case TMUX_NEXT_WIN:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_N);
        }
        break;
    case TMUX_PREV_WIN:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_P);
        }
        break;
    case TMUX_TO_PANE_LEFT:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_LEFT);
        }
        break;
    case TMUX_TO_PANE_RIGHT:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_RIGHT);
        }
        break;
    case TMUX_WIN_1:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_1);
        }
        break;
    case TMUX_WIN_2:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_2);
        }
        break;
    case TMUX_WIN_3:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_3);
        }
        break;
    case TMUX_WIN_4:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_4);
        }
        break;
    case TMUX_WIN_5:
        if (record->event.pressed){
            tap_code16(LCTL(KC_B));
            tap_code16(KC_5);
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
        case LIN_SYM:
            oled_write_P(PSTR("Linux symbols\n"), false);
            return;
            break;
        case LIN_FN1:
            oled_write_P(PSTR("Linux FN 1\n"), false);
            return;
            break;
        case LIN_FN2:
            oled_write_P(PSTR("Linux FN 2\n"), false);
            return;
            break;
        case LIN_FN3:
            oled_write_P(PSTR("Linux FN 3\n"), false);
            return;
            break;
         case WIN_SYM:
            oled_write_P(PSTR("Windows symbols\n"), false);
            return;
            break;
        case WIN_FN1:
            oled_write_P(PSTR("Windows FN 1\n"), false);
            return;
            break;
        case WIN_FN2:
            oled_write_P(PSTR("Windows FN 2\n"), false);
            return;
            break;
        case WIN_FN3:
            oled_write_P(PSTR("Windows FN 3\n"), false);
            return;
            break;
         case MAC_SYM:
            oled_write_P(PSTR("MacOS symbols\n"), false);
            return;
            break;
        case MAC_FN1:
            oled_write_P(PSTR("MacOS FN 1\n"), false);
            return;
            break;
        case MAC_FN2:
            oled_write_P(PSTR("MacOS FN 2\n"), false);
            return;
            break;
        case MAC_FN3:
            oled_write_P(PSTR("MacOS FN 3\n"), false);
            return;
            break;
        case SHORTCUTS:
            oled_write_P(PSTR("SHORTCUTS\n"), false);
            return;
            break;
        case FN_KEYS:
            oled_write_P(PSTR("F keys\n"), false);
            return;
            break;
        case LEFT_CURSOR_KEYS:
            oled_write_P(PSTR("Left cursor keys\n"), false);
            return;
            break;
        case LEFT_NUMBERS:
            oled_write_P(PSTR("Left numbers\n"), false);
            return;
            break;
        case SPECIAL:
            oled_write_P(PSTR("SPECIAL\n"), false);
            return;
            break;
       default:
            break;
            // Or use the write_ln shortcut over adding '\n' to the end of your string
    }

    if (IS_LAYER_ON_STATE(default_layer_state,WIN)) {
        oled_write_P(PSTR("Windows\n"), false);
    } else if (IS_LAYER_ON_STATE(default_layer_state,LIN)) {
        oled_write_P(PSTR("Linux\n"), false);
    } else if (IS_LAYER_ON_STATE(default_layer_state, MAC)) {
        oled_write_P(PSTR("MacOS\n"), false);
    } else {
    oled_write_ln_P(PSTR("Undefined"), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("\nCaps Lock is ON\n") : PSTR("\n                "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }
    return rotation;
}

#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OSM(KC_LSFT):
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}