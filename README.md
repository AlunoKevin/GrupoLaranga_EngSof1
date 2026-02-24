# 🏥 CliniGest - Sistema de Gestão Clínica

Este projeto é uma aplicação modular desenvolvida em **C++** com o framework **Qt**, seguindo padrões de arquitetura como **Facade** e **Repository** para organização de responsabilidades entre lógica, dados e interface.

---

## 📂 Estrutura do Projeto

O projeto está dividido em três grandes módulos:

1.  **CliniGestLogic**: Contém as regras de negócio, modelos (Consulta, Triagem) e as interfaces de serviços. Gera a biblioteca `libCliniGestLogic.so`.
2.  **CliniGestData**: Responsável pela persistência em banco de dados SQL e implementação dos repositórios. Gera a biblioteca `libCliniGestData.so`.
3.  **CliniGestGUI**: Interface gráfica desenvolvida em Qt Widgets. Contém o executável principal.

---

## 🚀 Processo de Compilação e Execução

Todo o processo abaixo deve ser executado via terminal dentro da pasta `CliniGestGUI`.

### 1. Entrar na pasta do módulo principal

```bash
cd CliniGestGUI
```

### 2. Limpar arquivos temporários

```bash
make clean
```

### 3. Gerar o Makefile e Compilar

```bash
qmake6
make
```

### 4. Configurar Bibliotecas e Executar

```bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/../CliniGestLogic:$(pwd)/../CliniGestData

./CliniGestGUI
```

## 🧪 Executando os Testes Unitários

Para garantir que a lógica de agendamento, triagem e manutenção de usuário esteja funcionando, siga os passos abaixo:

### 1. **Acesse a pasta de mocks/testes:**
   ```bash
   cd tests/mocks
   ```

### 2. Gere o Makefile (necessário apenas na primeira vez ou se mudar o .pro):

```bash
qmake6
```

### 3. Compile os testes:

```bash
make clean && make
```

### 4. Execute os testes:

```bash
./test
```

## 📝 Atualizar Documentação

Sempre que alterar o código, atualize a documentação técnica rodando:

```bash
doxygen Doxyfile_Novo
```