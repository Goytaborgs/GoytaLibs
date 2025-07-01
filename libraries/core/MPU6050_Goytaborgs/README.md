# MPU6050_Yaw

Biblioteca de abstração leve em C++ que simplifica a leitura do **ângulo de YAW** do sensor **MPU6050** usando a DMP (Digital Motion Processor).  
Foi construída sobre as bibliotecas **MPU6050_6Axis_MotionApps20.h** e **I2Cdev.h**, ambas também presentes no repositório da equipe Goytaborgs.

Ideal para robôs que precisam apenas do eixo de guinada (yaw) para navegação e controle.

---

## ⚙️ Funcionalidades

- Inicializa a DMP do MPU6050 e realiza calibração automática
- Disponibiliza o valor de yaw em graus por meio da variável global `yaw`
- Função de _boot_ para zerar o ângulo a qualquer momento
- Oculta detalhes de I2C, interrupções e buffers de pacotes
- Compatível com **ESP32** e outras que suportem I2C

---

## ✅ Compatibilidade

### IDEs testadas

| IDE                     | Status                                     |
|-------------------------|------------------------------------------- |
| Arduino IDE             | ✅                                         |
| PlatformIO (VSCode)     | ✅ (framework *Arduino*)                   |
```Legenda: ⚠️ Não testado / ❌ Não compila / ✅ Funciona ```


### Microcontroladores testados

| Microcontrolador       | Status                               |
|------------------------|--------------------------------------|
| ESP32 (DevKit v1)      | ✅                                   |
| ESP32-S3               | ⚠️ (esperado funcionar)              |
| Arduino UNO / Nano     | ⚠️                                   |
```Legenda: ⚠️ Não testado / ❌ Imcompatível / ✅ Funciona ```

---

## 📦 Dependências

- [`Arduino.h`](https://docs.arduino.cc/language-reference/pt/)
- `Wire.h` (já incluída ao usar Arduino)
- [`third_party/I2Cdev`](https://github.com/jrowberg/i2cdevlib/tree/master)
- [`third_party/MPU6050`](https://github.com/jrowberg/i2cdevlib/tree/master)

---

## ⚡ Conexões típicas do módulo MPU6050

| Pino do MPU6050 | Conexão sugerida            |
| --------------- | --------------------------- |
| VCC             | 3 V3 (ou 5 V com regulador) |
| GND             | GND                         |
| SDA             | GPIO21 (ESP32) / A4 (Uno)   |
| SCL             | GPIO22 (ESP32) / A5 (Uno)   |

---

## 📁 Estrutura

```bash
MPU6050_Goytaborgs/
├── MPU6050_YAW_Goytaborgs.h    # Header principal
├── MPU6050_YAW_Goytaborgs.cpp  # Implementação
└── examples/
    └── yaw_read.cpp            # Exemplo funcional de uso
```

---

## 👨‍💻 Autor

- Criado por: Heverton Souza
- Data: 4 de junho de 2025

---

## 📝 Licença

Este projeto está licenciado sob os termos da licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
