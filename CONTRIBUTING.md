## Requisitos de documentação para novas bibliotecas

Toda biblioteca adicionada à pasta `libraries/core/` deve conter:

1. Um arquivo `.h` com banner padronizado no topo (com descrição, autor, data e dependências).
2. Um exemplo funcional localizado em `examples/`.
3. Um arquivo `README.md` **dentro da própria pasta da biblioteca**, explicando:

   - O que a biblioteca faz
   - Quais são suas dependências
   - Observações específicas (caso necessário)
   - Estrutura do diretório
   - Informações sobre o autor e data
   - Licença

   > 📄 **Modelo pronto:** utilize o arquivo [`library_readme_template.md`](docs/library_readme_template.md)(localizado na pasta `docs/`) como base para criar o `README.md` da sua biblioteca.

---

## Diretrizes

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
└── examples/
    └── pid_demo.cpp
```

### 5. Licença

Use a licença MIT (já incluída no repositório). Caso a biblioteca use outra, deixe isso claro no README.md da pasta dela.
