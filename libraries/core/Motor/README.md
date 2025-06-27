# Motor_TB6612FNG

Uma biblioteca simples em C++ para controle de motores DC usando o driver em ponte H **TB6612FNG**, compatível também com outros drivers que possuam a mesma pinagem de controle.

Ideal para uso com **ESP32**, **Arduino** e outros sistemas embarcados que suportem PWM.

---

## ⚙️ Funcionalidades

- Suporte a controle de direção e velocidade via PWM
- Compatível com `ledcWrite()` (ESP32)
- Abstrai toda a configuração de pinos (`pinMode`, `ledcAttachPin`, etc.)
- Compatível com drivers com pinos do tipo semelhantes aos da TB6612FNG

---

## 📦 Dependências

- [`Arduino.h`](https://docs.arduino.cc/language-reference/pt/)
- Funções `ledcWrite`, `ledcAttachPin`, `ledcSetup` (para ESP32)

---

## ⚡ Pinagem típica do TB6612FNG
| Pino do TB6612FNG         | Conexão sugerida                                                         |
| --------------------------| ------------------------------------------------------------------------ |
| AI1 / AI2 / BI1 / BI2     | GPIOs digitais                                                           |
| PWMA / PWMB               | GPIO com suporte a PWM                                                   |
| STBY                      | *Não gerenciado pela biblioteca – ligue no 3.3V ou controle manualmente* |

```
⚠️Importante: a biblioteca não controla o pino STBY. Você deve garantir que ele esteja em nível alto (HIGH) para o motor funcionar.
```

## 📁 Estrutura
```bash
Motor/
├── Motor_TB6612FNG.h       # Header principal
├── Motor_TB6612FNG.cpp     # Implementação
└── example/
    └── motor_demo.cpp      # Exemplo funcional de uso
```

## 👨‍💻 Autor
- Criado por: Marllon Batista
- Data: 5 de novembro de 2024

## 📝 Licença
Este projeto está licenciado sob os termos da licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.