int state1 = 0; 
int state2 = 0;
int dc1 = 6;
int dc2 = 7;
int push1 = 5;
int push2 = 4;

int SubirAndar(int estado1){
	analogWrite (dc1,10);//liga o motor no sentido horário
    analogWrite (dc2,LOW);
    delay(3000);//espera 3 segundos
    analogWrite (dc1,LOW);//desliga o motor
    analogWrite (dc2,LOW);
}

int DescerAndar(int estado2){
	analogWrite (dc1,LOW);
    analogWrite (dc2,10);//liga o motor no sentido anti-horário
    delay(3000);//espera 3 segundos
    analogWrite (dc1,LOW);//desliga o motor
    analogWrite (dc2,LOW);
}

void setup()
{
 pinMode (dc1,OUTPUT); 
 pinMode (dc2,OUTPUT);
 pinMode (push1,INPUT);
 pinMode (push2,INPUT);
 Serial.begin(9600);
}

void loop()
{
  state1 = digitalRead (push1); //determina o stado 1 como o botão 1 está pressionado ou não
  state2 = digitalRead (push2); //determina o stado 2 como o botão 2 está pressionado ou não
  Serial.print(state1);
  Serial.println();
}
