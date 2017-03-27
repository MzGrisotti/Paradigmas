#===============================TRABALHO 2=========================================
#=================================PARTE 1==========================================

# Exercício 1
def addSufix(suf, nomes):
    return [nome + suf for nome in nomes]


# Exercício 2
def countShorts(words):
    return len([x for x in words if len(x)<5])


# Exercício 3
def isVowel(c):
	return c in 'aeiouAEIOU'

def stripVowels(s):
	return [x for x in s if not(isVowel(x))]


# Exercício 4
def isSpace(c):
	return  ' ' if c == ' ' else '-'

def hideChars(s):
	return ''.join([isSpace(x) for x in s]) 


# Exercício 5
def findSquares(n):
    return [(x,x**2) for x in range(1, n+1)]

# Exercício 6
def genTable(n):
	return [(x,x**2) for x in range(1, n+1)]

def genCode(s):
	return [x[0] + x[-1] for x in s] 


# Exercício 7
def myZip(l1, l2):
    return [(l1[x],l2[x]) for x in range(min(len(l1),len(l2)))]


# Exercício 8
def enumerate(words):
    return [(x+1, words[x]) for x in range(len(words))]


# Exercício 9
def isBin_aux(s):
	return [x for x in s if x == '1' or x == '0']

def isBin(s):
	return len(s) == len (isBin_aux(s))


# Exercício 10
def reverse(digits):
	return digits[::-1]

def bin2dec(digits):
	return sum([2**x for x in range(len(digits)) if reverse(digits)[x] == '1'])
