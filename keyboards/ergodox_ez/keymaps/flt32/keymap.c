#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_jp.h"
#include "led.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

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
 * | Meh/Esc|   1  |   2  |   3  |   4  |   5  | TGL1 |           |Delete|   6  |   7  |   8  |   9  |   0  |    -   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Caps |           | Ins  |   Y  |   U  |   I  |   O  |   P  |    @   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | TDLANG |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |    :   |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | S- / \ |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl | Gui  | Alt  | ONE1 | MO2  |                                       | Left | Down | Up   | Right| MO1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F2   | F3   |       | F4   | App  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space|Backsp|------|       |------| Del  |Enter |
 *                                 |      |ace   | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        MEH_T(KC_ESC),  KC_1,         KC_2,   KC_3,     KC_4,   KC_5,   TG(SYMB),
        KC_TAB,         KC_Q,         KC_W,   KC_E,     KC_R,   KC_T,   KC_CAPS,
        TD(TD_LANG),    KC_A,         KC_S,   KC_D,     KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,     KC_V,   KC_B,   JP_LBRC,
        KC_LCTRL,       KC_LGUI,      KC_LALT,OSL(SYMB),MO(MDIA),
                                              KC_F2,  KC_F3,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_DEL,      KC_6,   KC_7,    KC_8,   KC_9,   KC_0,           JP_MINS,
             KC_INS,      KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,           JP_AT,
                          KC_H,   KC_J,    KC_K,   KC_L,   JP_SCLN,        JP_COLN,
             JP_RBRC,     KC_N,   KC_M,    JP_COMM,JP_DOT, KC_SLSH,        SFT_T(JP_BSLS),
                                  KC_LEFT, KC_DOWN,KC_UP,  KC_RGHT,        MO(SYMB),
             KC_F4,        KC_APP,
             KC_PGUP,
             KC_PGDN,KC_DEL, KC_ENT
    ),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  F1     |  F2  |  F3  |  F4  |  F5  |  F6  |      |           |      |  F7  |  F8  |  F9  |  F10 | F11  | F12    |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   ~  |   ^  | Yen  |      |           |      | Bspc |   7  |   8  |   9  |   /  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   [  |   `  |------|           |------| One0 |   4  |   5  |   6  |   *  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   )  |   ]  |   \  |      |           |      |   &  |   1  |   2  |   3  |   -  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |    , |   .  |   +  |=/MDIA  |
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
       KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6, KC_TRNS,
       KC_TRNS,JP_EXLM,JP_AT,  KC_TILD,JP_CIRC,JP_YEN,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, JP_LPRN,JP_LBRC,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,JP_RPRN,JP_RBRC,JP_BSLS,KC_TRNS,
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F7,     KC_F8,  KC_F9,   KC_F10,   KC_F11,  KC_F12,
       KC_TRNS, KC_BSPC,   KC_P7,  KC_P8,   KC_P9,    KC_PMNS, KC_TRNS,
                OSL(BASE), KC_P4,  KC_P5,   KC_P6,    KC_PAST, KC_TRNS,
       KC_TRNS, KC_AMPR,   KC_P1,  KC_P2,   KC_P3,    KC_PSLS, KC_TRNS,
                           KC_P0,  KC_PCMM, KC_PDOT,  KC_PPLS, LT(MDIA,KC_PEQL),
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | NumL | PSCR |Break | PLAY1| REC1   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      | Home |PgDown| PgUp | End  | PLAY2| REC2   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down | Up   | Right|      | RECSTOP|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Del  |MsWdow|MsWUp |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |BBack |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_DEL,  KC_WH_D, KC_WH_U, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_NLCK, KC_PSCR, KC_BRK,  DYN_MACRO_PLAY1, DYN_REC_START1,
       KC_TRNS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  DYN_MACRO_PLAY2, DYN_REC_START2,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,         DYN_REC_STOP,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS,         KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS,         KC_TRNS,
       KC_TRNS, KC_WBAK,
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
      default:
        break;
    }

  return state;
};
