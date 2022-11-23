# Código de cifrado por desplazamiento en Python

# Se obtiene del archivo de texto el mensaje a cifrar (M)
# Se requiere tener un archivo llamado 'message.txt'
file = open("message.txt", "r")

message = file.read()

print(f'\nMensaje original: {message}')

# Se solicita al usuario ingresar la clave del cifrado (K), 
# se valida que sea un valor numérico en el rango de 0 a 25
while True:
    try:
        key = int(input(f'\nIngresa el valor del desplazamiento (clave): '))
    except ValueError:
        print(f'\nError: Solo se admiten valores numericos\n')
        continue

    if (key >= 0 and key <= 25):
        break;
    else:
        print(f'\nError: El valor de la clave debe estar en el rango de 0 a 25\n')

# Se crea una lista vacía para almacenar el mensaje cifrado
ciphered = []

# Se recorre cada caracter en la cadena del mensaje original
for i in message:
    # Se comprueba si se ha llegado al EOF
    if(i == '\n'):
        break;

    # Se omiten del cifrado los caracteres de espacio
    if (i == " "):
        ciphered.append(" ")
        continue

    # Se crea una variable para guardar el valor ASCII del caracter actual
    c = ""
    # Se crea una variable para diferenciar si el caracter corresponde a una mayúscula o minúscula 
    alphabet = ""

    # Se comprueba si el caracter actual corresponde a una letra mayúscula o minúscula
    if (ord(i) >= ord("a") and ord(i) <= ord("z")):
        c = ord(i) - ord("a")
        alphabet = ord("a")
    elif (ord(i) >= ord("A") and ord(i) <= ord("Z")):
        c = ord(i) - ord("A")
        alphabet = ord("A")

    # Se realiza el cifrado por medio de la función de desplazamiento
    ciphered.append(chr(((c + key) % 26) + alphabet))

# Se imprime el mensaje cifrado
print("\n\nMensaje cifrado: " + "".join(ciphered) + "\n")

# Se escribe el mensaje cirfado en un archivo de texto
file = open('cipheredMessage.txt','w')
file.write("".join(ciphered))
file.close()

