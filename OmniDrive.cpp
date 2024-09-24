#include "OmniDrive.h"

// Construtor que inicializa as variáveis
OmniDrive::OmniDrive(float raio, float angulos[4], float posicoes[4][2])
    : raioRoda(raio) {
    // Armazena os ângulos e as posições das rodas
    for (int i = 0; i < 4; i++) {
        angulosRodas[i] = angulos[i];
        posicaoRodas[i][0] = posicoes[i][0];  // Posição x da roda
        posicaoRodas[i][1] = posicoes[i][1];  // Posição y da roda
    }
    // Calcula a matriz de conversão
    calcularMatrizConversao();
}

// Função privada que calcula a matriz de conversão de velocidades globais para as rodas
void OmniDrive::calcularMatrizConversao() {
    for (int i = 0; i < 4; i++) {
        // Componentes de velocidade linear (vx, vy) baseada nos ângulos
        matrizConversao[i][0] = -sin(angulosRodas[i]);  // Componente x
        matrizConversao[i][1] = cos(angulosRodas[i]);   // Componente y
        
        // Componente de velocidade angular (vtheta) baseada na posição da roda
        matrizConversao[i][2] = posicaoRodas[i][0] * cos(angulosRodas[i]) + posicaoRodas[i][1] * sin(angulosRodas[i]);
    }
}

// Calcula as velocidades das rodas com base em vx, vy e vtheta
void OmniDrive::calcularVelocidades(float vx, float vy, float vtheta, float* velocidadesRodas) {
    for (int i = 0; i < 4; i++) {
        // Multiplica as velocidades globais pela matriz de conversão
        velocidadesRodas[i] = (matrizConversao[i][0] * vx + matrizConversao[i][1] * vy + matrizConversao[i][2] * vtheta) / raioRoda;
    }
}

// Getter para obter o raio da roda
float OmniDrive::getRaioRoda() const {
    return raioRoda;
}

// Setter para modificar o raio da roda
void OmniDrive::setRaioRoda(float raio) {
    raioRoda = raio;
}
