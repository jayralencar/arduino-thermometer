//Sensor de temperatura usando o LM35
 
const int LM35 = A0; // Define o pino que lera a saída do LM35
float temperatura; // Variável que armazenará a temperatura medida
int tempInt,x,y,i,segment[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};;
 
//Função que será executada uma vez quando ligar ou resetar o Arduino
void setup() {
  Serial.begin(9600); // inicializa a comunicação serial
  for(i=0;i<16;i++){
    pinMode(i, OUTPUT);
  }
}
 
//Função que será executada continuamente
void loop() {
//  temperatura = (float(analogRead(LM35))*5/(1023))/0.01 ;
  temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
  tempInt = (int) temperatura;
  Serial.print("Temperatura: ");
  if(tempInt<100){
    acende(tempInt);
    digitalWrite(15,tempInt>30?HIGH:LOW);
  }
  Serial.println(tempInt);
  delay(5000);
}

void acende(int numb){
  if(numb>9){
   x = numb%10;
   y = numb/10;
  }else{
    y = 0;
  }
  digitalWrite(14, ((segment[x]&0b00000001))?HIGH:LOW);
  digitalWrite(1, ((segment[x]&0b00000010))?HIGH:LOW);
  digitalWrite(2, ((segment[x]&0b00000100))?HIGH:LOW);
  digitalWrite(3, ((segment[x]&0b00001000))?HIGH:LOW);
  digitalWrite(4, ((segment[x]&0b00010000))?HIGH:LOW);
  digitalWrite(5, ((segment[x]&0b00100000))?HIGH:LOW);
 digitalWrite(6, ((segment[x]&0b01000000))?HIGH:LOW);
 digitalWrite(7, ((segment[y]&0b00000001))?HIGH:LOW);
 digitalWrite(8, ((segment[y]&0b00000010))?HIGH:LOW);
 digitalWrite(9, ((segment[y]&0b00000100))?HIGH:LOW);
 digitalWrite(10, ((segment[y]&0b00001000))?HIGH:LOW);
 digitalWrite(11, ((segment[y]&0b00010000))?HIGH:LOW);
 digitalWrite(12, ((segment[y]&0b00100000))?HIGH:LOW);
 digitalWrite(13, ((segment[y]&0b01000000))?HIGH:LOW);
}
