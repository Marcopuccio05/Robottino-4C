#RobottinoWIFI-4C

Robottino per la classe 4C del Maxwell

Aggiungiamo la connessione WIFI al Robottino basato su Arduino

Implementazione della ricezione di pacchetti UDP dal modulo WiFi (ESP01) configura come Access Point, e l'inoltro del contenuto (testo) al monitor seriale collegato all'Arduino.

Stiamo esplorando la comunicazione tra sistemi informatici.

Il robottino utilizza l'Arduino come centro nervoso (cervello) che comunica segnali elettrici con attuatori (motori) e sensori (di distanza ad ultrasuoni)

Inoltre l'Arduino presenta una porta Seriale/UART di DEBUG che, tramite conversione USB, si connette ad un PC per il trasferimento del programma e per l'interazione con lo sviluppatore tramite il Monitor Seriale.

La UART permette di scambiare informazioni tra 2 sistemi informatici, in questo caso l'Arduino e il PC.

Abbiamo studiato il protocollo illo UART, e abbiamo visto come vengono mappate le varie funzioni ai primi 2 livelli del modello ISO/OSI.

Con questo progetto vogliamo aggiungere, e studiare, la connessione WIFI.

Il modulo WIFI che usiamo si chiama ESP01, basato sul microcontrollore 8266.

ESP01 presenta da un lato l'antenna WIFI e dall'altro una porta seriale che può essere utilizzata per la connessione all'Arduino.

L'Arduino dovrà inizialmente configurare il modulo WIFI inviando dei comandi "AT", e quindi, nel suo funzionamento a regime, consentire la connessione di una stazione (cellulare) tramite WIFI, e inoltrare i dati ricevuti all'Arduino.

cellphone --> WIFI --> ESP01 --> UART1 --> Arduino --> UART0 --> PC

Il codice offerto da questo progetto implementa la comunicazione come da schema sopra.

Per la connessione WIFI sono stati visti nuovi concetti, visti che, oltre i primi 2 livelli del modello ISO/OSI, vengono usati 2 livelli aggiuntivi che vengono usati pacchetti UDP/IP.

Lo studente, deve essere il codice affinch venga realizzato il percorso inverso come da seguente schema

PC --> UART0 --> Arduino --> UART1 --> ESP01 --> WIFI --> cellphone

Questo esercizio serve a consolidare la comprensione del codice presentato, e l'oppurt di mettere in pratica quanto imparato in teoria.

Ogni deve passare il codice docente e inserire commenti a parole che facciano al capire la comprensione dello studente tutto.

Lo studente dovrà consegnare il codice modificato su GitHub (partendo dal FORK di progetto), la documentazione di quanto fatto (diario di bordo), nel file README del progetto.

Seguirà un videotutorial che lo studente dovrà consegnare che presenta il progetto.

Nel videotu sarebbe opportuno inserire il video della dimostrazione del risultato ottenuto, il funzionamento della connessione tramite WIFI connessione in dotazione i 2 livelli aggiuntivi aggiuntial, in particolare il livello di rete (IP) e di trasporto (UDP)

Il videotutorial dovrebbe essere consegnato su Classroom.

Procedura d'invio
utilizzare l'applicazione "UDP Monitor" (per Android) su telefonino
inserire Indirizzo IP dell'Access Point (192.168.4.1) e la porta del Server UDP (4567)
inserisci testo
Invio testo (premendo l'apposio pulsante offerto dall'APP)
Risultato: Monitor Seriale dovrebbe mostrare il testo inviato
