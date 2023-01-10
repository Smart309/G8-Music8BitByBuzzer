#define LED 21
#define Button_Pin 0

hw_timer_t *My_timer = NULL;
int speed;
void IRAM_ATTR onTimer(){
  digitalWrite(LED, !digitalRead(LED));
}

void IRAM_ATTR IO_INT_ISR(){
  speed++;
  if(speed == 6){
    speed = 1;
  }
}

void setup(){
  pinMode(LED, OUTPUT);
  My_timer = timerBegin(0, 80, true);
  timerAttachInterrupt(My_timer, &onTimer, true);
  pinMode(Button_Pin, INPUT);
  attachInterrupt(Button_Pin, IO_INT_ISR, RISING);
  speed = 1;
}

void loop(){
  timerAlarmWrite(My_timer, 379.07, true);//E
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(1500/speed);
  timerAlarmWrite(My_timer, 318.87, true);//G
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(750/speed);
  timerAlarmWrite(My_timer, 477.55, true);//C
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(3750/speed);
  timerAlarmWrite(My_timer, 284.09, true);//A
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(1500/speed);
  timerAlarmWrite(My_timer, 238.89, true);//C'
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(600/speed);
  timerAlarmWrite(My_timer, 357.909, true);//F
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(3900/speed);
  timerAlarmWrite(My_timer, 253.036, true);//B
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(750/speed);
  timerAlarmWrite(My_timer, 253.036, false);
  delay(30/speed);
  timerAlarmWrite(My_timer, 253.036, true);//B
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(750/speed);
  timerAlarmWrite(My_timer, 253.036, false);
  delay(30/speed);
  timerAlarmWrite(My_timer, 253.036, true);//B
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(750/speed);
  timerAlarmWrite(My_timer, 318.87, true);//G
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(750/speed);
  timerAlarmWrite(My_timer, 253.036, true);//B
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(750/speed);
  timerAlarmWrite(My_timer, 212.856, true);//D'
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(750/speed);
  timerAlarmWrite(My_timer, 238.89, true);//C'
  timerAlarmEnable(My_timer);  // enable the alarm
  delay(3000/speed);
  timerAlarmWrite(My_timer, 253.036, false);
  delay(10);
}