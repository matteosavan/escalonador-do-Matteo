# escalonador

Este programa ajuda a manipular matrizes (matriz aumentada) para facilitar
a resolução de sistemas lineares usando operações elementares de linha.

Principais características
- Entrada interativa de matrizes (numeradores e — opcionalmente — denominadores).
- Suporte a frações representadas por numerador/denominador.
- Operações elementares de linha:
	- Multiplicar linha por um inteiro
	- Dividir linha (ajusta denominadores)
	- Trocar duas linhas
	- Somar e subtrair linhas
	- Simplificar frações
- Impressão formatada da matriz com frações reduzidas quando possível.

Como funciona (baseado em [main.c](main.c))

1. O programa pergunta o número de linhas e colunas.
2. Pede os numeradores linha a linha.
3. Pergunta se há denominadores diferentes de 1; se sim, pede os denominadores.
4. Entra em um loop interativo onde você emite comandos para operar sobre a matriz.

Comandos principais (insira um caractere e pressione Enter):
- `p` — printar a matriz atual
- `s` — simplificar todas as frações
- `*` — multiplicar uma linha por um inteiro
- `/` — dividir uma linha (multiplica denominadores)
- `t` — trocar duas linhas
- `+` — somar uma linha em outra
- `-` — subtrair uma linha de outra
- `.` — encerrar o programa

Exemplo rápido de uso
1. Compile:

```bash
gcc main.c -o escalonador
```

2. Execute:

```bash
./escalonador
```

3. Sessão (resumida):
- O programa pergunta: "quantas linhas?" e "quantas colunas?"
- Insira os numeradores por linha.
- Se houver denominadores diferentes de 1, responda `S` e insira-os.
- Use os comandos acima para manipular a matriz; use `p` para ver o resultado.

Observações e limitações
- Frações com denominador 0 não são processadas para divisão; o programa
	evita simplificações quando o denominador é zero.
- A simplificação de frações usa um conjunto fixo de primos (até 97).
- Entrada inválida pode fazer o comportamento ser imprevisível — tome
	cuidado ao digitar valores e índices de linhas.

Referência
- Código-fonte: [main.c](main.c)

Contribuições
- Alterações, correções ou melhorias são bem-vindas. Abra uma issue ou um pull request.

Licença
- Este repositório não especifica uma licença — adicione uma se quiser permitir
	usos/reutilizações explícitas.
