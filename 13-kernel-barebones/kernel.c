/* This will force us to create a kernel entry function instead of jumping to kernel.c:0x00 */
void dummy_test_entrypoint() {
}

void main() {
    int i = 0;
    char* video_memory = (char*) 0xb8000;
    for (i = 0; i < 80; i ++){
        *(video_memory + (i << 1)) = ' ';
    }
    *video_memory = 'X';
    *(video_memory + 2) = 'Y';
    *(video_memory + 4) = 'Z';
}
