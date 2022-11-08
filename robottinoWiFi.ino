#include <SoftwareSerial.h>// va a richiamare la libreria "SoftwareSerial.h"
//la classe è un insieme di attributi e di metodi

#define rxPin 10 
#define txPin 8
SoftwareSerial serialModuloWIFI =  SoftwareSerial(rxPin, txPin); //Configura un nuovo oggetto SoftwareSerial

//restituisce la risposta del modulo WIFI
String check4answer(){
    String str = ""; //serve a creare una stringa
    while (serialModuloWIFI.available() > 0) { // crea un ciclo while che funziona fino a quando serialModuloWIFI.available è maggiore di 0
        char c=serialModuloWIFI.read(); // crea una funzione per leggere la stringa inviata e la inserisce nella variabile c
        Serial.print(c); // stampa a schermo la stringa letta
        str += String(c); //nella stringa vuota aggiunge quella letta
    }
    return str; // fa il return della sringa
}


String esp01cmd(String cmd) {
  Serial.println("sending: " + cmd);
  serialModuloWIFI.println(cmd);
  delay(10);
  return check4answer();
}

void setup()  {
    // Definisce le modalità  di pin per TX e RX
    pinMode(rxPin, INPUT);
    pinMode(txPin, OUTPUT);
    
    // Imposta la velocità di trasmissione per l'oggetto SoftwareSerial
    serialModuloWIFI.begin(115200);
    Serial.begin(9600);
    delay(1000);
    esp01cmd("AT"); //verifico che il moudolo WIFI sia attivo e comunicante
    delay(1000);'0
    esp01cmd("AT+CWMODE=2"); // fa in modo che il robottino funzioni come acces point e quindi come server
    delay(1000);
    esp01cmd("AT+CWSAP=\"robottino\",\"robottino\",1,4"); //imposta ssid, poi la password, il canale e la crittografia 
    delay(1000);
    esp01cmd("AT+CIFSR"); //mostra l'indirizzo IP dell'Acces Point
    esp01cmd("AT+CIPMUX=1"); //consente ad un massimo di 1 connessione alla volta
    
    
    Serial.println("ESP-01 Configuration Completed");
}

void loop() {
  //AT+CWLIF restituisce IP del client (telefono) connesso al modulo WIFI
    Serial.println("loop..."); //stampa la stringa
    while(esp01cmd("AT+CWLIF").substring(11,18) != "192.168") { //controlla se c'è stata la connessione di un dispositivo
      Serial.println("no connections so far... still waiting"); // stampa questa stringa finchè uno non si collega
      delay(1000);
    }

    Serial.println("Connection from remote device was Established!!!");
    //ID socket: 3
    //accetta pacchetti da qualsiasi indirizzo/dispositivo IP
    //Ascolta la porta locale 4567
    //i pacchetti in uscita possono essere inviati a qualsiasi host remoto senza restrizioni
    esp01cmd("AT+CIPSTART=3,\"UDP\",\"0.0.0.0\",0,4567,2"); //avvio del server socket UDP

    

    delay(3000);
    while(true) {
      String str = serialModuloWIFI.readString();
      if(str != "") {
        int startOfSTR = str.indexOf(":",10)+1;
        Serial.println("Received: "+str.substring(startOfSTR));
      }
    }

}
