// 1 - Gravar os arquivos de áudio dentro do SD Card
// 2 - Converter os arquivos de áudio para AD4
// 3 - Mudar o nome dos arquivos para formato de número (0001, 0002)

// Bibliotecas
#include <Wtv020sd16p.h>
#include <SoftwareSerial.h>

// Variaveis do sistema
int resetPin = 4; // Pino de Reset
int clockPin = 5; // Pindo de Clock
int dataPin = 2; // Pino de Data (DI)
int busyPin = 3; // Pino de busy

int botao_audio_1 = 8; // Botão 1
int botao_audio_2 = 0; // Botão 2
int botao_audio_3 = 10; // Botão 3
int botao_audio_4 = 11; // Botão 4
int botao_audio_5 = 12; // Botão 5
int botao_audio_6 = 13; // Botão 6

Wtv020sd16p wtv020sd16p(resetPin, clockPin, dataPin, busyPin);

uint8_t records[7];
uint8_t buf[64];

void setup() {
  // Código de configuração para ser executado uma vez
  pinMode(botao_audio_1, INPUT_PULLUP); // INPUT_PULLUP = Utiliza resistor interno do módulo de voz
  pinMode(botao_audio_2, INPUT_PULLUP); // INPUT_PULLUP = Utiliza resistor interno do módulo de voz
  pinMode(botao_audio_3, INPUT_PULLUP); // INPUT_PULLUP = Utiliza resistor interno do módulo de voz
  pinMode(botao_audio_4, INPUT_PULLUP); // INPUT_PULLUP = Utiliza resistor interno do módulo de voz
  pinMode(botao_audio_5, INPUT_PULLUP); // INPUT_PULLUP = Utiliza resistor interno do módulo de voz
  pinMode(botao_audio_6, INPUT_PULLUP); // INPUT_PULLUP = Utiliza resistor interno do módulo de voz

  //Configura módulo
  wtv020sd16p.reset();

  //Mensagem de start
  Serial.write("Sistema iniciando!");
}

void loop() {
  //Botão 1
  int botao_valor_1 = digitalRead(botao_audio_1);

  if (botao_valor_1 == LOW) {
    TocaAudio(1);
  }

  //Botão 2
  int botao_valor_2 = digitalRead(botao_audio_2);

  if (botao_valor_2 == LOW) {
    TocaAudio(2);
  }

  //Botão 3
  int botao_valor_3 = digitalRead(botao_audio_3);

  if (botao_valor_3 == LOW) {
    TocaAudio(3);
  }

  //Botão 4
  int botao_valor_4 = digitalRead(botao_audio_4);

  if (botao_valor_4 == LOW) {
    TocaAudio(4);
  }

  //Botão 5
  int botao_valor_5 = digitalRead(botao_audio_5);

  if (botao_valor_5 == LOW) {
    TocaAudio(5); 
  }

  //Botão 6
  int botao_valor_6 = digitalRead(botao_audio_6);

  if (botao_valor_6 == LOW) {
    TocaAudio(6);
  }
  
}

void TocaAudio(int i) {
  Serial.println("Tocando: ");
  Serial.print(i);
  wtv020sd16p.playVoice(2);
  wtv020sd16p.asyncPlayVoice(i);
  delay(5000); 
  wtv020sd16p.stopVoice();
  delay(1000); 
}