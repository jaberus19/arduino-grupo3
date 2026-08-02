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

