// Description: A payload designed to open a YouTube link using the users default browser.

#include <Keyboard.h> // Library to access the keyboard

void setup() {
  blink_led();
  Keyboard.begin(); // Initialise the keyboard
  delay(3000); // Delay to ensure that ducky initialises properly
  Payload();
}

void Payload() {
  int keys[] = {KEY_LEFT_GUI, 'd'}; // Example combination: Windows + D
  typeKeyCombination(keys, 2); // Type the key combination
  delay(2000); // Delay to ensure the shortcut is executed properly
  int keys2[] = {KEY_LEFT_GUI, 'r'}; // Windows + R (opens run)
  typeKeyCombination(keys2,2);
  delay(1000); // Wait a second for run to open.

  // Open the Command Prompt
  Keyboard.print("cmd");
  keyboardInput(KEY_RETURN);
  delay(1000);

  // Open youtube link in default browser.
  Keyboard.print("start "" https://www.youtube.com/watch?v=hhUb5iknVJs");
  delay(1000);
  keyboardInput(KEY_RETURN);
  delay(1000);
}

// Blink the LED for 20 seconds.
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