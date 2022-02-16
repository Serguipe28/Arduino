// Prueba Shield CNC, Driver, Motores de Pasos y Arduino UNO
// By: www.dinastiatecnologica.com
//
#define x_paso 2    // Define el Pin de STEP para Motor de eje X
#define x_dire 5    // Define el Pin de DIR  para Motor de eje X
#define x_habi 8    // Define el Pin de ENABLE  para Motor de eje X


int retardo = 100;   // Menor numero el giro es mas rapido
int tiempo = 3000;   // durante cuanto timpo da el giro el motor (vueltas)

void setup() {
pinMode(x_paso, OUTPUT); pinMode(x_dire, OUTPUT); pinMode(x_habi, OUTPUT);     

}    

void loop() {
  giro(x_paso,x_dire,x_habi);
  
}

void giro(int paso_,int dire_,int habi_) {
   digitalWrite(habi_, LOW);  // Habilita el Driver
   digitalWrite(dire_, LOW);   // direccion de giro 1
   for(int i=0;i<tiempo;i++){  // da  pasos por un tiempo  
    digitalWrite(paso_, HIGH);      
    delayMicroseconds(retardo);          
    digitalWrite(paso_, LOW);       
    delayMicroseconds(retardo); 
   }
  digitalWrite(dire_, HIGH);   // direccion de giro 2
  for(int i=0;i<tiempo;i++){   // da  pasos por un tiempo  
    digitalWrite(paso_, HIGH);      
    delayMicroseconds(retardo);          
    digitalWrite(paso_, LOW);       
    delayMicroseconds(retardo);  
  }
  digitalWrite(habi_, HIGH);   // quita la habilitacion del Driver

 delay(1000);
}
