int a [] = {5, 6, 7, 8};                //vcc pins
int b [] = {9, 10};                     //gnd pins
void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(a[i], OUTPUT);      // vcc pins
  }
  for (int i = 0; i < 2; i++) {
    pinMode(b[i], OUTPUT);      //gnd pins
  }

}
int dt = 300;               //  here i took dt as delay time common so that changing this value all the values are changed
                            //    so less effort it takes
void loop() {
  // led glows in series
  //led1
  digitalWrite(a[0], 1);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);
  //led5
  digitalWrite(a[0], 1);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);

  //led6
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 1);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);

  //led2
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 1);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);

  //led3
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 1);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);

  //led7
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 1);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);

  //led8
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 1);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);

  //led4
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 1);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);
  digitalWrite(a[3], 0);

  //next pattern
  //led1
  digitalWrite(a[0], 1);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);
  //led8
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 1);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);

  //led2
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 1);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);

  //led7
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 1);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);

  //led6
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 1);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);

  //led3
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 1);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);

  //led4
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 1);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);

  //led5
  digitalWrite(a[0], 1);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);
  digitalWrite(a[0], 0);
  v1();
  v2();
  v3();
  v4();

}

void v1() {
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 0);
  for (int i = 0; i < 4; i++) {

    digitalWrite(a[i], 0);
    delay (100);
    digitalWrite(a[i], 1);
    delay (500);
    digitalWrite(a[i], 0);
  }
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 0);
  for (int i = 0; i < 4; i++) {

    digitalWrite(a[i], 1);
    delay (500);
    digitalWrite(a[i], 0);
    delay (100);
  }
}
void v2() {
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  for (int i = 0; i < 4; i++) {

    digitalWrite(a[i], 1);
    delay (100);
    digitalWrite(a[i], 0);
    delay (500);


  }
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  for (int i = 0; i < 4; i++) {

    digitalWrite(a[i], 1);
    delay (500);
    digitalWrite(a[i], 0);
    delay (100);
  }
}
void v3() {
  //led1
  digitalWrite(a[0], 1);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);
  //led6
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 1);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);
  //led3
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 1);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);
  //led8
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 1);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);

  //reversing
  //led1
  digitalWrite(a[0], 1);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);
  //led6
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 1);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);
  //led3
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 1);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  delay (dt);
  //led8
  digitalWrite(a[0], 0);
  digitalWrite(a[1], 0);
  digitalWrite(a[2], 0);
  digitalWrite(a[3], 1);
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  delay (dt);
  digitalWrite(a[3], 0);
  digitalWrite(b[0], 0);
}
void v4() {
  digitalWrite(b[0], 1);
  digitalWrite(b[1], 0);
  for (int i = 0; i < 4; i++) {

    digitalWrite(a[i], 0);
    delay (100);
    digitalWrite(a[i], 1);
    delay (500);

  }
  digitalWrite(b[0], 0);
  digitalWrite(b[1], 1);
  for (int i = 0; i < 4; i++) {

    digitalWrite(a[i], 1);
    delay (500);
    digitalWrite(a[i], 0);
    delay (100);

  }
}
