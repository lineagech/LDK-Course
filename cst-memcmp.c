int cst_memcmp(const void *m1, const void *m2, size_t n) {
    const uint8_t *pm1 = (const uint8_t *) m1 + n;
    const uint8_t *pm2 = (const uint8_t *) m2 + n;
    int res = 0;
    if (n) {
        do {
            int diff = *--pm1 - *--pm2;
            res = (res & (((diff-1) & ~diff) >> 8)) | diff;
        } while (pm1 != m1);
    }
    return ((res - 1) >> 8) + (res >> 8) + 1;
}
