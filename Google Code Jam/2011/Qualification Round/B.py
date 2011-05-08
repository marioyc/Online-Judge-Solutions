import psyco

psyco.full()

T = int(raw_input())

for tc in xrange(1,T+1):
    tokens = [x for x in raw_input().split(" ")]
    #print "tokens : ", tokens
    L = []
    tail = 0
    
    C = int(tokens[0])
    D = int(tokens[C + 1])
    N = int(tokens[C + D + 2])
    seq = tokens[C + D + 3]
    sz = len(seq)
    #print C,D,N
    
    comb = tokens[1 : C + 1]
    #print "comb : ", comb
    
    opp = tokens[C + 2 : C + D + 2]
    #print "opp : ", opp
    
    for i in xrange(0,sz):
        #print i, seq[i]
        search = -1
        
        if tail > 0:
            for j in xrange(0,C):
                if (comb[j][0] == L[tail - 1] and comb[j][1] == seq[i]) or (comb[j][0] == seq[i] and comb[j][1] == L[tail - 1]):
                    search = j
                
                if search != -1:
                    break
        
        if search != -1:
            L.pop()
            L.append(comb[search][2])
        else:
            for j in xrange(0,tail):
                for k in xrange(0,D):
                    if opp[k] in (L[j] + seq[i], seq[i] + L[j]):
                        search = 1
                    
                    if search != -1:
                        break
                
                if search != -1:
                    break
            
            if search == 1:
                L = []
                tail = 0
            else:
                L.append(seq[i])
                tail += 1
    
    print "Case #%d: %s" % (tc, str(L).replace('\'',''))
