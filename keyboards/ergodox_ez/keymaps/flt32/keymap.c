#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_jp.h"
#include "led.h"

#define BASE 0 // default layer
#define KFNC 1 // functions layer
#define MDIA 2 // media keys
#define SYMB 3 // symbols

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

enum {
    TD_LANG = 0
};

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PLOVER,
    LOWER,
    RAISE,
    BACKLIT,
    EXT_PLV,
    DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Meh/Esc|   1  |   2  |   3  |   4  |   5  | TGL2 |           |Delete|   6  |   7  |   8  |   9  |   0  |    -   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | LANG |           | Ins  |   Y  |   U  |   I  |   O  |   P  |    @   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | TGL1   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    :   |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | S- / \ |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | Gui  | App  | Alt  | MO2  |                                       | F2   | F3   | F4   | F5   |  \   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F6   | F7   |       | F8   | F9   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | MHEN |       | KANA |      |      |
 *                                 | Space|MO3   |------|       |------|Back  |Enter |
 *                                 |      |      | Caps |       |Space |space |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        MEH_T(KC_ESC),  KC_1,         KC_2,   KC_3,     KC_4,   KC_5,   TG(MDIA),
        KC_TAB,         KC_Q,         KC_W,   KC_E,     KC_R,   KC_T,   TD(TD_LANG),
        TG(KFNC),       KC_A,         KC_S,   KC_D,     KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,     KC_V,   KC_B,   JP_LBRC,
        KC_LCTRL,       KC_LGUI,      KC_APP, KC_LALT,  MO(MDIA),
                                              KC_F6,  KC_F7,
                                                               KC_MHEN,
                                               KC_SPC,MO(SYMB),LSFT(KC_CAPS),
        // right hand
             KC_DEL,      KC_6,   KC_7,    KC_8,   KC_9,   KC_0,           JP_MINS,
             KC_INS,      KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,           JP_AT,
                          KC_H,   KC_J,    KC_K,   KC_L,   JP_SCLN,        JP_COLN,
             JP_RBRC,     KC_N,   KC_M,    JP_COMM,JP_DOT, KC_SLSH,        SFT_T(JP_BSLS),
                                  KC_F2,   KC_F3,  KC_F4,  KC_F5,          JP_YEN,
             KC_F8,          KC_F9,
             KC_KANA,
             KC_SPC,KC_BSPC, KC_ENT
    ),

// function-layer
[KFNC] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      | Home |PgUp  | PSCR |Break | PLAY1| REC1   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | End  |PgDown|      |      | PLAY2| REC2   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down | Up   | Right|      | RECSTOP|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_HOME, KC_PGUP, KC_PSCR, KC_BRK,  DYN_MACRO_PLAY1, DYN_REC_START1,
       KC_TRNS,  KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, DYN_MACRO_PLAY2, DYN_REC_START2,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,         DYN_REC_STOP,
       KC_TRNS,  XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX,         KC_TRNS,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |   ^  |   '  |   /  |   *  |   -  | NumLock|
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  F6  |  F7  |  F8  |  F9  | F10  |      |           |      | Yen  |   7  |   8  |   9  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  F11 |  F12 |  F13 |  F14 | F15  |------|           |------| Bspc |   4  |   5  |   6  |  Up  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  F16 |  F17 |  F18 |  F19 | F20  |      |           |      | Left |   1  |   2  |   3  |  ,   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  | Down |   .  | Right|       |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_TRNS,
       KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,KC_TRNS,
       KC_TRNS,KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,
       KC_TRNS,KC_F16, KC_F17, KC_F18, KC_F19, KC_F20,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, JP_CIRC,   JP_QUOT,KC_PSLS, KC_PAST,  KC_PMNS, KC_NLCK,
       KC_TRNS, JP_YEN,    KC_P7,  KC_P8,   KC_P9,    KC_PPLS, XXXXXXX,
                KC_BSPC,   KC_P4,  KC_P5,   KC_P6,    KC_UP,   XXXXXXX,
       KC_TRNS, KC_LEFT,   KC_P1,  KC_P2,   KC_P3,    JP_COMM, KC_TRNS,
                           KC_P0,  KC_DOWN, KC_PDOT,  KC_RGHT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
};

// control IME
void dance_lang (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_MHEN);
    unregister_code (KC_MHEN);
    register_code (KC_LANG2);
    unregister_code (KC_LANG2);
  } else {
    register_code (KC_HENK);
    unregister_code (KC_HENK);
    register_code (KC_LANG1);
    unregister_code (KC_LANG1);
  }
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LANG]  = ACTION_TAP_DANCE_FN (dance_lang)
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      default:
        break;
    }

  return state;
};
