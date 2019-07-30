Este trabalho foi desenvolvido por :

Christian Rodrigues Moura - 3629
Douglas Patrick Barbosa Boaventura -- 5144

Jordi Henrique Marques da Silva -- 3927




Neste codigo é feita a implementação dos algoritmos de Prim e de Kruskal para fazer o cenario de K-agrupamentos.

Esses algoritmos são usados para descobrir uma arvore geradora minima (MST). o problema da MST consiste em encontrar, 
dado um grafo com arestas ponderadas, uma estrutura de conexão (árvore) em que todos os nós (geradora) se conectem (direta ou indiretamente)
uns aos outros. Essa estrutura deve possuir o menor peso possível, onde o peso é dado pela soma dos pesos das arestas escolhidas (mínima).

No algoritmo de Kruskal, começamos com várias árvores separadas (no começo, cada nó é uma árvore) e vamos juntando essas árvores
através das arestas de menor valor até formarmos uma árvore geradora. No algoritmo de Prim, iniciamos com uma árvore formada
por um único nó (qualquer nó do grafo) e vamos adicionando à árvore, a cada passo, o nó que estiver mais próximo dela.

O agrupamento de dados atribui objetos semelhantes juntos para descobrir estruturas em dados que não possuem rótulos. 
É uma das mais populares técnicas de aprendizado de máquina sem supervisão com casos de uso variados. Quando você tem 
um grande volume de informações e deseja transformar essas informações em uma análise gerenciável de cluster, é uma
abordagem útil. Ele pode ser usado para resumir os dados e preparar os dados para outras técnicas. 

SAIDA PRIM : Fornece um vetor com os pais de cada vertice que formam a arvore geradora minima.

Vertice: 1 => Pai: 0

Vertice: 2 => Pai: 0

Vertice: 3 => Pai: 0

Vertice: 4 => Pai: 0

Vertice: 5 => Pai: 0

Vertice: 6 => Pai: 0

Vertice: 7 => Pai: 0

Vertice: 8 => Pai: 0

Vertice: 9 => Pai: 0

Vertice: 10 => Pai:0

Vertice: 11 => Pai: 0

Vertice: 12 => Pai: 0

Vertice: 13 => Pai: 0

Vertice: 14 => Pai: 0

Vertice: 15 => Pai: 0

Vertice: 16 => Pai: 0

Vertice: 17 => Pai: 0

Vertice: 18 => Pai: 0

Vertice: 19 => Pai: 0

Vertice: 20 => Pai: 0

Vertice: 21 => Pai: 0

Vertice: 22 => Pai: 0

Vertice: 23 => Pai: 0

Vertice: 24 => Pai: 0

Vertice: 25 => Pai: 0

Vertice: 26 => Pai: 0

Vertice: 27 => Pai: 0

Vertice: 28 => Pai: 0

Vertice: 29 => Pai: 0

Vertice: 30 => Pai: 0

Vertice: 31 => Pai: 0

Vertice: 32 => Pai: 0

Vertice: 33 => Pai: 0

Vertice: 34 => Pai: 0

Vertice: 35 => Pai: 0

Vertice: 36 => Pai: 0

Vertice: 37 => Pai: 0

Vertice: 38 => Pai: 0

Vertice: 39 => Pai: 0

Vertice: 40 => Pai: 0

Vertice: 41 => Pai: 0

Vertice: 42 => Pai: 0

Vertice: 43 => Pai: 0

Vertice: 44 => Pai: 0

Vertice: 45 => Pai: 0

Vertice: 46 => Pai: 0

Vertice: 47 => Pai: 0

Vertice: 48 => Pai: 0

Vertice: 49 => Pai: 0

Vertice: 50 => Pai: 0

Vertice: 51 => Pai: 1

Vertice: 52 => Pai: 63

Vertice: 53 => Pai: 63

Vertice: 54 => Pai: 63

Vertice: 55 => Pai: 63

Vertice: 56 => Pai: 50

Vertice: 57 => Pai: 50

Vertice: 58 => Pai: 50

Vertice: 59 => Pai: 50

Vertice: 60 => Pai: 50

Vertice: 61 => Pai: 50

Vertice: 62 => Pai: 50

Vertice: 63 => Pai: 50

Vertice: 64 => Pai: 50

Vertice: 65 => Pai: 50

