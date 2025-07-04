# ESP32L298nMini

Uma biblioteca simples em C++ para controle de motores DC usando o driver em ponte H **L298N mini**, compatível também com outros drivers que possuam a mesma pinagem de controle.

Ideal para uso com **ESP32** e outros sistemas embarcados que suportem PWM de forma semalhante a ele.

---

## ⚙️ Funcionalidades

- Suporte a controle de direção e velocidade via PWM
- Compatível com `ledcWrite()` (ESP32)
- Abstrai toda a configuração de pinos (`pinMode`, `ledcAttachPin`, etc.)
- Compatível com drivers com pinos do tipo semelhantes aos da L298N mini

---

## ✅ Compatibilidade

### IDEs testadas

| IDE                 | Status                   |
| ------------------- | ------------------------ |
| Arduino IDE         | ✅                       |
| PlatformIO (VSCode) | ✅ (framework _Arduino_) |

`Legenda: ⚠️ Não testado / ❌ Não compila / ✅ Funciona `

### Microcontroladores testados

| Microcontrolador   | Status                  |
| ------------------ | ----------------------- |
| ESP32 (DevKit v1)  | ✅                      |
| ESP32-S3           | ⚠️ (esperado funcionar) |
| Arduino UNO / Nano | ❌                      |

`Legenda: ⚠️ Não testado / ❌ Imcompatível / ✅ Funciona `

---

## 📦 Dependências

- [`Arduino.h`](https://docs.arduino.cc/language-reference/pt/)
- Funções `ledcWrite`, `ledcAttachPin`, `ledcSetup` (para ESP32)

---

## ⚡ Pinagem típica do L298N mini

| Pino do L298N mini    | Conexão sugerida       |
| --------------------- | ---------------------- |
| IN1 / IN2 / IN3 / IN4 | GPIO com suporte a PWM |

````
## 📁 Estrutura

```bash
Motor/ESP32L298nMini
├── ESP32L298nMini.h       # Header principal
├── ESP32L298nMini.cpp     # Implementação
└── examples/
    └── ESP32L29nMiniExample.cpp    # Exemplo funcional de uso
````

## 👨‍💻 Autor

- Criado por: Marllon Batista
- Data: 5 de novembro de 2024

## 📝 Licença

Este projeto está licenciado sob os termos da licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
