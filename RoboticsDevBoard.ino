/*
 * Joystick
 * 
 * Joystick is connected to A0->A2
 * A0 = SW input (press joystick down) (NEEDS PULLUP RESISTOR)
 * A1 = Y-axis
 * A2 = X-axis
 * 
 * X and Y inputs return 0..1023 (normal arduino analog input)
 * SW returns 0 (not pressed) or 1 (pressed)
 */

// setup joystick
void joystick_setup() {
  // must enable pullup on SW input
  pinMode(A0, INPUT_PULLUP);
}

// read joystick switch
inline int joystick_sw() {
  return analogRead(A0) > 512 ? 0 : 1;
}

// read joystick y
inline int joystick_y() {
  return analogRead(A1);
}

// read joystick x
inline int joystick_x() {
  return analogRead(A2);
}

/*
 * Servo
 * 
 * Servo connectors are provided on pins 7->12
 * Use the following to access the servos as required
 */

// include servo API
#include <Servo.h>

// define one for each servo required
// for the sample app, only servo12 is used...
//#define SERVO7
//#define SERVO8
//#define SERVO9
//#define SERVO10
//#define SERVO11
#define SERVO12

// servo objects
#ifdef SERVO7
Servo servo7;
#endif
#ifdef SERVO8
Servo servo8;
#endif
#ifdef SERVO9
Servo servo9;
#endif
#ifdef SERVO10
Servo servo10;
#endif
#ifdef SERVO11
Servo servo11;
#endif
#ifdef SERVO12
Servo servo12;
#endif

// set up enabled servos (timings are chosen for full range of cheap 9m micro servos)
void servo_setup() {
#ifdef SERVO7
  servo7.attach(7, 400, 2600);
#endif
#ifdef SERVO8
  servo8.attach(8, 400, 2600);
#endif
#ifdef SERVO9
  servo9.attach(9, 400, 2600);
#endif
#ifdef SERVO10
  servo10.attach(10, 400, 2600);
#endif
#ifdef SERVO11
  servo11.attach(11, 400, 2600);
#endif
#ifdef SERVO12
  servo12.attach(12, 400, 2600);
#endif
}

/*
 * Display is a SH1106 128x64 OLED on I2C
 * 
 * Code is configured for the u8g2 driver
 * Can use any examples but choose this display init:
 */
#include <U8x8lib.h>
U8X8_SH1106_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

// set up display
void display_setup() {
  u8x8.begin();
  u8x8.setFont(u8x8_font_amstrad_cpc_extended_f);    
  u8x8.clear();
}

/*
 * EVERYTHING ABOVE IS COMMON, REUSABLE CODE TO INIIALISE/USE THE DEV BOARD
 * 
 * Write your own setup()/loop() functions below
 */

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  // setup display
  display_setup();

  // setup joystick
  joystick_setup();

  // setup servos
  servo_setup();
}

void loop() {
  // serial console debugging example
  Serial.print("SW: ");
  Serial.println(joystick_sw());
  Serial.print("X: ");
  Serial.println(joystick_x());
  Serial.print("Y: ");
  Serial.println(joystick_y());

  // write to display example
  u8x8.setCursor(0,0);
  u8x8.print("Display Test!");
  u8x8.setCursor(0,1);
  u8x8.print("Y: ");
  u8x8.print(joystick_y());
  u8x8.println("    "); // print some extra spaces to clear the remains of longer numbers
  u8x8.print("X: ");
  u8x8.print(joystick_x());
  u8x8.println("    "); // print some extra spaces to clear the remains of longer numbers
  u8x8.print("SW: ");
  u8x8.println(joystick_sw());

  // servo write example
  servo12.write(map(joystick_x(), 0, 1023, 0, 180));
  delay(100);
}
