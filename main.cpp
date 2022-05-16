int state1 = 0; 
int state2 = 0;
int state3 = 0;
int posicao = 3;
int posicaoAtual = 0;
// OUTPUT
int ElevadorMotor1 = 6;
int ElevadorMotor2 = 5;

/*
int AbrePorta1 = ?;
int FechaPorta1 = ?;
int AbrePorta2 = ?;
int FechaPorta2 = ?;
int AbrePorta3 = ?;
int FechaPorta3 = ?;
*/


// INPUT
int BotaoAndar1 = 7;
int BotaoAndar2= 4;
int BotaoAndar3= 2;


// FUNÇÕES
void SubirAndar(){
	 analogWrite (ElevadorMotor1,10);//liga o motor no sentido horário
    analogWrite (ElevadorMotor2,LOW);
    delay(3000);//espera 3 segundos
    analogWrite (ElevadorMotor1,LOW);//desliga o motor
    analogWrite (ElevadorMotor2,LOW);
}

void DescerAndar(){
	analogWrite (ElevadorMotor1,LOW);
    analogWrite (ElevadorMotor2,10);//liga o motor no sentido anti-horário
    delay(3000);//espera 3 segundos
    analogWrite (ElevadorMotor1,LOW);//desliga o motor
    analogWrite (ElevadorMotor2,LOW);
}

/*

void AbrirPorta1(){
}

void FecharPorta1(){
}

void AbrirPorta2(){
}

void FecharPorta2(){
}

void AbrirPorta3(){
}

void FecharPorta3(){
}

*/

void setup()
{
 pinMode (ElevadorMotor1,OUTPUT); pinMode (ElevadorMotor2,OUTPUT); // OUTPUT
 pinMode (BotaoAndar1,INPUT);
 pinMode (BotaoAndar2, INPUT);
 pinMode(BotaoAndar3, INPUT);
 Serial.begin(9600);
}

void loop()
{
  state1 = digitalRead (BotaoAndar1);                                                      
  state2 = digitalRead (BotaoAndar2);                                                        
  state3 = digitalRead (BotaoAndar3);
  Serial.print(posicaoAtual);
  Serial.println();
  if (state1 == HIGH){
  	posicaoAtual = 1 - posicao;
    Serial.write(posicaoAtual);
    if (posicaoAtual < 0){
      abs(posicaoAtual);
      for (posicaoAtual; posicaoAtual >0; posicaoAtual -=1){
      	DescerAndar();
      }
    }
  }

}


