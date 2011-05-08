T = int(raw_input())

for tc in xrange(1, T+1):
    N = int(raw_input())
    p = [int(x) for x in raw_input().split(" ")]
    ans = N
    
    for i in xrange(1, N+1):
        if p[i-1] == i:
            ans -= 1
    
    print "Case #%d: %d.000000" % (tc, ans)
