include ../common.mk

SRCS=$(firstword $(wildcard *.asm))

BASE=$(basename ${SRCS})

BIN=${BASE}.bin

run:${BIN}
	${QEMU} -nographic -drive format=raw,file=${BIN}

${BIN}:$(SRCS)
	${ASM} -f bin ${SRCS} -o ${BIN}

server:${BIN}
	${QEMU} -nographic -drive format=raw,file=${BIN} -S -s

client:${BIN}
	${GDB} -q -ex "target remote :1234" -ex "b *0x7c00" -x ../gdbinit


clean:
	rm -f ${BIN}





