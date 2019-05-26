# ARG1 = Nombre del fichero

# Comprueba que se haya introducido el fichero correctamente
if [ $# -ne 1 ] || [ ! -f "$1"  ];
then
    echo "Los parámetros no son correctos"
    echo "Debe introducir el fichero"
    exit
fi

echo "Lista los directorios y ficheros del home del usuario ordenados por numero de caracteres"
ls -a ~/ | grep -E "^\..*" | awk '{ print length, $0 }' | sort -g | grep -Eo "\..+"

echo "#######################################################"
echo "Copia el fichero pasado por linea de comandos sin lineas"
grep -v -E '^\s*$' $1 > $1.sinLineasVacias

echo "#######################################################"
echo "Procesos del usuarios"

top -bn 1 | grep "$USER" | while read line
do 
    # Se tiene que usar grep pero no he encontrado forma de hacerlo
    pid=$(echo "$line" | awk '{ printf($1);}')
    hora=$(echo "$line" | awk '{ printf($11);}')
    ejecutable=$(echo "$line" | awk '{ printf($12);}')
    echo "PID: \"$pid\" HORA: \"$hora\" Ejecutable: \"$ejecutable\""
done

