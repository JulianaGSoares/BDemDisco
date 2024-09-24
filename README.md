## Projeto Banco de Dados em Disco
Código desenvolvido como um desafio em sala de aula.

    Desafio: Gerenciamento de Registros

# Criar um sistema que usa lista dinâmica, lista duplamente ligada e árvore binária para para simular um banco de dados em disco.

## Os dados a serem adicionados devem ser os seguintes:
- CPF (chave primária)
- Nome (índice de ordenação)
- Endereco
- Telefone
- email

## O sistema deve ter os seguintes itens de menu:
 1. Adicionar
 2. Alterar
 3. Excluir
 4. Procurar
 5. Relatório
 6. Sair

## Cada função deve seguir as seguintes regras:
1 - Adicionar:
- Quando for selecionada a opção Adicionar, o programa deve pedir pelo CPF.
- Depois pesquisar se o CPF já está na árvore binária, se estiver dizer que o CPF já está cadastrado.
- Senão, pedir os outros dados, adicionar na Lista Dinâmica, pegando o número do registro, adicionar na Árvore Binária e na Lista Ligada.

2 - Alterar:
- Quando for selecionada a opção Alterar, pedir o CPF, buscar na Árvore Binária. Se não existir, emitir a mensagem CPF não cadastrado.
- Senão, pedir os outros dados e alterar a Lista Dinâmica, se o nome for alterado, excluir da Lista Ligada o anterior e adicionar o novo.
- O CPF não deve ser alterado, ele é Chave Primária.

3 - Excluir:
- Quando for selecionada a opção Excluir, pedir o CPF, buscar na Árvore Binária. Se não existir, emitir a mensagem CPF não cadastrado.
- Senão, excluir da Árvore Binária e da Lista Ligada. Não é necessário excluir da Lista Dinâmica pois os dados estarão inacessíveis.

4 - Procurar:
- Quando for selecionada a opção Procurar, pedir o CPF, buscar na Árvore Binária. Se não existir, emitir a mensagem CPF não cadastrado.
- Senão, listar os dados da Lista Dinâmica.

5 - Relatório:
- Quando for selecionada a opção Relatório, usar a Lista Ligada para imprimir todos os registro ordenados por nome.
