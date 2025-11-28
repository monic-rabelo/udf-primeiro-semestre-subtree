# Visão geral

Repositório criado para exemplificar o uso de subtree no git, usando de exemplo a matéria algoritmos. Foi uma opção usada para que fosse possível importar um repositório original para outro repositório, mantendo os commits, centralizando os projetos em um só repositório e organizando os projetos em diretórios.

* **Diretórios: pastas**

| Matéria | Conteúdos |
| ----------- | ----------- |
| algoritmos  | gerenciamento de alunos com struct, calculadora científica e insertion sort  |
---

## Matérias e contéudos presentes

### Algoritmos e pensamento computacional
- Códigos feito em **linguagem C**, onde possuem o uso de estruturas de condição, repetição, estrutura de dados e estudos gerais de algoritmos (algoritmos de ordenação).
- Feitos com o uso de IDEs, são elas: Visual Studio Code, Dev C++ e GDB online.
- Aplicação de lógica e pensamento computacional, entendendo conceitos de pensamento computacional: abstração, decomposição, reconhecimento de padrões e algoritmos.
- Capacidade de analisar logicamente problemas levantados em sala de aula, tal qual comentar o código, mostrando entendimento sobre o assunto.

---

## Subtree
### Conceito

O método subtree em Git se trata de uma estratégia de merge (combinar o histórico de commits de duas branches diferentes, integrando as alterações de uma para a outra) aplicado a um diretório específico, fazendo com que um repositório original seja aplicado dentro de outro repositório como um subdiretório. <br>
É um método usado caso você queira importar um repositório para dentro de outro, buscando organizar projetos com dependências entre eles. O git subtree foi utilizado nesse repositório para praticar e demonstrar maneiras diferentes de relacionar projetos entre si. <br>
<br>
Quando você altera algo no repositório original (que virou um subdiretório no repositório com subtree), é possível fazer `pull` e `push` dos arquivos do repositório original para o arquivo da subtree.<br>
* A subtree pega os commits do repositório original e importa eles para o repositório subtree. É possível fazer que esses commits originais se tornem um só na subtree, usando o `--squash`, mas também é possível que sem o `--squash` mostre todos os commits individualmente.

---

### Como foi aplicado
As pastas **calculadora científica, gerenciamento de alunos com struct e insertion sort** foram integradas no repositório com o uso de `git subtree add`. Com a subtree **insertion sort**, especificamente, sem o uso de `--squash`, para que mostre os commits detalhadamente.

* Repositório precisa ser clonado na máquina com `git clone`
* Os comandos devem ser aplicados na **raiz** do repositório, exemplo:  `~/Documentos/udf-primeiro-semestre-subtree`
* É possível fazer a adição da subtree usando um remote (nome curto) ou a URL direta.
* `--prefix=algoritmos/calculadora` significa que o git criará uma pasta chamada "calculadora" dentro da pasta "algoritmos" e colocará o conteúdo lá. A ordem é o diretório/subdiretório, importante colocar "/" para indicar que após o primeiro diretório terá um subdiretório.

Exemplo: Adicionar o projeto original **gerenciamento com struct** dentro do repositório com subtree **udf-primeiro-semestre**: o subdiretório "gerenciamento-alunos-com-struct" dentro do diretório "algoritmos"

```bash
// adicionando subtree com remote
git remote add alunos-remote https://github.com/monic-rabelo/gerenciamento-alunos-com-struct.git 
git subtree add --prefix=algoritmos/gerenciamento-alunos-com-struct alunos-remote main --squash
git push

// adicionando subtree com url
git subtree add --prefix=algoritmos/gerenciamento-alunos-com-struct https://github.com/monic-rabelo/gerenciamento-alunos-com-struct.git main --squash
git push
```
*Caso haja alguma alteração no repositório original*: puxando os arquivos do repositório original para a subtree:

```bash
// fazendo pull repositório original para a subtree com remote
git subtree pull --prefix=algoritmos/gerenciamento-alunos-com-struct alunos-remote main --squash
git push

// fazendo pull repositório original para a subtree com url
git subtree pull --prefix=algoritmos/gerenciamento-alunos-com-struct https://github.com/monic-rabelo/gerenciamento-alunos-com-struct.git main --squash
git push
```

*Caso haja alguma alteração na subtree*: enviando os arquivos da subtree para o repositório original:

```bash
// enviando alterações da subtree para o repositório original com remote
git subtree push --prefix=algoritmos/gerenciamento-alunos-com-struct alunos-remote main

// enviando alterações da subtree para o repositório original com url
git subtree push --prefix=algoritmos/gerenciamento-alunos-com-struct https://github.com/monic-rabelo/gerenciamento-alunos-com-struct.git main
```
* É muito importante sempre estar atento se, caso você faça alguma mudança no site GitHub, sempre fazer um pull no arquivo que você está editando e usando o terminal localmente, para os comandos funcionarem sem problemas. É melhor alterar os arquivos sempre no IDE de preferência, para que não hajam conflitos.
---

## Informações adicionais:

* É importante ficar atento para a ordem dos comandos, também prestando na criação dos diretórios e subdiretórios, qual é o repositório original e qual será a subtree.
* Esse repositório é apenas um teste, qualquer erro nos conceitos ou ordens de comando fique a vontade de sugerir correções.




