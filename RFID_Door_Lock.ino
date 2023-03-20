#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <Wire.h>
#include <RTClib.h>
/**
 * This code includes several libraries for different purposes. Here's a brief description of each library:
 * Keypad.h: A library for reading keypad inputs.
 * Servo.h: A library for controlling servo motors.
 * LiquidCrystal_I2C.h: A library for controlling LCD displays with an I2C interface.
 * MFRC522.h: A library for interacting with RFID readers that use the MFRC522 chip.
 * Wire.h: A library for I2C communication.
 * RTClib.h: A library for interacting with Real Time Clock (RTC) modules.
 * These libraries may be used in conjunction with one another to create a project that involves keypad inputs, servo motor control, LCD display, RFID reader interaction, I2C communication, and RTC module interaction.
*/

//These are constants that define the pins for the MFRC522 RFID reader.
#define SS_PIN 10
#define RST_PIN 9 

//This is an object of the MFRC522 class that is used to interact with the RFID reader.
MFRC522 mfrc522(SS_PIN, RST_PIN); 

//This is an object of the LiquidCrystal_I2C class that is used to control the LCD display.
LiquidCrystal_I2C lcd(0x27 , 2,1,0,4,5,6,7,3,POSITIVE);

//This is an object of the RTC_DS1307 class that is used to interact with the RTC module.
RTC_DS1307 rtc; 

//This is a 2D array that contains the names of the days of the week.
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; 

//This is a variable that is used to define the pin for the LED buzzer.
byte led=6; 

//These are constants that define the number of rows and columns in the keypad.
const byte ROWS = 4;
const byte COLS = 3; 

//This is a 2D array that contains the characters that correspond to each key on the keypad.
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
}; 

//These are arrays that define the pins for the rows and columns of the keypad.
byte rowPins[ROWS] = {2, 3, 4, A3};
byte colPins[COLS] = {A2, A1, A0}; 

//This is an object of the Keypad class that is used to read input from the keypad.
Keypad myKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//This is an object of the Servo class that is used to control the servo motor for the gate.
Servo gate_s; 

//This is a string that contains the admin password for the system.
String password ="1234"; 

//This is a string that is used to store input from the keypad.
String s; 

//This is a string that is used to store characters as they are entered on the keypad.
String c=""; 

//This is a string that contains the ID of a valid RFID card.
String card="0D 11 57 73"; 

//This is a variable that is used to toggle between servo and lock modes for the gate.(0-servo 1-lock)
int l_mode=0; 

void setup() {
  pinMode(led,OUTPUT); //This sets the LED buzzer pin as an output.
  digitalWrite(led,LOW); //This sets the initial state of the LED buzzer to low (off).
  lcd.begin(20, 4); //This initializes the LCD display with a size of 20 columns and 4 rows.
  Serial.begin(9600); //This initializes serial communication at a baud rate of 9600.
  gate_s.attach(5); //This attaches the servo motor to pin 5.
  SPI.begin(); //This initializes the SPI bus.
  mfrc522.PCD_Init(); //This initializes the RFID reader.
  mfrc522.PCD_DumpVersionToSerial(); //This prints the version information of the RFID reader to the serial monitor.
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (! rtc.begin()) { //rtc.begin(): This initializes the RTC module.
    Serial.println("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) { //rtc.isrunning(): This checks if the RTC module is running.
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //This sets the date and time for the RTC module if it is not running.
  }
  Serial.println("Ready"); //This prints "Ready" to the serial monitor to indicate that the setup function has completed.
}

  void loop() {
    rfid(); //This function reads data from the RFID reader.
    display(1); //This function displays the current date and time on the LCD display.
    char b = myKeypad.getKey(); //This reads a key press from the keypad and assigns it to the variable "b".
    if(b){ //This checks if a key has been pressed on the keypad.
      if(b != '#'){ //This checks if the key pressed is not the "#" key.
          lcd.setCursor(0,2);
          s= s+ b; //This concatenates the key press to the string "s".
          Serial.println(s); //This prints the current value of "s" to the serial monitor.
          lcd.print(s); //This displays the current value of "s" on the LCD display. 
      }
      else{ //This executes if the "#" key has been pressed.
        Serial.println(s); //This prints the final value of "s" to the serial monitor.
        check(s); //This function checks if the entered password matches the correct password or if the entered RFID card matches the authorized card.
        s=""; //This resets the "s" string to an empty string to start accepting a new input.
      }
    }
  }

void display(int n){
  Display_time(); //This function is not shown in the code, but it presumably displays the current date and time on the LCD display.
  switch(n){ //This statement creates a switch statement that checks the value of the "n" parameter.
    default: //If "n" doesn't match any of the cases below, this default case is executed.
     lcd.setCursor(0,1); //This sets the cursor position of the LCD display to the beginning of the second line.  
     lcd.print("Enter Password"); //This prints the string "Enter Password" on the LCD display.
  }
}

// This is a function called "check" that takes a single string parameter "pass"
void check(String pass){
  if(pass.equals(password) || pass.equals(card)) // Use an if statement to check if "pass" is equal to "password" or "card"
  {
    access(1); // Call the "access" function with a parameter value of 1
  }
  else if(pass.equals("01110")){ // If "pass" is equal to "01110", execute the following code block
    l_mode=(!l_mode);  // Toggle the value of "l_mode" using the "!" operator     
  }
  else // If "pass" is not equal to "password", "card", or "01110", execute the following code block
  {
    // Call the "access" function with a parameter value of 2
    access(2);
  }
}


// This is a function called "access" that takes a single integer parameter "a"
void access(int a){
  lcd.setCursor(0,3); // Set the cursor position of the LCD to the fourth row (position 3)
  
  // Use a switch statement to check the value of the "a" parameter
  switch(a)
  {
    case 1: // If the value of "a" is 1, execute the following code block
      lcd.print("   Granted     "); // Print "Granted" on the LCD screen
      digitalWrite(led,HIGH); // Turn on an LED using the digitalWrite function
      gate(); // Call a function called "gate" to open the gate
      delay(500); // Delay for 500 milliseconds
    break;

    // If the value of "a" is 2, execute the following code block
    case 2:
      lcd.print("   Denied      "); // Print "Denied" on the LCD screen
      delay(500); // Delay for 500 milliseconds
    break;
  }
  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0,0); // Set the cursor position of the LCD to the first row (position 0)
}

