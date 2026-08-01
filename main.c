// hola se me olvido mi nombre, juan perdomo 27198676
// Pines Vías Norte y Sur (Conectados en paralelo)
const int cocheVerdeNS = 2;
const int cocheAmarilloNS = 3;
const int cocheRojoNS = 4;
const int peatonVerdeNS = 5;
const int peatonRojoNS = 6;

// Pines Vías Este y Oeste (Conectados en paralelo)
const int cocheVerdeEO = 7;
const int cocheAmarilloEO = 8;
const int cocheRojoEO = 9;
const int peatonVerdeEO = 10;
const int peatonRojoEO = 11;

void setup() {
  // Configurar los pines del 2 al 11 como salidas (OUTPUT)
  for (int i = 2; i <= 11; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // FASE 1: Avanza Norte-Sur, Peatones Este-Oeste cruzan.
  digitalWrite(cocheVerdeNS, HIGH);
  digitalWrite(cocheAmarilloNS, LOW);
  digitalWrite(cocheRojoNS, LOW);
  digitalWrite(peatonVerdeNS, LOW);
  digitalWrite(peatonRojoNS, HIGH); // Peatones NS esperan

  digitalWrite(cocheVerdeEO, LOW);
  digitalWrite(cocheAmarilloEO, LOW);
  digitalWrite(cocheRojoEO, HIGH); // Coches EO detenidos
  digitalWrite(peatonVerdeEO, HIGH); // Peatones EO cruzan
  digitalWrite(peatonRojoEO, LOW);
  
  delay(5000); // Duración de la luz verde (5 segundos)

  // FASE 2: Precaución Norte-Sur (Amarillo).
  digitalWrite(cocheVerdeNS, LOW);
  digitalWrite(cocheAmarilloNS, HIGH);
  // Por seguridad, los peatones EO ya no deben iniciar el cruce
  digitalWrite(peatonVerdeEO, LOW);
  digitalWrite(peatonRojoEO, HIGH);
  
  delay(2000); // Duración de la luz amarilla (2 segundos)

  // FASE 3: Avanza Este-Oeste, Peatones Norte-Sur cruzan.
  digitalWrite(cocheAmarilloNS, LOW);
  digitalWrite(cocheRojoNS, HIGH); // Coches NS detenidos
  digitalWrite(peatonVerdeNS, HIGH); // Peatones NS cruzan
  digitalWrite(peatonRojoNS, LOW);

  digitalWrite(cocheVerdeEO, HIGH);
  digitalWrite(cocheRojoEO, LOW);
  
  delay(5000); // Duración de la luz verde (5 segundos)

  // FASE 4: Precaución Este-Oeste (Amarillo).
  digitalWrite(cocheVerdeEO, LOW);
  digitalWrite(cocheAmarilloEO, HIGH);
  // Por seguridad, los peatones NS ya no deben iniciar el cruce
  digitalWrite(peatonVerdeNS, LOW);
  digitalWrite(peatonRojoNS, HIGH);
  
  delay(2000); // Duración de la luz amarilla (2 segundos)

  // Apagar el amarillo de Este-Oeste para reiniciar el loop limpiamente
  digitalWrite(cocheAmarilloEO, LOW);
}