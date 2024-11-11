// Description: A payload designed to test keyboard usage. 
// Allows the user to type any key keys consecutively and use combination keys (hotkeys).
// Example usage uses a hotkey to close everything to return to desktop.
// Interesting observation is that PiP does not actually close with this hotkey could get in the way of mouse movements.

#include <Keyboard.h> // Library to access the keyboard

void setup() {
  // put your setup code here, to run once:
  blink_led();
  Keyboard.begin(); // Initialise the keyboard
  delay(1000); // Delay to ensure that ducky initialises properly
  int keys[] = {KEY_LEFT_GUI, 'd'}; // Example combination: Windows + D
  typeKeyCombination(keys, 2); // Type the key combination
  delay(10000); // Delay to avoid spamming the shortcut
}

// Blink the LED for 20 seconds. Green for the first 40 and red for the final 10. Gives warning for when a payload will execute and time to do re-upload etc.
void blink_led(){
  // Blink LED for the first 20 seconds
  for (int i = 0; i < 20; i++){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }

}

// Helper Function which uses the keyboard library to press and release a key.
void keyboardInput(int key) {
  Keyboard.press(key);
  delay(100); // Small delay to ensure the key press is registered
  Keyboard.release(key);
}

// Helper Function to type any combination of keypresses
void typeKeyCombination(int keys[], int length) {
  for (int i = 0; i < length; i++) {
    Keyboard.press(keys[i]);
  }
  delay(100); // Small delay to ensure all key presses are registered
  for (int i = 0; i < length; i++) {
    Keyboard.release(keys[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
