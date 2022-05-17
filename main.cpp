int state1 = 0; // estado do botão 1
int state2 = 0; // estado do botão 2
int state3 = 0; // estado do botão 3
int posicao = 3; //variável que indica a posicao atual do elevador
int posicaoAtual = 0; // variavel que assosciada à posição, diz quantas vez o elevador repetirá a ação

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
void SubirAndar(){ // sobe o elevador 1 andar
	 analogWrite (ElevadorMotor1,10);//liga o motor no sentido horário
    analogWrite (ElevadorMotor2,LOW);
    delay(3000);//espera 3 segundos
    analogWrite (ElevadorMotor1,LOW);//desliga o motor
    analogWrite (ElevadorMotor2,LOW);
}

void DescerAndar(){ // desce o elevador 1 andar
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
}

void loop()
{
  state1 = digitalRead (BotaoAndar1);                                                      
  state2 = digitalRead (BotaoAndar2);                                                        
  state3 = digitalRead (BotaoAndar3);
  
  if (state1 == HIGH){ //o que acontece ao apertar o botão do 1º andar
  	posicaoAtual = 1 - posicao;
    if (posicaoAtual < 0){
      while (posicaoAtual <0){
      	posicaoAtual += 1;
        DescerAndar();
      }
    posicao = 1; 
    }
  }
  
  if (state2 == HIGH){ // o que acontece ao apertar o botão do 2º andar
  	posicaoAtual = 2 - posicao;
    if (posicaoAtual <0){
      while (posicaoAtual < 0){
      	posicaoAtual += 1;
        DescerAndar();
      }
    }  
    else{
        while (posicaoAtual > 0){
        	posicaoAtual -= 1;
        	SubirAndar();
        }	
      }
    posicao = 2;
    }
  if (state3 == HIGH){
  	posicaoAtual = 3 - posicao;
    if (posicaoAtual > 0){
      while (posicaoAtual > 0){
      	posicaoAtual -=1;
        SubirAndar();
      }
    }
  }
}



