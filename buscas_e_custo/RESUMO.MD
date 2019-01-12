  
  

  
  

COMPLEXIDADE DE ALGORITMOS

  
  

**Custo**

  
  

*O custo final* de um algoritmo pode estar relacionado a diversos fatores: - Tempo de execução - Utilização de memória principal - Utilização de disco - Consumo de energia, etc..

  
  

Por que analisar a complexidade dos algoritmos? A preocupação com a complexidade de algoritmos é fundamental para projetar algoritmos eficientes. Podemos desenvolver um algoritmo e depois analisar a sua complexidade para verificar a sua eficiência. Mas o melhor ainda é ter a preocupação de projetar algoritmos eficientes desde a sua concepção.

  
  

Precisamos definir alguma medida que expresse a eficiência. Costuma-se medir um algoritmo em termos de tempo de execução, quantidade de ações ou o espaço (ou memória) usado. Para o tempo, podemos considerar o tempo absoluto (em minutos, segundos, etc.). Medir o tempo absoluto não é interessante por depender da máquina. Em Análise de Algoritmos conta-se o número de operações consideradas relevantes realizadas pelo algoritmo e expressa-se esse número como uma função de n. Essas operações podem ser comparações, operações aritméticas, movimento de dados, etc.

  
  

O número de operações realizadas por um determinado algoritmo pode depender da particular instância da entrada. Em geral interessa-nos o pior caso, o maior número de operações usadas para qualquer entrada de tamanho n. Análises também podem ser feitas para o melhor caso e o caso médio. Neste último, supõe-se conhecida uma certa distribuição da entrada. Exemplo: Busca sequencial de um dado elemento em um vetor armazenando n elementos de forma aleatória. Discuta o pior caso, melhor caso e o caso médio. No caso médio suponha a distribuição uniforme e que o dado buscado está dentro do vetor.

  
  

Um algoritmo possui a função operações dada por: f1(n) = 2n^2 + 5n operações e um segundo algoritmo pode ter a função dada por: f2(n) = 500n + 4000 operações.

  
  

Um caso de particular interesse é quando n tem valor muito grande (n → ∞), denominado comportamento assintótico. Os termos inferiores e as constantes multiplicativas contribuem pouco na comparação e podem ser descartados. O importante é observar que f1(n) cresce com n^2 ao passo que f2(n) cresce com n. Um crescimento quadrático é considerado pior que um crescimento linear. Assim, vamos preferir o segundo algoritmo ao primeiro.

  
  

Dada uma função g(n), denotamos por O(g(n)) o conjunto das funções { f(n) : ∃ constantes c e n0 tais que 0 ≤ f(n) ≤ cg(n) para n ≥ n0.} Isto é, para valores de n suficientemente grandes, f(n) é igual, menor ou muito próximo de g(n). Como abuso de notação, vamos escrever f(n) = O(g(n)) ao invés de f(n) ∈ O(g(n)).

  
  

Algoritmo 1: f1(n) = 2n^2 + 5n = O(n^2 )

Algoritmo 2: f2(n) = 500n + 4000 = O(n).

  
  

**A Notação O**

  
  

Desprezar constantes aditivas ou multiplicativas: Número de passos 3n será aproximado para n.

  
  

Termos de menor grau podem ser desprezados: n^2 + n será aproximado para n^2 e 6n 3 + 4n - 9 será aproximado para n^3

  
  

![Gráfico busca ingênua](https://kkzwcg.by.files.1drv.com/y4mT5hZRG9MUKG38nBlT4wpVzRGuCbOxdbLJLISGpAeNuDM1vtuA4GTFj4_YJ5TXw3MnHsnLiPZQmE1rIr0h_5A610VleGoT6wXeYelfeeOF23KxJZEjkdWu-nEjF0NOdoe3Ey0a10c6a-EIqOd7j-hRzCbQK0LrcHF0_Pv2VWRGSY-PGZI0wQoyUnVfajGUXJ_ctu-n-KbHQUOxqKdjLLiWA?width=1476&height=1017&cropmode=none)

Após fitar uma reta do gráfico acima no gnuplot, obtemos um algoritmo de custo f1(n) = 0,68n +0,28 , que pode ser aproximado para O(n).

![Gráfico busca binária](https://j6zwcg.by.files.1drv.com/y4mn2Dc_xsRlakfY647RMptC25HmoVa3aVSo_suj5MJFYwl-_R9JGij6zi4qJWxL0KWVYRDJjDSjhTISHsnTlMEJcGxU68OcQhgeCp0qV9ZW6h-YX8SfNuzwNEn3cEtL1hx7SfWH0nZVAB2frsbz9xYY8K-AwizTB8gGeN8tSJCEYa3Fimn1PIiiJVgPC9HsifbUk9XTGgps5Kdm914z_2vMQ?width=1476&height=1017&cropmode=none)



Após fitar uma reta do gráfico acima no gnuplot, obtemos um algoritmo de custo f2(n) = 1,48 log(0,280n) + 0,532, que pode ser aproximado para O(log n).
  
 

  
  

  
  

[http://wiki.icmc.usp.br/images/d/de/Analise_complexidade.pdf](http://wiki.icmc.usp.br/images/d/de/Analise_complexidade.pdf)

  
  

[https://www.ime.usp.br/~song/mac5710/slides/01complex.pdf](https://www.ime.usp.br/~song/mac5710/slides/01complex.pdf)

  
  

[http://www.uern.br/professor/arquivo_baixar.asp?arq_id=5173](http://www.uern.br/professor/arquivo_baixar.asp?arq_id=5173)

