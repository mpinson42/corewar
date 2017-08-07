.name "toto"
.comment "test"

xor r1, r1, r1
or r1, %42, r1
lld %105042, r2
st r2, 46
lld 4, r2
st r2, 50
fork %128
lld 4, r2
st r2, 54