Vertice: 66 => Pai: 50

Vertice: 67 => Pai: 50

Vertice: 68 => Pai: 50

Vertice: 69 => Pai: 50

Vertice: 70 => Pai: 50

Vertice: 71 => Pai: 50

Vertice: 72 => Pai: 50

Vertice: 73 => Pai: 50

Vertice: 74 => Pai: 50

Vertice: 75 => Pai: 50

Vertice: 76 => Pai: 50

Vertice: 77 => Pai: 50

Vertice: 78 => Pai: 50

Vertice: 79 => Pai: 50

Vertice: 80 => Pai: 50

Vertice: 81 => Pai: 50

Vertice: 82 => Pai: 50

Vertice: 83 => Pai: 50

Vertice: 84 => Pai: 50

Vertice: 85 => Pai: 50

Vertice: 86 => Pai: 50

Vertice: 87 => Pai: 50

Vertice: 88 => Pai: 50

Vertice: 89 => Pai: 63

Vertice: 90 => Pai: 63

Vertice: 91 => Pai: 63

Vertice: 92 => Pai: 77

Vertice: 93 => Pai: 50

Vertice: 94 => Pai: 50

Vertice: 95 => Pai: 50

Vertice: 96 => Pai: 50

Vertice: 97 => Pai: 50

Vertice: 98 => Pai: 50

Vertice: 99 => Pai: 50

Vertice: 100 => Pai: 50

Vertice: 101 => Pai: 53

Vertice: 102 => Pai: 53

Vertice: 103 => Pai: 53

Vertice: 104 => Pai: 53

Vertice: 105 => Pai: 53

Vertice: 106 => Pai: 53

Vertice: 107 => Pai: 53

Vertice: 108 => Pai: 53

Vertice: 109 => Pai: 53

Vertice: 110 => Pai: 53

Vertice: 111 => Pai: 53

Vertice: 112 => Pai: 53

Vertice: 113 => Pai: 53

Vertice: 114 => Pai: 67

Vertice: 115 => Pai: 67

Vertice: 116 => Pai: 67

Vertice: 117 => Pai: 67

Vertice: 118 => Pai: 67

Vertice: 119 => Pai: 67

Vertice: 120 => Pai: 67

Vertice: 121 => Pai: 67

Vertice: 122 => Pai: 69

Vertice: 123 => Pai: 69

Vertice: 124 => Pai: 69

Vertice: 125 => Pai: 69

Vertice: 126 => Pai: 69

Vertice: 127 => Pai: 69

Vertice: 128 => Pai: 69

Vertice: 129 => Pai: 69

Vertice: 130 => Pai: 69

Vertice: 131 => Pai: 69

Vertice: 132 => Pai: 69

Vertice: 133 => Pai: 69

Vertice: 134 => Pai: 79

Vertice: 135 => Pai: 79

Vertice: 136 => Pai: 79

Vertice: 137 => Pai: 64

Vertice: 138 => Pai: 64

Vertice: 139 => Pai: 64

Vertice: 140 => Pai: 51

Vertice: 141 => Pai: 51

Vertice: 142 => Pai: 51

Vertice: 143 => Pai: 51

Vertice: 144 => Pai: 51

Vertice: 145 => Pai: 51

Vertice: 146 => Pai: 51

Vertice: 147 => Pai: 51

Vertice: 148 => Pai: 63

Vertice: 149 => Pai: 53


SAIDA KRUSKAL: Fornece os vertices da MST.




0 	 2 	 0.100000

7 	 2 	 0.100000

9 	 2 	 0.100000

10 	 2 	 0.100000

17 	 2 	 0.100000

34 	 2 	 0.100000

39 	 2 	 0.100000

48 	 2 	 0.100000

128 	 2 	 0.100000

132 	 2 	 0.100000

0 	 3 	 0.141421

0 	 4 	 0.141421

0 	 5 	 0.141421

0 	 6 	 0.141421

1 	 2 	 0.141421

8 	 2 	 0.141421

12 	 2 	 0.141421

19 	 2 	 0.141421

21 	 2 	 0.141421

27 	 2 	 0.141421

28 	 2 	 0.141421

29 	 2 	 0.141421

30 	 2 	 0.141421

37 	 2 	 0.141421

38 	 2 	 0.141421