// This is a function called "gate" that does not take any parameters
void gate(){
  // Use a switch statement to check the value of the variable "l_mode"
  switch(l_mode){
    case 0: // If the value of "l_mode" is 0, execute the following code block
      // Use a for loop to gradually close the gate
      for(int i=100;i>=0;i--)
      {
        gate_s.write(i); // Set the position of the gate using the gate_s servo object
        delay(15); // Delay for 15 milliseconds
      }
      
      delay(2000); // Delay for 2 seconds to keep the gate closed
      digitalWrite(led,LOW); // Turn off an LED using the digitalWrite function     
      // Use a for loop to gradually open the gate
      for(int i=0;i<=100;i++)
      {
        gate_s.write(i); // Set the position of the gate using the gate_s servo object
        delay(15); // Delay for 15 milliseconds
      }
    break;

    // If the value of "l_mode" is 1, execute the following code block
    case 1:
      digitalWrite(5,HIGH);  // Turn on a motor or some other device connected to pin 5
      delay(2000); // Delay for 2 seconds to keep the device turned on
      digitalWrite(led,LOW); // Turn off an LED using the digitalWrite function
      digitalWrite(5,LOW); // Turn off the motor or device connected to pin 5
    break;
 }
}


// This is a function called "rfid" with no parameters
void rfid(){
  if ( ! mfrc522.PICC_IsNewCardPresent()) // Check if a new RFID card is present; if not, return from the function
    return;
  
  if ( ! mfrc522.PICC_ReadCardSerial()) // Read the serial number of the RFID card; if it fails, return from the function
    return;
  
  String content= ""; // Create an empty string called "content" to store the UID of the RFID card
 
  // Loop through each byte of the UID and convert it to a string of hexadecimal characters
  for (int i = 0; i < mfrc522.uid.size; i++) 
  {
    // Concatenate the hexadecimal string representation of the current byte to the "content" string
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  content.toUpperCase(); // Convert the "content" string to all uppercase characters
  Serial.println(content.substring(1)+" ");  // Print the RFID tag to the Serial Monitor, starting from the second character (to remove leading space)
  check(content.substring(1)); // Call the "check" function with the UID of the RFID tag as the parameter
  content=""; // Reset the "content" string to an empty string
}


// This function displays the current date and time on an LCD screen
void Display_time(){
  DateTime now = rtc.now(); // Get the current date and time from the RTC module
  int h=((now.hour()>12)?(now.hour()%12):now.hour()); // Determine the hour in 12-hour format with AM/PM indicator
  String hr=h>9?String(h):"0"+String(h); // Convert the hour to a String with leading zero if necessary
  String min=now.minute()>9?String(now.minute()):"0"+String(now.minute()); // Convert the minute to a String with leading zero if necessary
  String clck=(now.hour()>12)?" PM":" AM"; 
  String time_n=hr+":"+min+clck+" "; // Determine whether the time is in the AM or PM and add to the time string
  String date=String(now.day(),DEC)+"/"+String(now.month(),DEC)+"/"+String(now.year(),DEC); // Create a string with the full date in the format "day/month/year"
  String time=time_n+date; // Combine the time and date strings into a single string
  lcd.setCursor(0,0); // Set the cursor of the LCD screen to the top left corner
  lcd.print(time); // Print the time and date string on the LCD screen
}





