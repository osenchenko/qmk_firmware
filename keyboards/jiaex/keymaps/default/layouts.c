#include QMK_KEYBOARD_H
#include "config.h"


/*
#define KC_QTSH RSFT_T(KC_QUOT)
#define KC_SLSF RSFT_T(KC_LSCR)
#define KC_NLCT RCTL_T(KC_LNUM)
#define KC_ETAL RALT_T(KC_ENT)
#define LOWER MO(_LOWER)
*/

#define LIN_ALT_TAB        LALT(KC_TAB)           //Switch windows Alt+Tab
#define LIN_SW_TO_WS_DOWN  LALT(LCTL(KC_DOWN))    // Switch to workspace down
#define LIN_SW_TO_WS_UP    LALT(LCTL(KC_UP))      //Switch to workspace up
#define LIN_LAUNCHER       LGUI(KC_S)             // Show windows + launcher prompt
#define LIN_TAB_RIGHT      LCTL(KC_PGDOWN)          // Switch browser tab right
#define LIN_TAB_LEFT       LCTL(KC_PGUP)        // Switch browser tab left
#define LIN_MV_DISP_LEFT   LSFT(LGUI(KC_LEFT))    // Move window to display left
#define LIN_MV_DISP_RIGHT  LSFT(LGUI(KC_RIGHT))   // Move window to display right
#define LIN_MV_WS_DOWN     LSFT(LGUI(KC_PGDOWN))  // Move window to workspace down
#define LIN_MV_WS_UP       LSFT(LGUI(KC_PGUP))    // Move window to workspace up
#define LIN_SW_LANG_RUS    LSFT(RGUI(KC_SPC))     // Switch language to russian
#define LIN_SW_LANG_ENG    RGUI(KC_SPC)           // Switch language to english
#define LIN_CLOSE_WIN      LALT(KC_F4)            // Close window Alt+F4
#define LIN_CLOSE_TAB      LCTL(KC_W)             // Close tab in browser
#define LIN_MAX_WIN        LGUI(KC_UP)            // Maximize window