40 	 2 	 0.141421

45 	 2 	 0.141421

46 	 2 	 0.141421

47 	 2 	 0.141421

49 	 2 	 0.141421

57 	 2 	 0.141421

63 	 2 	 0.141421

65 	 2 	 0.141421

75 	 2 	 0.141421

80 	 2 	 0.141421

81 	 2 	 0.141421

82 	 2 	 0.141421

91 	 2 	 0.141421

92 	 2 	 0.141421

93 	 2 	 0.141421

95 	 2 	 0.141421

96 	 2 	 0.141421

99 	 2 	 0.141421

116 	 2 	 0.141421

127 	 2 	 0.141421

137 	 2 	 0.141421

138 	 2 	 0.141421

25 	 2 	 0.173205

69 	 2 	 0.173205

88 	 2 	 0.173205

94 	 2 	 0.173205

112 	 2 	 0.173205

123 	 2 	 0.173205

126 	 2 	 0.173205

139 	 2 	 0.173205

23 	 2 	 0.200000

26 	 2 	 0.200000

42 	 2 	 0.200000

53 	 2 	 0.200000

66 	 2 	 0.200000

74 	 2 	 0.200000

78 	 2 	 0.200000

84 	 2 	 0.200000

89 	 2 	 0.200000

97 	 2 	 0.200000

11 	 2 	 0.223607

35 	 2 	 0.223607

43 	 2 	 0.223607

70 	 2 	 0.223607

73 	 2 	 0.223607

110 	 2 	 0.223607

120 	 2 	 0.223607

143 	 2 	 0.223607

147 	 2 	 0.223607

13 	 2 	 0.244949

54 	 2 	 0.244949

58 	 2 	 0.244949

67 	 2 	 0.244949

103 	 2 	 0.244949

136 	 2 	 0.244949

140 	 2 	 0.244949

141 	 2 	 0.244949

144 	 2 	 0.244949

145 	 2 	 0.244949

146 	 2 	 0.244949

148 	 2 	 0.244949

50 	 2 	 0.264575

51 	 2 	 0.264575

52 	 2 	 0.264575

56 	 2 	 0.264575

68 	 2 	 0.264575

87 	 2 	 0.264575

90 	 2 	 0.264575

101 	 3 	 0.264575

105 	 2 	 0.264575

107 	 2 	 0.264575

113 	 2 	 0.264575

122 	 2 	 0.264575

130 	 2 	 0.264575

142 	 3 	 0.264575

20 	 2 	 0.282843

31 	 2 	 0.282843

86 	 2 	 0.282843

149 	 2 	 0.282843

24 	 2 	 0.300000

27 	 14 	 0.300000

36 	 2 	 0.300000

55 	 2 	 0.300000

61 	 2 	 0.300000

104 	 2 	 0.300000

115 	 2 	 0.300000

124 	 2 	 0.300000

27 	 15 	 0.316228

76 	 2 	 0.316228

77 	 2 	 0.316228

121 	 2 	 0.316228

18 	 2 	 0.331662

27 	 16 	 0.331662

71 	 2 	 0.331662

83 	 2 	 0.331662

133 	 2 	 0.331662

32 	 2 	 0.346410

33 	 2 	 0.346410

79 	 2 	 0.346410

111 	 2 	 0.346410

125 	 2 	 0.346410

129 	 2 	 0.346410

44 	 2 	 0.360555

60 	 2 	 0.360555

72 	 2 	 0.360555

49 	 22 	 0.374166

85 	 2 	 0.374166

59 	 2 	 0.387298

98 	 2 	 0.387298

102 	 2 	 0.387298

117 	 2 	 0.412311

118 	 2 	 0.412311

131 	 2 	 0.412311

64 	 2 	 0.424264

100 	 2 	 0.424264

119 	 2 	 0.435890

62 	 2 	 0.489898

114 	 2 	 0.489898

134 	 2 	 0.538516

135 	 2 	 0.538516

108 	 2 	 0.556776

41 	 2 	 0.624500

109 	 2 	 0.632456

106 	 2 	 0.734847




CUSTO TOTAL DA ARVORE:   
36.925836 




Para executar o codigo basta, abrir o diretorio onde os arquivos se encontram e utilizar os comandos do compilador
ex:

gcc nomearquivo.c -o test, em seguida: ./test




