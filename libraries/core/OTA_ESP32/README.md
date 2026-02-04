# OtaManager

Biblioteca auxiliar em C++ para gerenciamento de conexão Wi-Fi e atualizações Over-The-Air (OTA) em dispositivos ESP32.  
Ela simplifica a configuração do OTA no framework Arduino, permitindo que o
firmware seja atualizado remotamente sem necessidade de conexão via cabo USB.

Compatível com projetos baseados em Arduino Framework para ESP32, com foco em uso via PlatformIO.

---

## ⚙️ Funcionalidades

- Conexão automática à rede Wi-Fi
- Configuração simplificada de OTA para ESP32
- Suporte a hostname personalizado
- Suporte a autenticação por senha OTA
- Interface estática simples (`begin()` e `handle()`)
- Integração fácil com loops não bloqueantes

---

## ✅ Compatibilidade

### IDEs testadas

| IDE                   | Status |
|-----------------------|--------|
| Arduino IDE           | ⚠️     |
| PlatformIO (VS Code)  | ✅     |

```Legenda: ⚠️ Não testado / ❌ Não compila / ✅ Funciona```

### Microcontroladores testados

| Microcontrolador  | Status |
|-------------------|--------|
| ESP32 (DevKit v1) | ✅     |
| Outros ESP32         | ⚠️ (esperado funcionar) |
| Arduino Uno / Mega| ❌     |

```Legenda: ⚠️ Não testado / ❌ Incompatível / ✅ Funciona```

---

## 📦 Dependências

- [`WiFi.h`](https://www.arduino.cc/en/Reference/WiFi)
- `ArduinoOTA`
- `Arduino.h`

---

## ⚡ Uso com PlatformIO (OTA)

### Configuração do `platformio.ini`

Para realizar uploads via OTA usando o PlatformIO, **é necessário adicionar** o seguinte bloco ao arquivo `platformio.ini`:

```ini
upload_protocol = espota
upload_port = IP_DO_ESP32 #Exemplo: 192.168.137.XX
upload_flags =
    --port=3232
    --auth=SenhaOTA #Exemplo ota123 / Caso tenha optado por não adicionar uma senha na chamada da função begin(), basta remover essa flag.

board_build.partitions = default.csv
```

## ⚠️ Observações específicas

- Esta biblioteca **não gerencia reconexão automática ao Wi-Fi** caso a conexão seja perdida durante a execução.
- A função `OtaManager::handle()` **deve ser chamada continuamente** dentro do `loop()` para que o OTA funcione corretamente.
- Para o primeiro upload do firmware, é necessário realizar o upload via **porta serial** antes de utilizar OTA.
- A porta padrão do OTA é **3232**, podendo ser alterada via configuração no `platformio.ini`.

---

## 🔍 Como descobrir o IP do ESP32

O IP do ESP32 pode ser obtido por meios comuns, como:
- Interface do roteador (lista de dispositivos conectados)
- Aplicativos de varredura de rede
- Outros dispositivos que identifiquem hosts na mesma rede

Além disso, a própria biblioteca imprime o IP no monitor serial, desde que:
- O ESP32 esteja conectado via cabo USB
- A função `OtaManager::begin()` tenha sido chamada corretamente no `setup()`

Esse `Serial.println()` é executado dentro da função `begin()`, logo após a conexão bem-sucedida ao Wi-Fi.

---

## 🧠 Sobre board_build.partitions

A linha:
```ini
board_build.partitions = default.csv
```
é necessária para garantir que haja espaço suficiente para a partição OTA,permitindo que o ESP32 armazene o firmware atual e o novo firmware durante a atualização.

Caso o projeto cresça e ocorram erros relacionados a tamanho de firmware, é possível trocar essa partição por outra com mais espaço para a aplicação. Para altera-la, consulte o esquema de partições e escolha a mais adequada.

---

## 🚨 IMPORTANTE – Primeiro upload via serial
Para que o OTA funcione, o primeiro upload do firmware deve ser feito via porta serial.

Durante esse primeiro upload, o bloco abaixo NÃO pode estar ativo no `platformio.ini`:
```ini
upload_protocol = espota
upload_port = ...
upload_flags = ...
```

**Você deve:**
- Remover esse bloco ou
- Comentá-lo temporariamente

Somente após o firmware estar gravado no ESP32 via USB é que esse bloco deve
ser adicionado novamente para permitir uploads OTA.

**Por que isso é necessário?**
- O arquivo platformio.ini pertence exclusivamente ao PlatformIO
- Ele não é compilado nem enviado para o ESP32
- Ele apenas informa ao PlatformIO como o upload deve ser feito

Portanto, não há nenhum problema em modificar o platformio.ini depois que o firmware já foi carregado via serial.

---
## 📁 Estrutura

```bash
OTA_ESP32r/
├── OTA_ESP32.h        # Header principal
├── OTA_ESP32.cpp      # Implementação
└── examples/
    └── ota_demo/      # Exemplo funcional de uso

```
---

## 👨‍💻 Autor

- Criado por: Heverton Souza
- Data: 04 de Fevereiro de 2026

---

## 📝 Licença

Este projeto está licenciado sob os termos da licença MIT. Veja o arquivo [LICENSE](../../../LICENSE) para mais detalhes.
