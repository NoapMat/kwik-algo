# ofc takes the variables from "-v" for cli uses
BEGIN {
    cn1 = int(cn1)
    cn2 = int(cn2)
    k = substr(key, cn2 + 1, 1)
    for (i = 1; i <= length(key); i++) {
        key_map[substr(key, i, 1)] = i - 1
    }
    r = ""
    t = 0
    for (i = 1; i <= length(flstr); i++) {
        c = substr(flstr, i, 1)
        if (c == k) {
            r = r sprintf("%c", t - cn1)
            t = 0
        } else {
            t = t * cn2 + key_map[c]
        }
    }
    if (t > 0) {
        r = r sprintf("%c", t - cn1)
    }
    print r
}
