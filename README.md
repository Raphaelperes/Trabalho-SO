# Trabalho-SO
Raphael Peres - 5224, João Pedro - 5199, Ezquiel 5206
Como proposto no trabalho de Sistemas Operacionais fizemos um interpretador shell que execultadas as funções do terminal no linux, utilizei uma função flush_() que achei para limpar
o buffer pois a função pronta getcha() estava crashando o codigo fazendo com que se digitasse duas vezes o mesmo codigo para que ele fosse executavel, além de bugar o quit fazendo
assim que so funcionasse o "espaço"quit para sair do programa, fizemos uma if dentro do loop que ignora as virgulas fazendo com que o programa continue sendo execultado não 
importa quantas virgulas voce coloque ele vai ignorar todas elas e execultar um comando a baixo do outro.
Para o tratamento de codigo errado deixamos que o cmd mesmo te alerte sobre o erro basicamente o nosso interpretador shell esta simulando o cmd do linux sem muito trabalho execultando
todos os comandos um abaixo do outro. Determinamos um define 512 pois um regra era que não poderia ter mais que 512 caracteres na linha assim não sera executada mais que esse tanto
de caracter em uma linha de codigo.
Bom eu fiz teste com no maximo 4 comandos todos executados corretamente. Se não colocar a "," entre dois comandos ocorre o erro, mas o programa não é finalizado ele so sera toltamente
finalizado se voce digitar o quit, tentamos tratar os 3 tipos diferentes de digitação do quit sem espaço com espaço e com duplo espaço caso voce venha a digitar mais que 2 espaços
infelizmente ele não ira morrer.

https://github.com/Raphaelperes/Trabalho-SO
