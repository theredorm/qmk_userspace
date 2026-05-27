/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 * Copyright 2023 casuanoob <casuanoob@hotmail.com> (@casuanoob)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_BASE_MAC,
    LAYER_NUMERAL,
    LAYER_NUMERAL_MAC,
    LAYER_NAVIGATION,
    LAYER_NAVIGATION_MAC,
    LAYER_SYSTEM,
};

// Automatically enable sniping-mode on the pointer layer.
#define DILEMMA_AUTO_SNIPING_ON_LAYER LAYER_NAVIGATION
#define DILEMMA_MINIMUM_SNIPING_DPI 200
#define FLOW_TAP_TERM 150

#define DILEMMA_MINIMUM_DEFAULT_DPI 500
#define DILEMMA_DEFAULT_DPI_CONFIG_STEP 1

#define ESC_ESC KC_ESC
#define MO_NUM MO(LAYER_NUMERAL)
#define MO_NUM_MAC MO(LAYER_NUMERAL_MAC)

#define TAB_TAB KC_TAB
#define ENT_NUM LT(LAYER_NUMERAL, KC_ENT)
#define BSP_BSP KC_BSPC
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define PT_Z LT(LAYER_SYSTEM, KC_Z)
#define PT_SLSH LT(LAYER_SYSTEM, KC_SLSH)

#define ENT_NMC LT(LAYER_NUMERAL_MAC, KC_ENT)
#define SPC_NMC LT(LAYER_NAVIGATION_MAC, KC_SPC)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

enum tap_dances {
  TD_1 = 0,
  TD_2,
  TD_3,
  TD_4,
  TD_5,
  TD_6,
  TD_7,
  TD_8,
  TD_9,
  TD_0,
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_1] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_EXLM),
  [TD_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_AT),
  [TD_3] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_HASH),
  [TD_4] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_DLR),
  [TD_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_PERC),
  [TD_6] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_CIRC),
  [TD_7] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_AMPR),
  [TD_8] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_ASTR),
  [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LPRN),
  [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RPRN),
};

#define TD_KC_1 TD(TD_1)
#define TD_KC_2 TD(TD_2)
#define TD_KC_3 TD(TD_3)
#define TD_KC_4 TD(TD_4)
#define TD_KC_5 TD(TD_5)
#define TD_KC_6 TD(TD_6)
#define TD_KC_7 TD(TD_7)
#define TD_KC_8 TD(TD_8)
#define TD_KC_9 TD(TD_9)
#define TD_KC_0 TD(TD_0)

enum combos {
  UI_RPRN,
  ER_LPRN,
  JK_WIN_EQUAL,
  JK_MAC_EQUAL,
};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM jk_win_combo[] = {LCTL_T(KC_J), LGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM jk_mac_combo[] = {LGUI_T(KC_J), LCTL_T(KC_K), COMBO_END};

combo_t key_combos[] = {
  [UI_RPRN] = COMBO(ui_combo, KC_RIGHT_PAREN),
  [JK_WIN_EQUAL] = COMBO(jk_win_combo, KC_EQUAL),
  [JK_MAC_EQUAL] = COMBO(jk_mac_combo, KC_EQUAL),
};

const key_override_t semicolon_colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t tilde_grave_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_TILD, KC_GRAVE);
const key_override_t underscore_minus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDS, KC_MINUS);
const key_override_t pipe_backslash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_BSLS);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &semicolon_colon_key_override,
    &tilde_grave_key_override,
    &underscore_minus_key_override,
    &pipe_backslash_key_override
};

