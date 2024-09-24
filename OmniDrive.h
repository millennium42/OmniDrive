#ifndef OMNIDRIVE_H
#define OMNIDRIVE_H

#include <cmath>  // Para funções trigonométricas
#define _USE_MATH_DEFINES  // Define constantes como M_PI

class OmniDrive {
private:
    float raioRoda;  // Raio da roda [m]
    float angulosRodas[4];  // Ângulos de cada roda em relação ao centro do robô
    float posicaoRodas[4][2];  // Posições das rodas no robô (x, y)
    float matrizConversao[4][3];  // Matriz de conversão para transformar vx, vy, vtheta em velocidades das rodas

    // Método privado para calcular a matriz de conversão
    void calcularMatrizConversao();

public:
    // Construtor da classe, inicializa o raio, ângulos e posições das rodas
    OmniDrive(float raio, float angulos[4], float posicoes[4][2]);

    // Método para calcular as velocidades das rodas
    void calcularVelocidades(float vx, float vy, float vtheta, float* velocidadesRodas);

    // Getter para o raio da roda
    float getRaioRoda() const;

    // Setter para o raio da roda
    void setRaioRoda(float raio);
};

#endif  // OMNIDRIVE_H
