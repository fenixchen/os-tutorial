include ../common.mk

SRCS=$(firstword $(wildcard *main.asm))
BASE=$(basename $(SRCS))


BIN=${BASE}.bin

run:${BIN}
	${QEMU} -drive format=raw,file=${BIN} -boot c

${BIN}:$(SRCS)
	${ASM} -f bin ${SRCS} -o ${BIN}

server:${BIN}
	${QEMU} -drive format=raw,file=${BIN} -S -s

client:${BIN}
	${GDB} -q -ex "target remote :1234" -ex "b *0x7c00" -x ../gdbinit

asm:
	ndisasm ${BIN} > ${BASE}.S

clean:
	rm -f ${BIN} *.S





