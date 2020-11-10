# Construindo um Interpretador Shell - Sistemas Operacionais/Sistemas de Informação - UFV-CRP

## Raphael Peres - 5224
## João Pedro - 5199
## Ezequiel Gonçalves - 5206

## Descrição do projeto

Como proposto, fizemos um interpretador shell que executa as funções do terminal linux em geral. Utilizamos uma função flush_() que limpaa o buffer, pois a função pronta getcha() estava crashando o código, fazendo com que fosse necessário digitar duas vezes o mesmo comando para que o mesmo fosse executado, além de bugar o quit, fazendo com que só funcionasse a combinação "space" + "quit" para sair do programa. 

Fizemos um tratamento dentro do loop que ignora as vírgulas, fazendo com que o programa continue sendo executado, independente de quantas vírgulas sejam inseridas, ignorarando todas elas e executando um comando após do outro.

Para comandos errados deixamos que o CMD nativo mesmo alerte sobre o erro. Basicamente o nosso interpretador shell está simulando o CMD do linux, executando todos os comandos um após o outro.

Determinamos um tamanho  máximo de 512 caracteres, suprindo uma das regras do projeto.

Bom, fizemos testes com no máximo 4 comandos, todos executados corretamente. Se não colocar a "," entre dois comandos ocorre um erro, porém o programa não é finalizado.

Ele será toltamente finalizado apenas se digitado o comando "quit".

Tentamos tratar os 3 tipos diferentes de digitação do quit: sem espaço, com espaço e com duplo espaço. Caso venha a ser digitado mais que 2 espaços, infelizmente ele não irá morrer.

Pra execultar o codigo voce digita:
$ gcc shell.c -o shell
$ ./shell

https://github.com/Raphaelperes/Trabalho-SO
