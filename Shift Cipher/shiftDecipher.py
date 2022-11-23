# Código de descifrado por desplazamiento en Python

# Se obtiene del archivo de texto el mensaje a descifrar (C)
# Se requiere un archivo de texto llamado 'cipheredMessage.txt'
file = open("cipheredMessage.txt","r")

ciphered =  file.read()

print(f'\nMensaje cifrado: {ciphered}')

# Se solicita al usuario ingresar la clave del cifrado (K),
# se valida que sea un valor numérico en el rango de 0 a 25
while True:
    try:
        key = int(input(f'\nIngresa el valor del desplazamiento (clave): '))
    except ValueError:
        print(f'\nError: Solo se admiten valores numericos\n')
        continue

    if(key >= 0 and key <= 25):
        break;
    else:
        print(f'\nError: El valor de la clave debe ser en el rango de 0 a 25\n')

# Se crea una lista vacía para almacenar el mensaje descifrado
message = []

# Se recorre cada caracter en la cadena del mensaje cifrado
for i in ciphered:

    # Se omiten del descifrado los caracteres de espacio
    if (i == " "):
        message.append(" ")
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

    # Se realiza el descifrado por medio de la función de desplazamiento
    message.append(chr(((c - key) % 26) + alphabet))

# Se imprime el mensaje descifrado
print("\nMensaje descifrado: " + "".join(message) + "\n")
