#ARG1:ARG2...ARGN ficheros

date=$(date +%s) # Segundos que han pasado desde el 1/1/1970

# Comprueba si la carpeta ya existe
if [ ! -d "~/copia" ];
then 
    mkdir ~/copia
fi

for x in $(find ~/copia -type f)
do 
    modif=$(stat $x -c %X)
    let time=$date-$modif
    if [ $time -gt 200 ]
    then 
        rm -f $X
    fi 
done


if [ $# -gt 0 ];
then 
    tar -czf ~/copia/copia-$(whoami)-$date.tar.gz $*
else
    echo "No ha especificado ningún archivo o directorio"
fi
