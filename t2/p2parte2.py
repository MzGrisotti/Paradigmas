import itertools

'''
   Programacao funcional para gerar SVG:
   - gera uma lista de coordenadas de retangulos
   - define uma lista de estilos (cores), em qualquer quantidade
   - aplica os estilos aos retangulos, gerando uma lista com todos os dados para o SVG
   - coloca os dados no formato SVG, concatenando strings
'''

def svgRect(rs):
   (((x,y),w,h),style) = rs
   return "<rect x='%.3f' y='%.3f' width='%.2f' height='%.2f' style='%s'/>\n" % (x,y,w,h,style)

def svgImage(w, h, rs):
   return "<svg width='%.2f' height='%.2f' xmlns='http://www.w3.org/2000/svg'>\n" % (w,h) + \
          ''.join(map(svgRect, rs)) + "</svg>"

def applyStyles(rects, styles):
   return list(zip(rects, itertools.cycle(styles)))

# TODO: modifique essa funcao para gerar mais retangulos
def genRects(n, w, h):
   m = [(((i*50),0.0),w,h) for i in range(n)]
   return m

def writeFile(fname, contents):
   f = open(fname, 'w')
   f.write(contents)
   f.close()

# Função geradora de cores
# Gera uma paleta de vermelhos
def genColors(n):
    r = [40+i*8 for i in range(n)]
    g = [1+i for i in range(n)]
    b = [1+i for i in range(n)]
    m = ["fill:rgb(%d,%d,%d)" %(r[i], g[i], b[i]) for i in range(n)]
    return m

   
def main():
   maxWidth = 1000
   maxHeight = 100
   rects = genRects(15,50,50)
   styles = genColors(15)
   rectstyles = applyStyles(rects, styles)
   writeFile("mycolors.svg", svgImage(maxWidth, maxHeight, rectstyles))
   

if __name__ == '__main__':
   main()
