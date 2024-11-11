// Description: A payload designed to push keyboard and hotkey usage further.
// Opens the windows run tab using Win + R hotkey. Opens the notepad application as it is installed by default on all Windows computers.
// Types some text into the notepad and saves it to documents.

#include <Keyboard.h> // Library to access the keyboard

void setup() {
  blink_led();
  Keyboard.begin(); // Initialise the keyboard
  delay(3000); // Delay to ensure that ducky initialises properly
  Payload();
}

// Blink the LED for 30 seconds. Green for the first 40 and red for the final 10. Gives warning for when a payload will execute and time to do re-upload etc.
void blink_led(){
  // Blink LED for the first 30 seconds
  for (int i = 0; i < 30; i++){
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

void retrieveUsername() {
  int keys[] = {KEY_LEFT_GUI, 'r'};
  typeKeyCombination(keys, 2);
  delay(1000);

  // Open the powershell as an administrator
  Keyboard.print("cmd");
  keyboardInput(KEY_RETURN);
  delay(1000);
  Keyboard.print("powershell");
  keyboardInput(KEY_RETURN);
  delay(1000);
  Keyboard.print("Start-Process powershell -Verb RunAs");
  keyboardInput(KEY_RETURN);
  delay(1000);
  keyboardInput(KEY_LEFT_ARROW);
  delay(500);
  keyboardInput(KEY_RETURN);
  delay(2000);


  // Type the command to get the full path details
  Keyboard.print("\"C:\\Users\\$env:USERNAME\\Documents\\hello_world.txt\" | Out-File -FilePath 'C:\\username.txt'");

  delay(5000);
  keyboardInput(KEY_RETURN);
  delay(2000);

  // Close the powershell and command prompt
  int desktop[] = {KEY_LEFT_GUI, 'd'}; // Example combination: Windows + D
  int altf4[] = {KEY_LEFT_ALT, KEY_F4};
  typeKeyCombination(altf4, 2);
  delay(1000);
  typeKeyCombination(altf4, 2);
  delay(1000);
  delay(2000); // Delay to ensure the shortcut is executed properly

  // Open the username file
  int runapp[] = {KEY_LEFT_GUI,'r'}; // Windows + R (opens run)
  typeKeyCombination(runapp, 2);
  delay(1000);
  Keyboard.print("notepad C:\\username.txt");
  keyboardInput(KEY_RETURN);
  delay(1000);

  // Read the username from the file
  int keys3[] = {KEY_LEFT_CTRL, 'a'}; // Ctrl A to select all
  typeKeyCombination(keys3, 2);
  delay(1000);

  int keys4[] = {KEY_LEFT_CTRL, 'c'}; // Ctrl C to copy
  typeKeyCombination(keys4, 2);
  delay(1000);

  // Close Notepad
  int keys2[] = {KEY_LEFT_ALT, KEY_F4};
  typeKeyCombination(keys2, 2);
  delay(1000);
}

void Payload() {
  int keys[] = {KEY_LEFT_GUI, 'd'}; // Example combination: Windows + D
  typeKeyCombination(keys, 2); // Type the key combination
  delay(2000); // Delay to ensure the shortcut is executed properly
  int keys2[] = {KEY_LEFT_GUI, 'r'}; // Windows + R (opens run)
  typeKeyCombination(keys2,2);
  delay(1000); // Wait a second for run to open.

  // Retrieve the path to save Notepad file to documents.
  // Elevates permissions of powershell to administrator and retrieves username + appended path details. Copies to clipboard.
  retrieveUsername();
  delay(2000);

  // Open the Notepad
  typeKeyCombination(keys2,2);
  Keyboard.print("notepad");
  keyboardInput(KEY_RETURN);
  delay(1000);

  // Type "Hello World" in the Notepad
  Keyboard.print("Hello World!");
  delay(1000);

  // Save the file
  int keys3[] = {KEY_LEFT_CTRL, 's'}; // Ctrl S combination
  typeKeyCombination(keys3, 2);
  delay(2000);

  // Paste the path name and hit enter.
  int pastecombo[] = {KEY_LEFT_CTRL, 'v'}; // Ctrl V to paste
  typeKeyCombination(pastecombo, 2);
  delay(1000);
  keyboardInput(KEY_RETURN);
  delay(1000);

  // Close the file
  int altf44[] = {KEY_LEFT_ALT, KEY_F4};
  typeKeyCombination(altf44, 2);
  delay(1000);


}

void loop() {
  // put your main code here, to run repeatedly:

}
