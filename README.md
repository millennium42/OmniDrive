# OmniDrive Library

A `OmniDrive` é uma biblioteca em C++ projetada para calcular as velocidades angulares das rodas de um robô omnidirecional com quatro rodas, a partir das velocidades lineares e angulares fornecidas no referencial global. A entrada é fornecida em metros por segundo (m/s) para velocidades lineares (`vx`, `vy`) e em radianos por segundo (rad/s) para a velocidade angular (`vtheta`). A saída é a velocidade angular de cada roda em radianos por segundo (rad/s).

## Funcionalidades

- Converte velocidades lineares globais (`vx`, `vy`) e a velocidade angular (`vtheta`) em velocidades angulares para cada uma das quatro rodas do robô.
- A matriz de conversão leva em consideração a posição e o ângulo das rodas em relação ao centro do robô.
- A saída é dada em rad/s, pronta para ser utilizada em sistemas de controle de motores.

## Estrutura do Projeto

O projeto é dividido em três arquivos principais:

1. **OmniDrive.h**: Declaração da classe e métodos.
2. **OmniDrive.cpp**: Implementação dos métodos da classe.
3. **main.cpp**: Exemplo de uso da classe `OmniDrive`.

## Como Funciona

### Entrada

- `vx`: Velocidade linear no eixo x em metros por segundo (m/s).
- `vy`: Velocidade linear no eixo y em metros por segundo (m/s).
- `vtheta`: Velocidade angular ao redor do centro do robô em radianos por segundo (rad/s).

### Saída

- As velocidades angulares das quatro rodas em radianos por segundo (rad/s), calculadas com base nas velocidades fornecidas e no raio das rodas.

### Matriz de Conversão

A matriz de conversão é gerada a partir dos ângulos e posições das rodas. Cada roda possui uma equação que leva em consideração a transformação de velocidades lineares e angulares para velocidade angular da roda.

### Fórmula

A fórmula usada para calcular a velocidade angular de cada roda é:

```cpp
velocidadesRodas[i] = (matrizConversao[i][0] * vx + matrizConversao[i][1] * vy + matrizConversao[i][2] * vtheta) / raioRoda;
```

Onde:
- `matrizConversao[i][0]` e `matrizConversao[i][1]` dependem dos ângulos das rodas.
- `matrizConversao[i][2]` depende da posição das rodas.

## Como Usar

### 1. Compilação

Para compilar o código, use um compilador como o `g++`:

```bash
g++ main.cpp OmniDrive.cpp -o omni_drive
```

### 2. Execução

Execute o programa compilado:

```bash
./omni_drive
```

### 3. Saída Esperada

O programa calculará as velocidades angulares das quatro rodas e imprimirá os resultados no console, como no exemplo:

```bash
Velocidade da roda 1: 12.56 rad/s
Velocidade da roda 2: 10.47 rad/s
Velocidade da roda 3: 8.32 rad/s
Velocidade da roda 4: 11.21 rad/s
```

## Exemplo de Código

Aqui está um exemplo de como usar a classe `OmniDrive`:

```cpp
#include "OmniDrive.h"

int main() {
    float angulos[4] = {0, M_PI / 2, M_PI, -M_PI / 2};
    float posicoes[4][2] = {{0.3, 0.3}, {0.3, -0.3}, {-0.3, -0.3}, {-0.3, 0.3}};
    
    OmniDrive omni(0.05f, angulos, posicoes);

    float velocidadesRodas[4];
    omni.calcularVelocidades(1.0f, 0.5f, 0.2f, velocidadesRodas);

    for (int i = 0; i < 4; i++) {
        std::cout << "Velocidade da roda " << i + 1 << ": " << velocidadesRodas[i] << " rad/s" << std::endl;
    }

    return 0;
}
```

## Customização

- **Raio das Rodas**: Modifique o raio da roda com o método `setRaioRoda()`, por exemplo:

```cpp
omni.setRaioRoda(0.07f);  // Atualiza o raio da roda para 0.07 metros
```

- **Posição e Ângulo das Rodas**: Defina diferentes posições e ângulos para as rodas durante a construção da classe.
