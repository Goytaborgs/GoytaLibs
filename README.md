# GoytaLibs

**GoytaLibs** é uma coleção de bibliotecas C/C++ organizadas pela equipe de robótica [Goytaborgs](https://www.goytaborgs.com.br).

- ⚙️ Prontas para uso com Arduino e ESP32
- 📐 Enxutas, bem documentadas e voltadas para desempenho
- 🧠 Mistura de código próprio (_core_) e bibliotecas externas confiáveis (_third_party_)

---

## 📁 Organização do repositório

| Pasta                  | Conteúdo                                                                 |
|------------------------|--------------------------------------------------------------------------|
| `libraries/core`       | Bibliotecas desenvolvidas ou adaptadas pela equipe (Motores, PID, MPU_customizada…) |
| `libraries/third_party`| Bibliotecas externas sem modificações (I2Cdev, MPU6050, etc.)         |
| `libraries/core/{lib}/examples`             | Exemplos práticos para testar cada biblioteca                            |
| `docs`                 | Diagramas, datasheets, anotações extras                                  |

---

## ✍️ Diretrizes para novas bibliotecas

Ao adicionar ou editar uma biblioteca em `libraries/core`, siga estas boas práticas:

### 1. Banner no cabeçalho

Todos os arquivos `.h` devem começar com um bloco como este:

```cpp
/********************************************************************
 * File: minha_biblioteca.h
 * 
 * Description: Explicação detalhada…
 *              Manter a identação dessa forma…
 * 
 *  Dependencies:
 * - NomeDaBiblioteca1.h (explicação breve se necessário)
 * - NomeDaBiblioteca2.h
 *
 * Created by: Seu Nome – MM-DD-AAAA
 * Revised by: (opcional)
 ********************************************************************/
```

### 2. Comentários das funções

Documente todas as funções públicas com este estilo:

```cpp
 /**
 * @brief Descreve o que a função faz.
 * 
 * @param parametro Explica o parâmetro.
 * @return Explica o que é retornado.
 */
```
### 3. Separação .h / .cpp

Nunca implemente as funções diretamente no .h. Use .cpp para definições e .h para declarações.

### 4. Exemplo de uso

Inclua ao menos um sketch funcional da biblioteca dentro da pasta example/ da própria biblioteca.

```bash
libraries/core/pid_controller/
├── pid_controller.h
├── pid_controller.cpp
└── example/
    └── pid_demo.cpp
```
### 5. Licença

Use a licença MIT (já incluída no repositório).

## 🤝 Como contribuir
1. Faça um fork deste repositório e crie uma branch.
2. Siga as diretrizes acima.
3. Abra um Pull Request explicando o que mudou e por quê.
4. Um dos mantenedores revisará e dará o merge.


Dúvidas? Abra uma issue ou fale conosco no pelo email da [Goytaborgs](goytaborgs.centro@iff.edu.br).

## 📜 Licença
Todo o conteúdo do GoytaLibs está disponível sob a [licença MIT](https://web.mit.edu/), salvo indicação em contrário.