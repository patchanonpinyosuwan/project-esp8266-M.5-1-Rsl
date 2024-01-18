#include <TridentTD_LineNotify.h>
#define SSID        "JAONINE_2G"      //ใส่ ชื่อ Wifi ที่จะเชื่อมต่อ
#define PASSWORD    "KATE133279"     //ใส่ รหัส Wifi
#define LINE_TOKEN  "k55b0fsXMEEDLLcyelRQThTJhUsmaMM3Nrup7Wo2pJu"   //ใส่ รหัส TOKEN ที่ได้มาจากข้างบน

int ledPin = D0;//ประกาศตัวแปร ให้ LED
int GAS = A0;//ประกาศตัวแปร ให้ GAS
int SPEAKER = D8;//ประกาศตัวแปร ให้ Buzzer
int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  // sets the pin as output
  pinMode(SPEAKER, OUTPUT);
  Serial.begin(9200);     // Corrected the syntax for Serial.begin
  Serial.println(LINE.getVersion());  // Corrected the typo in Serial.println

  WiFi.begin(SSID, PASSWORD);   // ให้บอร์ดต่ออินเตอรเน็ต
  Serial.print("WiFi connecting to ");
  Serial.print(SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.println("\nWiFi connected\nIP: ");
  Serial.println(WiFi.localIP());

  // Set Line Token
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  val = analogRead(GAS);  //อ่านค่าสัญญาณ analog 
  int val1 = map(val , 200, 1024 , 0 , 100 );
  Serial.print("val = "+ String(val1) +" % "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(val); // พิมพ์ค่าของตัวแปร val
  
   if (val1 >= 50) { // สามารถกำหนดปรับค่าได้ตามสถานที่ต่างๆ
    digitalWrite(ledPin,HIGH); // สั่งให้ LED กระพริบ
    delay(200);
    digitalWrite(ledPin,LOW);
    delay(200);

    digitalWrite(SPEAKER,HIGH); // สั่งให้ลำโพงส่งเสียง
    delay(200);
    digitalWrite(SPEAKER,LOW);
    delay(200); 

    LINE.notify("อันตราย!!! มีควันหรือแก๊สรั่ว = "+ String(val1) +" % "); // ส่งแจ้งเตือนใน line
  }
  else{
    digitalWrite(ledPin, LOW); // สั่งให้ LED ดับ
    digitalWrite(SPEAKER,LOW); // สั่งให้ลำโพง ดับ
  } 
  delay(100);
  return;
}