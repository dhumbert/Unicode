int *code_point_to_utf8(int code_point)
{
    int *bytes = malloc(4 * sizeof(int));
    bytes[0] = -1;
    bytes[1] = -1;
    bytes[2] = -1;
    bytes[3] = -1;

    if (code_point >= 0x0000 && code_point <= 0x007F) {
        bytes[0] = code_point; // characters below code point 127 are ASCII
    } else if (code_point >= 0x0080 && code_point <= 0x07FF) { // 2 byte encoding
        bytes[0] = 0xC0 | ((code_point & 0x7C0) >> 6);
        bytes[1] = 0x80 | (code_point & 0x3F);
    } else if (code_point >= 0x0800 && code_point <= 0xFFFF) { // 3 byte encoding
        bytes[0] = 0xE0 | ((code_point & 0xF000) >> 12);
        bytes[1] = 0x80 | ((code_point & 0xFC0) >> 6);
        bytes[2] = 0x80 | (code_point & 0x3F);
    } else if (code_point >= 0x10000 && code_point <= 0x1FFFFF) { // 4 byte encoding
        bytes[0] = 0xF0 | ((code_point & 0x1C0000) >> 18);
        bytes[1] = 0x80 | ((code_point & 0x3F000) >> 12);
        bytes[2] = 0x80 | ((code_point & 0xFC0) >> 6);
        bytes[3] = 0x80 | (code_point & 0x3F);
    }

    return bytes;
}