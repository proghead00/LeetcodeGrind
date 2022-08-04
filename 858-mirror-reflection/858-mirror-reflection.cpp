class Solution {
public:
    int mirrorReflection(int p, int q) {
        int reflections = p;
        int extensions = q;

        while (extensions % 2 == 0 and reflections % 2 == 0) {
            extensions /= 2;
            reflections /= 2;
        }

        if (extensions % 2 == 0 and reflections % 2 != 0) return 0;
        if (extensions % 2 == 1 and reflections % 2 == 0)  return 2;
        if (extensions % 2 == 1 and reflections % 2 != 0) return 1;

        return -1;

    }
};