.name "toto"
.comment "test"

xor r1, r1, r1
or r1, %42, r1
lld %105042, r2
st r2, 46
lld 4, r2
st r2, 50
#ld 2, r2
#xor r2, 8, r2 
#st r2, 50

#NOTE ld copie toujours 4 octets, lld copie seulement 2 octets si l'argument est un indirect