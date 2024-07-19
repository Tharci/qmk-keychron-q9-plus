# Keychron Q9 Plus

![Keychron Q9 Plus](https://i.imgur.com/Yp9K7Gsh.jpg)

This project is a fork of the QMK framework for the [Keychron Q9 QMK Custom Mechanical Keyboard](https://www.keychron.com/products/keychron-q9-qmk-custom-mechanical-keyboard).


## Build

- Build the firmware by running `make keychron/q9_plus/ansi_encoder:tharci`.

> See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information.

## Flash

1. **Reset Key**: Hold down the key located at *K00*, programmed as *TAB* while plugging in the keyboard.
2. Flash the firmware using QMK Toolbox.

## Layout

### `Caps`

**Single tap** on `Caps` activates *Caps Word*.

**Single tap hold** on `Caps` activates *Navigation layer*.

**Double tap** on `Caps` toggles caps lock.

**Double tap hold** on `Caps` activates *Navigation layer* with shift modifier applied.

### `Left space`

`Left space` is just a regular space. *Tabloop* can be activated by `Caps`+`Left space` to loop between windows.

### `Right space`

**Single tap** on `Right space` activates *Space Num*.

**Single tap hold** on `Right space` activates *Numeric layer*.

## Features

### Caps Word

*Caps Word* activates caps lock as long as only the allowed keys are pressed. It deactivates when any other key is pressed, or nothing is pressed for 5 seconds. The allowed keys are the following:

- Alphabetic characters
- Numeric characters
- Backspace
- Delete
- Left shift

### Space Num

*Space Num* activates the *Numeric layer* as long as only the allowed keys are pressed. It deactivates when any other key is pressed, or nothing is pressed for 5 seconds. The allowed keys are the following:

- Numeric characters
- Comma
- Dot
- Backspace

### Knob Utils

*Knob Utils* provides a set of keycodes and functionalities to conveniently switch between what it does without having to define separate layers for each functionality. Assign the keycodes `KC_KNOB_LEFT` and `KC_KNOB_RIGHT` to the knob, then swith between the knob modes using `set_knob_mode`, or by assigning and pressing a `KC_KNOB_{}` keycode. For example, by pressing the `KC_KNOB_VOLUME` keycode, the knob mode switches to setting the volume.

Keycodes:

- `KC_KNOB_LEFT`: Keycode for turning the knob left.
- `KC_KNOB_RIGHT`: Keycode for turning the knob right.
- `KC_KNOB_VOLUME`: Swith knob mode to setting the volume - decrease/increase volume, toggle mute.
- `KC_KNOB_MEDIA`: Swith knob mode to media keys - previous/next, toggle play.
- `KC_KNOB_BRIG`: Swith knob mode to setting the brightness - decrease/increase brightness.
- `KC_KNOB_RGB_MODE`: Swith knob mode to setting the rgb effect - previous/next effect, toggle effect.
- `KC_KNOB_RGB_BRIG`: Swith knob mode to setting the brightness of the rgb effect - decrease/increase brightness.
- `KC_KNOB_RGB_COLOR`: Swith knob mode to setting the hue of the rgb effect - previous/next hue.
- `KC_KNOB_RGB_SAT`: Swith knob mode to setting the saturation of the rgb effect - decrease/increase saturation. 
- `KC_KNOB_SPEED`: Swith knob mode to setting the speed of the rgb effect - decrease/increase speed. 

### Tabloop

*Tabloop* is used to loop between windows.

### Gaming Numpad

*Gaming Numpad* switches the arrow keys to the numpad arrows and lights them up.


