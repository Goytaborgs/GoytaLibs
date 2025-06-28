# PID_Controller

Uma biblioteca simples e eficiente em C++ para controle PID (Proporcional, Integral, Derivativo) em robôs com dois motores, como robôs de tração diferencial ou tração traseira.

Ideal para aplicações embarcadas com **Arduino**, **ESP32** e outras plataformas que necessitam de controle fino de orientação ou velocidade.

---

## ⚙️ Funcionalidades

- Implementação leve de controle PID
- Suporte a ajuste dinâmico dos ganhos Kp, Ki e Kd
- Função de cálculo PID com suporte a `delta_time` real (em segundos)
- Funções auxiliares para cálculo das velocidades dos motores esquerdo e direito com saturação e compensação de bias

---

## 📦 Dependências

- Nenhuma dependência externa além da biblioteca padrão `cstdint`

---

## 📁 Estrutura

```bash
pid_controller/
├── pid_controller.h    # Header principal
├── pid_controller.cpp  # Implementação
└── examples/
    └── pid_demo.cpp    # Exemplo funcional de uso
```

---

## 👨‍💻 Autor

- Criado por: Iarley Santos
- Data: 4 de junho de 2025

---

## 📝 Licença

Este projeto está licenciado sob os termos da licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
