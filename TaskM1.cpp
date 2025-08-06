// turn LED on while button is held down,
// off when button is released, using pin
// change interrupt instead of polling

// interrupt service routine for pin change interrupt 0 vector
ISR(PCINT0_vect){  
  PORTD ^= 1<<7; // toggle pin 7
  Serial.println("Interrupt triggered"); 
  // determine rising or falling edge based on
  // whether pin 12 is high or low
  if(PINB & 0b00010000){ 
    Serial.println("Rising edge (button pushed)");
  }
  else{
    Serial.println("Falling edge (button released)");
  }
}

int main(void){
  // code that only runs once when program starts
  // need to to enable the right pin change interrupt
  // see datasheet page 92 and Arduino pinout diagram
  // pin 12 is PCINT4 which is part of Pin Change
  // Mask Register 0
  PCMSK0 = 1 << 4;    // enables PCINT4 (individual pin)
  PCICR = 0b00000001; // enables pin change ISR 0
  sei(); // enable interrupts
  Serial.begin(9600);  // initialize serial communication
  DDRD = 0b10000000; // set LED pin as output
  while(1){  
    // don't actually need any code here!
    // can put a delay here and button press will still work
    _delay_ms(1000);
  }
}