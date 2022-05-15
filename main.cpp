int state1 = 0; 
int state2 = 0;
int dc1 = 5;
int dc2 = 6;
int push1 = 7;
int push2 = 4;

void setup()
{
 pinMode (dc1,OUTPUT); 
 pinMode (dc2,OUTPUT);
 pinMode (push1,INPUT);
 pinMode (push2,INPUT);
}

void loop()
{
  state1 = digitalRead (push1); //determina o stado 1 como o botão 1 está pressionado ou não
  state2 = digitalRead (push2); //determina o stado 2 como o botão 2 está pressionado ou não
  if (state1 == HIGH)//lê se o botão está pressionado
  {
    digitalWrite (dc1,64);//liga o motor no sentido horário
    digitalWrite (dc2,LOW);
    delay(3000);//espera 3 segundos
    digitalWrite (dc1,LOW);//desliga o motor
    digitalWrite (dc2,LOW);
  }
  if (state2 == HIGH)
  {
    digitalWrite (dc1,LOW);
    digitalWrite (dc2,64);//liga o motor no sentido anti-horário
    delay(3000);//espera 3 segundos
    digitalWrite (dc1,LOW);//desliga o motor
    digitalWrite (dc2,LOW);
  }
}
