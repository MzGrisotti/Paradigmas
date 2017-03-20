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
