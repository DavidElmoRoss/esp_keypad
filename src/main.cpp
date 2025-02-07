/**********************************************************************
  Filename    : Get Input Characters
  Description : Call the Keypad function to set the matrix keyboard 
                and get the value for the matrix keyboard
                A - clears all attributes (bold,dim, colour etc.)
                B - chars in BOLD
                C - chars DIM
                D - chars RED
                # - chars MAGENTA
                * - chars YELLOW
  Author      : FreeNove modified by David Elmo Ross
  Modification: 2025/01/23
**********************************************************************/
#include <Keypad.h>

// define the symbols on the buttons of the keypad
char keys[4][4] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

unsigned char rowPins[4] = {27, 26, 25, 33};   // connect to the row pinouts of the keypad
unsigned char colPins[4] = {21, 22, 23, 19};   // connect to the column pinouts of the keypad

// initialize an instance of class NewKeypad
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);

void setup() {
  Serial.begin(115200);                       // Initialize the serial port and set the baud rate to 115200
  printf("\e[2J\e[12;35HKey Pressed   HEX");  // clear screen and set to (12,35)
  fflush(stdout);                             // flush this to screen
}

void loop() {
  // Get the character input
  char keyPressed = myKeypad.getKey();
  // If there is a character input, sent it to the serial port
  if (keyPressed) 
  {
    switch(keyPressed)
    {
      case 'A':   printf("\e[0m");     // clear all colours and modes
                  break;
      case 'B':   printf("\e[1m");     // letters in bold
                  break;
      case 'C':   printf("\e[2m");     // letters in dim
                  break;
      case 'D':   printf("\e[31m");    // letters in red
                  break;
      case '#':   printf("\e[35m");    // letters in magenta
                  break;
      case '*':   printf("\e[33m");    // letters in yellow
                  break;
      default:    break;               // no change for other characters
    }
    printf("\e[13;39H");               // position to (13,39)
    printf("%c",keyPressed);           // print keypressed as character
    printf("\e[13;50H%X",keyPressed);  // print hex equiv at (13,50)
    fflush(stdout);                    // fflush output to screen
  }
}
