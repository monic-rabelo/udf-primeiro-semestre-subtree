# Visão geral

Repositório criado para exemplificar o uso de subtree com git, usando de exemplo a matéria algoritmos. Foi uma opção usada para que pudusse "passar" um repositório para outro repositório mantendo os commits e organizando os projetos em diretórios (pastas).

| Matéria | Conteúdos |
| ----------- | ----------- |
| algoritmos  | gerenciamento de alunos com struct, calculadora científica e insertion sort  |
---

## Matérias e contéudos presentes

### Algoritmos e pensamento computacional
- Códigos feito em **linguagem C**, onde possuem o uso de estruturas de condição, repetição, estrutura de dados e estudos gerais de algoritmos (algoritmos de ordenação).
- Feitos com o uso de IDEs, são elas: Visual Studio Code, Dev C++ e GDB online.
- Aplicação de lógica e pensamento computacional, entendendo conceitos de pensamento computacional: abstração, decomposição, reconhecimento de padrões e algoritmos.
- Capacidade de analisar logicamente problemas levantados em sala de aula, tal qual comentar o código, mostrando entedimento sobre o assunto.

---

## Subtree
### Conceito e porquê foi usado

O método subtree em Git se trata de uma estratégia de merge (combinar o histórico de commits de duas branches diferentes, integrando as alterações de uma para a outra) aplicado a um diretório específico, fazendo com que um repositório externo seja aplicado dentro de outro repositório como um subdiretório. <br>
É um método usado caso você queira importar um repositório para dentro de outro, buscando organizar projetos com dependências entre eles. O git subtree foi utilizado nesse repositório para praticar e demonstrar maneiras diferentes de relacionar projetos entre si. <br>
<br>
Quando você altera algo no repositório externo (que virou um subdiretório no repositório com subtree), é possível fazer `pull` e `push` dos arquivos dos arquivos do repositório externo para o arquivo da subtree.<br>
* O subtree pega os commits do repositório externo e importa eles para o repositório subtree. É possível fazer que esses commits externos se tornem um só na subtree, usando o `--squash`, mas também é possível que sem o `--squash` mostre todos os commits individualmente.

### Como foi aplicado
As pastas **calculadora científicia, gerenciamento de alunos com struct e insertion sort** foram integradas no repositório com o uso de `git subtree add`, com o subtree **insertion sort**, especificamente, sem o uso de `--squash` para que mostre os commits detalhadamente.

* Repositório precisa ser clonado na máquina com `git clone`
* Os comandos devem ser aplicados na **raiz** do repositório, exemplo:  `~/Documentos/udf-primeiro-semestre-subtree`
* É possível fazer a adição da subtree usando um remote (nome curto) ou a URL direta.

Exemplo: Adicionar o projeto externo **gerenciamento com struct** dentro do repositório com subtree **udf-primeiro-semestre**: o subdiretório "gerenciamento-alunos-com-struct" dentro do diretório "algoritmos"

```bash
// adicionando subtree com remote
git remote add alunos-remote https://github.com/monic-rabelo/gerenciamento-alunos-com-struct.git 
git subtree add --prefix=algoritmos/gerenciamento-alunos alunos-remote main --squash
git push

// adicionando subtree com url
git subtree add --prefix=algoritmos/gerenciamento-alunos https://github.com/monic-rabelo/gerenciamento-alunos-com-struct.git main --squash
git push
```

```bash
// fazendo pull repositório externo para a subtree com remote
git subtree pull --prefix=algoritmos/gerenciamento-alunos alunos-remote main --squash
git push

// fazendo pull repositório externo para a subtree com url
git subtree pull --prefix=algoritmos/gerenciamento-alunos https://github.com/monic-rabelo/gerenciamento-alunos-com-struct.git main --squash
git push
```

## Informações adicionais:

* É importante ficar atento para a ordem dos comandos, também prestando na criação dos diretórios e subdiretórios, qual é o repositório externo e qual será a subtree.
* Esse repositório é apenas um teste, qualquer erro nos conceitos ou ordens fique a vontade de sugerir correções.
