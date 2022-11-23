# Código del cifrador Afín en Python 

# Funcion para el cálculo del máximo común divisor (Greatest common divider)
def gcd (a, b):
    aux = ''

    while (b != 0):
        aux = b
        b = a % b
        a = aux

    return a

# Se obtiene del archivo de texto el mensaje a cifrar (M)
# Se requiere tener un archivo llamado 'message.txt'
file = open("message.txt","r")

message = file.read()

print(f'\nMensaje original: {message}')

# Se solicita al usuario ingresar el valor de 'a' y 'b'
# Se valida que sea un valor numérico en el rango de 0 a 25
# El valor de 'a' debe cumplir la condición de: gcd(a,26) = 1

while True:
    try:
        a = int(input("\nIngresa el valor de a (constante de decimación): "))
        b = int(input("\nIngresa el valor de b (constante de desplazamiento): "))
    except ValueError:
        print(f'\nError: Solo se permiten valores numericos en el rango de 0 a 25\n')
        continue

    if ((a >= 0 and a <= 25 and gcd(a,26) == 1)  and (b >= 0 and b <= 25)):
        break;
    else:
        print(f'\nError: El valor de "a" y "b" deben estar en el rango de 0 a 25 \nEl valor de "a" debe ser coprimo con 26')

# Se crea una lista vacía para almacenar el mensaje de cifrado
ciphered = []

# Se recorre cada caracter en la cadena del mensaje original
for i in message:
    # Se compureba si se ha llegado al EOF
    if(i == '\n'):
        break;

    # Se omiten del cifrado los caracteres de espacio
    if(i == " "):
        ciphered.append(" ")
        continue

    # Se crea una variable para guardar el valor ASCII del caracter actual
    c = ""
    # Se crea una variable para diferenciar si el caracter corresponde a una mayúscula o minúscula
    alphabet = ""

    # Se comprueba si el caracter actual corresponde a una letra mayúscula o minúscula
    if(ord(i) >= ord("a") and ord(i) <= ord("z")):
        c = ord(i) - ord("a")
        alphabet = ord("a")
    elif (ord(i) >= ord("A") and ord(i) <= ord("Z")):
        c = ord(i) - ord("A")
        alphabet = ord("A")

    # Se realiza el cifrado por medio de la función de desplazamiento
    ciphered.append(chr(((a*c + b) % 26) + alphabet))

# Se imprime el mensaje cifrado
print("\n\nMensaje cifrado: " + "".join(ciphered) + "\n")

# Se escribe el mensaje cifrado en un archivo de texto
file = open('cipheredMessage.txt','w')
file.write("".join(ciphered))
file.close()
