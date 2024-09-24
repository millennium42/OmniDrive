#include <iostream>
#include "OmniDrive.h"

int main() {
    // Ângulos das 4 rodas em radianos
    float angulos[4] = {0, M_PI / 2, M_PI, -M_PI / 2};

    // Posições das rodas em relação ao centro do robô (x, y)
    float posicoes[4][2] = {
        {0.3, 0.3},   // Roda 1 (frontal direita)
        {0.3, -0.3},  // Roda 2 (frontal esquerda)
        {-0.3, -0.3}, // Roda 3 (traseira esquerda)
        {-0.3, 0.3}   // Roda 4 (traseira direita)
    };

    // Inicializa o controle omnidirecional com o raio da roda de 0.05 metros
    OmniDrive omni(0.05f, angulos, posicoes);

    // Vetor para armazenar as velocidades das rodas
    float velocidadesRodas[4];

    // Calcula as velocidades das rodas para vx = 1 m/s, vy = 0.5 m/s, vtheta = 0.2 rad/s
    omni.calcularVelocidades(1.0f, 0.5f, 0.2f, velocidadesRodas);

    // Exibe as velocidades angulares das rodas
    for (int i = 0; i < 4; i++) {
        std::cout << "Velocidade da roda " << i + 1 << ": " << velocidadesRodas[i] << " rad/s" << std::endl;
    }

    return 0;
}
