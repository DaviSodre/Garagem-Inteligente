# 🚗 Garagem Inteligente com Sensor Ultrassônico

Projeto de IoT usando Arduino para detectar objetos com sensor ultrassônico, acionar LEDs e um buzzer de alerta com base na distância.

---

## 🔧 Componentes Utilizados

- Arduino Uno
- Sensor Ultrassônico HC-SR04
- LEDs: verde, amarelo e vermelho
- Buzzer piezoelétrico
- Jumpers e Protoboard

---

## 📐 Funcionamento

| Distância Detectada | LED Ativado | Buzzer |
|---------------------|-------------|--------|
| 40cm a 20cm         | Verde       | Som fraco (buzzer3) |
| 20cm a 10cm         | Amarelo     | Som médio (buzzer2) |
| < 10cm              | Vermelho    | Som forte (buzzer1) |

---

## 🧠 Lógica

- O sensor mede a distância e ativa os LEDs e o buzzer proporcionalmente.
- O buzzer usa funções senoidais para variar a frequência do som.

---

## 📂 Código

O código está disponível no arquivo `garagem_inteligente.ino`.

---

## ✨ Autor

Davi Sodré — [GitHub](https://github.com/DaviSodre)