/*
 #define LIN_  //
 #define LIN_  //
 #define LIN_  //
 #define LIN_  //
 #define LIN_  //
 #define LIN_  //
 #define LIN_  //
 #define LIN_  //
 #define LIN_  //



#define WIN_ALT_TAB   //Switch windows Alt+Tab
#define WIN_   // Switch to workspace down
#define WIN_    //Switch to workspace up
#define WIN_    // Show windows + launcher prompt
#define WIN_    // Switch browser tab right
#define WIN_    // Switch browser tab left
##define WIN_    // Move window to display left
#define WIN_    // Move window to display right
define WIN_     // Move window to workspace down
#define WIN_    // Move window to workspace up
#define WIN_    // Switch language to russian
#define WIN_    // Switch language to english
#define WIN_  // Close window Alt+F4
#define WIN_  // Maximize window

#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_
#define WIN_


#define MAC_   //Switch windows Alt+Tab
#define MAC_   // Switch to workspace down
#define MAC_    //Switch to workspace up
#define MAC_    // Show windows + launcher prompt
#define MAC_    // Switch browser tab right
#define MAC_    // Switch browser tab left
##define MAC_    // Move window to display left
#define MAC_    // Move window to display right
define MAC_     // Move window to workspace down
#define MAC_    // Move window to workspace up
#define MAC_    // Switch language to russian
#define MAC_    // Switch language to english
#define MAC_  // Close window Alt+F4
#define MAC_  // Maximize window
#define MAC_  //
#define MAC_  //
#define MAC_  //
#define MAC_  //
#define MAC_  //
#define MAC_  //
#define MAC_  //
#define MAC_  //
#define MAC_  //
#define MAC_  //
#define MAC_  //

*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LIN] = LAYOUT(
     //┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐          ┌─────────────┬─────────────┬─────────────┬─────────────┬───────────┬────────────┬──────────────┬─────────────┐
         TG(LIN_FN2),      KC_1,         KC_2,         KC_3,         KC_4,         KC_5,        KC_NO,      /* | */   KC_NO,        KC_6,           KC_7,       KC_8,           KC_9,       KC_0,       KC_RALT,       /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
           KC_ESC,        KC_Q,        KC_W,       KC_E,           KC_R,       KC_T,           KC_LGUI,       /* | */   MO(LIN_FN1),        KC_Y,           KC_U,       KC_I,           KC_O,       KC_P,       KC_LBRC,       KC_RBRC,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          KC_BSPACE,  HYPR_T(KC_A),   KC_S,       LT(LIN_FN2,KC_D), KC_F,       KC_G,         /*NO_KEY*/    /* | */   /*NO_KEY*/    KC_H,           KC_J,       KC_K,           KC_L,   HYPR_T(KC_SCOLON),RGUI_T(KC_QUOTE),RGUI_T(KC_ENTER),
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
        LCTL(KC_LSFT), LCTL_T(KC_Z),    KC_X,        KC_C,          KC_V,      LGUI_T(KC_B),           KC_NO,      /* | */     KC_NO,      KC_N,           KC_M,       KC_COMM,        KC_DOT,  RCTL_T(KC_SLSH),RCTL(KC_RSFT), /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          /*NO_KEY*/   LCTL(KC_LALT),  KC_LCTL,       KC_LALT,     MO(LIN_FN1),LSFT_T(KC_TAB),MO(LIN_SYM),/* | */     KC_LEAD,    LT(LIN_SYM,KC_ESC),RSFT_T(KC_SPC),KC_LALT,   KC_RCTL,   RCTL(KC_LALT) /*NO_KEY*/    /*NO_KEY*/
     //└─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┘  /* | */ └─────────────┴─────────────┴─────────────┴─────────────┴───────────┴────────────┴──────────────┴─────────────┘
        ),

    [LIN_SYM] = LAYOUT(
     //┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐          ┌─────────────┬─────────────┬─────────────┬─────────────┬───────────┬────────────┬──────────────┬─────────────┐
         MO(SPECIAL),    KC_NO,        KC_NO,     RALT(KC_3)/*№*/,  KC_NO,       KC_NO,         KC_NO,      /* | */   KC_F14,        KC_NO,           KC_NO,       KC_NO,           KC_NO,       KC_NO,       MO(SPECIAL),    /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
           KC_ESC,       KC_NO,     RALT(KC_GRAVE),LSFT(KC_GRAVE),KC_GRAVE,   RALT(KC_T)/*ё*/,      KC_NO,       /* | */    KC_NO,        KC_Y,    KC_BSLASH,  LSFT(KC_BSLASH),RALT(KC_BSLASH),   KC_NO,       KC_NO,       KC_NO,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          KC_BSPACE,      KC_NO,      LSFT(KC_9),LSFT(KC_LBRACKET),KC_LBRACKET,  KC_MINUS,    /*NO_KEY*/    /* | */   /*NO_KEY*/     KC_EQUAL,    KC_RBRACKET,LSFT(KC_RBRACKET),LSFT(KC_0),   KC_NO,    KC_NO,         KC_NO,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
         LCTL(KC_LSFT),      KC_NO,       LCTL(KC_S),       KC_NO,        KC_NO,   LSFT(KC_MINUS),  KC_NO,      /* | */     KC_NO,  LSFT(KC_EQUAL), RALT(KC_M)/*ъ*/, RALT(KC_COMM),RALT(KC_DOT),KC_NO, RCTL(KC_RSFT),  /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          /*NO_KEY*/    LCTL(KC_LALT),  KC_LCTL,       KC_LALT,     KC_NO,         KC_NO,       KC_NO,        /* | */     KC_NO,       KC_NO,       KC_RSFT,   KC_LALT,       KC_RCTL,  RCTL(KC_LALT)  /*NO_KEY*/     /*NO_KEY*/
     //└─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┘  /* | */ └─────────────┴─────────────┴─────────────┴─────────────┴───────────┴────────────┴──────────────┴─────────────┘
        ),

     [LIN_FN1] = LAYOUT(
     //┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐          ┌─────────────┬─────────────┬─────────────┬─────────────┬───────────┬────────────┬──────────────┬─────────────┐
          KC_NO,         KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,     KC_NO,      /* | */   KC_NO,        KC_F6,           KC_F7,       KC_F8,           KC_F9,         KC_F10,       KC_NO,         /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
           KC_ESC,        KC_NO,    LIN_TAB_LEFT, LIN_SW_LANG_ENG,LIN_TAB_RIGHT,LIN_SW_LANG_RUS, KC_NO,     /* | */    KC_NO,        KC_HOME,      KC_PGDOWN,     KC_PGUP,     KC_END,   KC_PSCREEN,   KC_NO,         KC_NO,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          KC_DELETE,    KC_PAUSE,   LIN_SW_TO_WS_UP,ALT_TAB,LIN_SW_TO_WS_DOWN,LIN_LAUNCHER,/*NO_KEY*/    /* | */   /*NO_KEY*/     KC_LEFT,       KC_DOWN,     KC_UP,        KC_RIGHT,  KC_INSERT,       KC_RGUI,      KC_ENTER,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          KC_LSFT,      KC_NO,         KC__MUTE,    KC__VOLDOWN,   KC__VOLUP,  LIN_CLOSE_TAB,    KC_NO,      /* | */     KC_NO,   LIN_MV_DISP_LEFT,LIN_MV_WS_DOWN,LIN_MV_WS_UP,LIN_MV_DISP_RIGHT,KC_NO,   KC_RSFT,      /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          /*NO_KEY*/   LCTL(KC_LALT),  KC_LCTL,     KC_LALT,   KC_NO,         KC_NO,       KC_NO,        /* | */     KC_NO,       KC_NO,         KC_LSFT,    KC_LALT,       KC_RCTL,  RCTL(KC_LALT)   /*NO_KEY*/     /*NO_KEY*/
     //└─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┘  /* | */ └─────────────┴─────────────┴─────────────┴─────────────┴───────────┴────────────┴──────────────┴─────────────┘
        ),

    [LIN_FN2] = LAYOUT(
     //┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐          ┌─────────────┬─────────────┬─────────────┬─────────────┬───────────┬────────────┬──────────────┬─────────────┐
        TG(LIN_FN2),     KC_NO,         KC_NO,         KC_NO,    LIN_CLOSE_WIN, LIN_MAX_WIN,  TG(LIN_FN2),      /* | */   KC_NO,        KC_NO,           KC_NO,       KC_NO,           KC_NO,       KC_NO,       KC_NO,         /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
           KC_ESC,        KC_NO,        KC_NO,       KC_UP,           KC_NO,       KC_SPC,       KC_NO,      /* | */   KC_NO,        KC_NO,           KC_NO,       KC_NO,           KC_NO,       KC_NO,       KC_NO,       KC_NO,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          KC_DELETE,      KC_NO,         KC_LEFT,    KC_DOWN,      KC_RIGHT,       KC_NO,    /*NO_KEY*/    /* | */   /*NO_KEY*/    KC_NO,          KC_BSPACE,   KC_NO,        KC_DELETE,     KC_NO,    KC_NO,      KC_ENTER,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          KC_LSFT,      KC_NO,         KC__MUTE,       KC__VOLDOWN,           KC__VOLUP,       KC_NO,           KC_NO,      /* | */     KC_NO,      KC_NO,           KC_NO,       KC_NO,        KC_NO,   KC_NO,      KC_RSFT,        /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          /*NO_KEY*/    LCTL(KC_LALT),  KC_LCTL,     KC_LALT,      KC_NO,         KC_NO,       KC_NO,        /* | */     KC_NO,       KC_NO,         KC_SPC,     KC_RCTL,        KC_RALT,    KC_RCTL     /*NO_KEY*/     /*NO_KEY*/
     //└─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┘  /* | */ └─────────────┴─────────────┴─────────────┴─────────────┴───────────┴────────────┴──────────────┴─────────────┘
        ),


    [SPECIAL] = LAYOUT(
     //┌─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────┐          ┌─────────────┬─────────────┬─────────────┬─────────────┬───────────┬────────────┬──────────────┬─────────────┐
         KC_NO,         DF(LIN),         KC_NO,         KC_NO,         KC_NO,         KC_NO,      RESET,      /* | */   RESET,        KC_NO,           KC_NO,       KC_NO,           KC_NO,       KC_NO,       KC_NO,         /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
           KC_ESC,        KC_NO,        KC_NO,       KC_NO,           KC_NO,       KC_NO,       KC_NO,      /* | */   KC_NO,        KC_NO,           KC_NO,       KC_NO,           KC_NO,       KC_NO,       KC_LBRC,       KC_RBRC,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          KC_BSPACE,      KC_NO,         KC_NO,         KC_NO,         KC_NO,       KC_NO,    /*NO_KEY*/    /* | */   /*NO_KEY*/    KC_NO,           KC_NO,       KC_NO,           KC_NO,     KC_SCOLON,    KC_QUOTE,      KC_ENTER,
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          KC_LSFT,      KC_NO,           KC_NO,       KC_NO,           KC_NO,       KC_NO,           KC_NO,      /* | */     KC_NO,      KC_NO,           KC_NO,       KC_COMM,        KC_DOT,   KC_SLSH,      KC_RSFT,        /*NO_KEY*/
     //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤  /* | */ ├─────────────┼─────────────┼─────────────┼─────────────┼───────────┼────────────┼──────────────┼─────────────┤
          /*NO_KEY*/    KC_LCTL,      KC_LALT,       KC_LCTL,     KC_NO,         KC_NO,       KC_NO,        /* | */     KC_NO,       KC_NO,         KC_SPC,     KC_RCTL,        KC_RALT,    KC_RCTL     /*NO_KEY*/     /*NO_KEY*/
     //└─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┴─────────────┘  /* | */ └─────────────┴─────────────┴─────────────┴─────────────┴───────────┴────────────┴──────────────┴─────────────┘
        ),

};



