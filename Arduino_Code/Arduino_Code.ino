int Th1, Th2, tmp;

void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,0);
  Th1 = 0;
  Th2 = 0;
}

void loop() 
{
  delay(200);

  if(Serial.available()>=2)
  {
    Th1 = Serial.read();
    Th2 = Serial.read();

    //Remove any extra worng reading
    while(Serial.available()) tmp = Serial.read();    
    
    // Run the robotic arm here. For testing, we will 
    //switch On or switch off a LED according to Th1 value
    if(Th1 ==1) digitalWrite(13,1);
    else digitalWrite(13,0);

    
    Serial.print('1'); // This tell the PC that Arduino is Ready for next angles
  }


}
