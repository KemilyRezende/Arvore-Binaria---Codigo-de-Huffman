# Arvore-Binaria---Codigo-de-Huffman
Resolução do exercício proposto em sala.
# Árvore Binária:
São árvores cuja estrutura é formada por vértices tal que cada um destes tenha um filho esquerdo e direito. Todas as funções de uma estrutura em árvore são recursivas e cada filho de uma raiz é considerado uma subárvore.
O processo de inserção em árvore seguirá uma regra, valores menores que a raiz serão inseridos como filho esquerdo e maiores como filho direito.
# Código de Huffman
Trata-se de uma codificação de caracteres que permite compactar arquivos de texto, ou seja, representar um arquivo de texto A por um arquivo de bits B bem menor. O algoritmo de Huffman calcula uma tabela de códigos sob medida para o arquivo A de modo que o arquivo B seja o menor possível.
# Árvore de Huffman
É uma árvore binária, entretanto, esta não segue a regra de inserção anteriormente mencionada. 
Neste caso a árvore é construída de forma a otimizar a busca de palavras de um arquivo, de forma que as palavras mais recorrentes tenham os menores custos de busca.
# Funcionamento do programa:
É fornecido pelo usuário um arquivo de texto, em seguida as palavras presentes são contabilizadaas quanto à recorrência no arquivo (no processo as stop words são removidas, vide arquivo StopWords.txt - File). A contabilização é feita tomando por base a seguinte equação: Rp/(Rp.max - Rp.min).
Feita essa contabilização um vector de Nós é criado e ordenado de forma crescente, a partir deste a Árvore de Huffman será criada. 
Feita a árvore esta será percorrida usando a metodologa DFS e atribuindo a cada Nó, ou seja, a cada palavra a string Huffman - código que a substituirá no arquivo tokenizado. 
Após a definição das string Huffman elas são armazenadas em um tabela Hash e então o arquivo é lido mais uma vez para criar um novo arquivo tokenizado.
# Funções importantes:
  main.cpp:
    insertWord: Procura se uma palavra já foi inserida no vector, caso sim, o contador desta é incrementado, caso não esta é inserida.
    StopList: Cria a lista de stop words a partir do arquivo StopWords.txt.
    StopWord: Retorna verdadeiro se uma palavra é uma stop word e falso caso contrário.
    cmp/cmpNode: Parâmetros para usar a função sort.
    createTree: A partir de um vetor de nós cria a Árvore de Huffman das folhas até a raiz. Os dois menores valores são ligados a um novo nó e este é inserido no vetor ao passo que os dois são apagados, logo depois o vetor é novamente ordenado. Esse processo se repete até que só haja no vetor o nó raiz.
    Hashing: Função que calcula em que posição na tabela Hash uma palavra deve estar. Utiliza o método da congruência linear aplicado à string.
  No.cpp:
    HuffmanDFS: Utilizando o método de busca em profundidade percorre a árvore recursivamente até o ultimo nó, ao caminhar para a esquerda um 0 é concatenado a string Huffman, para a direita um 1. Ao encontrar o último nó retorna a palavra armazenada e apaga-o, ou seja, a árvore é destruída para criar a Hash com os valores de HUffman.