// clang-format off
/** \brief QWERTY layout (3 rows, 10 columns). */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x5_3(
    KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,              KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,
    LSFT_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    LCTL_T(KC_F),    KC_G,              KC_H,            LCTL_T(KC_J),    LGUI_T(KC_K),    LALT_T(KC_L),    LSFT_T(KC_QUOT),
    PT_Z,            RALT_T(KC_X),    KC_C,            KC_V,            KC_B,              KC_N,            KC_M,            KC_COMM,         RALT_T(KC_DOT),  PT_SLSH,
                                      MO_NUM,          TAB_TAB,         SPC_NAV,           ENT_NUM,         BSP_BSP,         ESC_ESC
  ),

  [LAYER_NUMERAL] = LAYOUT_split_3x5_3(
    XXXXXXX,         XXXXXXX,         XXXXXXX,         KC_PIPE,         XXXXXXX,           KC_UNDS,         TD_KC_7,         TD_KC_8,         TD_KC_9,         TD_KC_0,
    KC_LSFT,         KC_LALT,         KC_LGUI,         KC_LCTL,         XXXXXXX,           KC_EQUAL,        TD_KC_4,         TD_KC_5,         TD_KC_6,         KC_COLN,
    KC_TILD,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,           XXXXXXX,         TD_KC_1,         TD_KC_2,         TD_KC_3,         KC_SLSH,
                                      MO_NUM,          KC_LBRC,         KC_RBRC,           KC_ENT,          BSP_BSP,         ESC_ESC
  ),

  [LAYER_NAVIGATION] = LAYOUT_split_3x5_3(
    XXXXXXX,         XXXXXXX,         XXXXXXX,         KC_VOLD,         KC_VOLU,           MS_WHLU,         LCTL(KC_LEFT),   XXXXXXX,         LCTL(KC_RGHT),   XXXXXXX,
    KC_LSFT,         KC_LALT,         KC_LGUI,         KC_LCTL,         MS_BTN1,           KC_LEFT,         KC_DOWN,         KC_UP,           KC_RGHT,         KC_COLN,
    KC_TILD,         KC_RALT,         XXXXXXX,         XXXXXXX,         DRGSCRL,           MS_WHLD,         KC_HOME,         XXXXXXX,         KC_END,          KC_SLSH,
                                      MO_NUM,          TAB_TAB,         _______,           KC_ENT,          BSP_BSP,         ESC_ESC
  ),


  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  [LAYER_SYSTEM] = LAYOUT_split_3x5_3(
    XXXXXXX,         XXXXXXX,         DF(LAYER_BASE),  XXXXXXX,         QK_BOOT,           QK_BOOT,         XXXXXXX,         DF(LAYER_BASE_MAC), XXXXXXX,      XXXXXXX,
    EE_CLR,          DT_DOWN,         DT_UP,           DT_PRNT,         XXXXXXX,           XXXXXXX,         XXXXXXX,         XXXXXXX,            XXXXXXX,      EE_CLR,
    XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,           XXXXXXX,         XXXXXXX,         XXXXXXX,            XXXXXXX,      XXXXXXX,
                                      XXXXXXX,         XXXXXXX,         KC_CAPS,           KC_CAPS,         XXXXXXX,         XXXXXXX
  ),
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  [LAYER_BASE_MAC] = LAYOUT_split_3x5_3(
    KC_Q,            KC_W,            KC_E,            KC_R,            KC_T,              KC_Y,            KC_U,            KC_I,            KC_O,            KC_P,
    LSFT_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    LCTL_T(KC_F),    KC_G,              KC_H,            LCTL_T(KC_J),    LGUI_T(KC_K),    LALT_T(KC_L),    LSFT_T(KC_QUOT),
    PT_Z,            RALT_T(KC_X),    KC_C,            KC_V,            KC_B,              KC_N,            KC_M,            KC_COMM,         RALT_T(KC_DOT),  PT_SLSH,
                                      MO_NUM_MAC,      TAB_TAB,         SPC_NMC,           ENT_NMC,         BSP_BSP,         ESC_ESC
  ),

  [LAYER_NUMERAL_MAC] = LAYOUT_split_3x5_3(
    XXXXXXX,         XXXXXXX,         XXXXXXX,         KC_PIPE,         XXXXXXX,           KC_UNDS,         TD_KC_7,         TD_KC_8,         TD_KC_9,         TD_KC_0,
    KC_LSFT,         KC_LALT,         KC_LGUI,         KC_LCTL,         XXXXXXX,           KC_EQUAL,        TD_KC_4,         TD_KC_5,         TD_KC_6,         KC_COLN,
    KC_TILD,         XXXXXXX,         XXXXXXX,         XXXXXXX,         XXXXXXX,           XXXXXXX,         TD_KC_1,         TD_KC_2,         TD_KC_3,         KC_SLSH,
                                      MO_NUM_MAC,      KC_LBRC,         KC_RBRC,           KC_ENT,          BSP_BSP,         ESC_ESC
  ),

  [LAYER_NAVIGATION_MAC] = LAYOUT_split_3x5_3(
    XXXXXXX,         XXXXXXX,         XXXXXXX,         KC_VOLD,         KC_VOLU,           MS_WHLU,         LGUI(KC_LEFT),   XXXXXXX,         LGUI(KC_RGHT),   XXXXXXX,
    KC_LSFT,         KC_LALT,         KC_LGUI,         KC_LCTL,         MS_BTN1,           KC_LEFT,         KC_DOWN,         KC_UP,           KC_RGHT,         KC_COLN,
    KC_TILD,         KC_RALT,         XXXXXXX,         XXXXXXX,         DRGSCRL,           MS_WHLD,         KC_HOME,         XXXXXXX,         KC_END,          KC_SLSH,
                                      MO_NUM_MAC,      TAB_TAB,         _______,           KC_ENT,          BSP_BSP,         ESC_ESC
  ),
};
// clang-format off

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
