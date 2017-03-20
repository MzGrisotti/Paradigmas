#===============================TRABALHO 1=========================================
#=================================PARTE 1==========================================
# Exercício 1
def somaQuad(x,y):
	x = pow(x,2)
	y = pow(y,2)

	return x+y


# Exercício 2
def hasEqHeads(l1,l2):

	return l1[0] == l2[0]


# Exercício 3
def add_sr2(l1): 
	return "Sr." + l1

def add_sr(l1): 
	return list(map(add_sr2, l1))


# Exercício 4
def localiza_espaco_aux(string)
	return string == ' '

def localiza_espaco(string)
	return len(list(filter(localiza_espaco_aux, string)))


# Exercício 5
def funcao_equacao(l1): 
	return 3*l1*2 + 2/l1 + 1

def funcao_add(l1): 
	return list(map(funcao_equacao, l1))


# Exercício 6
def negativos_aux(l1): 
	return l1<0

def negativos(l1): 
	return list(filter(negativos_aux, l1)) 


# Exercício 7
def intervalo_aux(l1):
	return (l1>=1 and l1<=100)

def intervalo(l1):
	return list(filter(intervalo_aux, l1))


# Exercício 8
def par_aux(l1):
	return ((l1%2)==0)

def par(l1):
	return list(filter(par_aux, l1))


# Exercício 9 
def charFound(c, s):
	def charFound_aux(x):
		return c == x

	return filter(charFound_aux, s)


# Exercício 10
def add_marcadores_aux(string):
	return "<B>" + l1 + "</B>"

def add_marcadores_aux(lista_string):
	return list(map(add_marcadores_aux, lista_string)) 

#==================================================================================
#=================================PARTE 2==========================================
#==================================================================================
	
# Exercício 1
def add_sr(l1): 
	return list(map(lambda x: "Sr." + x , l1))


# Exercício 2
def funcao_equacao(l1): 
	return list(map(lambda x: 3*x*2 + 2/x + 1, l1))


# Exercício 3
def procura_letra(l1):
	return list(filter(lambda x: x[-1] == 'a', l1))


# Exercício 4
def apos_70(l1):
	return list(filter(lambda x: x < 2017 - 1970, l1));


# Exercício 5
def dobra_valor(l1):
	return list(map(lambda x: x*2, l1))
