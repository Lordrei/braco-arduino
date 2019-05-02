
#include <Servo.h>


class Motor{
  //acesso
  private:
    //atributos
    int porta, maxi, mini, passo;
    Servo motor;
    int grau; 
  //construtor
  public:
    Motor(int porta, int maxi, int mini, int passo){
        this->porta = porta;
        this->maxi = maxi;
        this->mini = mini;
        this->passo = passo;    
        }

     void setPorta(){
      motor.attach(this->porta);
      }
    
    
    void setGrau(int num){
      this->grau = num;
      this->motor.write(this->grau);
      Serial.print("grau: ");
      Serial.println(this->grau);
      }

    

    void aumentaGrau(){
      if (this->grau < maxi){
        this->grau  += passo;  
      }
      this->setGrau(this->grau);
    }
    
    
    void diminuiGrau(){
      if (this->grau  > mini){
        this->grau  -= passo;
      }
      this->setGrau(this->grau);  
    }
    
  
    void limiteGrau(){
      if (this->grau  == mini || this->grau  <= ((this->maxi - this->mini)/2)){
        this->grau  = maxi;
        this->setGrau(this->grau);
      }
      else{
        this->grau  = mini;
        this->setGrau(this->grau);
      }
    }

    void metadeGrau(){
      setGrau((this->maxi - this->mini) /2);
    }
   

};

Motor garra = Motor(9,  20, 0,  5);
Motor base  = Motor(8, 180, 0, 20);
Motor vertical = Motor(10, 180, 0, 20);
Motor horizontal = Motor (11, 180, 0, 20);

char escolhe;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  base.setPorta();
  garra.setPorta();
  horizontal.setPorta();
  vertical.setPorta();
  garra.setGrau(0);
  base.setGrau(90);
  vertical.setGrau(90);
  horizontal.setGrau(90);
}



void loop() {
   escolhe = Serial.read();
   switch(escolhe){
    case '1':
      Serial.print("A garra esta no ");
      garra.aumentaGrau();
      delay(1000);
      break;

    case '2':
      Serial.print("A garra esta no ");
      garra.diminuiGrau();
      delay(1000);
      break;
     
    case '3':
      Serial.print("A garra esta no ");
      base.aumentaGrau();
      delay(1000);
      break;

    case '4':
      Serial.print("A garra esta no ");
      base.diminuiGrau();
      delay(1000);
      break;

    case '5':
      Serial.print("A garra esta no ");
      vertical.aumentaGrau();
      delay(1000);
      break;

    case '6':
      Serial.print("A garra esta no ");
      vertical.diminuiGrau();
      delay(1000);
      break;
      
    case '7':
      Serial.print("A garra esta no ");
      horizontal.aumentaGrau();
      delay(1000);
      break;

    case '8':
      Serial.print("A garra esta no ");
      horizontal.diminuiGrau();
      delay(1000);
      break;
      
    
   }  
}


