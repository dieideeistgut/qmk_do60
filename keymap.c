#include QMK_KEYBOARD_H
#include "action_layer.h"

// Helpful Defines
#define _______    KC_TRNS
#define FN_FNLY    MO(1)
#define FN_HMSP    MO(2)

// Layers
#define L_QWERTY   0
#define L_FUNCTION 1
#define L_HMSP 2

// Status Variables
static uint8_t layer = L_QWERTY;
static uint8_t caps  = 0;
uint8_t mod_state;

// SHIFT Masks
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))

// Used to check underglow status
extern rgblight_config_t rgblight_config;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    static uint8_t shift_mask;
    shift_mask = get_mods()&MODS_SHIFT_MASK;

    switch (keycode) {

        // Ä & ä
        case KC_A:
            if (mod_state & MOD_MASK_ALT) {
                if (record->event.pressed) {
                    unregister_code(KC_LALT);
                    unregister_code(KC_RALT);

                    if (shift_mask){
                        unregister_code(KC_LSFT);
                        unregister_code(KC_RSFT);
                        SEND_STRING(SS_LALT("u") SS_LSFT("a"));
                    }
                    else {
                        tap_code16(A(KC_U));
                        tap_code(KC_A);
                    }

                    set_mods(mod_state);
                }
                return false;
            }
            return true;
            break;

        // Ü & ü
        case KC_U:
            if (mod_state & MOD_MASK_ALT) {
                if (record->event.pressed) {
                    unregister_code(KC_LALT);
                    unregister_code(KC_RALT);

                    if (shift_mask){
                        unregister_code(KC_LSFT);
                        unregister_code(KC_RSFT);
                        SEND_STRING(SS_LALT("u") SS_LSFT("u"));
                    }
                    else {
                        tap_code16(A(KC_U));
                        tap_code(KC_U);
                    }

                    set_mods(mod_state);
                }
                return false;
            }
            return true;
            break;

        // Ö & ö
        case KC_O:
            if (mod_state & MOD_MASK_ALT) {
                if (record->event.pressed) {
                    unregister_code(KC_LALT);
                    unregister_code(KC_RALT);

                    if (shift_mask){
                        unregister_code(KC_LSFT);
                        unregister_code(KC_RSFT);
                        SEND_STRING(SS_LALT("u") SS_LSFT("o"));
                    }
                    else {
                        tap_code16(A(KC_U));
                        tap_code(KC_O);
                    }

                    set_mods(mod_state);
                }
                return false;
            }
            return true;
            break;

        // ß
        case KC_S:
            if (mod_state & MOD_MASK_ALT) {
                if (record->event.pressed) {
                    unregister_code(KC_LALT);
                    unregister_code(KC_RALT);
                    SEND_STRING(SS_LALT("s"));
                    set_mods(mod_state);
                }
                return false;
            }
            return true;
            break;

        // EUR ß€€€€€€€
        case KC_E:
            if (mod_state & MOD_MASK_ALT) {
                if (record->event.pressed) {
                    unregister_code(KC_LALT);
                    unregister_code(KC_RALT);
                    SEND_STRING(SS_LALT(SS_LSFT("2")));
                    set_mods(mod_state);
                }
                return false;
            }
            return true;
            break;

        }
        return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // QWERTY Layer
  [0] = LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_GRV,  KC_BSPC,   \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,   \
      FN_HMSP, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  _______,           KC_ENT,    \
      KC_LSFT, FN_FNLY, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_RSFT,  KC_SLSH,  KC_UP,   KC_SLSH,   \
      KC_LCTL, KC_LALT, KC_LGUI,                  _______, KC_SPC, _______,                 KC_RGUI, KC_RALT,  KC_LEFT,  KC_DOWN, KC_RIGHT),

  // Function Layer
  [1] = LAYOUT_all(
      RTSEN,   KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_GRV,   KC_DEL,  \
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD,  BL_TOGG, BL_INC,  _______, _______, _______, _______, _______,  _______,           _______, \
      FN_HMSP, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD, BL_BRTG, BL_DEC,  _______, _______, _______, _______, _______,  _______,           KC_ENT,  \
      KC_LSFT, _______, _______, KC_APP,  _______,  _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, KC_RSFT,  _______, KC_PGUP,  KC_INS,  \
      KC_LCTL, KC_LALT, KC_LGUI,                    _______, KC_SPC,  _______,                   KC_RGUI, KC_RALT,  KC_MRWD, KC_PGDN,KC_MFFD),

  // HAMMERSPOON LAYER
  [2] = LAYOUT_all(
      KC_ESC,      KC_1,    KC_2,    KC_3,     KC_4,      KC_5,    KC_6,   KC_7,   KC_8,      KC_9,    KC_0,    KC_MINS,  KC_EQL,       KC_GRV,      KC_BSPC,       \
      LCA(KC_TAB), KC_Q,    KC_W,    LCA(KC_E),KC_R,      KC_T,    KC_Y,   KC_U,   LCA(KC_I), KC_O,    KC_P,    KC_LBRC,  KC_RBRC,                   KC_BSLS,       \
      _______,     KC_A,    KC_S,    LCA(KC_D),LCA(KC_F), KC_G,    KC_H,   KC_J,   KC_K,      KC_L,    KC_SCLN, KC_QUOT,  _______,                   LCA(KC_ENT),   \
      KC_LSFT,     _______, KC_Z,    KC_X,     LCA(KC_C), KC_V,    KC_B,   KC_N,   KC_M,      KC_COMM, KC_DOT,  KC_RSFT,  KC_SLSH,      LCA(KC_UP),  KC_SLSH,       \
      KC_LCTL,     KC_LALT, KC_LGUI,                     _______, KC_SPC, _______,                    KC_RGUI, KC_RALT,  LCA(KC_LEFT), LCA(KC_DOWN),LCA(KC_RIGHT)),
};

// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
     [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
 };

// Loop
void matrix_scan_user(void) {
  // Empty
};

// Set underglow color base on caps lock state and layer
// Use _noeeprom methods to prevent underglow from enabling on restart.
// Color predefinitions in /quantum/rgblight_list.h
void set_underglow(void) {
    if (layer == L_QWERTY) {
        //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        rgblight_disable_noeeprom();
        return;
    }

    if (!rgblight_config.enable) rgblight_enable_noeeprom();
    if (rgblight_config.mode != 1) rgblight_mode_noeeprom(1);

    switch (layer) {
    case L_QWERTY:
        //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        rgblight_disable_noeeprom();
        break;
    case L_FUNCTION:
        //rgblight_sethsv_noeeprom_white();
        //rgblight_disable_noeeprom();
        //sethsv(HSV_TEAL, (LED_TYPE *)&led[0]);
        sethsv(50,43,78, (LED_TYPE *)&led[0]);
        sethsv(50,43,78, (LED_TYPE *)&led[15]);
        //sethsv(HSV_TEAL, (LED_TYPE *)&led[15]);
        rgblight_set();
        break;
    case L_HMSP:
        //rgblight_sethsv_noeeprom_turquoise();
        //rgblight_disable_noeeprom();
        //sethsv(HSV_MAGENTA, (LED_TYPE *)&led[0]);
        sethsv(50,43,78, (LED_TYPE *)&led[1]);
        sethsv(50,43,78, (LED_TYPE *)&led[14]);
        //sethsv(HSV_MAGENTA, (LED_TYPE *)&led[15]);
        rgblight_set();
        break;
    default:
        rgblight_disable_noeeprom();
        //rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        break;
    }
}

// Update layer and set underglow
//uint32_t layer_state_set_user(uint32_t state) {
//    int new_layer = biton32(state);
//    if (layer != new_layer) {
//        layer = new_layer;
//        set_underglow();
//    }
//    return state;
//}

// Update caps lock status and set underglow
void led_set_user(uint8_t usb_led) {
    int new_caps = usb_led & (1<<USB_LED_CAPS_LOCK);
    if (caps != new_caps) {
        caps = new_caps;
        set_underglow();
    }
}
