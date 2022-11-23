# Programa para el análisis de frecuencia de aparición se símbolos

# Se crea un arreglo para hacer el conteo de los símbolos por medio del método de cubetas (buckets)

buckets = []

for i in range(0, 26):
    buckets.append(0)

# Se solicita al usuario el nombre del archivo a analizar (se requiere especificar la ruta del archivo en caso de no estar dentro de la misma carpeta)

fileName = input("\nIngresa el nombre del archivo a analizar: ")

# Se obtiene el texto del archivo especificado
file = open(fileName,"r")
text = file.read()

# Se recorre el texto y se realiza el conteo de símbolos

n = 0

for i in text:
    index = ''
    if(ord(i) >= ord("a") and ord(i) <= ord("z")):
        index = ord(i) - ord("a")
        buckets[index] = buckets[index] + 1
        n = n + 1
    elif(ord(i) >= ord("A") and ord(i) <= ord("Z")):
        index = ord(i) - ord("A")
        buckets[index] = buckets[index] + 1
        n = n + 1

# Se escriben los resultados en el archivo de texto
file = open("frequencyResults.txt","w")
file.write(f'El total de símbolos [A-Z | a-z] es: {n}\n')

for i in range(0, 26):
    file.write("\n"+ chr(i + ord("A")) + " -> " + "{:.4f}".format(buckets[i]/n))

file.close()

print("\nResultados generados en el archivo 'frequencyResults.txt'\n")
