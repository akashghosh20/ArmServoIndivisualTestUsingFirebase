#include <ESP32Servo.h>
#include <WiFi.h>
#include <FirebaseESP32.h>

#define FIREBASE_HOST "https://roboticarm-57eec-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "MIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQDEIjaG56JdxkCrkpX8UBNIWEuBmr1GX+odBzom1e4IpVbDlROd0SUXwmg0bJwvuj0AkgRUd/dAGcNTW+F1h70B1Ko4VYVmdpUwPbjkyUcsjCUvShXqDC7ArrjinBL05aTGcha0F49aWF+EzwEqkGDha2OhDdf+n3Hpmecygy49OTHW8R5moxRKzFm7fsW4PM6InDGl4zKkH0FpRvV5FCbaKEYUFA/+GwMfM0zkUgTgOLKI7iadaCJtfxBOC4i/DJT6NzAumNAPOHfotUjHG9nAAGg1D2R/OG8Ajsp/MjJvbuA8RU261TmEc4sdVvUK+9FYRrEfENE47OQgZDJtR9SdAgMBAAECggEABjXsIpj2ogALX7N4VuFFPwr2tx+qgy452Fn4fC7VhwYPSYmwsZRkF4zDJnfS+UrtMBWvl+ollOzL69mSudlGwaZVjoucugoivsCRmIMMIyu76LOwnnTszRKrTZeyHPmhnlwR/nlpg2udeLPiXlHsk27GXJz23Dv5zDMgqE+RmQQmrmKsBVj7Va5AlB74VrNvt3KBLqtDvZAh2hkpJqe1RwPU8ifxTov6PzD0RPrtCeZO/JIQIEzsbDMBdHwRmQB90VKG62k4e1MmL47mOIdtlAX6PMLRWhBJ0TUQu9wrWNBbHB8zsB3CSV05GYyLBXfkPucmcnT6l9GJ5jAj5TzkOQKBgQDnQzH2l6EwxH3O9U"

Servo servo1, servo2, servo3, servo4, servo5;

int prevAngle1 = 0;
int prevAngle2 = 0;
int prevAngle3 = 0;
int prevAngle4 = 0;
int prevAngle5 = 0;

void setup() {
  Serial.begin(9600);
  WiFi.begin("EEE_MEC", "MEC_EEE1234");

  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  // Initialize Firebase

  servo1.attach(25);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(13);
  servo5.attach(19);
}

void loop() {
  // Get a reference to the Firebase database
  FirebaseData data;

  // Read data from Firebase
  Firebase.get(data, "angle1");
  int angle1 = data.intData();
  Serial.println(angle1);

  Firebase.get(data, "angle2");
  int angle2 = data.intData();
  Serial.println(angle2);

  Firebase.get(data, "angle3");
  int angle3 = data.intData();
  Serial.println(angle3);

  Firebase.get(data, "angle4");
  int angle4 = data.intData();
  Serial.println(angle4);

  Firebase.get(data, "angle5");
  int angle5 = data.intData();
  Serial.println(angle5);

  // Update only if the new angle is different
  // if (angle1 != prevAngle1) {
    servo1.write(angle1);
    prevAngle1 = angle1;
  // }

    servo2.write(angle2);
    prevAngle2 = angle2;
  

 
    servo3.write(angle3);
    prevAngle3 = angle3;
  
    servo4.write(angle4);
    prevAngle4 = angle4;
 

 
    servo5.write(angle5);
    prevAngle5 = angle5;
  

  // Add a delay to control the update rate (adjust as needed)
  // delay(1000);  // Adjust the delay based on the response time of your system
}
