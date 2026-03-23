#define DATA 6 // pin 14
#define LATCH 8 // pin 12
#define CLOCK 10 // pin 11
int answer = 0;
void setup()
{
pinMode(LATCH, OUTPUT); // set up pins
pinMode(CLOCK, OUTPUT);
pinMode(DATA, OUTPUT);
Serial.begin(9600);
randomSeed(analogRead(0)); // initialize the random number generator
displayNumber(0); // clear the LEDs
}
void displayNumber(byte a)
{
digitalWrite(LATCH, LOW);

shiftOut(DATA, CLOCK, MSBFIRST, a);
digitalWrite(LATCH, HIGH);
}
void getAnswer()
{
// receive answer
int z = 0;
Serial.flush();
while (Serial.available() == 0)
{
// wait for serial buffer input
}
// one character of serial data is available, begin calculating
while (Serial.available() > 0)
{
// move digit to next column
answer = answer * 10;
z = Serial.read() - '0';
// add this digit to the total value
answer = answer + z;
// add delay to allow more numbers into Serial.available
delay(5);
}
Serial.print("You entered: ");
Serial.println(answer);
}
void checkAnswer()
{
//check answer and show results
if (answer == number) // correct
{
Serial.print("Correct! ");
Serial.print(answer, BIN);
Serial.print(" equals ");
Serial.println(number);
Serial.println();
}
else // incorrect
{
Serial.print("Incorrect, ");
Serial.print(number, BIN);
Serial.print(" equals ");
Serial.println(number);
Serial.println();
}
answer = 0;
delay(10000); // give time to review answers
}
void loop()
{
number = random(256);
displayNumber(number);
Serial.println("What is the binary number in base-10? ");
getAnswer();
checkAnswer();
}