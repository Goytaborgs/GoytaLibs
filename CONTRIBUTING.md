## Diretrizes para novas bibliotecas

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

Use a licença MIT (já incluída no repositório). Caso a biblioteca use outra, deixe isso claro no README.md da pasta dela.