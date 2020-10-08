// l293d, H-bridge entegreli bir motor denetleyicisidir. PWM sinyali enable pinlerine verilir. Çıkış pinlerinden de hangisi HIGH ise, o pinden pozitif PWM sinyali gelir. LOW pinden
// ise 0 değerinde PWM sinyali gelir.

int firstMotorDir;                                  // 4 motorun yönünü tutacak tamsayılar global tanımlanır.
int secondMotorDir;
int thirdMotorDir;
int fourthMotorDir;

int firstMotorVel;                                  // 4 motorun hızını tutacak tamsayılar global tanımlanır.
int secondMotorVel;
int thirdMotorVel;
int fourthMotorVel;

String message_str = "";                            // Serial porta basılacak mesajı tutacak değişken, boş bir şekilde global tanımlanır.

String int_to_str(int n){                           // Tamsayıları string e çevirecek bir fonksiyon. 3 basamağa kadar olan tamsayıları string e çevirir.

  char hundreds_digit = n/100 + 48;
  char tens_digit = (n/10)%10 + 48;
  char ones_digit = n%10 + 48;

  String converted = "";
  
  converted += hundreds_digit;
  converted += tens_digit;
  converted += ones_digit;

  return converted;
}

void setup()
{
  pinMode(2,OUTPUT);                                 // Arduinoda kullanılacak bütün portlar OUTPUT olarak tanımlanır.
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  
  Serial.begin(9600);                 
  randomSeed(analogRead(0));                         // Random seed, 0. porttan okunacak gürültüye göre belirlenir. Böylece random() fonksiyonunun her seferinde farklı sayı üretmesi sağlanır.
}

void loop()
{
  
  message_str = "S";                                 // Serial porta basılacak mesaj "S" ye eşitlenir. loop() sürekli döneceği için, mesajın loop() un başında sıfırlanması önemlidir.

  firstMotorDir = random(0,2);                       // 4 motorun yönleri, 0 ile 1 arasında rastgele belirlenir
  secondMotorDir = random(0,2);
  thirdMotorDir = random(0,2);
  fourthMotorDir = random(0,2);

  firstMotorVel = random(0,256);                    // 4 motorun hızları, 0 ile 255 arasında rastgele belirlenir.
  secondMotorVel = random(0,256);
  thirdMotorVel = random(0,256);
  fourthMotorVel = random(0,256);
  
  message_str += int_to_str(firstMotorDir);         // Belirlenen değerler, serial porta basılmak üzere string e dönüştürülür ve mesaja eklenir.
  message_str += int_to_str(firstMotorVel);
  message_str += int_to_str(secondMotorDir);
  message_str += int_to_str(secondMotorVel);
  message_str += int_to_str(thirdMotorDir);
  message_str += int_to_str(thirdMotorVel);
  message_str += int_to_str(fourthMotorDir);
  message_str += int_to_str(fourthMotorVel);
  
  message_str += "F";                               // Mesajın sonuna "F" konulur.

  Serial.println(message_str);                      // Mesaj serial port a basılır.
  
  if(firstMotorDir == 1){                           // Eğer 1. motorun yönü 1 ise.
  
    digitalWrite(7,HIGH);                           // 1. motoru kontrol etmeye giden mavi kablo HIGH yapılır.
    digitalWrite(6,LOW);                            // 1. motoru kontrol etmeye giden mor kablo LOW yapılır.
  }
  else{                                             // Eğer 1. motorun yönü 0 ise.
  
    digitalWrite(7,LOW);                            // 1. motoru kontrol etmeye giden mavi kablo LOW yapılır.             
    digitalWrite(6,HIGH);                           // 1. motoru kontrol etmeye giden mor kablo HIGH yapılır.
  }
  
  if(secondMotorDir == 1){                          // Eğer 2. motorun yönü 1 ise.
  
    digitalWrite(2,HIGH);                           // 2. motoru kontrol etmeye giden mavi kablo HIGH yapılır.
    digitalWrite(4,LOW);                            // 2. motoru kontrol etmeye giden mor kablo LOW yapılır.
  }
  else{                                             // Eğer 2. motorun yönü 0 ise.
  
    digitalWrite(2,LOW);                            // 2. motoru kontrol etmeye giden mavi kablo LOW yapılır.
    digitalWrite(4,HIGH);                           // 2. motoru kontrol etmeye giden mor kablo HIGH yapılır.
  }
  
  if(thirdMotorDir == 1){                           // Eğer 3. motorun yönü 1 ise.
  
    digitalWrite(12,HIGH);                          // 3. motoru kontrol etmeye giden mavi kablo HIGH yapılır.
    digitalWrite(13,LOW);                           // 3. motoru kontrol etmeye giden mor kablo LOW yapılır.
  }
  else{                                             // Eğer 3. motorun yönü 0 ise.
  
    digitalWrite(12,LOW);                           // 3. motoru kontrol etmeye giden mavi kablo LOW yapılır.
    digitalWrite(13,HIGH);                          // 3. motoru kontrol etmeye giden mor kablo HIGH yapılır.
  }
  
  if(fourthMotorDir == 1){                          // Eğer 4. motorun yönü 1 ise.
  
    digitalWrite(10,HIGH);                          // 4. motoru kontrol etmeye giden mavi kablo HIGH yapılır.
    digitalWrite(8,LOW);                            // 4. motoru kontrol etmeye giden mor kablo LOW yapılır.
  }
  else{                                             // Eğer 4. motorun yönü 0 ise.
  
    digitalWrite(10,LOW);                           // 4. motoru kontrol etmeye giden mavi kablo LOW yapılır.
    digitalWrite(8,HIGH);                           // 4. motoru kontrol etmeye giden mor kablo HIGH yapılır.
  }
  
  analogWrite(5,firstMotorVel);                     // Yönler rastgele belirlendikten sonra, önceden belirlenen rastgele motor hızları motorlara PWM sinyali ile basılır.
  analogWrite(3,secondMotorVel);
  analogWrite(11,thirdMotorVel);
  analogWrite(9,fourthMotorVel);
  
}
