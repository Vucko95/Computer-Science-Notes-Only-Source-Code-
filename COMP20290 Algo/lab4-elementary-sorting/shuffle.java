public static void shuffle(Object[] a) {
        int n = a.length;
        for (int i = 0; i < n; i++) {
            // choose index uniformly in [0, i]
            int r = (int) (Math.random() * (i + 1));
            Object swap = a[r];
            a[r] = a[i];
            a[i] = swap;
        }
    }