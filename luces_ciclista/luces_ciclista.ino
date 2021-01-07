int luces[] = {4,5,6,7,8,9,10,11,12,13};
int botones[] = {1,2,3};
boolean estado_boton_izquierdo = LOW;
boolean estado_boton_alto = LOW;
boolean estado_boton_derecho = LOW;
int cuenta_ociosa =0;
int cuenta_derecha =0;
void setup() {

  for(int i=0; i<10; i++){
    pinMode(luces[i],OUTPUT);  
  }  
  for(int i=0; i<3; i++){
    pinMode(botones[i],INPUT);  
  }
}

void loop() {

  for(int i=0; i<10;i++){
    digitalWrite(luces[i],LOW);  
  }
  estado_boton_izquierdo = digitalRead(botones[0]);
  estado_boton_alto = digitalRead(botones[1]);
  estado_boton_derecho = digitalRead(botones[2]);

  if(estado_boton_izquierdo == HIGH){
    izquierda();  
  }else if(estado_boton_alto == HIGH){
    alto();  
  }else if(estado_boton_derecho == HIGH){
    derecha();  
  }else{
    ociosa();  
  }
}

void izquierda(){}
void alto(){
  for(int i=0; i<10;i++){
    digitalWrite(luces[i],HIGH);  
  }
  delay(300);  
}
void derecha(){
  switch(cuenta_derecha){
    case 0:
      digitalWrite(luces[1],HIGH);
      digitalWrite(luces[8],HIGH);
      digitalWrite(luces[7],HIGH);
      break;
    case 1:
      digitalWrite(luces[2],HIGH);
      digitalWrite(luces[9],HIGH);
      digitalWrite(luces[6],HIGH);
      break;
    case 2:
      digitalWrite(luces[3],HIGH);
      digitalWrite(luces[4],HIGH);
      digitalWrite(luces[5],HIGH);
      break;
    default:
      break;
  }
  delay(300);
  cuenta_derecha++;
  if(cuenta_derecha >3){
    cuenta_derecha =0;
  }
}
void ociosa(){
  digitalWrite(luces[cuenta_ociosa],HIGH);
  digitalWrite(luces[cuenta_ociosa+4],HIGH);
  delay(300);
  cuenta_ociosa++;
  if(cuenta_ociosa >3){
    cuenta_ociosa =0;
  }  
}

